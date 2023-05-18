/*
 * * Copyright 2021 NVIDIA Corporation
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

static inline struct d3d12_command_list *d3d12_command_list_from_ID3D12GraphicsCommandListExt(d3d12_command_list_vkd3d_ext_iface *iface)
{
    return CONTAINING_RECORD(iface, struct d3d12_command_list, ID3D12GraphicsCommandListExt_iface);
}

extern ULONG STDMETHODCALLTYPE d3d12_command_list_AddRef(d3d12_command_list_iface *iface);

ULONG STDMETHODCALLTYPE d3d12_command_list_vkd3d_ext_AddRef(d3d12_command_list_vkd3d_ext_iface *iface)
{
    struct d3d12_command_list *command_list = d3d12_command_list_from_ID3D12GraphicsCommandListExt(iface);
    return d3d12_command_list_AddRef(&command_list->ID3D12GraphicsCommandList_iface);
}

extern ULONG STDMETHODCALLTYPE d3d12_command_list_Release(d3d12_command_list_iface *iface);

static ULONG STDMETHODCALLTYPE d3d12_command_list_vkd3d_ext_Release(d3d12_command_list_vkd3d_ext_iface *iface)
{
    struct d3d12_command_list *command_list = d3d12_command_list_from_ID3D12GraphicsCommandListExt(iface);
    return d3d12_command_list_Release(&command_list->ID3D12GraphicsCommandList_iface);
}

extern HRESULT STDMETHODCALLTYPE d3d12_command_list_QueryInterface(d3d12_command_list_iface *iface,
        REFIID iid, void **object);

static HRESULT STDMETHODCALLTYPE d3d12_command_list_vkd3d_ext_QueryInterface(d3d12_command_list_vkd3d_ext_iface *iface,
        REFIID iid, void **out)
{
    struct d3d12_command_list *command_list = d3d12_command_list_from_ID3D12GraphicsCommandListExt(iface);
    TRACE("iface %p, iid %s, out %p.\n", iface, debugstr_guid(iid), out);
    return d3d12_command_list_QueryInterface(&command_list->ID3D12GraphicsCommandList_iface, iid, out);
}

static HRESULT STDMETHODCALLTYPE d3d12_command_list_vkd3d_ext_GetVulkanHandle(d3d12_command_list_vkd3d_ext_iface *iface,
        VkCommandBuffer *pVkCommandBuffer)
{
    struct d3d12_command_list *command_list = d3d12_command_list_from_ID3D12GraphicsCommandListExt(iface);
    TRACE("iface %p, pVkCommandBuffer %p.\n", iface, pVkCommandBuffer);
    if (!pVkCommandBuffer)
        return E_INVALIDARG;

    *pVkCommandBuffer = command_list->cmd.vk_command_buffer;
    /* TODO: Do we need to block any attempt to split command buffers here?
     * Might be a problem if DLSS implementation caches the VkCommandBuffer across DLSS invocations. */
    return S_OK;
}

#define CU_LAUNCH_PARAM_BUFFER_POINTER (const void*)0x01
#define CU_LAUNCH_PARAM_BUFFER_SIZE    (const void*)0x02
#define CU_LAUNCH_PARAM_END            (const void*)0x00

static HRESULT STDMETHODCALLTYPE d3d12_command_list_vkd3d_ext_LaunchCubinShaderEx(d3d12_command_list_vkd3d_ext_iface *iface, D3D12_CUBIN_DATA_HANDLE *handle, UINT32 block_x, UINT32 block_y, UINT32 block_z, UINT32 smem_size, const void *params, UINT32 param_size, const void *raw_params, UINT32 raw_params_count)
{
    VkCuLaunchInfoNVX launchInfo = { VK_STRUCTURE_TYPE_CU_LAUNCH_INFO_NVX };
    const struct vkd3d_vk_device_procs *vk_procs;

    const void *config[] = {
        CU_LAUNCH_PARAM_BUFFER_POINTER, params,
        CU_LAUNCH_PARAM_BUFFER_SIZE,    &param_size,
        CU_LAUNCH_PARAM_END
    };

    struct d3d12_command_list *command_list = d3d12_command_list_from_ID3D12GraphicsCommandListExt(iface);
    TRACE("iface %p, handle %p, block_x %u, block_y %u, block_z %u, smem_size %u, params %p, param_size %u, raw_params %p, raw_params_count %u\n",
           iface, handle, block_x, block_y, block_z, smem_size, params, param_size, raw_params, raw_params_count);

    if (!handle || !block_x || !block_y || !block_z || !params || !param_size)
        return E_INVALIDARG;

    launchInfo.function = handle->vkCuFunction;
    launchInfo.gridDimX = block_x;
    launchInfo.gridDimY = block_y;
    launchInfo.gridDimZ = block_z;
    launchInfo.blockDimX = handle->blockX;
    launchInfo.blockDimY = handle->blockY;
    launchInfo.blockDimZ = handle->blockZ;
    launchInfo.sharedMemBytes = smem_size;
    launchInfo.paramCount = raw_params_count;
    launchInfo.pParams = raw_params;
    launchInfo.extraCount = 1;
    launchInfo.pExtras = config;
    
    vk_procs = &command_list->device->vk_procs;
    VK_CALL(vkCmdCuLaunchKernelNVX(command_list->cmd.vk_command_buffer, &launchInfo));
    return S_OK;
}

static HRESULT STDMETHODCALLTYPE d3d12_command_list_vkd3d_ext_LaunchCubinShader(d3d12_command_list_vkd3d_ext_iface *iface, D3D12_CUBIN_DATA_HANDLE *handle, UINT32 block_x, UINT32 block_y, UINT32 block_z, const void *params, UINT32 param_size)
{
    return d3d12_command_list_vkd3d_ext_LaunchCubinShaderEx(iface,
                                                            handle,
                                                            block_x,
                                                            block_y,
                                                            block_z,
                                                            0, /* smem_size */
                                                            params,
                                                            param_size,
                                                            NULL, /* raw_params */
                                                            0 /* raw_params_count */);
}

static HRESULT STDMETHODCALLTYPE d3d12_command_list_vkd3d_ext_BuildRaytracingAccelerationStructureEx(d3d12_command_list_vkd3d_ext_iface *iface,
        const void *params)
{
    struct d3d12_command_list *list = d3d12_command_list_from_ID3D12GraphicsCommandListExt(iface);
    const NVAPI_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_EX_PARAMS *nvParams = params;
    const NVAPI_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC_EX *desc;
    const struct vkd3d_vk_device_procs *vk_procs = &list->device->vk_procs;
    struct d3d12_rtas_batch_state *rtas_batch = &list->rtas_batch;
    VkAccelerationStructureTrianglesOpacityMicromapEXT *omm_infos;
    VkAccelerationStructureBuildGeometryInfoKHR *build_info;
    VkAccelerationStructureBuildRangeInfoKHR *range_infos;
    VkAccelerationStructureGeometryKHR *geometry_infos;
    uint32_t *primitive_counts = NULL;
    VkMemoryBarrier2 vk_barrier;
    VkDependencyInfo dep_info;
    uint32_t geometry_count;
    TRACE("iface %p, params %p.\n", iface, params);

    if (!nvParams)
        return NVAPI_INVALID_ARGUMENT;

    if (nvParams->version != NVAPI_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_EX_PARAMS_VER1)
        return NVAPI_INCOMPATIBLE_STRUCT_VERSION;

    if (!nvParams->pDesc || (nvParams->numPostbuildInfoDescs && !nvParams->pPostbuildInfoDescs))
        return NVAPI_INVALID_ARGUMENT;

    desc = nvParams->pDesc;

    if (!d3d12_device_supports_ray_tracing_tier_1_0(list->device))
    {
        WARN("Acceleration structure is not supported. Calling this is invalid.\n");
        return NVAPI_ERROR;
    }

    /* Do not batch TLAS and BLAS builds into the same command, since doing so
     * is disallowed if there are data dependencies between the builds. This
     * happens in Cyberpunk 2077, which does not emit appropriate UAV barriers. */
    if (rtas_batch->build_info_count && rtas_batch->build_type != desc->inputs.type)
    {
        d3d12_command_list_flush_rtas_batch(list);

        memset(&vk_barrier, 0, sizeof(vk_barrier));
        vk_barrier.sType = VK_STRUCTURE_TYPE_MEMORY_BARRIER_2;
        vk_barrier.srcStageMask = VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_KHR;
        vk_barrier.srcAccessMask = VK_ACCESS_2_ACCELERATION_STRUCTURE_WRITE_BIT_KHR;
        vk_barrier.dstStageMask = VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_KHR;
        vk_barrier.dstAccessMask = VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_KHR | VK_ACCESS_2_ACCELERATION_STRUCTURE_WRITE_BIT_KHR;

        if (list->device->device_info.opacity_micromap_features.micromap)
        {
            vk_barrier.srcAccessMask |= VK_ACCESS_2_MICROMAP_READ_BIT_EXT;
            vk_barrier.dstAccessMask |= VK_ACCESS_2_MICROMAP_READ_BIT_EXT;
        }

        memset(&dep_info, 0, sizeof(dep_info));
        dep_info.sType = VK_STRUCTURE_TYPE_DEPENDENCY_INFO;
        dep_info.memoryBarrierCount = 1;
        dep_info.pMemoryBarriers = &vk_barrier;

        VK_CALL(vkCmdPipelineBarrier2(list->cmd.vk_command_buffer, &dep_info));
    }

    rtas_batch->build_type = desc->inputs.type;

    geometry_count = vkd3d_acceleration_structure_get_geometry_count_nv(&desc->inputs);

#ifdef VKD3D_ENABLE_BREADCRUMBS
    if (vkd3d_config_flags & VKD3D_CONFIG_FLAG_BREADCRUMBS)
        primitive_counts = vkd3d_malloc(geometry_count * sizeof(*primitive_counts));
#endif

    if (!d3d12_command_list_allocate_rtas_build_info(list, geometry_count,
            &build_info, &geometry_infos, &omm_infos, &range_infos))
        return NVAPI_OUT_OF_MEMORY;

    if (!vkd3d_acceleration_structure_convert_inputs_nv(list->device, &desc->inputs,
            build_info, geometry_infos, omm_infos, range_infos, primitive_counts))
    {
        ERR("Failed to convert inputs.\n");
        return NVAPI_ERROR;
    }

    if (desc->destAccelerationStructureData)
    {
        build_info->dstAccelerationStructure =
                vkd3d_va_map_place_acceleration_structure(&list->device->memory_allocator.va_map,
                        list->device, desc->destAccelerationStructureData);
        if (build_info->dstAccelerationStructure == VK_NULL_HANDLE)
        {
            ERR("Failed to place destAccelerationStructure. Dropping call.\n");
            return NVAPI_ERROR;
        }
    }

    if (build_info->mode == VK_BUILD_ACCELERATION_STRUCTURE_MODE_UPDATE_KHR &&
            desc->sourceAccelerationStructureData)
    {
        build_info->srcAccelerationStructure =
                vkd3d_va_map_place_acceleration_structure(&list->device->memory_allocator.va_map,
                        list->device, desc->sourceAccelerationStructureData);
        if (build_info->srcAccelerationStructure == VK_NULL_HANDLE)
        {
            ERR("Failed to place srcAccelerationStructure. Dropping call.\n");
            return NVAPI_ERROR;
        }
    }

    build_info->scratchData.deviceAddress = desc->scratchAccelerationStructureData;

    /* Immediately execute the RTAS build command here
     * so that we don't have to copy micromap usage counts */
    d3d12_command_list_flush_rtas_batch(list);

#ifdef VKD3D_ENABLE_BREADCRUMBS
    if (vkd3d_config_flags & VKD3D_CONFIG_FLAG_BREADCRUMBS)
    {
        VKD3D_BREADCRUMB_TAG("RTAS build [Dest VA, Source VA, Scratch VA]");
        VKD3D_BREADCRUMB_AUX64(desc->destAccelerationStructureData);
        VKD3D_BREADCRUMB_AUX64(desc->sourceAccelerationStructureData);
        VKD3D_BREADCRUMB_AUX64(desc->scratchAccelerationStructureData);
        VKD3D_BREADCRUMB_TAG((desc->inputs.flags & D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PERFORM_UPDATE) ?
                "Update" : "Create");
        VKD3D_BREADCRUMB_TAG(desc->inputs.type == D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL ? "Top" : "Bottom");
        {
            VkAccelerationStructureBuildSizesInfoKHR size_info;

            memset(&size_info, 0, sizeof(size_info));
            size_info.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR;

            if (desc->inputs.flags & D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PERFORM_UPDATE)
            {
                build_info->mode = VK_BUILD_ACCELERATION_STRUCTURE_MODE_BUILD_KHR;
                build_info->flags |= VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_UPDATE_BIT_KHR;
            }
            VK_CALL(vkGetAccelerationStructureBuildSizesKHR(list->device->vk_device,
                    VK_ACCELERATION_STRUCTURE_BUILD_TYPE_DEVICE_KHR, build_info,
                    primitive_counts, &size_info));
            VKD3D_BREADCRUMB_TAG("Build requirements [Size, Build Scratch, Update Scratch]");
            VKD3D_BREADCRUMB_AUX64(size_info.accelerationStructureSize);
            VKD3D_BREADCRUMB_AUX64(size_info.buildScratchSize);
            VKD3D_BREADCRUMB_AUX64(size_info.updateScratchSize);

            if (desc->inputs.type == D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL)
            {
                VKD3D_BREADCRUMB_AUX64(desc->inputs.instanceDescs);
                VKD3D_BREADCRUMB_AUX32(desc->inputs.numDescs);
            }
            else
            {
                unsigned int i;
                for (i = 0; i < desc->inputs.numDescs; i++)
                {
                    const NVAPI_D3D12_RAYTRACING_GEOMETRY_DESC_EX *geom;
                    if (desc->inputs.descsLayout == D3D12_ELEMENTS_LAYOUT_ARRAY)
                        geom = &desc->inputs.pGeometryDescs[i];
                    else
                        geom = desc->inputs.ppGeometryDescs[i];

                    switch (geom->type)
                    {
                        case NVAPI_D3D12_RAYTRACING_GEOMETRY_TYPE_TRIANGLES_EX:
                            VKD3D_BREADCRUMB_TAG("Triangle [Flags, VBO VA, VBO stride, IBO, Transform, VBO format, IBO format, V count, I count]");
                            VKD3D_BREADCRUMB_AUX32(geom->flags);
                            VKD3D_BREADCRUMB_AUX64(geom->triangles.VertexBuffer.StartAddress);
                            VKD3D_BREADCRUMB_AUX64(geom->triangles.VertexBuffer.StrideInBytes);
                            VKD3D_BREADCRUMB_AUX64(geom->triangles.IndexBuffer);
                            VKD3D_BREADCRUMB_AUX64(geom->triangles.Transform3x4);
                            VKD3D_BREADCRUMB_AUX32(geom->triangles.VertexFormat);
                            VKD3D_BREADCRUMB_AUX32(geom->triangles.IndexFormat);
                            VKD3D_BREADCRUMB_AUX32(geom->triangles.VertexCount);
                            VKD3D_BREADCRUMB_AUX32(geom->triangles.IndexCount);
                            break;

                        case NVAPI_D3D12_RAYTRACING_GEOMETRY_TYPE_PROCEDURAL_PRIMITIVE_AABBS_EX:
                            VKD3D_BREADCRUMB_TAG("AABB [Flags, VA, stride, count]");
                            VKD3D_BREADCRUMB_AUX32(geom->flags);
                            VKD3D_BREADCRUMB_AUX64(geom->aabbs.AABBs.StartAddress);
                            VKD3D_BREADCRUMB_AUX64(geom->aabbs.AABBs.StrideInBytes);
                            VKD3D_BREADCRUMB_AUX64(geom->aabbs.AABBCount);
                            break;

                        case NVAPI_D3D12_RAYTRACING_GEOMETRY_TYPE_OMM_TRIANGLES_EX:
                            VKD3D_BREADCRUMB_TAG("OMM Triangle [Flags, VBO VA, VBO stride, IBO, Transform, VBO format, IBO format, V count, I count, OMM IBO VA, OMM IBO stride, OMM IBO format, OMM base location, OMM array, OMM usage count]");
                            VKD3D_BREADCRUMB_AUX32(geom->flags);
                            VKD3D_BREADCRUMB_AUX64(geom->ommTriangles.triangles.VertexBuffer.StartAddress);
                            VKD3D_BREADCRUMB_AUX64(geom->ommTriangles.triangles.VertexBuffer.StrideInBytes);
                            VKD3D_BREADCRUMB_AUX64(geom->ommTriangles.triangles.IndexBuffer);
                            VKD3D_BREADCRUMB_AUX64(geom->ommTriangles.triangles.Transform3x4);
                            VKD3D_BREADCRUMB_AUX32(geom->ommTriangles.triangles.VertexFormat);
                            VKD3D_BREADCRUMB_AUX32(geom->ommTriangles.triangles.IndexFormat);
                            VKD3D_BREADCRUMB_AUX32(geom->ommTriangles.triangles.VertexCount);
                            VKD3D_BREADCRUMB_AUX32(geom->ommTriangles.triangles.IndexCount);
                            VKD3D_BREADCRUMB_AUX64(geom->ommTriangles.ommAttachment.opacityMicromapIndexBuffer.StartAddress);
                            VKD3D_BREADCRUMB_AUX64(geom->ommTriangles.ommAttachment.opacityMicromapIndexBuffer.StrideInBytes);
                            VKD3D_BREADCRUMB_AUX32(geom->ommTriangles.ommAttachment.opacityMicromapIndexFormat);
                            VKD3D_BREADCRUMB_AUX32(geom->ommTriangles.ommAttachment.opacityMicromapBaseLocation);
                            VKD3D_BREADCRUMB_AUX64(geom->ommTriangles.ommAttachment.opacityMicromapArray);
                            VKD3D_BREADCRUMB_AUX32(geom->ommTriangles.ommAttachment.numOMMUsageCounts);
                            break;
                    }
                }
            }
        }

        vkd3d_free(primitive_counts);
    }
#endif

    if (nvParams->numPostbuildInfoDescs)
    {
        vkd3d_acceleration_structure_emit_immediate_postbuild_info(list,
                nvParams->numPostbuildInfoDescs, nvParams->pPostbuildInfoDescs,
                build_info->dstAccelerationStructure);
    }

    VKD3D_BREADCRUMB_COMMAND(BUILD_RTAS);

    return NVAPI_OK;
}

static HRESULT STDMETHODCALLTYPE d3d12_command_list_vkd3d_ext_BuildRaytracingOpacityMicromapArray(d3d12_command_list_vkd3d_ext_iface *iface,
        void *params)
{
    struct d3d12_command_list *list = d3d12_command_list_from_ID3D12GraphicsCommandListExt(iface);
    NVAPI_BUILD_RAYTRACING_OPACITY_MICROMAP_ARRAY_PARAMS *nvParams = params;
    const struct vkd3d_vk_device_procs *vk_procs = &list->device->vk_procs;
    const NVAPI_D3D12_BUILD_RAYTRACING_OPACITY_MICROMAP_ARRAY_DESC *desc;
    struct vkd3d_opacity_micromap_build_info build_info;
    TRACE("iface %p, params %p.\n", iface, params);

    if (!nvParams)
        return NVAPI_INVALID_ARGUMENT;

    if (nvParams->version != NVAPI_BUILD_RAYTRACING_OPACITY_MICROMAP_ARRAY_PARAMS_VER1)
        return NVAPI_INCOMPATIBLE_STRUCT_VERSION;

    if (!nvParams->pDesc || (nvParams->numPostbuildInfoDescs && !nvParams->pPostbuildInfoDescs))
        return NVAPI_INVALID_ARGUMENT;

    desc = nvParams->pDesc;

    if (!list->device->device_info.opacity_micromap_features.micromap)
    {
        ERR("Opacity micromap is not supported. Calling this is invalid.\n");
        return NVAPI_NOT_SUPPORTED;
    }

    if (!vkd3d_opacity_micromap_convert_inputs_nv(list->device, &build_info, &nvParams->pDesc->inputs))
    {
        ERR("Failed to convert inputs.\n");
        return NVAPI_ERROR;
    }

    if (desc->destOpacityMicromapArrayData)
    {
        build_info.build_info.dstMicromap =
                vkd3d_va_map_place_opacity_micromap(&list->device->memory_allocator.va_map,
                        list->device, desc->destOpacityMicromapArrayData);
        if (build_info.build_info.dstMicromap == VK_NULL_HANDLE)
        {
            ERR("Failed to place dstMicromap. Dropping call.\n");
            return NVAPI_ERROR;
        }
    }

    build_info.build_info.scratchData.deviceAddress = desc->scratchOpacityMicromapArrayData;

    d3d12_command_list_end_current_render_pass(list, true);
    d3d12_command_list_end_transfer_batch(list);

    VK_CALL(vkCmdBuildMicromapsEXT(list->cmd.vk_command_buffer, 1,
            &build_info.build_info));

#ifdef VKD3D_ENABLE_BREADCRUMBS
    VKD3D_BREADCRUMB_TAG("OMM build [Dest VA, Scratch VA]");
    VKD3D_BREADCRUMB_AUX64(desc->destOpacityMicromapArrayData);
    VKD3D_BREADCRUMB_AUX64(desc->scratchOpacityMicromapArrayData);
    {
        VkMicromapBuildSizesInfoEXT size_info;
        unsigned int i;

        memset(&size_info, 0, sizeof(size_info));
        size_info.sType = VK_STRUCTURE_TYPE_MICROMAP_BUILD_SIZES_INFO_EXT;

        VK_CALL(vkGetMicromapBuildSizesEXT(list->device->vk_device,
                VK_ACCELERATION_STRUCTURE_BUILD_TYPE_DEVICE_KHR, &build_info.build_info,
                &size_info));
        VKD3D_BREADCRUMB_TAG("Build requirements [Size, Build Scratch, Discardable]");
        VKD3D_BREADCRUMB_AUX64(size_info.micromapSize);
        VKD3D_BREADCRUMB_AUX64(size_info.buildScratchSize);
        VKD3D_BREADCRUMB_AUX32(size_info.discardable);

        VKD3D_BREADCRUMB_TAG("Inputs [Flags, VA, Descs VA, Descs stride]");
        VKD3D_BREADCRUMB_AUX32(desc->inputs.flags);
        VKD3D_BREADCRUMB_AUX64(desc->inputs.inputBuffer);
        VKD3D_BREADCRUMB_AUX64(desc->inputs.perOMMDescs.StartAddress);
        VKD3D_BREADCRUMB_AUX64(desc->inputs.perOMMDescs.StrideInBytes);

        for (i = 0; i < desc->inputs.numOMMUsageCounts; i++)
        {
            const NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_USAGE_COUNT *usage_count = &desc->inputs.pOMMUsageCounts[i];

            VKD3D_BREADCRUMB_TAG("Usage Count [Count, Subdivision Level, Format]");
            VKD3D_BREADCRUMB_AUX32(usage_count->count);
            VKD3D_BREADCRUMB_AUX32(usage_count->subdivisionLevel);
            VKD3D_BREADCRUMB_AUX32(usage_count->format);
        }
    }
#endif

    vkd3d_opacity_micromap_build_info_cleanup(&build_info);

    if (nvParams->numPostbuildInfoDescs)
    {
        vkd3d_opacity_micromap_emit_immediate_postbuild_info_nv(list,
                nvParams->numPostbuildInfoDescs, nvParams->pPostbuildInfoDescs,
                build_info.build_info.dstMicromap);
    }

    VKD3D_BREADCRUMB_COMMAND(BUILD_OMM);

    return NVAPI_OK;
}

static HRESULT STDMETHODCALLTYPE d3d12_command_list_vkd3d_ext_RelocateRaytracingOpacityMicromapArray(d3d12_command_list_vkd3d_ext_iface *iface,
        const void *params)
{
    FIXME("iface %p, params %p stub.\n", iface, params);
    return NVAPI_OK;
}

static HRESULT STDMETHODCALLTYPE d3d12_command_list_vkd3d_ext_EmitRaytracingOpacityMicromapArrayPostbuildInfo(d3d12_command_list_vkd3d_ext_iface *iface,
        const void *params)
{
    struct d3d12_command_list *list = d3d12_command_list_from_ID3D12GraphicsCommandListExt(iface);
    const NVAPI_EMIT_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_PARAMS *nvParams = params;
    TRACE("iface %p, params %p.\n", iface, params);

    if (!params)
        return NVAPI_INVALID_ARGUMENT;

    if (!nvParams)
        return NVAPI_INVALID_ARGUMENT;

    if (nvParams->version != NVAPI_EMIT_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_PARAMS_VER1)
        return NVAPI_INCOMPATIBLE_STRUCT_VERSION;

    if (!nvParams->pDesc || (nvParams->numSources && !nvParams->pSources))
        return NVAPI_INVALID_ARGUMENT;

    if (!list->device->device_info.opacity_micromap_features.micromap)
    {
        ERR("Opacity micromap is not supported. Calling this is invalid.\n");
        return NVAPI_NOT_SUPPORTED;
    }

    d3d12_command_list_end_current_render_pass(list, true);
    vkd3d_opacity_micromap_emit_postbuild_info_nv(list,
            nvParams->pDesc, nvParams->numSources, nvParams->pSources);

    VKD3D_BREADCRUMB_COMMAND(EMIT_OMM_POSTBUILD);

    return NVAPI_OK;
}

CONST_VTBL struct ID3D12GraphicsCommandListExt2Vtbl d3d12_command_list_vkd3d_ext_vtbl =
{
    /* IUnknown methods */
    d3d12_command_list_vkd3d_ext_QueryInterface,
    d3d12_command_list_vkd3d_ext_AddRef,
    d3d12_command_list_vkd3d_ext_Release,

    /* ID3D12GraphicsCommandListExt methods */
    d3d12_command_list_vkd3d_ext_GetVulkanHandle,
    d3d12_command_list_vkd3d_ext_LaunchCubinShader,

    /* ID3D12GraphicsCommandListExt1 methods */
    d3d12_command_list_vkd3d_ext_LaunchCubinShaderEx,

    /* ID3D12GraphicsCommandListExt2 methods */
    d3d12_command_list_vkd3d_ext_BuildRaytracingAccelerationStructureEx,
    d3d12_command_list_vkd3d_ext_BuildRaytracingOpacityMicromapArray,
    d3d12_command_list_vkd3d_ext_RelocateRaytracingOpacityMicromapArray,
    d3d12_command_list_vkd3d_ext_EmitRaytracingOpacityMicromapArrayPostbuildInfo,
};

