/*
 * Copyright 2023 Krzysztof Bogacki
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#define VKD3D_DBG_CHANNEL VKD3D_DBG_CHANNEL_API
#include "vkd3d_private.h"

#define RT_TRACE TRACE

void vkd3d_opacity_micromap_build_info_cleanup(
        struct vkd3d_opacity_micromap_build_info *info)
{
    if (info->usages != info->usages_stack)
        vkd3d_free(info->usages);
}

static VkBuildMicromapFlagsEXT nv_d3d12_build_flags_to_vk(
        NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_BUILD_FLAGS flags)
{
    VkBuildMicromapFlagsEXT vk_flags = 0;

    if (flags & NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_BUILD_FLAG_PREFER_FAST_TRACE)
        vk_flags |= VK_BUILD_MICROMAP_PREFER_FAST_TRACE_BIT_EXT;
    if (flags & NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_BUILD_FLAG_PREFER_FAST_BUILD)
        vk_flags |= VK_BUILD_MICROMAP_PREFER_FAST_BUILD_BIT_EXT;

    return vk_flags;
}

static VkOpacityMicromapFormatEXT nv_d3d12_format_to_vk(
        NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_FORMAT format)
{
    switch (format)
    {
        case NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_FORMAT_OC1_2_STATE:
            return VK_OPACITY_MICROMAP_FORMAT_2_STATE_EXT;
        case NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_FORMAT_OC1_4_STATE:
            return VK_OPACITY_MICROMAP_FORMAT_4_STATE_EXT;
        default:
            FIXME("Unrecognized format #%x.\n", format);
            return (VkOpacityMicromapFormatEXT)format;
    }
}

VKD3D_UNUSED static char const* debug_omm_format(
        NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_FORMAT format)
{
    switch (format)
    {
        #define ENUM_NAME(x) case x: return #x;
        ENUM_NAME(NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_FORMAT_OC1_2_STATE)
        ENUM_NAME(NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_FORMAT_OC1_4_STATE)
        #undef ENUM_NAME
    }

    return vkd3d_dbg_sprintf("Unknown NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_FORMAT (%u)",
        (uint32_t)format);
}

bool vkd3d_opacity_micromap_convert_inputs_nv(const struct d3d12_device *device,
        struct vkd3d_opacity_micromap_build_info *info,
        const NVAPI_D3D12_BUILD_RAYTRACING_OPACITY_MICROMAP_ARRAY_INPUTS *desc)
{
    const NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_USAGE_COUNT *usage_count;
    VkMicromapBuildInfoEXT *build_info;
    VkMicromapUsageEXT *usage;
    unsigned int i;

    RT_TRACE("Converting inputs.\n");
    RT_TRACE("=====================\n");

    build_info = &info->build_info;
    memset(build_info, 0, sizeof(*build_info));
    build_info->sType = VK_STRUCTURE_TYPE_MICROMAP_BUILD_INFO_EXT;
    build_info->type = VK_MICROMAP_TYPE_OPACITY_MICROMAP_EXT;
    build_info->flags = nv_d3d12_build_flags_to_vk(desc->flags);
    build_info->mode = VK_BUILD_MICROMAP_MODE_BUILD_EXT;
    build_info->usageCountsCount = desc->numOMMUsageCounts;

    info->usages = info->usages_stack;

    if (desc->numOMMUsageCounts <= VKD3D_BUILD_INFO_STACK_COUNT)
        memset(info->usages, 0, sizeof(*info->usages) * desc->numOMMUsageCounts);
    else
        info->usages = vkd3d_calloc(desc->numOMMUsageCounts, sizeof(*info->usages));

    for (i = 0; i < desc->numOMMUsageCounts; i++)
    {
        RT_TRACE(" Usage %u:\n", i);

        usage_count = &desc->pOMMUsageCounts[i];
        usage = &info->usages[i];

        usage->count = usage_count->count;
        usage->subdivisionLevel = usage_count->subdivisionLevel;
        usage->format = nv_d3d12_format_to_vk(usage_count->format);

        RT_TRACE("  Count: %u\n", usage_count->count);
        RT_TRACE("  Subdivision level: %u\n", usage_count->subdivisionLevel);
        RT_TRACE("  Format: %s\n", debug_omm_format(usage_count->format));
    }

    build_info->pUsageCounts = info->usages;
    build_info->data.deviceAddress = desc->inputBuffer;
    build_info->triangleArray.deviceAddress = desc->perOMMDescs.StartAddress;
    build_info->triangleArrayStride = desc->perOMMDescs.StrideInBytes;

    RT_TRACE(" IBO VA: %"PRIx64"\n", desc->inputBuffer);
    RT_TRACE(" Triangles VA: %"PRIx64"\n", desc->perOMMDescs.StartAddress);
    RT_TRACE(" Triangles stride: %"PRIu64" bytes\n", desc->perOMMDescs.StrideInBytes);

    RT_TRACE("=====================\n");
    return true;
}

static void vkd3d_opacity_micromap_end_barrier(struct d3d12_command_list *list)
{
    /* We resolve the query in TRANSFER, but DXR expects UNORDERED_ACCESS. */
    const struct vkd3d_vk_device_procs *vk_procs = &list->device->vk_procs;
    VkDependencyInfo dep_info;
    VkMemoryBarrier2 barrier;

    memset(&barrier, 0, sizeof(barrier));
    barrier.sType = VK_STRUCTURE_TYPE_MEMORY_BARRIER_2;
    barrier.srcStageMask = VK_PIPELINE_STAGE_2_COPY_BIT;
    barrier.srcAccessMask = VK_ACCESS_2_TRANSFER_WRITE_BIT;
    barrier.dstStageMask = VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT;

    memset(&dep_info, 0, sizeof(dep_info));
    dep_info.sType = VK_STRUCTURE_TYPE_DEPENDENCY_INFO;
    dep_info.memoryBarrierCount = 1;
    dep_info.pMemoryBarriers = &barrier;

    VK_CALL(vkCmdPipelineBarrier2(list->cmd.vk_command_buffer, &dep_info));
}

static void vkd3d_opacity_micromap_write_postbuild_info(
        struct d3d12_command_list *list,
        const NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_DESC *desc,
        VkDeviceSize desc_offset,
        VkMicromapEXT vk_opacity_micromap)
{
    const struct vkd3d_vk_device_procs *vk_procs = &list->device->vk_procs;
    const struct vkd3d_unique_resource *resource;
    VkBuffer vk_buffer;
    uint32_t offset;

    resource = vkd3d_va_map_deref(&list->device->memory_allocator.va_map, desc->destBuffer);
    if (!resource)
    {
        ERR("Invalid resource.\n");
        return;
    }

    vk_buffer = resource->vk_buffer;
    offset = desc->destBuffer - resource->va;
    offset += desc_offset;

    FIXME("Unsupported InfoType %u.\n", desc->infoType);
    /* TODO: CURRENT_SIZE is something we cannot query in Vulkan, so
        * we'll need to keep around a buffer to handle this.
        * For now, just clear to 0. */
    VK_CALL(vkCmdFillBuffer(list->cmd.vk_command_buffer, vk_buffer, offset,
            sizeof(uint64_t), 0));
}

void vkd3d_opacity_micromap_emit_postbuild_info_nv(
        struct d3d12_command_list *list,
        const NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_DESC *desc,
        uint32_t count,
        const D3D12_GPU_VIRTUAL_ADDRESS *addresses)
{
    const struct vkd3d_vk_device_procs *vk_procs = &list->device->vk_procs;
    VkMicromapEXT vk_opacity_micromap;
    VkDependencyInfo dep_info;
    VkMemoryBarrier2 barrier;
    uint32_t i;

    /* We resolve the query in TRANSFER, but DXR expects UNORDERED_ACCESS. */
    memset(&barrier, 0, sizeof(barrier));
    barrier.sType = VK_STRUCTURE_TYPE_MEMORY_BARRIER_2;
    barrier.srcStageMask = VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT;
    barrier.dstStageMask = VK_PIPELINE_STAGE_2_COPY_BIT;
    barrier.dstAccessMask = VK_ACCESS_2_TRANSFER_WRITE_BIT;

    memset(&dep_info, 0, sizeof(dep_info));
    dep_info.sType = VK_STRUCTURE_TYPE_DEPENDENCY_INFO;
    dep_info.memoryBarrierCount = 1;
    dep_info.pMemoryBarriers = &barrier;

    VK_CALL(vkCmdPipelineBarrier2(list->cmd.vk_command_buffer, &dep_info));

    for (i = 0; i < count; i++)
    {
        vk_opacity_micromap = vkd3d_va_map_place_opacity_micromap(
                &list->device->memory_allocator.va_map, list->device, addresses[i]);
        if (vk_opacity_micromap)
            vkd3d_opacity_micromap_write_postbuild_info(list, desc, i * sizeof(uint64_t), vk_opacity_micromap);
        else
            ERR("Failed to query opacity micromap for VA 0x%"PRIx64".\n", addresses[i]);
    }

    vkd3d_opacity_micromap_end_barrier(list);
}

void vkd3d_opacity_micromap_emit_immediate_postbuild_info_nv(
        struct d3d12_command_list *list, uint32_t count,
        const NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_DESC *desc,
        VkMicromapEXT vk_opacity_micromap)
{
    /* In D3D12 we are supposed to be able to emit without an explicit barrier,
     * but we need to emit them for Vulkan. */

    const struct vkd3d_vk_device_procs *vk_procs = &list->device->vk_procs;
    VkDependencyInfo dep_info;
    VkMemoryBarrier2 barrier;
    uint32_t i;

    memset(&barrier, 0, sizeof(barrier));
    barrier.sType = VK_STRUCTURE_TYPE_MEMORY_BARRIER_2;
    barrier.srcStageMask = VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT;
    barrier.srcAccessMask = VK_ACCESS_2_MICROMAP_WRITE_BIT_EXT;
    /* The query accesses STRUCTURE_READ_BIT in BUILD_BIT stage. */
    barrier.dstStageMask = VK_PIPELINE_STAGE_2_MICROMAP_BUILD_BIT_EXT | VK_PIPELINE_STAGE_2_COPY_BIT;
    barrier.dstAccessMask = VK_ACCESS_2_MICROMAP_READ_BIT_EXT | VK_ACCESS_2_TRANSFER_WRITE_BIT;

    memset(&dep_info, 0, sizeof(dep_info));
    dep_info.sType = VK_STRUCTURE_TYPE_DEPENDENCY_INFO;
    dep_info.memoryBarrierCount = 1;
    dep_info.pMemoryBarriers = &barrier;

    VK_CALL(vkCmdPipelineBarrier2(list->cmd.vk_command_buffer, &dep_info));

    for (i = 0; i < count; i++)
        vkd3d_opacity_micromap_write_postbuild_info(list, &desc[i], 0, vk_opacity_micromap);

    vkd3d_opacity_micromap_end_barrier(list);
}
