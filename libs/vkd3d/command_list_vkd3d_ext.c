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

    d3d12_command_list_flush_dgc_batch(command_list);
    d3d12_command_list_update_global_descriptor_heap(command_list);

    if (!handle || !params || !param_size)
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

static BOOL STDMETHODCALLTYPE d3d12_command_list_vkd3d_ext_VerifyOpacityMicromapArrayNVAPI(d3d12_command_list_vkd3d_ext_iface *iface,
    D3D12_GPU_VIRTUAL_ADDRESS opacity_micromap_array)
{
    struct d3d12_command_list *list = d3d12_command_list_from_ID3D12GraphicsCommandListExt(iface);
    enum vkd3d_rtas_kind rtas_kind;
    VkAccelerationStructureKHR as;

    TRACE("iface %p, opacity_micromap_array %#"PRIx64".\n", iface, opacity_micromap_array);

    vkd3d_va_map_try_read_rtas(&list->device->memory_allocator.va_map, list->device,
                opacity_micromap_array, &as, &rtas_kind);
    return as != VK_NULL_HANDLE && (rtas_kind == VKD3D_RTAS_KIND_NON_TLAS || rtas_kind == VKD3D_RTAS_KIND_MUTATED);
}

static HRESULT STDMETHODCALLTYPE d3d12_command_list_vkd3d_ext_RaytracingExecuteMultiIndirectClusterOperation(d3d12_command_list_vkd3d_ext_iface *iface,
        const void *params)
{
    struct d3d12_command_list *list = d3d12_command_list_from_ID3D12GraphicsCommandListExt(iface);
    const NVAPI_RAYTRACING_EXECUTE_MULTI_INDIRECT_CLUSTER_OPERATION_PARAMS *nvParams = params;
    VkClusterAccelerationStructureClustersBottomLevelInputNV clusters_bottom_level;
    const NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_DESC *desc;
    const struct vkd3d_vk_device_procs *vk_procs = &list->device->vk_procs;
    VkClusterAccelerationStructureTriangleClusterInputNV triangle_clusters;
    VkClusterAccelerationStructureMoveObjectsInputNV move_objects;
    VkClusterAccelerationStructureCommandsInfoNV commands_info;
    TRACE("iface %p, params %p.\n", iface, params);

    if (!nvParams)
        return NVAPI_INVALID_ARGUMENT;

    if (nvParams->version != NVAPI_RAYTRACING_EXECUTE_MULTI_INDIRECT_CLUSTER_OPERATION_PARAMS_VER1)
        return NVAPI_INCOMPATIBLE_STRUCT_VERSION;

    if (!nvParams->pDesc)
        return NVAPI_INVALID_ARGUMENT;

    desc = nvParams->pDesc;

    if (!list->device->device_info.cluster_acceleration_structure_features_nv.clusterAccelerationStructure)
    {
        ERR("Cluster acceleration structure is not supported. Calling this is invalid.\n");
        return NVAPI_NOT_SUPPORTED;
    }

    if (!vkd3d_acceleration_structure_convert_cluster_inputs_nv(&desc->inputs,
            &commands_info.input, &move_objects, &clusters_bottom_level, &triangle_clusters))
    {
        ERR("Failed to convert inputs.\n");
        return NVAPI_ERROR;
    }

    commands_info.sType = VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_COMMANDS_INFO_NV;
    commands_info.pNext = NULL;
    commands_info.dstImplicitData = desc->batchResultData;
    commands_info.scratchData = desc->batchScratchData;
    commands_info.dstAddressesArray.deviceAddress = desc->destinationAddressArray.StartAddress;
    commands_info.dstAddressesArray.stride = desc->destinationAddressArray.StrideInBytes;
    commands_info.dstAddressesArray.size = 0;
    commands_info.dstSizesArray.deviceAddress = desc->resultSizeArray.StartAddress;
    commands_info.dstSizesArray.stride = desc->resultSizeArray.StrideInBytes;
    commands_info.dstSizesArray.size = 0;
    commands_info.srcInfosArray.deviceAddress = desc->indirectArgArray.StartAddress;
    commands_info.srcInfosArray.stride = desc->indirectArgArray.StrideInBytes;
    commands_info.srcInfosArray.size = 0;
    commands_info.srcInfosCount = desc->indirectArgCount;
    commands_info.addressResolutionFlags = desc->addressResolutionFlags;

    d3d12_command_list_flush_rtas_batch(list);

    VK_CALL(vkCmdBuildClusterAccelerationStructureIndirectNV(list->cmd.vk_command_buffer, &commands_info));

    return NVAPI_OK;
}

static HRESULT STDMETHODCALLTYPE d3d12_command_list_vkd3d_ext_BuildRaytracingPartitionedTlasIndirect(d3d12_command_list_vkd3d_ext_iface *iface,
        const void *params)
{
    struct d3d12_command_list *list = d3d12_command_list_from_ID3D12GraphicsCommandListExt(iface);
    const NVAPI_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_PARAMS *nvParams = params;
    const NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_DESC *desc;
    const struct vkd3d_vk_device_procs *vk_procs = &list->device->vk_procs;
    VkBuildPartitionedAccelerationStructureInfoNV build_info;
    VkPartitionedAccelerationStructureFlagsNV flags;
    TRACE("iface %p, params %p.\n", iface, params);

    if (!nvParams)
        return NVAPI_INVALID_ARGUMENT;

    if (nvParams->version != NVAPI_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_PARAMS_VER1)
        return NVAPI_INCOMPATIBLE_STRUCT_VERSION;

    if (!nvParams->pDesc)
        return NVAPI_INVALID_ARGUMENT;

    desc = nvParams->pDesc;

    if (!list->device->device_info.partitioned_acceleration_structure_features_nv.partitionedAccelerationStructure)
    {
        ERR("Partitioned acceleration structure is not supported. Calling this is invalid.\n");
        return NVAPI_NOT_SUPPORTED;
    }

    vkd3d_acceleration_structure_convert_partitioned_inputs_nv(&desc->inputs, &build_info.input, &flags);

    build_info.sType = VK_STRUCTURE_TYPE_BUILD_PARTITIONED_ACCELERATION_STRUCTURE_INFO_NV;
    build_info.pNext = NULL;
    build_info.srcAccelerationStructureData = desc->srcAccelerationStructureData;
    build_info.dstAccelerationStructureData = desc->destAccelerationStructureData;
    build_info.scratchData = desc->scratchAccelerationStructureData;
    build_info.srcInfos = desc->indirectOps;
    build_info.srcInfosCount = desc->indirectOpCount;

    d3d12_command_list_flush_rtas_batch(list);

    VK_CALL(vkCmdBuildPartitionedAccelerationStructuresNV(list->cmd.vk_command_buffer, &build_info));

    return NVAPI_OK;
}

CONST_VTBL struct ID3D12GraphicsCommandListExt3Vtbl d3d12_command_list_vkd3d_ext_vtbl =
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
    d3d12_command_list_vkd3d_ext_VerifyOpacityMicromapArrayNVAPI,

    /* ID3D12GraphicsCommandListExt3 methods */
    d3d12_command_list_vkd3d_ext_RaytracingExecuteMultiIndirectClusterOperation,
    d3d12_command_list_vkd3d_ext_BuildRaytracingPartitionedTlasIndirect,
};

