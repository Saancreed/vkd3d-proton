/*********************************************************************************************************\
|*                                                                                                        *|
|* SPDX-FileCopyrightText: Copyright (c) 2019-2024 NVIDIA CORPORATION & AFFILIATES. All rights reserved.  *|
|* SPDX-License-Identifier: MIT                                                                           *|
|*                                                                                                        *|
|* Permission is hereby granted, free of charge, to any person obtaining a                                *|
|* copy of this software and associated documentation files (the "Software"),                             *|
|* to deal in the Software without restriction, including without limitation                              *|
|* the rights to use, copy, modify, merge, publish, distribute, sublicense,                               *|
|* and/or sell copies of the Software, and to permit persons to whom the                                  *|
|* Software is furnished to do so, subject to the following conditions:                                   *|
|*                                                                                                        *|
|* The above copyright notice and this permission notice shall be included in                             *|
|* all copies or substantial portions of the Software.                                                    *|
|*                                                                                                        *|
|* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR                             *|
|* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,                               *|
|* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL                               *|
|* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER                             *|
|* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING                                *|
|* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER                                    *|
|* DEALINGS IN THE SOFTWARE.                                                                              *|
|*                                                                                                        *|
|*                                                                                                        *|
\*********************************************************************************************************/

#pragma once
#include<stdbool.h>
#include"vkd3d_d3d12.h"
#include"nvapi_lite_salstart.h"
#pragma pack(push,8)
#ifdef __cplusplus
extern "C" {
#endif
#if (defined(WIN32) || defined(_WIN32)) && defined(_MSC_VER) && (_MSC_VER > 1399) && !defined(NVAPI_INTERNAL) && !defined(NVAPI_DEPRECATED_OLD)
#ifndef __nvapi_deprecated_function
#define __nvapi_deprecated_function(message) __declspec(deprecated(message))
#endif
#ifndef __nvapi_deprecated_datatype
#define __nvapi_deprecated_datatype(FirstRelease) __declspec(deprecated("Do not use this data type - it is deprecated in release " #FirstRelease "."))
#endif
#else
#ifndef __nvapi_deprecated_function
#define __nvapi_deprecated_function(message)
#endif
#ifndef __nvapi_deprecated_datatype
#define __nvapi_deprecated_datatype(FirstRelease)
#endif
#endif

#define NV_U8_MAX       (+255U)
#define NV_U16_MAX      (+65535U)
#define NV_S32_MAX      (+2147483647)
#define NV_U32_MIN      (0U)
#define NV_U32_MAX      (+4294967295U)
#define NV_U64_MAX      (+18446744073709551615ULL)

/* 64-bit types for compilers that support them, plus some obsolete variants */
#if (defined(WIN32) || defined(_WIN32)) && defined(_MSC_VER) && (_MSC_VER > 1399) && !defined(NVAPI_INTERNAL) && !defined(NVAPI_DEPRECATED_OLD)
#ifndef __nvapi_deprecated_function
#define __nvapi_deprecated_function(message) __declspec(deprecated(message))
#endif
#ifndef __nvapi_deprecated_datatype
#define __nvapi_deprecated_datatype(FirstRelease) __declspec(deprecated("Do not use this data type - it is deprecated in release " #FirstRelease "."))
#endif
#else
#ifndef __nvapi_deprecated_function
#define __nvapi_deprecated_function(message)
#endif
#ifndef __nvapi_deprecated_datatype
#define __nvapi_deprecated_datatype(FirstRelease)
#endif
#endif

#define NV_U8_MAX       (+255U)
#define NV_U16_MAX      (+65535U)
#define NV_S32_MAX      (+2147483647)
#define NV_U32_MIN      (0U)
#define NV_U32_MAX      (+4294967295U)
#define NV_U64_MAX      (+18446744073709551615ULL)

/* 64-bit types for compilers that support them, plus some obsolete variants */
#if defined(__GNUC__) || defined(__arm) || defined(__IAR_SYSTEMS_ICC__) || defined(__ghs__) || defined(_WIN64)
typedef unsigned long long NvU64; /* 0 to 18446744073709551615  */
typedef long long          NvS64; /* -9223372036854775808 to 9223372036854775807  */
#else
typedef unsigned __int64   NvU64; /* 0 to 18446744073709551615  */
typedef __int64            NvS64; /* -9223372036854775808 to 9223372036854775807  */
#endif

#ifndef NVAPI_USE_STDINT
#define NVAPI_USE_STDINT 0
#endif

#if NVAPI_USE_STDINT
typedef uint32_t           NvV32; /* "void": enumerated or multiple fields   */
typedef uint32_t           NvU32; /* 0 to 4294967295                         */
typedef  int32_t           NvS32; /* -2147483648 to 2147483647               */

#else
// mac os 32-bit still needs this
#if (defined(macintosh) || defined(__APPLE__)) && !defined(__LP64__)
typedef signed long        NvS32; /* -2147483648 to 2147483647  */   
#else
typedef signed int         NvS32; /* -2147483648 to 2147483647 */  
#endif

#if !((defined(NV_UNIX)) ||  (defined(__unix)))
// mac os 32-bit still needs this
#if ( (defined(macintosh) && defined(__LP64__) && (__NVAPI_RESERVED0__)) || \
      (!defined(macintosh) && defined(__NVAPI_RESERVED0__)) ) 
typedef unsigned int       NvU32; /* 0 to 4294967295                         */
#else
typedef unsigned long      NvU32; /* 0 to 4294967295                         */
#endif
#else
typedef unsigned int       NvU32; /* 0 to 4294967295                         */
#endif
#endif

typedef unsigned long    temp_NvU32; /* 0 to 4294967295                         */
typedef signed   short   NvS16;
typedef unsigned short   NvU16;
typedef unsigned char    NvU8;
typedef signed   char    NvS8;
typedef float            NvF32;
typedef double           NvF64;

/*!
 * Macro to convert NvU32 to NvF32.
 */
#define NvU32TONvF32(_pData) *(NvF32 *)(_pData)
/*!
 * Macro to convert NvF32 to NvU32.
 */
#define NvF32TONvU32(_pData) *(NvU32 *)(_pData)

#define NVAPI_SDK_VERSION 57218
/* Boolean type */
typedef NvU8 NvBool;
#define NV_TRUE           ((NvBool)(0 == 0))
#define NV_FALSE          ((NvBool)(0 != 0))

typedef struct _NV_RECT
{
    NvU32    left;
    NvU32    top;
    NvU32    right;
    NvU32    bottom;
} NV_RECT;


#define NV_DECLARE_HANDLE(name) struct name##__ { int unused; }; typedef struct name##__ *name

//! \addtogroup nvapihandles
//! NVAPI Handles - These handles are retrieved from various calls and passed in to others in NvAPI
//!                 These are meant to be opaque types.  Do not assume they correspond to indices, HDCs,
//!                 display indexes or anything else.
//!
//!                 Most handles remain valid until a display re-configuration (display mode set) or GPU
//!                 reconfiguration (going into or out of SLI modes) occurs.  If NVAPI_HANDLE_INVALIDATED
//!                 is received by an app, it should discard all handles, and re-enumerate them.
//! @{  
NV_DECLARE_HANDLE(NvLogicalGpuHandle);             //!< One or more physical GPUs acting in concert (SLI)
NV_DECLARE_HANDLE(NvPhysicalGpuHandle);            //!< A single physical GPU
NV_DECLARE_HANDLE(NvDisplayHandle);                //!< Display Device driven by NVIDIA GPU(s) (an attached display)
NV_DECLARE_HANDLE(NvMonitorHandle);                //!< Monitor handle
NV_DECLARE_HANDLE(NvUnAttachedDisplayHandle);      //!< Unattached Display Device driven by NVIDIA GPU(s)
NV_DECLARE_HANDLE(NvVisualComputingDeviceHandle);  //!< A handle to a Visual Computing Device
NV_DECLARE_HANDLE(NvEventHandle);                  //!< A handle to an event registration instance
NV_DECLARE_HANDLE(NvDLADeviceHandle);              //!< A handle to a DLA device


NV_DECLARE_HANDLE(NvHICHandle);                    //!< A handle to a Host Interface Card
NV_DECLARE_HANDLE(NvGSyncDeviceHandle);            //!< A handle to a Sync device
NV_DECLARE_HANDLE(NvVioHandle);                    //!< A handle to an SDI device
NV_DECLARE_HANDLE(NvTransitionHandle);             //!< A handle to address a single transition request
NV_DECLARE_HANDLE(NvAudioHandle);                  //!< NVIDIA HD Audio Device
NV_DECLARE_HANDLE(Nv3DVPContextHandle);            //!< A handle for a 3D Vision Pro (3DVP) context
NV_DECLARE_HANDLE(Nv3DVPTransceiverHandle);        //!< A handle for a 3DVP RF transceiver
NV_DECLARE_HANDLE(Nv3DVPGlassesHandle);            //!< A handle for a pair of 3DVP RF shutter glasses
NV_DECLARE_HANDLE(NvPcfClientHandle);              //!< A handle for NVPCF clients

typedef void* StereoHandle;                        //!< A stereo handle, that corresponds to the device interface

NV_DECLARE_HANDLE(NvSourceHandle);                 //!< Unique source handle on the system
NV_DECLARE_HANDLE(NvTargetHandle);                 //!< Unique target handle on the system
NV_DECLARE_HANDLE(NVDX_SwapChainHandle);           //!< DirectX SwapChain objects
static const NVDX_SwapChainHandle NVDX_SWAPCHAIN_NONE = 0;
NV_DECLARE_HANDLE(NvPresentBarrierClientHandle);   //!< PresentBarrier client object
//! @}

//! \ingroup nvapihandles
//! @{
#define NVAPI_DEFAULT_HANDLE        0
#define NV_BIT(x)    (1 << (x)) 
//! @}



//! \addtogroup nvapitypes
//! @{
#define NVAPI_GENERIC_STRING_MAX    4096
#define NVAPI_LONG_STRING_MAX       256
#define NVAPI_SHORT_STRING_MAX      64

typedef struct 
{
    NvS32   sX;
    NvS32   sY;
    NvS32   sWidth;
    NvS32   sHeight;
} NvSBox;

#ifndef NvGUID_Defined
#define NvGUID_Defined

typedef struct
{
    NvU32 data1;
    NvU16 data2;
    NvU16 data3;
    NvU8  data4[8];
} NvGUID, NvLUID;


#endif //#ifndef NvGUID_Defined
#define NVAPI_MAX_PHYSICAL_GPUS             64


#define NVAPI_MAX_PHYSICAL_BRIDGES          100
#define NVAPI_PHYSICAL_GPUS                 32
#define NVAPI_MAX_LOGICAL_GPUS              64
#define NVAPI_MAX_AVAILABLE_GPU_TOPOLOGIES  256
#define NVAPI_MAX_AVAILABLE_SLI_GROUPS      256
#define NVAPI_MAX_GPU_TOPOLOGIES            NVAPI_MAX_PHYSICAL_GPUS
#define NVAPI_MAX_GPU_PER_TOPOLOGY          8
#define NVAPI_MAX_DISPLAY_HEADS             2
#define NVAPI_ADVANCED_DISPLAY_HEADS        4
#define NVAPI_MAX_DISPLAYS                  NVAPI_PHYSICAL_GPUS * NVAPI_ADVANCED_DISPLAY_HEADS
#define NVAPI_MAX_ACPI_IDS                  16
#define NVAPI_MAX_VIEW_MODES                8


#define NVAPI_SYSTEM_MAX_HWBCS              128
#define NVAPI_SYSTEM_HWBC_INVALID_ID        0xffffffff

#define NVAPI_SYSTEM_MAX_DISPLAYS           NVAPI_MAX_PHYSICAL_GPUS * NV_MAX_HEADS
#define NV_MAX_HEADS                        4   //!< Maximum heads, each with NVAPI_DESKTOP_RES resolution
#define NVAPI_MAX_HEADS_PER_GPU             32
#define NV_MAX_VID_STREAMS      4   //!< Maximum number of input video streams, each with a #NVAPI_VIDEO_SRC_INFO
#define NV_MAX_VID_STREAMS_EX  20   //!< Increasing MAX no. of input video streams, each with a #NVAPI_VIDEO_SRC_INFO
#define NV_MAX_VID_PROFILES     4   //!< Maximum number of output video profiles supported

#define NVAPI_MAX_AUDIO_DEVICES             16


typedef char NvAPI_String[NVAPI_GENERIC_STRING_MAX];
typedef char NvAPI_LongString[NVAPI_LONG_STRING_MAX];
typedef char NvAPI_ShortString[NVAPI_SHORT_STRING_MAX];
typedef NvU16 NvAPI_UnicodeShortString[NVAPI_SHORT_STRING_MAX];
//! @}


// =========================================================================================
//!  NvAPI Version Definition \n
//!  Maintain per structure specific version define using the MAKE_NVAPI_VERSION macro. \n
//!  Usage: #define NV_GENLOCK_STATUS_VER  MAKE_NVAPI_VERSION(NV_GENLOCK_STATUS, 1)
//!  \ingroup nvapitypes
// =========================================================================================
#define MAKE_NVAPI_VERSION(typeName,ver) (NvU32)(sizeof(typeName) | ((ver)<<16))

//!  \ingroup nvapitypes
#define GET_NVAPI_VERSION(ver) (NvU32)((ver)>>16)

//!  \ingroup nvapitypes
#define GET_NVAPI_SIZE(ver) (NvU32)((ver) & 0xffff)


// ====================================================
//! NvAPI Status Values
//!   All NvAPI functions return one of these codes.
//!   \ingroup nvapistatus 
// ====================================================


typedef enum _NvAPI_Status
{
    NVAPI_OK                                    =  0,      //!< Success. Request is completed.
    NVAPI_ERROR                                 = -1,      //!< Generic error
    NVAPI_LIBRARY_NOT_FOUND                     = -2,      //!< NVAPI support library cannot be loaded.
    NVAPI_NO_IMPLEMENTATION                     = -3,      //!< not implemented in current driver installation
    NVAPI_API_NOT_INITIALIZED                   = -4,      //!< NvAPI_Initialize has not been called (successfully)
    NVAPI_INVALID_ARGUMENT                      = -5,      //!< The argument/parameter value is not valid or NULL.
    NVAPI_NVIDIA_DEVICE_NOT_FOUND               = -6,      //!< No NVIDIA display driver, or NVIDIA GPU driving a display, was found.
    NVAPI_END_ENUMERATION                       = -7,      //!< No more items to enumerate
    NVAPI_INVALID_HANDLE                        = -8,      //!< Invalid handle
    NVAPI_INCOMPATIBLE_STRUCT_VERSION           = -9,      //!< An argument's structure version is not supported
    NVAPI_HANDLE_INVALIDATED                    = -10,     //!< The handle is no longer valid (likely due to GPU or display re-configuration)
    NVAPI_OPENGL_CONTEXT_NOT_CURRENT            = -11,     //!< No NVIDIA OpenGL context is current (but needs to be)
    NVAPI_INVALID_POINTER                       = -14,     //!< An invalid pointer, usually NULL, was passed as a parameter
    NVAPI_NO_GL_EXPERT                          = -12,     //!< OpenGL Expert is not supported by the current drivers
    NVAPI_INSTRUMENTATION_DISABLED              = -13,     //!< OpenGL Expert is supported, but driver instrumentation is currently disabled
    NVAPI_NO_GL_NSIGHT                          = -15,     //!< OpenGL does not support Nsight

    NVAPI_EXPECTED_LOGICAL_GPU_HANDLE           = -100,    //!< Expected a logical GPU handle for one or more parameters
    NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE          = -101,    //!< Expected a physical GPU handle for one or more parameters
    NVAPI_EXPECTED_DISPLAY_HANDLE               = -102,    //!< Expected an NV display handle for one or more parameters
    NVAPI_INVALID_COMBINATION                   = -103,    //!< The combination of parameters is not valid. 
    NVAPI_NOT_SUPPORTED                         = -104,    //!< Requested feature is not supported in the selected GPU
    NVAPI_PORTID_NOT_FOUND                      = -105,    //!< No port ID was found for the I2C transaction
    NVAPI_EXPECTED_UNATTACHED_DISPLAY_HANDLE    = -106,    //!< Expected an unattached display handle as one of the input parameters.
    NVAPI_INVALID_PERF_LEVEL                    = -107,    //!< Invalid perf level 
    NVAPI_DEVICE_BUSY                           = -108,    //!< Device is busy; request not fulfilled
    NVAPI_NV_PERSIST_FILE_NOT_FOUND             = -109,    //!< NV persist file is not found
    NVAPI_PERSIST_DATA_NOT_FOUND                = -110,    //!< NV persist data is not found
    NVAPI_EXPECTED_TV_DISPLAY                   = -111,    //!< Expected a TV output display
    NVAPI_EXPECTED_TV_DISPLAY_ON_DCONNECTOR     = -112,    //!< Expected a TV output on the D Connector - HDTV_EIAJ4120.
    NVAPI_NO_ACTIVE_SLI_TOPOLOGY                = -113,    //!< SLI is not active on this device.
    NVAPI_SLI_RENDERING_MODE_NOTALLOWED         = -114,    //!< Setup of SLI rendering mode is not possible right now.
    NVAPI_EXPECTED_DIGITAL_FLAT_PANEL           = -115,    //!< Expected a digital flat panel.
    NVAPI_ARGUMENT_EXCEED_MAX_SIZE              = -116,    //!< Argument exceeds the expected size.
    NVAPI_DEVICE_SWITCHING_NOT_ALLOWED          = -117,    //!< Inhibit is ON due to one of the flags in NV_GPU_DISPLAY_CHANGE_INHIBIT or SLI active.
    NVAPI_TESTING_CLOCKS_NOT_SUPPORTED          = -118,    //!< Testing of clocks is not supported.
    NVAPI_UNKNOWN_UNDERSCAN_CONFIG              = -119,    //!< The specified underscan config is from an unknown source (e.g. INF)
    NVAPI_TIMEOUT_RECONFIGURING_GPU_TOPO        = -120,    //!< Timeout while reconfiguring GPUs
    NVAPI_DATA_NOT_FOUND                        = -121,    //!< Requested data was not found
    NVAPI_EXPECTED_ANALOG_DISPLAY               = -122,    //!< Expected an analog display
    NVAPI_NO_VIDLINK                            = -123,    //!< No SLI video bridge is present
    NVAPI_REQUIRES_REBOOT                       = -124,    //!< NVAPI requires a reboot for the settings to take effect
    NVAPI_INVALID_HYBRID_MODE                   = -125,    //!< The function is not supported with the current Hybrid mode.
    NVAPI_MIXED_TARGET_TYPES                    = -126,    //!< The target types are not all the same
    NVAPI_SYSWOW64_NOT_SUPPORTED                = -127,    //!< The function is not supported from 32-bit on a 64-bit system.
    NVAPI_IMPLICIT_SET_GPU_TOPOLOGY_CHANGE_NOT_ALLOWED = -128,    //!< There is no implicit GPU topology active. Use NVAPI_SetHybridMode to change topology.
    NVAPI_REQUEST_USER_TO_CLOSE_NON_MIGRATABLE_APPS = -129,      //!< Prompt the user to close all non-migratable applications.    
    NVAPI_OUT_OF_MEMORY                         = -130,    //!< Could not allocate sufficient memory to complete the call.
    NVAPI_WAS_STILL_DRAWING                     = -131,    //!< The previous operation that is transferring information to or from this surface is incomplete.
    NVAPI_FILE_NOT_FOUND                        = -132,    //!< The file was not found.
    NVAPI_TOO_MANY_UNIQUE_STATE_OBJECTS         = -133,    //!< There are too many unique instances of a particular type of state object.
    NVAPI_INVALID_CALL                          = -134,    //!< The method call is invalid. For example, a method's parameter may not be a valid pointer.
    NVAPI_D3D10_1_LIBRARY_NOT_FOUND             = -135,    //!< d3d10_1.dll cannot be loaded.
    NVAPI_FUNCTION_NOT_FOUND                    = -136,    //!< Couldn't find the function in the loaded DLL.
    NVAPI_INVALID_USER_PRIVILEGE                = -137,    //!< The application will require Administrator privileges to access this API.
	                                                       //!< The application can be elevated to a higher permission level by selecting "Run as Administrator".
    NVAPI_EXPECTED_NON_PRIMARY_DISPLAY_HANDLE   = -138,    //!< The handle corresponds to GDIPrimary.
    NVAPI_EXPECTED_COMPUTE_GPU_HANDLE           = -139,    //!< Setting Physx GPU requires that the GPU is compute-capable.
    NVAPI_STEREO_NOT_INITIALIZED                = -140,    //!< The Stereo part of NVAPI failed to initialize completely. Check if the stereo driver is installed.
    NVAPI_STEREO_REGISTRY_ACCESS_FAILED         = -141,    //!< Access to stereo-related registry keys or values has failed.
    NVAPI_STEREO_REGISTRY_PROFILE_TYPE_NOT_SUPPORTED = -142, //!< The given registry profile type is not supported.
    NVAPI_STEREO_REGISTRY_VALUE_NOT_SUPPORTED   = -143,    //!< The given registry value is not supported.
    NVAPI_STEREO_NOT_ENABLED                    = -144,    //!< Stereo is not enabled and the function needed it to execute completely.
    NVAPI_STEREO_NOT_TURNED_ON                  = -145,    //!< Stereo is not turned on and the function needed it to execute completely.
    NVAPI_STEREO_INVALID_DEVICE_INTERFACE       = -146,    //!< Invalid device interface.
    NVAPI_STEREO_PARAMETER_OUT_OF_RANGE         = -147,    //!< Separation percentage or JPEG image capture quality is out of [0-100] range.
    NVAPI_STEREO_FRUSTUM_ADJUST_MODE_NOT_SUPPORTED = -148, //!< The given frustum adjust mode is not supported.
    NVAPI_TOPO_NOT_POSSIBLE                     = -149,    //!< The mosaic topology is not possible given the current state of the hardware.
    NVAPI_MODE_CHANGE_FAILED                    = -150,    //!< An attempt to do a display resolution mode change has failed.        
    NVAPI_D3D11_LIBRARY_NOT_FOUND               = -151,    //!< d3d11.dll/d3d11_beta.dll cannot be loaded.
    NVAPI_INVALID_ADDRESS                       = -152,    //!< Address is outside of valid range.
    NVAPI_STRING_TOO_SMALL                      = -153,    //!< The pre-allocated string is too small to hold the result.
    NVAPI_MATCHING_DEVICE_NOT_FOUND             = -154,    //!< The input does not match any of the available devices.
    NVAPI_DRIVER_RUNNING                        = -155,    //!< Driver is running.
    NVAPI_DRIVER_NOTRUNNING                     = -156,    //!< Driver is not running.
    NVAPI_ERROR_DRIVER_RELOAD_REQUIRED          = -157,    //!< A driver reload is required to apply these settings.
    NVAPI_SET_NOT_ALLOWED                       = -158,    //!< Intended setting is not allowed.
    NVAPI_ADVANCED_DISPLAY_TOPOLOGY_REQUIRED    = -159,    //!< Information can't be returned due to "advanced display topology".
    NVAPI_SETTING_NOT_FOUND                     = -160,    //!< Setting is not found.
    NVAPI_SETTING_SIZE_TOO_LARGE                = -161,    //!< Setting size is too large.
    NVAPI_TOO_MANY_SETTINGS_IN_PROFILE          = -162,    //!< There are too many settings for a profile. 
    NVAPI_PROFILE_NOT_FOUND                     = -163,    //!< Profile is not found.
    NVAPI_PROFILE_NAME_IN_USE                   = -164,    //!< Profile name is duplicated.
    NVAPI_PROFILE_NAME_EMPTY                    = -165,    //!< Profile name is empty.
    NVAPI_EXECUTABLE_NOT_FOUND                  = -166,    //!< Application not found in the Profile.
    NVAPI_EXECUTABLE_ALREADY_IN_USE             = -167,    //!< Application already exists in the other profile.
    NVAPI_DATATYPE_MISMATCH                     = -168,    //!< Data Type mismatch 
    NVAPI_PROFILE_REMOVED                       = -169,    //!< The profile passed as parameter has been removed and is no longer valid.
    NVAPI_UNREGISTERED_RESOURCE                 = -170,    //!< An unregistered resource was passed as a parameter. 
    NVAPI_ID_OUT_OF_RANGE                       = -171,    //!< The DisplayId corresponds to a display which is not within the normal outputId range.
    NVAPI_DISPLAYCONFIG_VALIDATION_FAILED       = -172,    //!< Display topology is not valid so the driver cannot do a mode set on this configuration.
    NVAPI_DPMST_CHANGED                         = -173,    //!< Display Port Multi-Stream topology has been changed.
    NVAPI_INSUFFICIENT_BUFFER                   = -174,    //!< Input buffer is insufficient to hold the contents.    
    NVAPI_ACCESS_DENIED                         = -175,    //!< No access to the caller.
    NVAPI_MOSAIC_NOT_ACTIVE                     = -176,    //!< The requested action cannot be performed without Mosaic being enabled.
    NVAPI_SHARE_RESOURCE_RELOCATED              = -177,    //!< The surface is relocated away from video memory.
    NVAPI_REQUEST_USER_TO_DISABLE_DWM           = -178,    //!< The user should disable DWM before calling NvAPI.
    NVAPI_D3D_DEVICE_LOST                       = -179,    //!< D3D device status is D3DERR_DEVICELOST or D3DERR_DEVICENOTRESET - the user has to reset the device.
    NVAPI_INVALID_CONFIGURATION                 = -180,    //!< The requested action cannot be performed in the current state.
    NVAPI_STEREO_HANDSHAKE_NOT_DONE             = -181,    //!< Call failed as stereo handshake not completed.
    NVAPI_EXECUTABLE_PATH_IS_AMBIGUOUS          = -182,    //!< The path provided was too short to determine the correct NVDRS_APPLICATION
    NVAPI_DEFAULT_STEREO_PROFILE_IS_NOT_DEFINED = -183,    //!< Default stereo profile is not currently defined
    NVAPI_DEFAULT_STEREO_PROFILE_DOES_NOT_EXIST = -184,    //!< Default stereo profile does not exist
    NVAPI_CLUSTER_ALREADY_EXISTS                = -185,    //!< A cluster is already defined with the given configuration.
    NVAPI_DPMST_DISPLAY_ID_EXPECTED             = -186,    //!< The input display id is not that of a multi stream enabled connector or a display device in a multi stream topology 
    NVAPI_INVALID_DISPLAY_ID                    = -187,    //!< The input display id is not valid or the monitor associated to it does not support the current operation
    NVAPI_STREAM_IS_OUT_OF_SYNC                 = -188,    //!< While playing secure audio stream, stream goes out of sync
    NVAPI_INCOMPATIBLE_AUDIO_DRIVER             = -189,    //!< Older audio driver version than required
    NVAPI_VALUE_ALREADY_SET                     = -190,    //!< Value already set, setting again not allowed.
    NVAPI_TIMEOUT                               = -191,    //!< Requested operation timed out 
    NVAPI_GPU_WORKSTATION_FEATURE_INCOMPLETE    = -192,    //!< The requested workstation feature set has incomplete driver internal allocation resources
    NVAPI_STEREO_INIT_ACTIVATION_NOT_DONE       = -193,    //!< Call failed because InitActivation was not called.
    NVAPI_SYNC_NOT_ACTIVE                       = -194,    //!< The requested action cannot be performed without Sync being enabled.    
    NVAPI_SYNC_MASTER_NOT_FOUND                 = -195,    //!< The requested action cannot be performed without Sync Master being enabled.
    NVAPI_INVALID_SYNC_TOPOLOGY                 = -196,    //!< Invalid displays passed in the NV_GSYNC_DISPLAY pointer.
    NVAPI_ECID_SIGN_ALGO_UNSUPPORTED            = -197,    //!< The specified signing algorithm is not supported. Either an incorrect value was entered or the current installed driver/hardware does not support the input value.
    NVAPI_ECID_KEY_VERIFICATION_FAILED          = -198,    //!< The encrypted public key verification has failed.
    NVAPI_FIRMWARE_OUT_OF_DATE                  = -199,    //!< The device's firmware is out of date.
    NVAPI_FIRMWARE_REVISION_NOT_SUPPORTED       = -200,    //!< The device's firmware is not supported.
    NVAPI_LICENSE_CALLER_AUTHENTICATION_FAILED  = -201,    //!< The caller is not authorized to modify the License.
    NVAPI_D3D_DEVICE_NOT_REGISTERED             = -202,    //!< The user tried to use a deferred context without registering the device first  
    NVAPI_RESOURCE_NOT_ACQUIRED                 = -203,    //!< Head or SourceId was not reserved for the VR Display before doing the Modeset or the dedicated display.
    NVAPI_TIMING_NOT_SUPPORTED                  = -204,    //!< Provided timing is not supported.
    NVAPI_HDCP_ENCRYPTION_FAILED                = -205,    //!< HDCP Encryption Failed for the device. Would be applicable when the device is HDCP Capable.
    NVAPI_PCLK_LIMITATION_FAILED                = -206,    //!< Provided mode is over sink device pclk limitation.
    NVAPI_NO_CONNECTOR_FOUND                    = -207,    //!< No connector on GPU found. 
    NVAPI_HDCP_DISABLED                         = -208,    //!< When a non-HDCP capable HMD is connected, we would inform user by this code.
    NVAPI_API_IN_USE                            = -209,    //!< Atleast an API is still being called
    NVAPI_NVIDIA_DISPLAY_NOT_FOUND              = -210,    //!< No display found on Nvidia GPU(s).
    NVAPI_PRIV_SEC_VIOLATION                    = -211,    //!< Priv security violation, improper access to a secured register.
    NVAPI_INCORRECT_VENDOR                      = -212,    //!< NVAPI cannot be called by this vendor
    NVAPI_DISPLAY_IN_USE                        = -213,    //!< DirectMode Display is already in use
    NVAPI_UNSUPPORTED_CONFIG_NON_HDCP_HMD       = -214,    //!< The Config is having Non-NVidia GPU with Non-HDCP HMD connected
    NVAPI_MAX_DISPLAY_LIMIT_REACHED             = -215,    //!< GPU's Max Display Limit has Reached
    NVAPI_INVALID_DIRECT_MODE_DISPLAY           = -216,    //!< DirectMode not Enabled on the Display
    NVAPI_GPU_IN_DEBUG_MODE                     = -217,    //!< GPU is in debug mode, OC is NOT allowed.
    NVAPI_D3D_CONTEXT_NOT_FOUND                 = -218,    //!< No NvAPI context was found for this D3D object
    NVAPI_STEREO_VERSION_MISMATCH               = -219,    //!< there is version mismatch between stereo driver and dx driver
    NVAPI_GPU_NOT_POWERED                       = -220,    //!< GPU is not powered and so the request cannot be completed.
    NVAPI_ERROR_DRIVER_RELOAD_IN_PROGRESS       = -221,    //!< The display driver update in progress.
    NVAPI_WAIT_FOR_HW_RESOURCE                  = -222,    //!< Wait for HW resources allocation
    NVAPI_REQUIRE_FURTHER_HDCP_ACTION           = -223,    //!< operation requires further HDCP action
    NVAPI_DISPLAY_MUX_TRANSITION_FAILED         = -224,    //!< Dynamic Mux transition failure
    NVAPI_INVALID_DSC_VERSION                   = -225,    //!< Invalid DSC version
    NVAPI_INVALID_DSC_SLICECOUNT                = -226,    //!< Invalid DSC slice count
    NVAPI_INVALID_DSC_OUTPUT_BPP                = -227,    //!< Invalid DSC output BPP
    NVAPI_FAILED_TO_LOAD_FROM_DRIVER_STORE      = -228,    //!< There was an error while loading nvapi.dll from the driver store.
    NVAPI_NO_VULKAN                             = -229,    //!< OpenGL does not export Vulkan fake extensions
    NVAPI_REQUEST_PENDING                       = -230,    //!< A request for NvTOPPs telemetry CData has already been made and is pending a response.
    NVAPI_RESOURCE_IN_USE                       = -231,    //!< Operation cannot be performed because the resource is in use.
    NVAPI_INVALID_IMAGE                         = -232,    //!< Device kernel image is invalid
    NVAPI_INVALID_PTX                           = -233,    //!< PTX JIT compilation failed
    NVAPI_NVLINK_UNCORRECTABLE                  = -234,    //!< Uncorrectable NVLink error was detected during the execution
    NVAPI_JIT_COMPILER_NOT_FOUND                = -235,    //!< PTX JIT compiler library was not found.
    NVAPI_INVALID_SOURCE                        = -236,    //!< Device kernel source is invalid.
    NVAPI_ILLEGAL_INSTRUCTION                   = -237,    //!< While executing a kernel, the device encountered an illegal instruction.
    NVAPI_INVALID_PC                            = -238,    //!< While executing a kernel, the device program counter wrapped its address space
    NVAPI_LAUNCH_FAILED                         = -239,    //!< An exception occurred on the device while executing a kernel
    NVAPI_NOT_PERMITTED                         = -240,    //!< Attempted operation is not permitted.
    NVAPI_CALLBACK_ALREADY_REGISTERED           = -241,    //!< The callback function has already been registered.
    NVAPI_CALLBACK_NOT_FOUND                    = -242,    //!< The callback function is not found or not registered.
    NVAPI_INVALID_OUTPUT_WIRE_FORMAT            = -243,    //!< Invalid Wire Format for the VR HMD
} NvAPI_Status;

#define __cplusplus
#define __d3d12_h__

#if defined(__cplusplus) && defined(__d3d12_h__)
//! Flags specifying raytracing thread reordering hardware support.
//! Additional flags will be added as support becomes available.
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_THREAD_REORDERING_CAPS
{
    NVAPI_D3D12_RAYTRACING_THREAD_REORDERING_CAP_NONE     = 0x0,       //!< Thread reordering acts as a no-op
    NVAPI_D3D12_RAYTRACING_THREAD_REORDERING_CAP_STANDARD = NV_BIT(0)  //!< Standard thread reordering is supported
} NVAPI_D3D12_RAYTRACING_THREAD_REORDERING_CAPS;

//! Flags specifying raytracing Opacity Micromap support.
//! Additional flags will be added as support becomes available.
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_CAPS
{
    NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_CAP_NONE     = 0x0,       //!< Opacity Micromap support is not available.
                                                                      //!< The application must not attempt to use any OMM entrypoints or flags.
    NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_CAP_STANDARD = NV_BIT(0)  //!< Standard Opacity Micromap support is available
} NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_CAPS;

//! Flags specifying raytracing Displacement Micromap support.
//! Additional flags will be added as support becomes available.
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_CAPS
{
    NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_CAP_NONE     = 0x0,       //!< Displacement Micromap support is not available.
                                                                           //!< The application must not attempt to use any DMM entrypoints or flags.
    NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_CAP_STANDARD = NV_BIT(0)  //!< Standard Displacement Micromap support is available
} NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_CAPS;

//! Flags specifying raytracing Cluster Operation support.
//! Additional flags will be added as support becomes available.
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_CLUSTER_OPERATIONS_CAPS
{
    NVAPI_D3D12_RAYTRACING_CLUSTER_OPERATIONS_CAP_NONE     = 0x0,       //!< Cluster Operations support is not available.
                                                                        //!< The application must not attempt to use any Cluster Operations entrypoints or flags.
    NVAPI_D3D12_RAYTRACING_CLUSTER_OPERATIONS_CAP_STANDARD = NV_BIT(0)  //!< Standard Cluster Operations support is available
} NVAPI_D3D12_RAYTRACING_CLUSTER_OPERATIONS_CAPS;

//! Flags specifying raytracing Partitioned TLAS support.
//! Additional flags will be added as support becomes available.
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_CAPS
{
    NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_CAP_NONE     = 0x0,       //!< Partitioned TLAS support is not available.
                                                                      //!< The application must not attempt to use any Partitioned TLAS entrypoints or flags.
    NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_CAP_STANDARD = NV_BIT(0)  //!< Standard Partitioned TLAS support is available
} NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_CAPS;

//! Flags specifying raytracing sphere support.
//! Additional flags will be added as support becomes available.
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_SPHERES_CAP
{
    NVAPI_D3D12_RAYTRACING_SPHERES_CAP_NONE     = 0x0,       //!< Sphere primitive support is not available.
                                                             //!< The application must not attempt to use any sphere geometry.
    NVAPI_D3D12_RAYTRACING_SPHERES_CAP_STANDARD = NV_BIT(0)  //!< Standard sphere primitive support is available
} NVAPI_D3D12_RAYTRACING_SPHERES_CAPS;

//! Flags specifying raytracing linear swept sphere (LSS) support.
//! Additional flags will be added as support becomes available.
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_LINEAR_SWEPT_SPHERES_CAP
{
    NVAPI_D3D12_RAYTRACING_LINEAR_SWEPT_SPHERES_CAP_NONE     = 0x0,       //!< Linear swept sphere primitive support is not available.
                                                                          //!< The application must not attempt to use any linear swept sphere geometry.
    NVAPI_D3D12_RAYTRACING_LINEAR_SWEPT_SPHERES_CAP_STANDARD = NV_BIT(0)  //!< Standard linear swept sphere primitive support is available
} NVAPI_D3D12_RAYTRACING_LINEAR_SWEPT_SPHERES_CAPS;

//! List of Raytracing CAPS types that can be queried.
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_CAPS_TYPE
{
    NVAPI_D3D12_RAYTRACING_CAPS_TYPE_THREAD_REORDERING      =  0,
    NVAPI_D3D12_RAYTRACING_CAPS_TYPE_OPACITY_MICROMAP       =  1,
    NVAPI_D3D12_RAYTRACING_CAPS_TYPE_DISPLACEMENT_MICROMAP  =  2,
    NVAPI_D3D12_RAYTRACING_CAPS_TYPE_CLUSTER_OPERATIONS     =  3,
    NVAPI_D3D12_RAYTRACING_CAPS_TYPE_PARTITIONED_TLAS       =  4,
    NVAPI_D3D12_RAYTRACING_CAPS_TYPE_SPHERES                =  5,
    NVAPI_D3D12_RAYTRACING_CAPS_TYPE_LINEAR_SWEPT_SPHERES   =  6,
    NVAPI_D3D12_RAYTRACING_CAPS_TYPE_INVALID                = -1
} NVAPI_D3D12_RAYTRACING_CAPS_TYPE;

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D12_GetRaytracingCaps
//
//! DESCRIPTION: Query raytracing capabilities of a device.
//!
//! SUPPORTED OS:  Windows 10 and higher
//!
//!
//! \since Release: 520
//!
//! \param [in]     pDevice     Pointer to the device on which raytracing caps should be queried from.
//! \param [in]     type        Raytracing caps type requested. (ex: NVAPI_D3D12_RAYTRACING_CAPS_TYPE_THREAD_REORDERING)
//! \param [out]    pData       Pointer to memory that receives caps. (ex: NVAPI_D3D12_RAYTRACING_THREAD_REORDERING_CAPS*)
//! \param [in]     dataSize    Size in bytes to return to pData. Must match the size of the caps data requested. (ex: sizeof(NVAPI_D3D12_RAYTRACING_THREAD_REORDERING_CAPS))
//!
//! \return This API can return any of the error codes enumerated in #NvAPI_Status.
//!         If there are return error codes with specific meaning for this API, they are listed below.
//!
//! \retval ::NVAPI_OK                   Completed request
//! \retval ::NVAPI_INVALID_POINTER      A null pointer was passed as an argument
//! \retval ::NVAPI_INVALID_ARGUMENT     At least one of the arguments are invalid
//! \retval ::NVAPI_ERROR                Error occurred
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D12_GetRaytracingCaps(
    __in    ID3D12Device* pDevice,
    __in    NVAPI_D3D12_RAYTRACING_CAPS_TYPE type,
    __out   void* pData,
    __in    size_t dataSize);
#endif // defined(__cplusplus) && defined(__d3d12_h__)

#if defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12Device5_INTERFACE_DEFINED__) && defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__)

//! Flags specifying validation behaviour for raytracing operations.
//! \ingroup dx
//! See NvAPI_D3D12_EnableRaytracingValidation
typedef enum _NVAPI_D3D12_RAYTRACING_VALIDATION_FLAGS
{
    NVAPI_D3D12_RAYTRACING_VALIDATION_FLAG_NONE              = 0x0,       //!< No validation flags.
} NVAPI_D3D12_RAYTRACING_VALIDATION_FLAGS;

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D12_EnableRaytracingValidation
//
//! DESCRIPTION: Enable raytracing validation for a device.
//!              This function must be called before any other raytracing-related function
//!              is invoked on the device. Raytracing validation can only be enabled when
//!              the NV_ALLOW_RAYTRACING_VALIDATION envvar is set to 1.
//!
//! SUPPORTED OS:  Windows 10 and higher
//!
//!
//! \since Release: 545
//!
//! \param [in]     pDevice             Pointer to the device on which raytracing validation should be enabled.
//! \param [in]     flags               Raytracing validation flags.
//!
//! \return This API can return any of the error codes enumerated in #NvAPI_Status.
//!         If there are return error codes with specific meaning for this API, they are listed below.
//!
//! \retval ::NVAPI_OK                   Completed request
//! \retval ::NVAPI_INVALID_POINTER      A null pointer was passed as device argument
//! \retval ::NVAPI_INVALID_ARGUMENT     An unsupported flag was specified
//! \retval ::NVAPI_INVALID_CALL         The call was made too late (other raytracing-related calls have already been made)
//! \retval ::NVAPI_ACCESS_DENIED        Validation is not allowed by envvar
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D12_EnableRaytracingValidation(
    __in     ID3D12Device5* pDevice,
    __in     NVAPI_D3D12_RAYTRACING_VALIDATION_FLAGS flags);



//! Severity classification of validation messages.
//! \ingroup dx
//! See NVAPI_D3D12_RAYTRACING_VALIDATION_MESSAGE_CALLBACK
typedef enum _NVAPI_D3D12_RAYTRACING_VALIDATION_MESSAGE_SEVERITY
{
    NVAPI_D3D12_RAYTRACING_VALIDATION_MESSAGE_SEVERITY_ERROR    = 0x0,  //!< Error message (indicates likely bug)
    NVAPI_D3D12_RAYTRACING_VALIDATION_MESSAGE_SEVERITY_WARNING  = 0x1   //!< Warning message (indicates inadvisable usage or possible bug)
} NVAPI_D3D12_RAYTRACING_VALIDATION_MESSAGE_SEVERITY;

//! Callback for raytracing validation messages.
//! \param [in]     pUserData           User data pointer as provided to callback registration.
//! \param [in]     severity            Severity of message.
//! \param [in]     messageCode         Type of reported validation message.
//! \param [in]     message             Human-readable description of what the message code means.
//! \param [in]     messageDetails      Additional human-readable context for validation message. May contain newlines.
//! \ingroup dx
//! See NvAPI_D3D12_RegisterRaytracingValidationMessageCallback
typedef void(__stdcall *NVAPI_D3D12_RAYTRACING_VALIDATION_MESSAGE_CALLBACK)(void* pUserData, NVAPI_D3D12_RAYTRACING_VALIDATION_MESSAGE_SEVERITY severity, const char* messageCode, const char* message, const char* messageDetails);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D12_RegisterRaytracingValidationMessageCallback
//
//! DESCRIPTION: Register a message callback for raytracing validation messages.
//!              The provided callback may be invoked by the driver using any thread at any time until the callback is unregistered.
//!              It is invalid to register/unregister callbacks from within the callback.
//!              It is invalid to create or destroy objects for the device or record commands onto command lists from within the callback.
//!
//! SUPPORTED OS:  Windows 10 and higher
//!
//!
//! \since Release: 545
//!
//! \param [in]     pDevice             Pointer to the device from which to obtain raytracing validation messages.
//! \param [in]     pfnMessageCallback  Callback used to report validation messages.
//! \param [in]     pUserData           [optional] User data to pass as argument to message callback.
//! \param [out]    pHandle             Handle that may be used to unregister the callback.
//!
//! \return This API can return any of the error codes enumerated in #NvAPI_Status.
//!         If there are return error codes with specific meaning for this API, they are listed below.
//!
//! \retval ::NVAPI_OK                   Completed request
//! \retval ::NVAPI_INVALID_POINTER      A null pointer was passed as an argument
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D12_RegisterRaytracingValidationMessageCallback(
    __in     ID3D12Device5* pDevice,
    __in     NVAPI_D3D12_RAYTRACING_VALIDATION_MESSAGE_CALLBACK pfnMessageCallback,
    __in_opt void* pUserData,
    __out    void** pHandle);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D12_UnregisterRaytracingValidationMessageCallback
//
//! DESCRIPTION: Unregister a previously registered message callback for raytracing validation messages.
//!              The provided callback will not be invoked once the unregister call has returned.
//!
//! SUPPORTED OS:  Windows 10 and higher
//!
//!
//! \since Release: 545
//!
//! \param [in]     pDevice             Pointer to the device from which to stop obtaining raytracing validation messages.
//! \param [in]     handle              Handle to which callback should be unregistered, obtained at registration.
//!
//! \return This API can return any of the error codes enumerated in #NvAPI_Status.
//!         If there are return error codes with specific meaning for this API, they are listed below.
//!
//! \retval ::NVAPI_OK                   Completed request
//! \retval ::NVAPI_INVALID_POINTER      A null pointer was passed as device argument
//! \retval ::NVAPI_INVALID_ARGUMENT     Callback handle not recognized
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D12_UnregisterRaytracingValidationMessageCallback(
    __in  ID3D12Device5* pDevice,
    __in  void* handle);



///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D12_FlushRaytracingValidationMessages
//
//! DESCRIPTION: Flush any validation messages that have not yet been reported.
//!              This guarantees that any validation messages for work which is known to be complete on the GPU
//!              at the time of the call are reported to registered callbacks.
//!              This operation is lightweight if the flushed device does not have raytracing validation enabled.
//!
//! SUPPORTED OS:  Windows 10 and higher
//!
//!
//! \since Release: 545
//!
//! \param [in]     pDevice     Pointer to the device on which raytracing validation messages should be flushed.
//!
//! \return This API can return any of the error codes enumerated in #NvAPI_Status.
//!         If there are return error codes with specific meaning for this API, they are listed below.
//!
//! \retval ::NVAPI_OK                   Completed request
//! \retval ::NVAPI_INVALID_POINTER      A null pointer was passed as device argument
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D12_FlushRaytracingValidationMessages(
    __in     ID3D12Device5* pDevice);

#endif // defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12Device5_INTERFACE_DEFINED__) && defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__)

//! SUPPORTED OS:  Windows 10 and higher
//!
#if defined(__cplusplus) && defined(__d3d12_h__) && (defined(__ID3D12Device5_INTERFACE_DEFINED__) || defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__))

// Types used by both device and command list functions.

//! Flags specifying building instructions and hints when constructing a DMM Array.
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_BUILD_FLAGS
{
    NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_BUILD_FLAG_NONE              = 0x0,       //!< No options specified for the DMM Array build.
    NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_BUILD_FLAG_PREFER_FAST_TRACE = NV_BIT(0), //!< Allow the DMM Array build to take a little longer in order to optimize for traversal performance.
                                                                                                 //!< This flag is incompatible with #NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_BUILD_FLAG_PREFER_FAST_BUILD.
    NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_BUILD_FLAG_PREFER_FAST_BUILD = NV_BIT(1)  //!< Spend as little time as possible on the DMM Array build with some potential loss to traversal performance.
                                                                                                 //!< This flag is incompatible with #NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_BUILD_FLAG_PREFER_FAST_TRACE.
} NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_BUILD_FLAGS;

//! Specifies the input Displacement Micromap formats.
//! The DC1 (Displacement Compression 1) format follows the space-filling curve in barycentric space over the uniformly tessellated micro-triangles.
//!
//! \note This is a 16-bit value when used in #NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_DESC
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_FORMAT
{
    NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_FORMAT_DC1_64_TRIS_64_BYTES    = 0x1, //!< 64 micro-triangles packed into 64 bytes
    NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_FORMAT_DC1_256_TRIS_128_BYTES  = 0x2, //!< 256 micro-triangles packed into 128 bytes
    NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_FORMAT_DC1_1024_TRIS_128_BYTES = 0x3, //!< 1024 micro-triangles packed into 128 bytes

} NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_FORMAT;

//! Number of DMMs of a specific configuration in a DMM Array or BLAS build.
//! Used to compute conservative buffer size estimates for DMM Array and BLAS builds.
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_USAGE_COUNT
{
    NvU32                                               count;            //!< For DMM Array builds: total number of DMMs in the DMM Array with the particular \p subdivisionLevel and \p format specified in this descriptor.
                                                                          //!< For BLAS builds: total number of DMMs with the \p subdivisionLevel and \p format combination that is referenced from the BLAS.
    NvU32                                               subdivisionLevel; //!< Number of subdivisions for the DMM; valid inputs are [0, 5] (#NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_DC1_MAX_SUBDIVISION_LEVEL).
                                                                          //!< The total number of micro-triangles is 4<sup><tt>subdivisionLevel</tt></sup>.
    NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_FORMAT format;           //!< Displacement Micromap format.
} NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_USAGE_COUNT;

//! Describes one Displacement Micromap.
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_DESC
{
    NvU32 byteOffset;       //!< Byte offset from the \c inputBuffer, specified in the input structure #NVAPI_D3D12_BUILD_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_INPUTS, to where the input DMM data is located.
    NvU16 subdivisionLevel; //!< Number of subdivisions for the DMM; valid inputs are [0, 5] (#NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_DC1_MAX_SUBDIVISION_LEVEL).
                            //!< The total number of micro-triangles is 4<sup><tt>subdivisionLevel</tt></sup>.
    NvU16 format;           //!< Format of the DMM of type #NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_FORMAT.
} NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_DESC;

//! Input structure to DMM Array construction.
//! Individual DMMs are accessed via indices when used in bottom-level acceleration structure (BLAS) construction.
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_BUILD_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_INPUTS
{
    NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_BUILD_FLAGS  flags;             //!< Flags which apply to all DMMs in the array.
    NvU32                                                           numDMMUsageCounts; //!< Number of DMM usage count entries in the \p pDMMUsageCounts array.
    const NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_USAGE_COUNT* pDMMUsageCounts;   //!< Usage counts for each subdivision level and format combination across all the DMM entries in the build.
    D3D12_GPU_VIRTUAL_ADDRESS                                       inputBuffer;       //!< Address for raw DMM input data; it must be 256-byte aligned (#NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_BYTE_ALIGNMENT)
                                                                                       //!< It is recommended to try to organize DMMs together in memory that are expected to be used close together spatially.
    D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE                            perDMMDescs;       //!< GPU array with one #NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_DESC entry per DMM.
} NVAPI_D3D12_BUILD_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_INPUTS;

#endif // defined(__cplusplus) && defined(__d3d12_h__) && (defined(__ID3D12Device5_INTERFACE_DEFINED__) || defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__))

#if defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12Device5_INTERFACE_DEFINED__)

//! Conservative memory requirements for building a DMM Array.
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PREBUILD_INFO
{
    NvU64 resultDataMaxSizeInBytes; //!< Size required to hold the result of a DMM Array build based on the specified inputs.
    NvU64 scratchDataSizeInBytes;   //!< Scratch storage on GPU required during DMM Array build based on the specified inputs.
} NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PREBUILD_INFO;

//! Parameters given to NvAPI_D3D12_GetRaytracingDisplacementMicromapArrayPrebuildInfo().
//!
//! \ingroup dx
typedef struct _NVAPI_GET_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PREBUILD_INFO_PARAMS_V1
{
    NvU32                                                                  version; //!< [in]  Structure version; it should be set to #NVAPI_GET_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PREBUILD_INFO_PARAMS_VER.
    const NVAPI_D3D12_BUILD_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_INPUTS* pDesc;   //!< [in]  Description of the DMM Array build.
    NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PREBUILD_INFO*      pInfo;   //!< [out] Result of the query.
} NVAPI_GET_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PREBUILD_INFO_PARAMS_V1;
#define NVAPI_GET_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PREBUILD_INFO_PARAMS_VER1          MAKE_NVAPI_VERSION(NVAPI_GET_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PREBUILD_INFO_PARAMS_V1, 1)
typedef NVAPI_GET_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PREBUILD_INFO_PARAMS_V1            NVAPI_GET_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PREBUILD_INFO_PARAMS;
#define NVAPI_GET_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PREBUILD_INFO_PARAMS_VER           NVAPI_GET_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PREBUILD_INFO_PARAMS_VER1

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D12_GetRaytracingDisplacementMicromapArrayPrebuildInfo
//
//! DESCRIPTION: Query conservative memory requirements for building a DMM (Displacement Micromap) Array.
//!              The returned size is conservative for DMM Array builds containing
//!              a lower or equal number of entries for each resolution and format combination.
//!
//!
//! SUPPORTED OS:  Windows 10 and higher
//!
//! \deprecated  Do not use this function - it is deprecated in release 570.
//!
//! \since Release: 525
//!
//! \param [in]     pDevice                      Device on which the DMM Array will be built.
//! \param [in,out] pParams                      Wrapper around the inputs and outputs of the function.
//!
//! \return This API can return any of the error codes enumerated in #NvAPI_Status.
//!         If there are return error codes with specific meaning for this API, they are listed below.
//!
//! \ingroup dx 
///////////////////////////////////////////////////////////////////////////////
__nvapi_deprecated_function("Do not use this function - it is deprecated in release 570.")
NVAPI_INTERFACE NvAPI_D3D12_GetRaytracingDisplacementMicromapArrayPrebuildInfo(
    __in    ID3D12Device5* pDevice,
    __inout NVAPI_GET_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PREBUILD_INFO_PARAMS* pParams);

#endif // defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12Device5_INTERFACE_DEFINED__)

//! SUPPORTED OS:  Windows 10 and higher
//!
#if defined(__cplusplus) && defined(__d3d12_h__) && (defined(__ID3D12Device5_INTERFACE_DEFINED__) || defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__))

// Types used by both device and command list functions.

//! Flags specifying building instructions and hints when constructing an OMM Array.
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_BUILD_FLAGS
{
    NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_BUILD_FLAG_NONE              = 0x0,       //!< No options specified for the OMM Array build.
    NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_BUILD_FLAG_PREFER_FAST_TRACE = NV_BIT(0), //!< Allow the OMM Array build to take a little longer in order to optimize for traversal performance.
                                                                                            //!< This flag is incompatible with #NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_BUILD_FLAG_PREFER_FAST_BUILD.
    NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_BUILD_FLAG_PREFER_FAST_BUILD = NV_BIT(1)  //!< Spend as little time as possible on the OMM Array build with some potential loss to traversal performance.
                                                                                            //!< This flag is incompatible with #NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_BUILD_FLAG_PREFER_FAST_TRACE.
} NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_BUILD_FLAGS;

//! Specifies the input Opacity Micromap formats.
//! The OC1 (Opacity Compression 1) format follows the space-filling curve in barycentric space over the uniformly tessellated micro-triangles.
//!
//! \note This is a 16-bit value when used in #NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_DESC.
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_FORMAT
{
    NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_FORMAT_OC1_2_STATE = 0x1, //!< 2-state (Transparent/Opaque) format.
    NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_FORMAT_OC1_4_STATE = 0x2  //!< 4-state (Transparent/Opaque, Known/Unknown) format.
} NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_FORMAT;

//! Number of OMMs of a specific configuration in an OMM Array.
//! Used to compute conservative buffer size estimates for OMM Array builds.
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_USAGE_COUNT
{
    NvU32                                          count;            //!< Total number of OMMs in the OMM Array with the particular \p subdivisionLevel and \p format specified in this descriptor.
    NvU32                                          subdivisionLevel; //!< Number of subdivisions for the OMM; valid inputs are [0, 12] (#NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_OC1_MAX_SUBDIVISION_LEVEL).
                                                                     //!< The total number of micro-triangles is 4<sup><tt>subdivisionLevel</tt></sup>.
    NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_FORMAT format;           //!< Opacity Micromap format.
} NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_USAGE_COUNT;

//! Describes one Opacity Micromap.
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_DESC
{
    NvU32 byteOffset;       //!< Byte offset from the \c inputBuffer, specified in the input structure #NVAPI_D3D12_BUILD_RAYTRACING_OPACITY_MICROMAP_ARRAY_INPUTS, to where the input OMM data is located.
    NvU16 subdivisionLevel; //!< Number of subdivisions for the OMM; valid inputs are [0, 12] (#NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_OC1_MAX_SUBDIVISION_LEVEL).
                            //!< The total number of micro-triangles is 4<sup><tt>subdivisionLevel</tt></sup>.
    NvU16 format;           //!< Format of the OMM of type #NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_FORMAT.
} NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_DESC;

//! Input structure to OMM Array construction.
//! Individual OMMs are accessed via indices when used in bottom-level acceleration structure (BLAS) construction.
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_BUILD_RAYTRACING_OPACITY_MICROMAP_ARRAY_INPUTS
{
    NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_BUILD_FLAGS  flags;             //!< Flags which apply to all OMMs in the array.
    NvU32                                                      numOMMUsageCounts; //!< Number of OMM usage count entries in the \p pOMMUsageCounts array.
    const NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_USAGE_COUNT* pOMMUsageCounts;   //!< Usage counts for each subdivision level and format combination across all the OMM entries in the build.
    D3D12_GPU_VIRTUAL_ADDRESS                                  inputBuffer;       //!< Address for raw OMM input data; it must be 256-byte aligned.
                                                                                  //!< It is recommended to try to organize OMMs together in memory that are expected to be used close together spatially.
    D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE                       perOMMDescs;       //!< GPU array with one #NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_DESC entry per OMM.
} NVAPI_D3D12_BUILD_RAYTRACING_OPACITY_MICROMAP_ARRAY_INPUTS;

#endif // defined(__cplusplus) && defined(__d3d12_h__) && (defined(__ID3D12Device5_INTERFACE_DEFINED__) || defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__))

#if defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12Device5_INTERFACE_DEFINED__)

//! Conservative memory requirements for building an OMM Array.
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_PREBUILD_INFO
{
    NvU64 resultDataMaxSizeInBytes; //!< Size required to hold the result of an OMM Array build based on the specified inputs.
    NvU64 scratchDataSizeInBytes;   //!< Scratch storage on GPU required during OMM Array build based on the specified inputs.
} NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_PREBUILD_INFO;

//! Parameters given to NvAPI_D3D12_GetRaytracingOpacityMicromapArrayPrebuildInfo().
//!
//! \ingroup dx
typedef struct _NVAPI_GET_RAYTRACING_OPACITY_MICROMAP_ARRAY_PREBUILD_INFO_PARAMS_V1
{
    NvU32                                                             version; //!< [in]  Structure version; it should be set to #NVAPI_GET_RAYTRACING_OPACITY_MICROMAP_ARRAY_PREBUILD_INFO_PARAMS_VER.
    const NVAPI_D3D12_BUILD_RAYTRACING_OPACITY_MICROMAP_ARRAY_INPUTS* pDesc;   //!< [in]  Description of the OMM Array build.
    NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_PREBUILD_INFO*      pInfo;   //!< [out] Result of the query.
} NVAPI_GET_RAYTRACING_OPACITY_MICROMAP_ARRAY_PREBUILD_INFO_PARAMS_V1;
#define NVAPI_GET_RAYTRACING_OPACITY_MICROMAP_ARRAY_PREBUILD_INFO_PARAMS_VER1          MAKE_NVAPI_VERSION(NVAPI_GET_RAYTRACING_OPACITY_MICROMAP_ARRAY_PREBUILD_INFO_PARAMS_V1, 1)
typedef NVAPI_GET_RAYTRACING_OPACITY_MICROMAP_ARRAY_PREBUILD_INFO_PARAMS_V1            NVAPI_GET_RAYTRACING_OPACITY_MICROMAP_ARRAY_PREBUILD_INFO_PARAMS;
#define NVAPI_GET_RAYTRACING_OPACITY_MICROMAP_ARRAY_PREBUILD_INFO_PARAMS_VER           NVAPI_GET_RAYTRACING_OPACITY_MICROMAP_ARRAY_PREBUILD_INFO_PARAMS_VER1

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D12_GetRaytracingOpacityMicromapArrayPrebuildInfo
//
//! DESCRIPTION: Query conservative memory requirements for building an OMM (Opacity Micromap) Array.
//!              The returned size is conservative for OMM Array builds containing
//!              a lower or equal number of entries for each resolution and format combination.
//!
//!
//! SUPPORTED OS:  Windows 10 and higher
//!
//!
//! \since Release: 520
//!
//! \param [in]     pDevice                      Device on which the OMM Array will be built.
//! \param [in,out] pParams                      Wrapper around the inputs and outputs of the function.
//!
//! \return This API can return any of the error codes enumerated in #NvAPI_Status.
//!         If there are return error codes with specific meaning for this API, they are listed below.
//!
//! \ingroup dx 
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D12_GetRaytracingOpacityMicromapArrayPrebuildInfo(
    __in    ID3D12Device5* pDevice,
    __inout NVAPI_GET_RAYTRACING_OPACITY_MICROMAP_ARRAY_PREBUILD_INFO_PARAMS* pParams);

#endif // defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12Device5_INTERFACE_DEFINED__)

#if defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12Device5_INTERFACE_DEFINED__)

//! Pipeline creation state flags.
//! Support should only be enabled for the specific features that are present, since they may incur a small penalty on traversal performance overall.
//! If the pipeline is not created with the correct primitive support, and that primitive type is encountered during traversal, behavior is undefined.
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_PIPELINE_CREATION_STATE_FLAGS
{
    NVAPI_D3D12_PIPELINE_CREATION_STATE_FLAGS_NONE                   = 0,         //!< [in] No pipeline flags.
    NVAPI_D3D12_PIPELINE_CREATION_STATE_FLAGS_ENABLE_OMM_SUPPORT     = NV_BIT(0), //!< [in] Change whether raytracing pipelines are created with support for Opacity Micromaps.
    NVAPI_D3D12_PIPELINE_CREATION_STATE_FLAGS_ENABLE_DMM_SUPPORT     = NV_BIT(1), //!< [in] Change whether raytracing pipelines are created with support for Displacement Micromaps.
    NVAPI_D3D12_PIPELINE_CREATION_STATE_FLAGS_ENABLE_CLUSTER_SUPPORT = NV_BIT(2), //!< [in] Change whether raytracing pipelines are created with support for Clustered BLAS.
    NVAPI_D3D12_PIPELINE_CREATION_STATE_FLAGS_ENABLE_SPHERE_SUPPORT  = NV_BIT(3), //!< [in] Change whether raytracing pipelines are created with support for Spheres.
    NVAPI_D3D12_PIPELINE_CREATION_STATE_FLAGS_ENABLE_LSS_SUPPORT     = NV_BIT(4), //!< [in] Change whether raytracing pipelines are created with support for Linear Swept Spheres (LSS).
} NVAPI_D3D12_PIPELINE_CREATION_STATE_FLAGS;

//! State used when creating new pipelines.
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_SET_CREATE_PIPELINE_STATE_OPTIONS_PARAMS_V1
{
    NvU32 version; //!< [in] Structure version; it should be set to #NVAPI_D3D12_SET_CREATE_PIPELINE_STATE_OPTIONS_PARAMS_VER.
    NvU32 flags;   //!< [in] A bitwise OR of one or more #NVAPI_D3D12_PIPELINE_CREATION_STATE_FLAGS flags for raytracing pipeline creation.
} NVAPI_D3D12_SET_CREATE_PIPELINE_STATE_OPTIONS_PARAMS_V1;
#define NVAPI_D3D12_SET_CREATE_PIPELINE_STATE_OPTIONS_PARAMS_VER1          MAKE_NVAPI_VERSION(NVAPI_D3D12_SET_CREATE_PIPELINE_STATE_OPTIONS_PARAMS_V1, 1)
typedef NVAPI_D3D12_SET_CREATE_PIPELINE_STATE_OPTIONS_PARAMS_V1            NVAPI_D3D12_SET_CREATE_PIPELINE_STATE_OPTIONS_PARAMS;
#define NVAPI_D3D12_SET_CREATE_PIPELINE_STATE_OPTIONS_PARAMS_VER           NVAPI_D3D12_SET_CREATE_PIPELINE_STATE_OPTIONS_PARAMS_VER1

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D12_SetCreatePipelineStateOptions
//
//! DESCRIPTION: Globally change the state affecting pipeline creations.
//!              This affects all pipelines created after this call, and until this function is called again.
//!
//! \note Only supported on GPUs capable of DXR.
//!       Some of the flags and fields have further restrictions, in which case their description will include a note with more details.
//!
//! SUPPORTED OS:  Windows 10 and higher
//!
//!
//! \since Release: 520
//!
//! \param [in]  pDevice                         Device on which the pipelines will be created.
//! \param [in]  pState                          State to be applied to all future pipeline creations.

//! \return This API can return any of the error codes enumerated in #NvAPI_Status.
//!         If there are return error codes with specific meaning for this API, they are listed below.
//!
//! \ingroup dx 
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D12_SetCreatePipelineStateOptions(
    __in ID3D12Device5* pDevice,
    __in const NVAPI_D3D12_SET_CREATE_PIPELINE_STATE_OPTIONS_PARAMS* pState);

#endif // defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12Device5_INTERFACE_DEFINED__)

#if defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12Device5_INTERFACE_DEFINED__)

//! Type of serialized data.
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_SERIALIZED_DATA_TYPE_EX
{
    // D3D12_SERIALIZED_DATA_TYPE flags
    NVAPI_D3D12_SERIALIZED_DATA_RAYTRACING_ACCELERATION_STRUCTURE_EX = 0x0,      //!< Serialized data contains a raytracing acceleration structure.
                                                                                 //!< Starting from offset 0, the first bytes of the serialized acceleration structure can be reinterpreted as \c D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER.
                                                                                 //!< That structure contains the identifier to be passed along to NvAPI_D3D12_CheckDriverMatchingIdentifierEx().

    // NVAPI_D3D12_SERIALIZED_DATA_TYPE_EX specific flags
    NVAPI_D3D12_SERIALIZED_DATA_RAYTRACING_OPACITY_MICROMAP_ARRAY_EX = 0x1,      //!< Data blob contains an OMM Array.
                                                                                 //!< Starting from offset 0, the first bytes of the OMM Array can be reinterpreted as \c D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER.
    NVAPI_D3D12_SERIALIZED_DATA_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_EX = 0x2, //!< Data blob contains a DMM Array.
                                                                                 //!< Starting from offset 0, the first bytes of the DMM Array can be reinterpreted as \c D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER.

} NVAPI_D3D12_SERIALIZED_DATA_TYPE_EX;

//! Parameters given to NvAPI_D3D12_CheckDriverMatchingIdentifierEx().
//!
//! \ingroup dx
typedef struct _NVAPI_CHECK_DRIVER_MATCHING_IDENTIFIER_EX_PARAMS_V1
{
    NvU32                                                   version;            //!< [in]  Structure version; it should be set to #NVAPI_CHECK_DRIVER_MATCHING_IDENTIFIER_EX_PARAMS_VER.
    NVAPI_D3D12_SERIALIZED_DATA_TYPE_EX                     serializedDataType; //!< [in]  Type of data to be deserialized; see #NVAPI_D3D12_SERIALIZED_DATA_TYPE_EX.
    const D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER* pIdentifierToCheck; //!< [in]  Identifier from the header of the serialized data to check with the driver; see \c D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER.
                                                                                //!<       Information about how to retrieve that identifier can be found in the description of each #NVAPI_D3D12_SERIALIZED_DATA_TYPE_EX enum.
    D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS                 checkStatus;        //!< [out] Result of the check; see \c D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS.
} NVAPI_CHECK_DRIVER_MATCHING_IDENTIFIER_EX_PARAMS_V1;
#define NVAPI_CHECK_DRIVER_MATCHING_IDENTIFIER_EX_PARAMS_VER1          MAKE_NVAPI_VERSION(NVAPI_CHECK_DRIVER_MATCHING_IDENTIFIER_EX_PARAMS_V1, 1)
typedef NVAPI_CHECK_DRIVER_MATCHING_IDENTIFIER_EX_PARAMS_V1            NVAPI_CHECK_DRIVER_MATCHING_IDENTIFIER_EX_PARAMS;
#define NVAPI_CHECK_DRIVER_MATCHING_IDENTIFIER_EX_PARAMS_VER           NVAPI_CHECK_DRIVER_MATCHING_IDENTIFIER_EX_PARAMS_VER1

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D12_CheckDriverMatchingIdentifierEx
//
//! DESCRIPTION: This function is an extension of <tt>ID3D12Device5::CheckDriverMatchingIdentifier()</tt> with additional serialized data types.
//!
//! SUPPORTED OS:  Windows 10 and higher
//!
//!
//! \since Release: 520
//!
//! \param [in]     pDevice                      Device on which the data will be deserialized.
//! \param [in,out] pParams                      Wrapper around the inputs and outputs of the function.
//!
//! \return This API can return any of the error codes enumerated in #NvAPI_Status.
//!         If there are return error codes with specific meaning for this API, they are listed below.
//!
//! \ingroup dx 
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D12_CheckDriverMatchingIdentifierEx(
    __in    ID3D12Device5* pDevice,
    __inout NVAPI_CHECK_DRIVER_MATCHING_IDENTIFIER_EX_PARAMS* pParams);

#endif // defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12Device5_INTERFACE_DEFINED__)

#if defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12Device5_INTERFACE_DEFINED__)

//! This enum extends \c D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS with modified and additional values.
//! Only modified/new values are fully described; for more information on the other values, please check Microsoft's DirectX Raytracing Specification.
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS_EX
{
    // D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS flags
    NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_NONE_EX                            = 0x0,        //!< No options specified for the acceleration structure build.
    NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_UPDATE_EX                    = NV_BIT(0),  //!< Allow the acceleration structure to later be updated (via the flag #NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PERFORM_UPDATE_EX), rather than always requiring a full rebuild.
    NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_COMPACTION_EX                = NV_BIT(1),  //!< Allow for the acceleration structure to later be compacted.
    NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PREFER_FAST_TRACE_EX               = NV_BIT(2),  //!< Favorize higher raytracing performance at the cost of longer build times.
    NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PREFER_FAST_BUILD_EX               = NV_BIT(3),  //!< Favorize faster build times at the cost of lower raytracing performance.
    NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_MINIMIZE_MEMORY_EX                 = NV_BIT(4),  //!< Minimize the memory footprint of the produced acceleration structure, potentially at the cost of longer build time or lower raytracing performance.
    NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PERFORM_UPDATE_EX                  = NV_BIT(5),  //!< Instead of rebuilding the acceleration structure from scratch, the existing acceleration structure will be updated.
                                                                                                              //!< Added behaviour: If #NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_OMM_UPDATE_EX is specified, OMM references may be changed along with positions when an update is performed.

    // NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS_EX specific flags
    NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_OMM_UPDATE_EX                = NV_BIT(6),  //!< The acceleration structure (AS) supports updating OMM contents (base OMM Array and/or indices).
                                                                                                              //!< Specifying this flag may result in larger AS size and may reduce traversal performance.
    NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_DISABLE_OMMS_EX              = NV_BIT(7),  //!< Only applicable for BLAS builds. If enabled, any instances referencing this BLAS are allowed to disable the OMM test through the #NVAPI_D3D12_RAYTRACING_INSTANCE_FLAG_DISABLE_OMMS_EX flag.
                                                                                                              //!< Specifying this build flag may result in some reductions in traversal performance.
    NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_OMM_OPACITY_STATES_UPDATE_EX = NV_BIT(8),  //!< The acceleration structure (AS) supports updating OMM data (encoded opacity values).
                                                                                                              //!< Specifying this flag may reduce traversal performance.
    NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_DATA_ACCESS_EX               = NV_BIT(9),  //!< Allows triangle and micro-triangle data to be accessed through the BLAS via shader intrinsics.
} NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS_EX;

//! This enum extends \c D3D12_RAYTRACING_GEOMETRY_TYPE with additional values.
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_GEOMETRY_TYPE_EX
{
    // D3D12_RAYTRACING_GEOMETRY_TYPE flags
    NVAPI_D3D12_RAYTRACING_GEOMETRY_TYPE_TRIANGLES_EX                  = 0x0, //!< This geometry is made of basic triangles.
    NVAPI_D3D12_RAYTRACING_GEOMETRY_TYPE_PROCEDURAL_PRIMITIVE_AABBS_EX = 0x1, //!< This geometry is made of axis-aligned bounding boxes (AABBs).

    // NVAPI_D3D12_RAYTRACING_GEOMETRY_TYPE_EX specific flags
    NVAPI_D3D12_RAYTRACING_GEOMETRY_TYPE_OMM_TRIANGLES_EX              = 0x2, //!< Shares most fields with the basic triangle geometry type, but allows an OMM Array to be attached to the geometry.
                                                                              //!< The basic triangle type and this OMM-enabled type geometries may be mixed in the same BLAS build.
    NVAPI_D3D12_RAYTRACING_GEOMETRY_TYPE_DMM_TRIANGLES_EX              = 0x3, //!< Triangle geometry with attached DMM data.
                                                                              //!< This geometry cannot be mixed with other geometry types in the same BLAS.
    NVAPI_D3D12_RAYTRACING_GEOMETRY_TYPE_SPHERES_EX                    = 0x4, //!< This geometry contains sphere primitives.
                                                                              //!< Cannot be mixed with other geometry types in the same BLAS.
    NVAPI_D3D12_RAYTRACING_GEOMETRY_TYPE_LSS_EX                        = 0x5, //!< This geometry contains linear swept sphere primitives.
                                                                              //!< Cannot be mixed with other geometry types in the same BLAS.

} NVAPI_D3D12_RAYTRACING_GEOMETRY_TYPE_EX;

//! If a triangle has a uniform OMM state in a BLAS build, it is preferable to signal this explicitly rather than attaching a single state OMM.
//! This can be accomplished by supplying these special indices as entries in \c opacityMicromapIndexBuffer, in #NVAPI_D3D12_RAYTRACING_GEOMETRY_OMM_TRIANGLES_DESC.
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_SPECIAL_INDEX
{
    NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_TRANSPARENT         = -1, //!< Uniform transparent OMM state.
    NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_OPAQUE              = -2, //!< Uniform opaque OMM state.
    NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_UNKNOWN_TRANSPARENT = -3, //!< Uniform unknown-transparent OMM state.
    NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_UNKNOWN_OPAQUE      = -4, //!< Uniform unknown-opaque OMM state.

    NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_SPECIAL_INDEX_CLUSTER_SKIP_OMM          = -5, //!< Don't apply any OMM for triangle. Reverts to using the geometry supplied opaque/non-opaque state. This special index is only available for the opacity micromap index buffer supplied to
                                                                                          //!< NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_MULTI_INDIRECT_TRIANGLE_TEMPLATE_ARGS and NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_MULTI_INDIRECT_TRIANGLE_CLUSTER_ARGS.
                                                                                          //!< This state does _not_ require the AS to be built with NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_CLUSTER_FLAG_ALLOW_DISABLE_OMMS, as that only applies to the instance flag.
} NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_SPECIAL_INDEX;

//! Geometry descriptor attachment with Opacity Micromaps.
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_GEOMETRY_OMM_ATTACHMENT_DESC
{
    D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE                       opacityMicromapIndexBuffer;  //!< Optional buffer specifying which OMM index to use for each triangle; if \c NULL, there is a 1:1 mapping between input triangles and OMM Array entries.
                                                                                            //!< Special values can be used to encode OMMs with uniform state for individual triangles (see #NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_SPECIAL_INDEX).
                                                                                            //!< For BLAS updates, this input buffer must match that of the original build if the #NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_OMM_UPDATE_EX build flag is not set.
    DXGI_FORMAT                                                opacityMicromapIndexFormat;  //!< Format of \c opacityMicromapIndexBuffer, either \c DXGI_FORMAT_R32_UINT or \c DXGI_FORMAT_R16_UINT.
    NvU32                                                      opacityMicromapBaseLocation; //!< Constant added to all non-negative OMM indices in \p opacityMicromapIndexBuffer.
    D3D12_GPU_VIRTUAL_ADDRESS                                  opacityMicromapArray;        //!< Pointer to an OMM Array used by this geometry; it may be set to \c NULL if no non-uniform OMMs are used.
                                                                                            //!< Unlike vertex, index, and transform buffers, this resource is dereferenced during raytracing.

    NvU32                                                      numOMMUsageCounts;           //!< Number of OMM usage count entries in the \p pOMMUsageCounts array.
    const NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_USAGE_COUNT* pOMMUsageCounts;             //!< Usage counts for each subdivision level and format combination across all the OMM entries referred-to by the OMM index buffer specified by this geometry.

} NVAPI_D3D12_RAYTRACING_GEOMETRY_OMM_ATTACHMENT_DESC;

//! The edge vA..vB is decimated: after subdivision the number of micro-triangles on that edge is halved.
//! (i.e. the neighboring primitive can have a lower subdivision level without introducing cracks)
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_PRIMITIVE_FLAGS
{
    NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_PRIMITIVE_FLAG_DECIMATE_01 = NV_BIT(0),
    NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_PRIMITIVE_FLAG_DECIMATE_12 = NV_BIT(1),
    NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_PRIMITIVE_FLAG_DECIMATE_20 = NV_BIT(2),

} NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_PRIMITIVE_FLAGS;

//! Geometry descriptor attachment with Displacement Micromaps.
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_GEOMETRY_DMM_ATTACHMENT_DESC
{
    D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE                            triangleMicromapIndexBuffer;    //!< Optional buffer specifying which DMM index to use for each triangle; if \c NULL, there is a 1:1 mapping between input triangles and DMM Array entries.
                                                                                                    //!< For BLAS updates, this input buffer must match that of the original build.
    DXGI_FORMAT                                                     triangleMicromapIndexFormat;    //!< Format of \c displacementMicromapIndexBuffer, either \c DXGI_FORMAT_R32_UINT or \c DXGI_FORMAT_R16_UINT.
    NvU32                                                           triangleMicromapBaseLocation;   //!< Constant added to all DMM indices in \p displacementMicromapIndexBuffer.

    D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE                            trianglePrimitiveFlagsBuffer;   //!< Optional, per-triangle UINT8 mode flags (#NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_PRIMITIVE_FLAGS)

    D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE                            vertexBiasAndScaleBuffer;       //!< Optional displacement base vertex bias and displacement vector scale buffer. If not supplied, bias defaults to 0 and scale to 1.
    DXGI_FORMAT                                                     vertexBiasAndScaleFormat;       //!< Format of \c displacementBiasAndScaleBuffer. Supported formats are \c DXGI_FORMAT_R16G16_FLOAT and \c DXGI_FORMAT_R32G32_FLOAT

    D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE                            vertexDisplacementVectorBuffer; //!< Per-vertex displacement vector buffer. This buffer is indexed using the index buffer from the base triangle geometry.
    DXGI_FORMAT                                                     vertexDisplacementVectorFormat; //!< Format of \c displacementVectorBuffer. Supported formats are \c DXGI_FORMAT_R32G32B32_FLOAT, \c DXGI_FORMAT_R32G32B32A32_FLOAT, and \c DXGI_FORMAT_R16G16B16A16_FLOAT (The Alpha channel is ignored, and stride can be set accordingly).

    D3D12_GPU_VIRTUAL_ADDRESS                                       displacementMicromapArray;      //!< Pointer to a DMM Array used by this geometry.
                                                                                                    //!< Unlike vertex, index, and transform buffers, this resource is dereferenced during raytracing.

    NvU32                                                           numDMMUsageCounts;              //!< Number of DMM usage count entries in the \p pDMMUsageCounts array.
    const NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_USAGE_COUNT* pDMMUsageCounts;                //!< Usage counts for each subdivision level and format combination across all the DMM entries referred-to by the DMM index buffer specified by this geometry.

} NVAPI_D3D12_RAYTRACING_GEOMETRY_DMM_ATTACHMENT_DESC;

//! Geometry triangle descriptor with attached augmented Displacement Micromaps.
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_GEOMETRY_DMM_TRIANGLES_DESC
{
    D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC            triangles;     //!< Triangle mesh descriptor.
    NVAPI_D3D12_RAYTRACING_GEOMETRY_DMM_ATTACHMENT_DESC dmmAttachment; //!< Displacement Micromap attachment descriptor.
} NVAPI_D3D12_RAYTRACING_GEOMETRY_DMM_TRIANGLES_DESC;

//! Geometry triangle descriptor with attached augmented Opacity Micromaps.
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_GEOMETRY_OMM_TRIANGLES_DESC
{
    D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC            triangles;     //!< Triangle mesh descriptor.
    NVAPI_D3D12_RAYTRACING_GEOMETRY_OMM_ATTACHMENT_DESC ommAttachment; //!< Opacity Micromap attachment descriptor.
} NVAPI_D3D12_RAYTRACING_GEOMETRY_OMM_TRIANGLES_DESC;

//! Sphere geometry descriptor.
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_GEOMETRY_SPHERES_DESC
{
    NvU32                                       vertexCount;          //!< The largest valid index plus one.
    NvU32                                       indexCount;           //!< Number of indices in index buffer.

    D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE        vertexPositionBuffer; //!< Vertex position buffer and stride.
    DXGI_FORMAT                                 vertexPositionFormat; //!< Supports the same formats as the triangle vertex buffers.

    D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE        vertexRadiusBuffer;   //!< Vertex radius buffer and stride. Radii must be 0 or greater. The stride can be set to 0 to set a constant radius for all primitives in the geometry.
    DXGI_FORMAT                                 vertexRadiusFormat;   //!< Supported formats are `DXGI_FORMAT_R32_FLOAT` and `DXGI_FORMAT_R16_FLOAT`.

    D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE        indexBuffer;          //!< Indices to positions and radii, one entry per sphere primitive. May be set to NULL to use the list of positions and radii from vertexPositionBuffer and vertexRadiusBuffer.
    DXGI_FORMAT                                 indexFormat;          //!< Supported formats are `DXGI_FORMAT_R32_UINT`, `DXGI_FORMAT_R16_UINT`, `DXGI_FORMAT_R8_UINT`.

} NVAPI_D3D12_RAYTRACING_GEOMETRY_SPHERES_DESC;

//! Describes the endcap enable/disable behavior of LSS primitives.
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_LSS_ENDCAP_MODE
{
    NVAPI_D3D12_RAYTRACING_LSS_ENDCAP_MODE_NONE    = 0, //!< None of the primitives have endcaps enabled. Only midsections may be intersected.
    NVAPI_D3D12_RAYTRACING_LSS_ENDCAP_MODE_CHAINED = 1, //!< The last primitive in each chain has both endcaps enabled. Preceding primitives within chains only have their first endcap enabled.

} NVAPI_D3D12_RAYTRACING_LSS_ENDCAP_MODE;

//! Describes how LSS primitives are constructed from vertex and index buffer inputs.
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_LSS_PRIMITIVE_FORMAT
{
    NVAPI_D3D12_RAYTRACING_LSS_PRIMITIVE_FORMAT_LIST                = 0, //!< Each LSS primitive is defined by a pair of vertices. The index buffer is optional for this format.
    NVAPI_D3D12_RAYTRACING_LSS_PRIMITIVE_FORMAT_SUCCESSIVE_IMPLICIT = 1, //!< Each LSS is defined by two successive vertices (k, k + 1), where k is the entry in the index buffer. This format requires an index buffer to be supplied in the geometry descriptor.

} NVAPI_D3D12_RAYTRACING_LSS_PRIMITIVE_FORMAT;

//! Linear Swept Sphere (LSS) geometry descriptor.
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_GEOMETRY_LSS_DESC
{
    NvU32                                       vertexCount;          //!< The largest valid index plus one.
    NvU32                                       indexCount;           //!< Number of indices in index buffer.
    NvU32                                       primitiveCount;       //!< Specifies the total number of primitives (including inactive ones).

    D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE        vertexPositionBuffer; //!< Vertex position buffer and stride.
    DXGI_FORMAT                                 vertexPositionFormat; //!< Supports the same formats as the triangle vertex buffers.

    D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE        vertexRadiusBuffer;   //!< Vertex radius buffer and stride. Radii must be 0 or greater. The stride can be set to 0 to set a constant radius for all primitives in the geometry.
    DXGI_FORMAT                                 vertexRadiusFormat;   //!< Supported formats are `DXGI_FORMAT_R32_FLOAT` and `DXGI_FORMAT_R16_FLOAT`.

    D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE        indexBuffer;          //!< Indices to positions and radii, one entry per sphere primitive. May be set to NULL to use the list of positions and radii from vertexPositionBuffer and vertexRadiusBuffer.
    DXGI_FORMAT                                 indexFormat;          //!< Supported formats are `DXGI_FORMAT_R32_UINT`, `DXGI_FORMAT_R16_UINT`, `DXGI_FORMAT_R8_UINT`.

    NVAPI_D3D12_RAYTRACING_LSS_ENDCAP_MODE      endcapMode;           //!< Specifies which endcaps are enabled and disabled over collections of LSS primitives within the geometry.
    NVAPI_D3D12_RAYTRACING_LSS_PRIMITIVE_FORMAT primitiveFormat;      //!< Selects how input buffers are to be interpreted to construct LSS primitives.

} NVAPI_D3D12_RAYTRACING_GEOMETRY_LSS_DESC;

//! This structure extends \c D3D12_RAYTRACING_GEOMETRY_DESC by supporting additional geometry types.
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_GEOMETRY_DESC_EX
{
    NVAPI_D3D12_RAYTRACING_GEOMETRY_TYPE_EX type;  //!< The type of geometry stored in the union of this structure.
    D3D12_RAYTRACING_GEOMETRY_FLAGS         flags; //!< Flags affecting how this geometry is processed by the raytracing pipeline.
    union
    {
        D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC           triangles;    //!< Describes triangle geometry if \c type is #NVAPI_D3D12_RAYTRACING_GEOMETRY_TYPE_TRIANGLES_EX.
                                                                         //!< Otherwise, this parameter is unused (space repurposed in a union).
        D3D12_RAYTRACING_GEOMETRY_AABBS_DESC               aabbs;        //!< Describes AABB geometry if \c type is #NVAPI_D3D12_RAYTRACING_GEOMETRY_TYPE_PROCEDURAL_PRIMITIVE_AABBS_EX.
                                                                         //!< Otherwise, this parameter is unused (space repurposed in a union).
        NVAPI_D3D12_RAYTRACING_GEOMETRY_OMM_TRIANGLES_DESC ommTriangles; //!< Describes triangle geometry which may optionally use Opacity Micromaps, if \c type is #NVAPI_D3D12_RAYTRACING_GEOMETRY_TYPE_OMM_TRIANGLES_EX.
                                                                         //!< Otherwise, this parameter is unused (space repurposed in a union).
        NVAPI_D3D12_RAYTRACING_GEOMETRY_DMM_TRIANGLES_DESC dmmTriangles; //!< Describes micro-triangle geometry, if \c type is #NVAPI_D3D12_RAYTRACING_GEOMETRY_TYPE_DMM_TRIANGLES_EX.
                                                                         //!< Otherwise, this parameter is unused (space repurposed in a union).
        NVAPI_D3D12_RAYTRACING_GEOMETRY_SPHERES_DESC       spheres;      //!< Describes sphere geometry if \c type is #NVAPI_D3D12_RAYTRACING_GEOMETRY_TYPE_SPHERE_EX.
                                                                         //!< Otherwise, this parameter is unused (space repurposed in a union).
        NVAPI_D3D12_RAYTRACING_GEOMETRY_LSS_DESC           lss;          //!< Describes linear swept sphere geometry if \c type is #NVAPI_D3D12_RAYTRACING_GEOMETRY_TYPE_LSS_EX.
                                                                         //!< Otherwise, this parameter is unused (space repurposed in a union).
    };
} NVAPI_D3D12_RAYTRACING_GEOMETRY_DESC_EX;

//! This enum extends \c D3D12_RAYTRACING_INSTANCE_FLAGS with additional values.
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_INSTANCE_FLAGS_EX
{
    // D3D12_RAYTRACING_INSTANCE_FLAGS flags
    NVAPI_D3D12_RAYTRACING_INSTANCE_FLAG_NONE_EX                            = 0x0,       //!< No options specified for this instance.
    NVAPI_D3D12_RAYTRACING_INSTANCE_FLAG_TRIANGLE_CULL_DISABLE_EX           = NV_BIT(0), //!< Disable triangle culling for this instance.
    NVAPI_D3D12_RAYTRACING_INSTANCE_FLAG_TRIANGLE_FRONT_COUNTERCLOCKWISE_EX = NV_BIT(1), //!< Use counter-clockwise winding for defining front faces, instead of the default of clockwise winding.
    NVAPI_D3D12_RAYTRACING_INSTANCE_FLAG_FORCE_OPAQUE_EX                    = NV_BIT(2), //!< Force all geometries in this instance to be opaque.
    NVAPI_D3D12_RAYTRACING_INSTANCE_FLAG_FORCE_NON_OPAQUE_EX                = NV_BIT(3), //!< All geometries in this instance will be processed as if they never had the \c D3D12_RAYTRACING_GEOMETRY_FLAG_OPAQUE flag applied to them.

    // NVAPI_D3D12_RAYTRACING_INSTANCE_FLAGS_EX specific flags
    NVAPI_D3D12_RAYTRACING_INSTANCE_FLAG_FORCE_OMM_2_STATE_EX               = NV_BIT(4), //!< Ignore the Unknown state and only consider the Transparent/Opaque bit for all 4-state OMMs encountered during traversal.
                                                                                         //!< This flag has no effect if #NVAPI_D3D12_RAYTRACING_INSTANCE_FLAG_DISABLE_OMMS_EX is set.
    NVAPI_D3D12_RAYTRACING_INSTANCE_FLAG_DISABLE_OMMS_EX                    = NV_BIT(5)  //!< Disable OMMs for all triangles, and revert to using geometry opaque/non-opaque state instead (legacy behavior).
                                                                                         //!< This flag is only valid if the referenced BLAS was built with the #NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_DISABLE_OMMS_EX flag; omitting that flag during BLAS build will result in undefined behavior.
} NVAPI_D3D12_RAYTRACING_INSTANCE_FLAGS_EX;

//! This structure extends \c D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS by supporting additional geometry types.
//! Only modified members are fully described below; for more information on the other members, please check Microsoft's DirectX Raytracing Specification.
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS_EX
{
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE                 type;                      //!< Whether a top-level acceleration structure (TLAS) or bottom-level acceleration structure (BLAS) will be built using this information.
    NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS_EX flags;                     //!< Options influencing how the acceleration structure is built and which of its features can be used.
    NvU32                                                        numDescs;                  //!< If \c type is \c D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TOP_LEVEL, it represents the number of descriptions stored in \c instanceDescs.
                                                                                            //!< Otherwise, it contains the number of geometry descriptions stored in \c pGeometryDescs or \c ppGeometryDescs.
    D3D12_ELEMENTS_LAYOUT                                        descsLayout;               //!< If \c type is \c D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BOTTOM_LEVEL, it specifies which of \c pGeometryDescs and \c ppGeometryDescs to use.
                                                                                            //!< Otherwise, this parameter is unused.
    NvU32                                                        geometryDescStrideInBytes; //!< Stride between consecutive geometry descriptors. Should typically be set to sizeof(NVAPI_D3D12_RAYTRACING_GEOMETRY_DESC_EX).
                                                                                            //!< Only used if \c type is \c D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL and \c descLayout is \c D3D12_ELEMENTS_LAYOUT_ARRAY.
                                                                                            //!< This field guarantees backwards compatibility, even if the geometry descriptor size increases in future NVAPI versions.
    union
    {
        D3D12_GPU_VIRTUAL_ADDRESS                            instanceDescs;   //!< If \c type is \c D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TOP_LEVEL, the referenced instance structures can used the extended set of flags #NVAPI_D3D12_RAYTRACING_INSTANCE_FLAGS_EX in place of the \c D3D12_RAYTRACING_INSTANCE_FLAGS mentioned in \c D3D12_RAYTRACING_INSTANCE_DESC.
                                                                              //!< Otherwise, this parameter is unused (space repurposed in a union).
        const NVAPI_D3D12_RAYTRACING_GEOMETRY_DESC_EX*       pGeometryDescs;  //!< If \c type is \c D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BOTTOM_LEVEL and \c descLayout is \c D3D12_ELEMENTS_LAYOUT_ARRAY, it contains the descriptions of all geometries to be built into a BLAS.
                                                                              //!< Otherwise, this parameter is unused (space repurposed in a union).
        const NVAPI_D3D12_RAYTRACING_GEOMETRY_DESC_EX*const* ppGeometryDescs; //!< If \c type is \c D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BOTTOM_LEVEL and \c descLayout is \c D3D12_ELEMENTS_LAYOUT_ARRAY_OF_POINTERS, it contains the addresses of descriptions for all geometries to be built into a BLAS.
                                                                              //!< Otherwise, this parameter is unused (space repurposed in a union).
    };
} NVAPI_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS_EX;

//! Parameters given to NvAPI_D3D12_GetRaytracingAccelerationStructurePrebuildInfoEx().
//!
//! \ingroup dx
typedef struct _NVAPI_GET_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO_EX_PARAMS_V1
{
    NvU32                                                                version; //!< [in]  Structure version; it should be set to #NVAPI_GET_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO_EX_PARAMS_VER.
    const NVAPI_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS_EX* pDesc;   //!< [in]  Description of the acceleration-structure build.
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO*               pInfo;   //!< [out] Result of the query.
} NVAPI_GET_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO_EX_PARAMS_V1;
#define NVAPI_GET_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO_EX_PARAMS_VER1          MAKE_NVAPI_VERSION(NVAPI_GET_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO_EX_PARAMS_V1, 1)
typedef NVAPI_GET_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO_EX_PARAMS_V1            NVAPI_GET_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO_EX_PARAMS;
#define NVAPI_GET_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO_EX_PARAMS_VER           NVAPI_GET_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO_EX_PARAMS_VER1

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D12_GetRaytracingAccelerationStructurePrebuildInfoEx
//
//! DESCRIPTION: This function is an extension of <tt>ID3D12Device5::GetRaytracingAccelerationStructurePrebuildInfo()</tt> with additional input types.
//!
//! \note Only supported on GPUs capable of DXR.
//!       Some of the flags and fields have further restrictions, in which case their description will include a note with more details.
//!
//! SUPPORTED OS:  Windows 10 and higher
//!
//!
//! \since Release: 520
//!
//! \param [in]     pDevice                      Device on which the acceleration structure will be built.
//! \param [in,out] pParams                      Wrapper around the inputs and outputs of the function.
//!
//! \return This API can return any of the error codes enumerated in #NvAPI_Status.
//!         If there are return error codes with specific meaning for this API, they are listed below.
//!
//! \ingroup dx 
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D12_GetRaytracingAccelerationStructurePrebuildInfoEx(
    __in    ID3D12Device5* pDevice,
    __inout NVAPI_GET_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO_EX_PARAMS* pParams);

#endif // defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12Device5_INTERFACE_DEFINED__)

#if defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__)

//! Description of the inputs and memory areas used during the building of OMM Arrays.
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_BUILD_RAYTRACING_OPACITY_MICROMAP_ARRAY_DESC
{
    D3D12_GPU_VIRTUAL_ADDRESS                                  destOpacityMicromapArrayData;    //!< Output location for the OMM Array build.
                                                                                                //!< NvAPI_D3D12_GetRaytracingOpacityMicromapArrayPrebuildInfo() reports the amount of memory required for the result given a set of input parameters.
                                                                                                //!< The address must be aligned to 256 bytes (#NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_BYTE_ALIGNMENT).
    NVAPI_D3D12_BUILD_RAYTRACING_OPACITY_MICROMAP_ARRAY_INPUTS inputs;                          //!< Description of the input data for the OMM Array build.
    D3D12_GPU_VIRTUAL_ADDRESS                                  scratchOpacityMicromapArrayData; //!< Location where the build will store temporary data.
                                                                                                //!< NvAPI_D3D12_GetRaytracingOpacityMicromapArrayPrebuildInfo() reports the amount of scratch memory the implementation will need for a given set of input parameters.
                                                                                                //!< The address must be aligned to 256 bytes (#NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_BYTE_ALIGNMENT).
                                                                                                //!< Contents of this memory going into a build on the GPU timeline are irrelevant and will not be preserved.
                                                                                                //!< After the build is complete on the GPU timeline, the memory is left with whatever undefined contents the build finished with.
                                                                                                //!< The memory pointed to must be in state \c D3D12_RESOURCE_STATE_UNORDERED_ACCESS.
} NVAPI_D3D12_BUILD_RAYTRACING_OPACITY_MICROMAP_ARRAY_DESC;

//! Structure emitted by NvAPI_D3D12_EmitRaytracingOpacityMicromapArrayPostbuildInfo(), and optionally NvAPI_D3D12_BuildRaytracingOpacityMicromapArray(), when \c type equals #NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_CURRENT_SIZE.
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_CURRENT_SIZE_DESC
{
    NvU64 currentSizeInBytes; //!< Size of the OMM Array buffer.
                              //!< The queried size may be smaller than the size reported by NvAPI_D3D12_GetRaytracingOpacityMicromapArrayPrebuildInfo().
                              //!< This allows the application to move and relocate the OMM Array to a smaller buffer to reclaim any unused memory after the OMM Array build is complete.
} NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_CURRENT_SIZE_DESC;

//! Type of postbuild info to emit after an OMM Array build.
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_TYPE
{
    NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_CURRENT_SIZE       = 0x0  //!< Size of the current OMM Array. May be smaller than reported by the NvAPI_D3D12_GetRaytracingOpacityMicromapArrayPrebuildInfo() call.
                                                                                           //!< Unused memory can be reclaimed by copying the OMM Array into a new resource; see #NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_CURRENT_SIZE_DESC.
} NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_TYPE;

//! Description of the postbuild information to generate from an OMM Array.
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_DESC
{
    D3D12_GPU_VIRTUAL_ADDRESS                                        destBuffer; //!< Result storage.
                                                                                 //!< Size required and the layout of the contents written by the system depend on \p infoType.
                                                                                 //!< The memory pointed to must be in state \c D3D12_RESOURCE_STATE_UNORDERED_ACCESS.
                                                                                 //!< The memory must be aligned to the natural alignment for the members of the particular output structure being generated (e.g. 8 bytes for a struct with the largest member being \c NvU64).
    NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_TYPE infoType;  //!< Type of postbuild information to retrieve.
} NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_DESC;

//! Parameters given to NvAPI_D3D12_BuildRaytracingOpacityMicromapArray().
//!
//! \ingroup dx
typedef struct _NVAPI_BUILD_RAYTRACING_OPACITY_MICROMAP_ARRAY_PARAMS_V1
{
    NvU32                                                                    version;               //!< [in] Structure version; it should be set to #NVAPI_BUILD_RAYTRACING_OPACITY_MICROMAP_ARRAY_PARAMS_VER.
    const NVAPI_D3D12_BUILD_RAYTRACING_OPACITY_MICROMAP_ARRAY_DESC*          pDesc;                 //!< [in] Description of the OMM Array build.
    NvU32                                                                    numPostbuildInfoDescs; //!< [in] Size of postbuild info desc array. Set to 0 if none are needed.
    const NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_DESC* pPostbuildInfoDescs;   //!< [in] Optional array of descriptions for postbuild info to generate describing properties of the acceleration structure that was built.
                                                                                                    //!< [in] Any given postbuild info type, \c D3D12_RAYTRACING_ACCEELRATION_STRUCTURE_POSTBUILD_INFO_TYPE, can only be selected for output by at most one array entry.
} NVAPI_BUILD_RAYTRACING_OPACITY_MICROMAP_ARRAY_PARAMS_V1;
#define NVAPI_BUILD_RAYTRACING_OPACITY_MICROMAP_ARRAY_PARAMS_VER1          MAKE_NVAPI_VERSION(NVAPI_BUILD_RAYTRACING_OPACITY_MICROMAP_ARRAY_PARAMS_V1, 1)
typedef NVAPI_BUILD_RAYTRACING_OPACITY_MICROMAP_ARRAY_PARAMS_V1            NVAPI_BUILD_RAYTRACING_OPACITY_MICROMAP_ARRAY_PARAMS;
#define NVAPI_BUILD_RAYTRACING_OPACITY_MICROMAP_ARRAY_PARAMS_VER           NVAPI_BUILD_RAYTRACING_OPACITY_MICROMAP_ARRAY_PARAMS_VER1

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D12_BuildRaytracingOpacityMicromapArray
//
//! DESCRIPTION: Construct OMM Array for a collection of OMMs on the GPU.
//!              The CPU-side input buffers are not referenced after this call.
//!              The GPU-side input resources are not referenced after the build has concluded after <tt>ExecuteCommandList()</tt>.
//!              Additionally, the application may optionally output postbuild information immediately after the build.
//!
//! SUPPORTED OS:  Windows 10 and higher
//!
//!
//! \since Release: 520
//!
//! \param [in] pCommandList                     Command list on which the command will execute.
//! \param [in] pParams                          Wrapper around the inputs and outputs of the function.
//!
//! \return This API can return any of the error codes enumerated in #NvAPI_Status.
//!         If there are return error codes with specific meaning for this API, they are listed below.
//!
//! \retval NVAPI_INVALID_COMBINATION            <tt>pParams->pPostbuildInfoDescs</tt> was set to \c NULL while <tt>pParams->numPostbuildInfoDescs</tt> is non zero.
//!
//! \ingroup dx 
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D12_BuildRaytracingOpacityMicromapArray(
    __in ID3D12GraphicsCommandList4* pCommandList,
    __in NVAPI_BUILD_RAYTRACING_OPACITY_MICROMAP_ARRAY_PARAMS* pParams);

#endif // defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__)

#if defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__)

//! Parameters given to NvAPI_D3D12_RelocateRaytracingOpacityMicromapArray().
//!
//! \ingroup dx
typedef struct _NVAPI_RELOCATE_RAYTRACING_OPACITY_MICROMAP_ARRAY_PARAMS_V1
{
    NvU32                     version;              //!< [in] Structure version; it should be set to #NVAPI_RELOCATE_RAYTRACING_OPACITY_MICROMAP_ARRAY_PARAMS_VER.
    D3D12_GPU_VIRTUAL_ADDRESS opacityMicromapArray; //!< [in] OMM Array current memory address; it must be 256-byte aligned (#NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_BYTE_ALIGNMENT).
} NVAPI_RELOCATE_RAYTRACING_OPACITY_MICROMAP_ARRAY_PARAMS_V1;
#define NVAPI_RELOCATE_RAYTRACING_OPACITY_MICROMAP_ARRAY_PARAMS_VER1          MAKE_NVAPI_VERSION(NVAPI_RELOCATE_RAYTRACING_OPACITY_MICROMAP_ARRAY_PARAMS_V1, 1)
typedef NVAPI_RELOCATE_RAYTRACING_OPACITY_MICROMAP_ARRAY_PARAMS_V1            NVAPI_RELOCATE_RAYTRACING_OPACITY_MICROMAP_ARRAY_PARAMS;
#define NVAPI_RELOCATE_RAYTRACING_OPACITY_MICROMAP_ARRAY_PARAMS_VER           NVAPI_RELOCATE_RAYTRACING_OPACITY_MICROMAP_ARRAY_PARAMS_VER1

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D12_RelocateRaytracingOpacityMicromapArray
//
//! DESCRIPTION: Makes the OMM Array usable at its current location in memory.
//!              An OMM Array that has been copied to a new location must be relocated using this function before it may be attached to any BLAS.
//!
//! SUPPORTED OS:  Windows 10 and higher
//!
//!
//! \since Release: 520
//!
//! \param [in] pCommandList                     Command list on which the command will execute.
//! \param [in] pParams                          Wrapper around the inputs and outputs of the function.
//!
//! \return This API can return any of the error codes enumerated in #NvAPI_Status.
//!         If there are return error codes with specific meaning for this API, they are listed below.
//!
//! \ingroup dx 
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D12_RelocateRaytracingOpacityMicromapArray(
    __in ID3D12GraphicsCommandList4* pCommandList,
    __in const NVAPI_RELOCATE_RAYTRACING_OPACITY_MICROMAP_ARRAY_PARAMS* pParams);

#endif // defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__)

#if defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__)

//! Description of the inputs and memory areas used during the building of DMM Arrays.
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_BUILD_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_DESC
{
    D3D12_GPU_VIRTUAL_ADDRESS                                       destDisplacementMicromapArrayData;    //!< Output location for the DMM Array build.
                                                                                                          //!< NvAPI_D3D12_GetRaytracingDisplacementMicromapArrayPrebuildInfo() reports the amount of memory required for the result given a set of input parameters.
                                                                                                          //!< The address must be aligned to 256 bytes (#NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_BYTE_ALIGNMENT).
    NVAPI_D3D12_BUILD_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_INPUTS inputs;                               //!< Description of the input data for the DMM Array build.
    D3D12_GPU_VIRTUAL_ADDRESS                                       scratchDisplacementMicromapArrayData; //!< Location where the build will store temporary data.
                                                                                                          //!< NvAPI_D3D12_GetRaytracingDisplacementMicromapArrayPrebuildInfo() reports the amount of scratch memory the implementation will need for a given set of input parameters.
                                                                                                          //!< The address must be aligned to 256 bytes (#NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_BYTE_ALIGNMENT).
                                                                                                          //!< Contents of this memory going into a build on the GPU timeline are irrelevant and will not be preserved.
                                                                                                          //!< After the build is complete on the GPU timeline, the memory is left with whatever undefined contents the build finished with.
                                                                                                          //!< The memory pointed to must be in state \c D3D12_RESOURCE_STATE_UNORDERED_ACCESS.
} NVAPI_D3D12_BUILD_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_DESC;

//! Structure emitted by NvAPI_D3D12_EmitRaytracingDisplacementMicromapArrayPostbuildInfo(), and optionally NvAPI_D3D12_BuildRaytracingDisplacementMicromapArray(), when \c type equals #NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_POSTBUILD_INFO_CURRENT_SIZE.
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_POSTBUILD_INFO_CURRENT_SIZE_DESC
{
    NvU64 currentSizeInBytes; //!< Size of the DMM Array buffer.
                              //!< The queried size may be smaller than the size reported by NvAPI_D3D12_GetRaytracingDisplacementMicromapArrayPrebuildInfo().
                              //!< This allows the application to move and relocate the DMM Array to a smaller buffer to reclaim any unused memory after the DMM Array build is complete.
} NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_POSTBUILD_INFO_CURRENT_SIZE_DESC;

//! Type of postbuild info to emit after a DMM Array build.
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_POSTBUILD_INFO_TYPE
{
    NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_POSTBUILD_INFO_CURRENT_SIZE = 0x0, //!< Size of the current DMM Array. May be smaller than reported by the NvAPI_D3D12_GetRaytracingDisplacementMicromapArrayPrebuildInfo() call.
                                                                                          //!< Unused memory can be reclaimed by copying the DMM Array into a new resource; see #NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_POSTBUILD_INFO_CURRENT_SIZE_DESC.
} NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_POSTBUILD_INFO_TYPE;

//! Description of the postbuild information to generate from a DMM Array.
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_POSTBUILD_INFO_DESC
{
    D3D12_GPU_VIRTUAL_ADDRESS                                              destBuffer; //!< Result storage.
                                                                                       //!< Size required and the layout of the contents written by the system depend on \p infoType.
                                                                                       //!< The memory pointed to must be in state \c D3D12_RESOURCE_STATE_UNORDERED_ACCESS.
                                                                                       //!< The memory must be aligned to the natural alignment for the members of the particular output structure being generated (e.g. 8 bytes for a struct with the largest member being \c NvU64).
    NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_POSTBUILD_INFO_TYPE infoType;   //!< Type of postbuild information to retrieve.
} NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_POSTBUILD_INFO_DESC;

//! Parameters given to NvAPI_D3D12_BuildRaytracingDisplacementMicromapArray().
//!
//! \ingroup dx
typedef struct _NVAPI_BUILD_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PARAMS_V1
{
    NvU32                                                                         version;               //!< [in] Structure version; it should be set to #NVAPI_BUILD_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PARAMS_VER.
    const NVAPI_D3D12_BUILD_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_DESC*          pDesc;                 //!< [in] Description of the DMM Array build.
    NvU32                                                                         numPostbuildInfoDescs; //!< [in] Size of postbuild info desc array. Set to 0 if none are needed.
    const NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_POSTBUILD_INFO_DESC* pPostbuildInfoDescs;   //!< [in] Optional array of descriptions for postbuild info to generate describing properties of the acceleration structure that was built.
                                                                                                         //!< [in] Any given postbuild info type, \c D3D12_RAYTRACING_ACCEELRATION_STRUCTURE_POSTBUILD_INFO_TYPE, can only be selected for output by at most one array entry.
} NVAPI_BUILD_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PARAMS_V1;
#define NVAPI_BUILD_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PARAMS_VER1          MAKE_NVAPI_VERSION(NVAPI_BUILD_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PARAMS_V1, 1)
typedef NVAPI_BUILD_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PARAMS_V1            NVAPI_BUILD_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PARAMS;
#define NVAPI_BUILD_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PARAMS_VER           NVAPI_BUILD_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PARAMS_VER1

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D12_BuildRaytracingDisplacementMicromapArray
//
//! DESCRIPTION: Construct DMM Array for a collection of DMMs on the GPU.
//!              The CPU-side input buffers are not referenced after this call.
//!              The GPU-side input resources are not referenced after the build has concluded after <tt>ExecuteCommandList()</tt>.
//!              Additionally, the application may optionally output postbuild information immediately after the build.
//!
//! SUPPORTED OS:  Windows 10 and higher
//!
//! \deprecated  Do not use this function - it is deprecated in release 570.
//!
//! \since Release: 525
//!
//! \param [in] pCommandList                     Command list on which the command will execute.
//! \param [in] pParams                          Wrapper around the inputs of the function.
//!
//! \return This API can return any of the error codes enumerated in #NvAPI_Status.
//!         If there are return error codes with specific meaning for this API, they are listed below.
//!
//! \retval NVAPI_INVALID_COMBINATION            <tt>pParams->pPostbuildInfoDescs</tt> was set to \c NULL while <tt>pParams->numPostbuildInfoDescs</tt> is non zero.
//!
//! \ingroup dx 
///////////////////////////////////////////////////////////////////////////////
__nvapi_deprecated_function("Do not use this function - it is deprecated in release 570.")
NVAPI_INTERFACE NvAPI_D3D12_BuildRaytracingDisplacementMicromapArray(
    __in ID3D12GraphicsCommandList4* pCommandList,
    __in NVAPI_BUILD_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PARAMS* pParams);

#endif // defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__)

#if defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__)

//! Parameters given to NvAPI_D3D12_RelocateRaytracingDisplacementMicromapArray().
//!
//! \ingroup dx
typedef struct _NVAPI_RELOCATE_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PARAMS_V1
{
    NvU32                     version;                   //!< [in] Structure version; it should be set to #NVAPI_RELOCATE_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PARAMS_VER.
    D3D12_GPU_VIRTUAL_ADDRESS displacementMicromapArray; //!< [in] DMM Array current memory address; it must be 256-byte aligned (#NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_BYTE_ALIGNMENT).
} NVAPI_RELOCATE_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PARAMS_V1;
#define NVAPI_RELOCATE_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PARAMS_VER1          MAKE_NVAPI_VERSION(NVAPI_RELOCATE_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PARAMS_V1, 1)
typedef NVAPI_RELOCATE_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PARAMS_V1            NVAPI_RELOCATE_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PARAMS;
#define NVAPI_RELOCATE_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PARAMS_VER           NVAPI_RELOCATE_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PARAMS_VER1

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D12_RelocateRaytracingDisplacementMicromapArray
//
//! DESCRIPTION: Makes the DMM Array usable at its current location in memory.
//!              A DMM Array that has been copied to a new location must be relocated using this function before it may be attached to any BLAS.
//!
//! SUPPORTED OS:  Windows 10 and higher
//!
//! \deprecated  Do not use this function - it is deprecated in release 570.
//!
//! \since Release: 525
//!
//! \param [in] pCommandList                     Command list on which the command will execute.
//! \param [in] pParams                          Wrapper around the inputs of the function.
//!
//! \return This API can return any of the error codes enumerated in #NvAPI_Status.
//!         If there are return error codes with specific meaning for this API, they are listed below.
//!
//! \ingroup dx 
///////////////////////////////////////////////////////////////////////////////
__nvapi_deprecated_function("Do not use this function - it is deprecated in release 570.")
NVAPI_INTERFACE NvAPI_D3D12_RelocateRaytracingDisplacementMicromapArray(
    __in ID3D12GraphicsCommandList4* pCommandList,
    __in const NVAPI_RELOCATE_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_PARAMS* pParams);

#endif // defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__)

#if defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__)

//! Parameters given to NvAPI_D3D12_EmitRaytracingDisplacementMicromapArrayPostbuildInfo().
//!
//! \ingroup dx
typedef struct _NVAPI_EMIT_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_POSTBUILD_INFO_PARAMS_V1
{
    NvU32                                                                         version;    //!< [in] Structure version; it should be set to #NVAPI_EMIT_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_POSTBUILD_INFO_PARAMS_VER.
    const NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_POSTBUILD_INFO_DESC* pDesc;      //!< [in] Description of which postbuild info to emit.
    NvU32                                                                         numSources; //!< [in] Number of DMM Arrays in \p pSources.
    const D3D12_GPU_VIRTUAL_ADDRESS*                                              pSources;   //!< [in] List of DMM Arrays for which postbuild info should be emitted.
} NVAPI_EMIT_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_POSTBUILD_INFO_PARAMS_V1;
#define NVAPI_EMIT_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_POSTBUILD_INFO_PARAMS_VER1          MAKE_NVAPI_VERSION(NVAPI_EMIT_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_POSTBUILD_INFO_PARAMS_V1, 1)
typedef NVAPI_EMIT_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_POSTBUILD_INFO_PARAMS_V1            NVAPI_EMIT_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_POSTBUILD_INFO_PARAMS;
#define NVAPI_EMIT_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_POSTBUILD_INFO_PARAMS_VER           NVAPI_EMIT_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_POSTBUILD_INFO_PARAMS_VER1

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D12_EmitRaytracingDisplacementMicromapArrayPostbuildInfo
//
//! DESCRIPTION: Emits information about one or more DMM Arrays, only available after the DMM Array constructions have finished.
//!
//! SUPPORTED OS:  Windows 10 and higher
//!
//! \deprecated  Do not use this function - it is deprecated in release 570.
//!
//! \since Release: 525
//!
//! \param [in] pCommandList                     Command list on which the command will execute.
//! \param [in] pParams                          Wrapper around the inputs of the function.
//!
//! \return This API can return any of the error codes enumerated in #NvAPI_Status.
//!         If there are return error codes with specific meaning for this API, they are listed below.
//!
//! \ingroup dx 
///////////////////////////////////////////////////////////////////////////////
__nvapi_deprecated_function("Do not use this function - it is deprecated in release 570.")
NVAPI_INTERFACE NvAPI_D3D12_EmitRaytracingDisplacementMicromapArrayPostbuildInfo(
    __in ID3D12GraphicsCommandList4* pCommandList,
    __in const NVAPI_EMIT_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_POSTBUILD_INFO_PARAMS* pParams);

#endif // defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__)

#if defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__)

//! Parameters given to NvAPI_D3D12_EmitRaytracingOpacityMicromapArrayPostbuildInfo().
//!
//! \ingroup dx
typedef struct _NVAPI_EMIT_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_PARAMS_V1
{
    NvU32                                                                    version;    //!< [in] Structure version; it should be set to #NVAPI_EMIT_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_PARAMS_VER.
    const NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_DESC* pDesc;      //!< [in] Description of which postbuild info to emit.
    NvU32                                                                    numSources; //!< [in] Number of OMM Arrays in \p pSources.
    const D3D12_GPU_VIRTUAL_ADDRESS*                                         pSources;   //!< [in] List of OMM Arrays for which postbuild info should be emitted.
} NVAPI_EMIT_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_PARAMS_V1;
#define NVAPI_EMIT_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_PARAMS_VER1          MAKE_NVAPI_VERSION(NVAPI_EMIT_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_PARAMS_V1, 1)
typedef NVAPI_EMIT_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_PARAMS_V1            NVAPI_EMIT_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_PARAMS;
#define NVAPI_EMIT_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_PARAMS_VER           NVAPI_EMIT_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_PARAMS_VER1

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D12_EmitRaytracingOpacityMicromapArrayPostbuildInfo
//
//! DESCRIPTION: Emits information about one or more OMM Arrays, only available after the OMM Array constructions have finished.
//!
//! SUPPORTED OS:  Windows 10 and higher
//!
//!
//! \since Release: 520
//!
//! \param [in] pCommandList                     Command list on which the command will execute.
//! \param [in] pParams                          Wrapper around the inputs and outputs of the function.
//!
//! \return This API can return any of the error codes enumerated in #NvAPI_Status.
//!         If there are return error codes with specific meaning for this API, they are listed below.
//!
//! \ingroup dx 
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D12_EmitRaytracingOpacityMicromapArrayPostbuildInfo(
    __in ID3D12GraphicsCommandList4* pCommandList,
    __in const NVAPI_EMIT_RAYTRACING_OPACITY_MICROMAP_ARRAY_POSTBUILD_INFO_PARAMS* pParams);

#endif // defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__)

#if defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__)

//! This structure extends \c D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC by supporting additional geometry types as inputs.
//! For more information on the different members, please check Microsoft's DirectX Raytracing Specification.
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC_EX
{
    D3D12_GPU_VIRTUAL_ADDRESS                                     destAccelerationStructureData;    //!< Memory where the resulting acceleration structure will be stored.
    NVAPI_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS_EX inputs;                           //!< The inputs to the build process.
    D3D12_GPU_VIRTUAL_ADDRESS                                     sourceAccelerationStructureData;  //!< The acceleration structure to be updated.
                                                                                                    //!< Otherwise if the acceleration structure should be rebuilt entirely, this value must be \c NULL.
    D3D12_GPU_VIRTUAL_ADDRESS                                     scratchAccelerationStructureData; //!< Memory that will be temporarily used during the building process.
} NVAPI_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC_EX;

//! Parameters given to NvAPI_D3D12_RelocateRaytracingOpacityMicromapArray().
//!
//! \ingroup dx
typedef struct _NVAPI_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_EX_PARAMS_V1
{
    NvU32                                                              version;               //!< [in] Structure version; it should be set to #NVAPI_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_EX_PARAMS_VER.
    const NVAPI_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC_EX* pDesc;                 //!< [in] Description of the acceleration structure to build.
    NvU32                                                              numPostbuildInfoDescs; //!< [in] Size of postbuild info desc array. Set to 0 if none are needed.
    const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* pPostbuildInfoDescs;   //!< [in] Optional array of descriptions for postbuild info to generate describing properties of the acceleration structure that was built.
                                                                                              //!<      Any given postbuild info type, \c D3D12_RAYTRACING_ACCEELRATION_STRUCTURE_POSTBUILD_INFO_TYPE, can only be selected for output by at most one array entry.
} NVAPI_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_EX_PARAMS_V1;
#define NVAPI_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_EX_PARAMS_VER1          MAKE_NVAPI_VERSION(NVAPI_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_EX_PARAMS_V1, 1)
typedef NVAPI_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_EX_PARAMS_V1            NVAPI_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_EX_PARAMS;
#define NVAPI_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_EX_PARAMS_VER           NVAPI_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_EX_PARAMS_VER1

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D12_BuildRaytracingAccelerationStructureEx
//
//! DESCRIPTION: Perform an acceleration structure build on the GPU.
//!              Also optionally output postbuild information immediately after the build.
//!              This function is an extension of <tt>ID3D12GraphicsCommandList4::BuildRaytracingAccelerationStructure()</tt> with additional serialized data types.
//!
//! \note Only supported on GPUs capable of DXR.
//!       Some of the flags and fields have further restrictions, in which case their description will include a note with more details.
//!
//! SUPPORTED OS:  Windows 10 and higher
//!
//!
//! \since Release: 520
//!
//! \param [in] pCommandList                     Command list on which the command will execute.
//! \param [in] pParams                          Wrapper around the inputs and outputs of the function.
//!
//! \return This API can return any of the error codes enumerated in #NvAPI_Status.
//!         If there are return error codes with specific meaning for this API, they are listed below.
//!
//! \retval NVAPI_INVALID_COMBINATION            <tt>pParams->pPostbuildInfoDescs</tt> was set to \c NULL while <tt>pParams->numPostbuildInfoDescs</tt> is non zero.
//!
//! \ingroup dx 
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D12_BuildRaytracingAccelerationStructureEx(
    __in ID3D12GraphicsCommandList4* pCommandList,
    __in const NVAPI_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_EX_PARAMS* pParams);

#endif // defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__)

#if defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__)

///////////////////////////////////////////////////////////////////////////////
// 
// Miscellaneous
//
///////////////////////////////////////////////////////////////////////////////

//! Opacity Micromap micro-triangle states.
//! Not part of any input, but listed here for convenience.
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_STATE
{
    NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_STATE_TRANSPARENT         = 0, //!< Transparent OMM state: hit is ignored.
    NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_STATE_OPAQUE              = 1, //!< Opaque OMM state: hit is committed.
    NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_STATE_UNKNOWN_TRANSPARENT = 2, //!< Unknown-transparent OMM state.
                                                                           //!< * If operating in 2-state mode, ignore hit.
                                                                           //!< * If operating in 4-state mode, invoke any-hit shader.
    NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_STATE_UNKNOWN_OPAQUE      = 3  //!< Unknown-opaque OMM state.
                                                                           //!< * If operating in 2-state mode, commit hit.
                                                                           //!< * If operating in 4-state mode, invoke any-hit shader.
} NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_STATE;

//! Mandatory alignment for the address of an OMM Array.
//!
//! \ingroup dx
#define NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_BYTE_ALIGNMENT 256

//! Highest subdivision-level allowed with OC1.
//!
//! \ingroup dx
#define NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_OC1_MAX_SUBDIVISION_LEVEL 12

//! A list of flags that can be given to the \c TraceRay() function in HLSL.
//!
//! \ingroup dx
typedef enum _NVAPI_RAY_FLAGS_EX
{
    // RAY_FLAGS flags
    NVAPI_RAY_FLAG_NONE_EX                            = 0x0,        //!< No flag specified.
    NVAPI_RAY_FLAG_FORCE_OPAQUE_EX                    = NV_BIT( 0), //!< Consider all intersected geometries to be opaque, regardless of the flags specified at the geometry and instance level.
    NVAPI_RAY_FLAG_FORCE_NON_OPAQUE_EX                = NV_BIT( 1), //!< Consider all intersected geometries to be non-opaque, regardless of the flags specified at the geometry and instance level.
    NVAPI_RAY_FLAG_ACCEPT_FIRST_HIT_AND_END_SEARCH_EX = NV_BIT( 2), //!< End the traversal as soon as a geometry is hit, and that hit is not ignored by the any hit shader.
    NVAPI_RAY_FLAG_SKIP_CLOSEST_HIT_SHADER_EX         = NV_BIT( 3), //!< Do not invoke the closest hit shader once the traversal ends.
    NVAPI_RAY_FLAG_CULL_BACK_FACING_TRIANGLES_EX      = NV_BIT( 4), //!< Never intersect triangle geometries that are back facing with regard to the ray.
    NVAPI_RAY_FLAG_CULL_FRONT_FACING_TRIANGLES_EX     = NV_BIT( 5), //!< Never intersect triangle geometries that are front facing with regard to the ray.
    NVAPI_RAY_FLAG_CULL_OPAQUE_EX                     = NV_BIT( 6), //!< Never intersect geometries that were flagged as opaque.
    NVAPI_RAY_FLAG_CULL_NON_OPAQUE_EX                 = NV_BIT( 7), //!< Never intersect geometries that were not flagged as opaque.
    NVAPI_RAY_FLAG_SKIP_TRIANGLES_EX                  = NV_BIT( 8), //!< Never intersect triangle geometries.
    NVAPI_RAY_FLAG_SKIP_PROCEDURAL_PRIMITIVES_EX      = NV_BIT( 9), //!< Never intersect AABB geometries.

    // NVAPI_RAY_FLAGS_EX specific flags
    NVAPI_RAY_FLAG_FORCE_OMM_2_STATE_EX               = NV_BIT(10), //!< Treat unknown-opaque and unknown-transparent as opaque and transparent, respectively, during traversal.
                                                                    //!< If an instance is flagged with #NVAPI_D3D12_RAYTRACING_INSTANCE_FLAG_DISABLE_OMMS_EX, that takes precedence over this flag.
} NVAPI_RAY_FLAG_EX;

//! Mandatory alignment for the address of a DMM Array.
//!
//! \ingroup dx
#define NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_ARRAY_BYTE_ALIGNMENT 256

//! Highest subdivision-level allowed with DC1.
//!
//! \ingroup dx
#define NVAPI_D3D12_RAYTRACING_DISPLACEMENT_MICROMAP_DC1_MAX_SUBDIVISION_LEVEL 5

#endif // defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__)


//! \ingroup DX
typedef enum _NV_D3D12_WORKSTATION_FEATURE_TYPE
{
    NV_D3D12_WORKSTATION_FEATURE_TYPE_PRESENT_BARRIER = 1,       // PresentBarrier feature
    NV_D3D12_WORKSTATION_FEATURE_TYPE_RDMA_BAR1_SUPPORT = 2,     // RDMA heap supported via Bar1 carveout
} NV_D3D12_WORKSTATION_FEATURE_TYPE;

// parameter structure for NV_D3D12_WORKSTATION_FEATURE_TYPE_RDMA_BAR1_AVAILABLE related information
typedef struct _NV_D3D12_WORKSTATION_FEATURE_RDMA_PROPERTIES
{
    NvU64 rdmaHeapSize;     // maximum available Bar1 heap size for RDMA allocations
} NV_D3D12_WORKSTATION_FEATURE_RDMA_PROPERTIES;

// parameter structure for querying workstation feature information
typedef struct _NV_D3D12_WORKSTATION_FEATURE_PROPERTIES
{
    NvU32 version;                                              //!< (IN) Structure version
    NV_D3D12_WORKSTATION_FEATURE_TYPE   workstationFeatureType; //!< (IN) the type of workstation feature to be queried
    NvBool                              supported;              //!< (OUT) boolean returning if feature is supported
    union
    {
        NV_D3D12_WORKSTATION_FEATURE_RDMA_PROPERTIES  rdmaInfo;       //!< (OUT) RDMA feature related information, returned only if
                                                                      //!<       workstationFeatureType is NV_D3D12_WORKSTATION_FEATURE_TYPE_RDMA_BAR1_SUPPORT
    };
} NVAPI_D3D12_WORKSTATION_FEATURE_PROPERTIES_PARAMS_V1;

#define NVAPI_D3D12_WORKSTATION_FEATURE_PROPERTIES_PARAMS_VER1 MAKE_NVAPI_VERSION(NVAPI_D3D12_WORKSTATION_FEATURE_PROPERTIES_PARAMS_V1,1)
#define NVAPI_D3D12_WORKSTATION_FEATURE_PROPERTIES_PARAMS_VER  NVAPI_D3D12_WORKSTATION_FEATURE_PROPERTIES_PARAMS_VER1
#define NVAPI_D3D12_WORKSTATION_FEATURE_PROPERTIES_PARAMS      NVAPI_D3D12_WORKSTATION_FEATURE_PROPERTIES_PARAMS_V1


#if defined(__cplusplus) && defined(__d3d12_h__)
///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D12_QueryWorkstationFeatureProperties
//
//!   DESCRIPTION: This API returns information about the properties of specific workstation features on the specified device.
//!
//! \since Release: 530
//!
//! \param [in]     pDevice                         The ID3D12Device device which is queried for feature properties
//! \param [inout]  pWorkstationFeatureProperties   Pointer to a structure containing workstation feature query information.
//!
//! \return ::NVAPI_OK                     the call succeeded
//! \return ::NVAPI_ERROR                  the call failed
//! \return ::NVAPI_NO_IMPLEMENTATION      the API is not implemented
//! \return ::NVAPI_INVALID_POINTER        an invalid pointer was passed as an argument
//! \retval ::NVAPI_API_NOT_INITIALIZED    NvAPI not initialized
//!
//! SUPPORTED OS:  Windows 10 and higher
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D12_QueryWorkstationFeatureProperties(__in ID3D12Device *pDevice, __inout NVAPI_D3D12_WORKSTATION_FEATURE_PROPERTIES_PARAMS *pWorkstationFeatureProperties);
#endif // defined(__cplusplus) && defined(__d3d12_h__)


#if defined (__cplusplus) && defined(__d3d12_h__)

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D12_CreateCommittedRDMABuffer
//
//! \since Release: 530
//
//! \code
//!   DESCRIPTION: NvAPI_D3D12_CreateCommittedRDMABuffer is a wrapper of ID3D12Device::CreateCommittedResource 
//!                which allows to allocate linear memory which can be used for remote direct memory access (RDMA) from other devices.
//!                It creates an implicit D3D12 heap of the requested size, allocates the resource and returns an RDMA address for remote direct memory access.
//!                The created memory will reside on the specified device local memory and won't be cpu accessible.
//!
//!         \param [in]        pDevice                A pointer to a D3D12 device.
//!         \param [in]        size                   Size in bytes of the linear buffer to be allocated for the resource.
//!         \param [in]        heapCreationNodeMask   This mask indicates the node where the resource should be created.
//!         \param [in]        heapVisibleNodeMask    This mask indicates on which nodes the resource is accessible.
//!         \param [in]        riidResource           The globally unique identifier (GUID) for the resource interface.
//!         \param [out]       ppvResource            A pointer to memory that receives the requested interface pointer to the created resource object. 
//!         \param [out]       ppRDMAAddress          A pointer to memory that receives the Bar1 memory region for remote direct memory access.

//! SUPPORTED OS:  Windows 10 and higher
//!
//!
//! \return  This API can return any of the error codes enumerated in
//!          #NvAPI_Status.
//!
//! \endcode
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D12_CreateCommittedRDMABuffer(
        __in  ID3D12Device* pDevice,
        __in  NvU64 size,
        __in  NvU32 heapCreationNodeMask,
        __in  NvU32 heapVisibleNodeMask,
        __in  REFIID riidResource,
        __out void **ppvResource,
        __out void **ppRDMAAddress);

#endif //defined(__cplusplus) && defined(__d3d12_h__)

#if defined(__cplusplus) && (defined(__d3d12_h__))

//! Underlying component types of a cooperative vector or matrix
//! \ingroup dx
typedef enum NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE {
    NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE_FLOAT16      = 0,
    NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE_FLOAT32      = 1,
    NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE_FLOAT64      = 2,
    NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE_SINT8        = 3,
    NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE_SINT16       = 4,
    NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE_SINT32       = 5,
    NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE_SINT64       = 6,
    NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE_UINT8        = 7,
    NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE_UINT16       = 8,
    NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE_UINT32       = 9,
    NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE_UINT64       = 10,
    NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE_SINT8_PACKED = 11,
    NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE_UINT8_PACKED = 12,
    NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE_FLOAT_E4M3   = 13,  
    NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE_FLOAT_E5M2   = 14, 
    NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE_INVALID      = 0x7FFFFFFF
} NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE;

//! Device or Host address descriptor to specify source/destination addresses. Both source and destination must either be on host or both on device.
//! \ingroup dx
typedef struct NVAPI_DEVICE_OR_HOST_ADDRESS
{
    NvBool bIsDeviceAlloc;                          //!< [in] Is false if allocation is on CPU, true otherwise. The value of this also decides whether conversion will happen on host or device. 
    union 
    {
        D3D12_GPU_VIRTUAL_ADDRESS deviceAddress;    //!< [in] GPU VA of allocation
        void*                     pHostAddress;     //!< [in] Pointer to host allocation
    };
} NVAPI_DEVICE_OR_HOST_ADDRESS;

//! Possible cooperative vector matrix layouts
//! \ingroup dx
typedef enum NVAPI_COOPERATIVE_VECTOR_MATRIX_LAYOUT {
    NVAPI_COOPERATIVE_VECTOR_MATRIX_LAYOUT_ROW_MAJOR           = 0,
    NVAPI_COOPERATIVE_VECTOR_MATRIX_LAYOUT_COLUMN_MAJOR        = 1,
    NVAPI_COOPERATIVE_VECTOR_MATRIX_LAYOUT_INFERENCING_OPTIMAL = 2,
    NVAPI_COOPERATIVE_VECTOR_MATRIX_LAYOUT_TRAINING_OPTIMAL    = 3,
    NVAPI_COOPERATIVE_VECTOR_MATRIX_LAYOUT_INVALID             = 0x7FFFFFFF
} NVAPI_COOPERATIVE_VECTOR_MATRIX_LAYOUT;

//! Structure specifying a request to convert the layout and type of a cooperative vector matrix
//! \ingroup dx
typedef struct _NVAPI_CONVERT_COOPERATIVE_VECTOR_MATRIX_DESC_V1
{    
    NvU32                                   version;                //!< [in]    Struct version.
    size_t                                  srcSize;                //!< [in]    Is the length in bytes of srcData
    NVAPI_DEVICE_OR_HOST_ADDRESS            srcData;                //!< [in]    Is either `NULL` when calling the command to query the required size of the destination or a pointer to the source data in the source layout.
    size_t*                                 pDstSize;               //!< [inout] Is a pointer to an integer storing the number of bytes required or requested to convert.
    NVAPI_DEVICE_OR_HOST_ADDRESS            dstData;                //!< [inout] Is either `NULL` when calling the command to query the required size of the destination or a pointer to the destination data.
    NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE srcComponentType;       //!< [in]    Is the type of a source matrix element
    NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE dstComponentType;       //!< [in]    Is the type of a destination matrix element.
    NvU32                                   numRows;                //!< [in]    Is the number of rows in the matrix.
    NvU32                                   numColumns;             //!< [in]    Is the number of columns in the matrix.
    NVAPI_COOPERATIVE_VECTOR_MATRIX_LAYOUT  srcLayout;              //!< [in]    Is the layout of the source matrix.
    size_t                                  srcStride;              //!< [in]    Is the number of elements between a consecutive row or column (depending on srcLayout) of the source matrix, if it is row-major or column-major.
    NVAPI_COOPERATIVE_VECTOR_MATRIX_LAYOUT  dstLayout;              //!< [in]    Is the layout the matrix is converted to.
    size_t                                  dstStride;              //!< [in]    Is the number of bytes between a consecutive row or column (depending on dstLayout) of the destination matrix if it is row-major or column-major.
} NVAPI_CONVERT_COOPERATIVE_VECTOR_MATRIX_DESC_V1;

typedef NVAPI_CONVERT_COOPERATIVE_VECTOR_MATRIX_DESC_V1 NVAPI_CONVERT_COOPERATIVE_VECTOR_MATRIX_DESC;

//! Macro for deriving version of NVAPI_CONVERT_COOPERATIVE_VECTOR_MATRIX_DESC
#define NVAPI_CONVERT_COOPERATIVE_VECTOR_MATRIX_DESC_VER1 MAKE_NVAPI_VERSION(NVAPI_CONVERT_COOPERATIVE_VECTOR_MATRIX_DESC_V1,1)
#define NVAPI_CONVERT_COOPERATIVE_VECTOR_MATRIX_DESC_VER  NVAPI_CONVERT_COOPERATIVE_VECTOR_MATRIX_DESC_VER1

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D12_ConvertCooperativeVectorMatrix
//
//!   DESCRIPTION: Queries the size of a cooperative vector matrix or converts a matrix to another layout and type. Performs a single conversion using descriptor pointed to by pDesc.
//!                For multiple conversions in a single API call, use NvAPI_D3D12_ConvertCooperativeVectorMatrixMultiple.
//!                If both the source (src) and destination (dst) allocations reside on the host, the conversion is run on the host. 
//!                Conversely, if both allocations are on the device, the conversion is run on the device.
//!                Note that conversions between host and device allocations (and vice versa) are not supported.
//!                If pDstData is `NULL`, then the number of bytes required to store the converted matrix is returned in pDstSize.
//!                Otherwise, pDstSize must point to a variable set by the user to the number of bytes in pDstData, and on return the
//!                variable is overwritten with the number of bytes actually written to pDstData.
//!                pSrcData can be `NULL` when pDstData is `NULL`. If pDstSize is less than the number of bytes required to store the
//!                converted matrix, no bytes will be written, and NVAPI_INSUFFICIENT_BUFFER will be returned instead of NVAPI_OK, to indicate that not enough space was provided.
//!                The size of the destination is only a function of the destination layout information, and does not depend on the source layout information.                
//!                If srcLayout is row-major or column-major, then srcStride should be greater than the length of a row/column, and a multiple of the element size.
//!                If dstLayout is row-major or column-major, then dstStride should be greater than the length of a row/column, and a multiple of the element size.
//!                If srcComponentType is not a supported MatrixInterpretation value as reported by NvAPI_D3D12_GetPhysicalDeviceCooperativeVectorProperties() then srcComponentType should be `NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE_FLOAT32`.
//!                If dstComponentType is not a supported MatrixInterpretation value as reported by NvAPI_D3D12_GetPhysicalDeviceCooperativeVectorProperties() then dstComponentType should be `NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE_FLOAT32`.
//!                If srcComponentType and dstComponentType are not equal, then one should be `NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE_FLOAT32`  or `NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE_FLOAT16` and the other should be a lower-precision floating-point type. 
//!                If dstComponentType is `NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE_FLOAT_E4M3` or `NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE_FLOAT_E5M2`, then dstLayout should be `NVAPI_COOPERATIVE_VECTOR_MATRIX_LAYOUT_INFERENCING_OPTIMAL` or `NVAPI_COOPERATIVE_VECTOR_MATRIX_LAYOUT_TRAINING_OPTIMAL`.
//!
//! \since Release: 570
//! SUPPORTED OS:  Windows 10 and higher
//!
//! \param [in] pDevice       Pointer to the ID3D12Device created by application.
//! \param [in] pCommandList  Pointer to ID3D12GraphicsCommandList for device side conversion. Ignored if host side conversion is desired.
//! \param [in] pDesc         Pointer to NVAPI_CONVERT_COOPERATIVE_VECTOR_MATRIX_DESC created by app
//!
//! \retval NVAPI_OK                          Conversion done succesfully.          
//! \retval NVAPI_API_NOT_INITIALIZED         NvAPI was not yet initialized.
//! \retval NVAPI_INVALID_POINTER             pDevice and/or pDesc is NULL.
//! \retval NVAPI_INVALID_COMBINATION         Either src and dst data are both not on CPU/GPU or both are on GPU but pCommandList is NULL.
//! \retval NVAPI_INSUFFICIENT_BUFFER         Destination size passed was not enough for the conversion result.
//! \retval NVAPI_INCOMPATIBLE_STRUCT_VERSION Incompatible structure version of pDesc.
//! \retval NVAPI_ERROR                       Generic error.
//! \retval NVAPI_OUT_OF_MEMORY               Internal allocation failed.
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D12_ConvertCooperativeVectorMatrix(__in ID3D12Device *pDevice, __in ID3D12GraphicsCommandList* pCommandList, __in NVAPI_CONVERT_COOPERATIVE_VECTOR_MATRIX_DESC const* const pDesc);

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D12_ConvertCooperativeVectorMatrixMultiple
//
//!   DESCRIPTION: Queries the size of a cooperative vector matrix or converts a matrix to another layout and type.
//!                Can perform multiple conversions in a single API call. The number of descriptors pointed to by pDesc is specified using descCount. 
//!                Function returns error if any of the conversions fail and does not process further conversions.
//!                Behavior is same as NvAPI_D3D12_ConvertCooperativeVectorMatrix if descCount is equal to 1.
//!                If both the source (src) and destination (dst) allocations reside on the host, the conversion is run on the host. 
//!                See NvAPI_D3D12_ConvertCooperativeVectorMatrix documentation for valid usage.
//!
//! \since Release: 570
//! SUPPORTED OS:  Windows 10 and higher
//!
//! \param [in] pDevice       Pointer to the ID3D12Device created by application.
//! \param [in] pCommandList  Pointer to ID3D12GraphicsCommandList for device side conversion. Ignored if host side conversion is desired.
//! \param [in] pDesc         Pointer to NVAPI_CONVERT_COOPERATIVE_VECTOR_MATRIX_DESC created by app.
//! \param [in] desCount      Specifies the count of NVAPI_CONVERT_COOPERATIVE_VECTOR_MATRIX_DESC descriptors pointed to by pDesc. Must be greater than 0.
//!
//! \retval NVAPI_OK                          Conversion done succesfully.          
//! \retval NVAPI_API_NOT_INITIALIZED         NvAPI was not yet initialized.
//! \retval NVAPI_INVALID_POINTER             pDevice and/or pDesc is NULL.
//! \retval NVAPI_INVALID_ARGUMENT            descCount is 0.
//! \retval NVAPI_INVALID_COMBINATION         Either src and dst data are both not on CPU/GPU or both are on GPU but pCommandList is NULL.
//! \retval NVAPI_INSUFFICIENT_BUFFER         Destination size passed was not enough for the conversion result.
//! \retval NVAPI_INCOMPATIBLE_STRUCT_VERSION Incompatible structure version of pDesc.
//! \retval NVAPI_ERROR                       Generic error.
//! \retval NVAPI_OUT_OF_MEMORY               Internal allocation failed.
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D12_ConvertCooperativeVectorMatrixMultiple(__in ID3D12Device *pDevice, __in ID3D12GraphicsCommandList* pCommandList, __in NVAPI_CONVERT_COOPERATIVE_VECTOR_MATRIX_DESC const* const pDesc, __in NvU32 descCount);

//! Each structure describes a single supported combination of types for a matrix-vector multiply (or multiply-add) operation
//! \ingroup dx
typedef struct _NVAPI_COOPERATIVE_VECTOR_PROPERTIES_V1
{
    NvU32                                       version;                //!< [out] Struct version. App must verify the value returned by API.
    NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE     inputType;              //!< [out] Is the component type of vector Input, of type NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE.
    NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE     inputInterpretation;    //!< [out] Is the value of InputInterpretation, of type NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE.
    NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE     matrixInterpretation;   //!< [out] Is the value of MatrixInterpretation, of type NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE.
    NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE     biasInterpretation;     //!< [out] Is the value of BiasInterpretation, of type NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE.
    NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE     resultType;             //!< [out] Is the component type of Result Type, of type NVAPI_COOPERATIVE_VECTOR_COMPONENT_TYPE.
    bool                                        transpose;              //!< [out] Is a boolean indicating whether opaque layout matrices with this combination of input and output types supports transposition.
}NVAPI_COOPERATIVE_VECTOR_PROPERTIES_V1;

typedef NVAPI_COOPERATIVE_VECTOR_PROPERTIES_V1 NVAPI_COOPERATIVE_VECTOR_PROPERTIES;

//! Macro for deriving version of NVAPI_COOPERATIVE_VECTOR_PROPERTIES
#define NVAPI_COOPERATIVE_VECTOR_PROPERTIES_VER1  MAKE_NVAPI_VERSION(NVAPI_COOPERATIVE_VECTOR_PROPERTIES_V1,1)
#define NVAPI_COOPERATIVE_VECTOR_PROPERTIES_VER   NVAPI_COOPERATIVE_VECTOR_PROPERTIES_VER1

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D12_GetPhysicalDeviceCooperativeVectorProperties
//
//!   DESCRIPTION: Enumerates supported cooperative vector types combinations. 
//!                If pProperties is `NULL`, then the number of cooperative vector properties available is returned in pPropertyCount.
//!                Otherwise, pPropertyCount must point to a variable set by the user to the number of elements in the pProperties array, 
//!                and on return the variable is overwritten with the number of structures actually written to pProperties. 
//!                If pPropertyCount is less than the number of cooperative vector properties available, at most pPropertyCount structures will be
//!                written, and status will be NVAPI_INSUFFICIENT_BUFFER to indicate that not all the available cooperative vector properties were returned.
//!
//! \since Release: 570
//! SUPPORTED OS:  Windows 10 and higher
//!
//! \param [in]    pDevice       Pointer to the ID3D12Device created by application.
//! \param [inout] propertyCount Number of cooperative vector properties available or queried
//! \param [inout] pProperties   Is either `NULL` or a pointer to an array of NVAPI_COOPERATIVE_VECTOR_PROPERTIES structures.
//!
//! \retval NVAPI_OK                          Properties returned succesfully
//! \retval NVAPI_API_NOT_INITIALIZED         NvAPI was not yet initialized.
//! \retval NVAPI_INSUFFICIENT_BUFFER         Not an error but all supported properties could not be written into as propertyCount was insufficient.
//! \retval NVAPI_INVALID_POINTER             pDevice is NULL.
//! \retval NVAPI_ERROR                       Generic error.
//! \retval NVAPI_OUT_OF_MEMORY               Internal allocation failed.
//!
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D12_GetPhysicalDeviceCooperativeVectorProperties(__in ID3D12Device *pDevice, __inout NvU32 *pPropertyCount, __inout NVAPI_COOPERATIVE_VECTOR_PROPERTIES* pProperties);
#endif //defined(__cplusplus) && (defined(__d3d12_h__))

#if defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12Device5_INTERFACE_DEFINED__)

//! \ingroup dx
#define NVAPI_D3D12_RAYTRACING_CLAS_BYTE_ALIGNMENT 128                    //!< The alignment required for storage of CLAS objects

//! \ingroup dx
#define NVAPI_D3D12_RAYTRACING_CLUSTER_TEMPLATE_BYTE_ALIGNMENT 32         //!< The alignment required for storage of Cluster Templates objects

//! \ingroup dx
#define NVAPI_D3D12_RAYTRACING_CLUSTER_TEMPLATE_BOUNDS_BYTE_ALIGNMENT 32  //!< The alignment required for the optional AABB provided to Cluster Template builds

//! \ingroup dx
#define NVAPI_D3D12_RAYTRACING_MAXIMUM_GEOMETRY_INDEX 16777215            //!< The maximum supported geometry index for use with cluster objects

//! Enumeration listing permitted flag values for NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INPUTS
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_FLAGS
{
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_FLAG_NONE                   = 0x0,        //!< No option specified for the multi indirect cluster operation
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_FLAG_FAST_TRACE             = NV_BIT(0),  //!< Indicates that the operation should optimize results for trace performance at the cost of build performance
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_FLAG_FAST_BUILD             = NV_BIT(1),  //!< Indicates that the operation should optimize results for build performance at the cost of trace performance
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_FLAG_NO_OVERLAP             = NV_BIT(2),  //!< For cluster operations that permit input/output overlap this indicates that no such overlap exists, invalid to use when inputs and outputs are overlapping
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_FLAG_ALLOW_OMM              = NV_BIT(3),  //!< Specifies that the operation will interact with Cluster BLAS, CLAS or Templates that reference OMMs. All Operation Types & Modes require this field to be set correctly when interacting (building or consuming) objects that contain OMMs.
} NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_FLAGS;

//! Enumeration listing permitted geometry flag values for Clusters
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_CLUSTER_FLAGS
{
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_CLUSTER_FLAG_NONE                            = 0x0,        //!< No option specified for the argument of this cluster
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_CLUSTER_FLAG_ALLOW_DISABLE_OMMS              = NV_BIT(0),  //!< If set, any instances referencing a Cluster BLAS containing this CLAS are allowed to disable the OMM test through the `NVAPI_D3D12_RAYTRACING_INSTANCE_FLAG_DISABLE_OMMS` flag.
} NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_CLUSTER_FLAGS;

//! Enumeration listing permitted geometry flag values for Cluster Geometry
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_GEOMETRY_FLAGS
{
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_GEOMETRY_FLAG_NONE                           = 0x0,         //!< No option specified for the argument of this cluster geometry
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_GEOMETRY_FLAG_CULL_DISABLE                   = NV_BIT(29),  //!< Disables front and back face culling for affected triangles, see D3D12_RAYTRACING_INSTANCE_FLAG_TRIANGLE_CULL_DISABLE 
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_GEOMETRY_FLAG_NO_DUPLICATE_ANYHIT_INVOCATION = NV_BIT(30),  //!< Same behavior as D3D12_RAYTRACING_GEOMETRY_FLAG_NO_DUPLICATE_ANYHIT_INVOCATION for non-cluster Geometry
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_GEOMETRY_FLAG_OPAQUE                         = NV_BIT(31),  //!< Same behavior as D3D12_RAYTRACING_GEOMETRY_FLAG_OPAQUE for non-cluster Geometry
} NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_GEOMETRY_FLAGS;

//! Enumeration listing possible values for Cluster Operation types
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_TYPE
{
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_TYPE_MOVE_CLUSTER_OBJECT                     = 0, //!< Copies/moves CLAS, Cluster BLAS or Templates, use NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_MOVES_DESC as desc. Alignment requirement depends on the type of object moved.
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_TYPE_BUILD_BLAS_FROM_CLAS                    = 1, //!< Constructs Cluster BLAS from arrays of CLAS addresses, use NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_CLAS_DESC as desc. Alignment of Cluster BLAS is a multiple of D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BYTE_ALIGNMENT.
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_TYPE_BUILD_CLAS_FROM_TRIANGLES               = 2, //!< Constructs CLAS from triangle data, use NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_TRIANGLES_DESC as desc. Alignment of CLAS is a multiple of NVAPI_D3D12_RAYTRACING_CLAS_BYTE_ALIGNMENT.
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_TYPE_BUILD_CLUSTER_TEMPLATES_FROM_TRIANGLES  = 3, //!< Constructs Cluster Templates from triangle data, use NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_TRIANGLES_DESC as desc. Alignment of Cluster Templates is a multiple of NVAPI_D3D12_RAYTRACING_CLUSTER_TEMPLATE_BYTE_ALIGNMENT.
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_TYPE_INSTANTIATE_CLUSTER_TEMPLATES           = 4, //!< Instantiates Cluster Templates to create CLAS results, use NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_TRIANGLES_DESC as desc. Alignment of CLAS is a multiple of NVAPI_D3D12_RAYTRACING_CLAS_BYTE_ALIGNMENT.
} NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_TYPE;

//! Specifies the index format to use for cluster operations.
//! The values are chosen to match Vulkan's style of index size (in bytes) for the appropriate format
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INDEX_FORMAT
{
  NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INDEX_FORMAT_8BIT  = 1,  //!< Use 8-bit indices
  NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INDEX_FORMAT_16BIT = 2,  //!< Use 16-bit indices
  NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INDEX_FORMAT_32BIT = 4,  //!< Use 32-bit indices
} NVAPI_3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INDEX_FORMAT;

//! Enumeration listing possible values for the Cluster Operation mode
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_MODE
{
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_MODE_IMPLICIT_DESTINATIONS   = 0, //!< User provides total buffer space, driver places results within, returns VAs and actual sizes
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_MODE_EXPLICIT_DESTINATIONS   = 1, //!< User provides individual target VAs, driver places them there, returns actual sizes
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_MODE_GET_SIZES               = 2, //!< Driver returns maximum sizes per element, results may only be used with NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_MODE_EXPLICIT_DESTINATIONS
} NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_MODE;

//! Desc used for operation type NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_TYPE_BUILD_BLAS_FROM_CLAS
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INPUT_CLAS_DESC
{
    NvU32                       maxTotalClasCount;  //!< The maximum total number of CLAS used by all BLAS that will be built by one call (reuse of the same CLAS counts multiple times)
    NvU32                       maxClasCountPerArg; //!< The maximum number of CLAS used by an individual Arg (equivalent to a BLAS being built). Maximum supported value is D3D12_RAYTRACING_MAXIMUM_PRIMITIVE_COUNT.
} NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INPUT_CLAS_DESC;

//! Desc used for operation type either NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_TYPE_BUILD_CLAS_FROM_TRIANGLES, NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_TYPE_BUILD_CLUSTER_TEMPLATES_FROM_TRIANGLES or NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_TYPE_INSTANTIATE_CLUSTER_TEMPLATES
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INPUT_TRIANGLES_DESC
{
    NvU32                       vertexFormat;                   //!< A value of `DXGI_FORMAT` describing the vertex format used in the vertex buffer passed for the cluster operation. For a list of supported vertex formats, see D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC::VertexFormat
    NvU32                       maxGeometryIndexValue;          //!< The maximum value of any geometry index that will occur in the results of the cluster operation (including instanced CLAS from templates constructed by it). Maximum supported value is NVAPI_D3D12_RAYTRACING_MAXIMUM_GEOMETRY_INDEX.
    NvU32                       maxUniqueGeometryCountPerArg;   //!< The maximum value number of unique geometry index values that will occur in each individual result of the cluster operation. A value of 0 is treated as a value of 1. Maximum supported value is 256.
    NvU32                       maxTriangleCountPerArg;         //!< The maximum number of triangles that will occur in each individual result of the cluster operation. Maximum supported value is 256.
    NvU32                       maxVertexCountPerArg;           //!< The maximum number of vertices that will occur in each individual result of the cluster operation. Maximum supported value is 256.
    NvU32                       maxTotalTriangleCount;          //!< The maximum total value of summing up the number of triangles that will occur in each individual result of the cluster operation.
    NvU32                       maxTotalVertexCount;            //!< The maximum total value of summing up the number of vertices that will occur in each individual result of the cluster operation.
    NvU32                       minPositionTruncateBitCount;    //!< The minimum number of bits that will be truncated from vertex positions in the arguments of this cluster operation. Maximum supported value is 32.
} NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INPUT_TRIANGLES_DESC;

//! Enumeration listing the possible types used by NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INPUT_MOVES_DESC
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_MOVE_TYPE
{
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_MOVE_TYPE_BOTTOM_LEVEL_ACCELERATION_STRUCTURE  = 0, //!< The moved objects are Clustered BLAS
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_MOVE_TYPE_CLUSTER_LEVEL_ACCELERATION_STRUCTURE = 1, //!< The moved objects are CLAS
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_MOVE_TYPE_TEMPLATE                             = 2, //!< The moved objects are Cluster Templates
} NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_MOVE_TYPE;

//! Desc used for operation type NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_TYPE_MOVE_CLUSTER_OBJECT
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_MOVES_DESC 
{
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_MOVE_TYPE   type;          //!< Determines the type of object to be copied/moved by this cluster operation
    NvU32                                                               maxBytesMoved; //!< Determines the maximum total number of bytes copied/moved by the operation (maximum sum of sizes of all copied/moved objects)
} NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INPUT_MOVES_DESC;

//! Inputs describing the configuration of a cluster operation, used to determine the memory requirement for the operation
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INPUTS
{
    NvU32                                                                  maxArgCount; //!< Represents the maximum number of arguments to process
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_FLAGS          flags;       //!< Flags to modify the operation
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_TYPE           type;        //!< The type of multi indirect operation to execute
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_MODE           mode;        //!< The operation mode executed
 
    //!< Different arguments depending on type, see NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_TYPE for details
    union
    {
        NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INPUT_CLAS_DESC      clasDesc;      //!< Use when type is equal to NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_TYPE_BUILD_BLAS_FROM_CLAS
        NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INPUT_TRIANGLES_DESC trianglesDesc; //!< Use when type is equal to one of: NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_TYPE_BUILD_CLAS_FROM_TRIANGLES, NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_TYPE_BUILD_CLUSTER_TEMPLATES_FROM_TRIANGLES, NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_TYPE_INSTANTIATE_CLUSTER_TEMPLATES
        NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INPUT_MOVES_DESC     movesDesc;     //!< Use when type is equal to NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_TYPE_MOVE_CLUSTER_OBJECT
    };
} NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INPUTS;

//! Structure describing the memory requirement of a cluster operation
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_REQUIREMENTS_INFO
{
    NvU64 resultDataMaxSizeInBytes; //!< Allocated size required to hold the result of the multi indirect operation based on the specified inputs. 
                                    //!< For NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_MODE_EXPLICIT_DESTINATIONS this will be one per object.
                                    //!< For NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_MODE_IMPLICIT_DESTINATIONS this will be for all objects in the given call.
                                    //!< For NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_MODE_GET_SIZES always 0.
    NvU64 scratchDataSizeInBytes;   //!< Scratch storage on GPU required during multi indirect operation based on the specified inputs.
} NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_REQUIREMENTS_INFO;

//! Parameter structure for NvAPI_D3D12_GetRaytracingMultiIndirectClusterOperationRequirementsInfo
//!
//! \ingroup dx
typedef struct _NVAPI_GET_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_REQUIREMENTS_INFO_PARAMS_V1
{
    NvU32                                                                       version; //!< [in]  Structure version; it should be set to #NVAPI_GET_RAYTRACING_ACCELERATION_STRUCTURE_MULTI_INDIRECT_PREBUILD_INFO_PARAMS_VER.
    const NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INPUTS*       pInput;  //!< [in]  Description of the multi indirect operation.
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_REQUIREMENTS_INFO*  pInfo;   //!< [out] Result of the query.
} NVAPI_GET_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_REQUIREMENTS_INFO_PARAMS_V1;
#define NVAPI_GET_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_REQUIREMENTS_INFO_PARAMS_VER1          MAKE_NVAPI_VERSION(NVAPI_GET_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_REQUIREMENTS_INFO_PARAMS_V1, 1)
typedef NVAPI_GET_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_REQUIREMENTS_INFO_PARAMS_V1            NVAPI_GET_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_REQUIREMENTS_INFO_PARAMS;
#define NVAPI_GET_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_REQUIREMENTS_INFO_PARAMS_VER           NVAPI_GET_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_REQUIREMENTS_INFO_PARAMS_VER1

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D12_GetRaytracingMultiIndirectClusterOperationRequirementsInfo
//
//! DESCRIPTION: Function call used to determine the memory requirements for a future call to NvAPI_D3D12_RaytracingExecuteMultiIndirectClusterOperation
//!
//! SUPPORTED OS:  Windows 10 and higher
//!
//!
//! \since Release: 560
//!
//! \param [in]     pDevice              The D3D device that owns the command list the future call to NvAPI_D3D12_RaytracingExecuteMultiIndirectClusterOperation will be made from
//! \param [in]     pParams              API parameters
//!
//! \return This API can return any of the error codes enumerated in #NvAPI_Status.
//!         If there are return error codes with specific meaning for this API, they are listed below.
//!
//! \retval ::NVAPI_OK                   Completed request
//! \retval ::NVAPI_INVALID_POINTER      A null pointer was passed as pDevice, pParams, pParams->pInput 
//!                                      or pParams->pInfo argument
//! \retval ::NVAPI_INVALID_ARGUMENT     The pParams->pInfo parameter was set in an invalid way
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D12_GetRaytracingMultiIndirectClusterOperationRequirementsInfo(
    __in    ID3D12Device5* pDevice,
    __inout const NVAPI_GET_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_REQUIREMENTS_INFO_PARAMS* pParams);

//! Argument structure used on device for operation type NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_TYPE_BUILD_BLAS_FROM_CLAS
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_MULTI_INDIRECT_CLUSTER_ARGS
{
    NvU32                     clusterCount; //!< [in] The size of the array referenced by clusterVAs. Must be less than or equal to NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INPUT_CLAS_DESC::maxClasCountPerArg
    NvU32                     reserved;     //!< [in] Reserved, must be 0
    D3D12_GPU_VIRTUAL_ADDRESS clusterVAs;   //!< [in] Address of an array of D3D12_GPU_VIRTUAL_ADDRESS holding valid addresses of CLAS previously constructed. 8 byte stride/alignment.
} NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_MULTI_INDIRECT_CLUSTER_ARGS;

//! Argument structure used on device for operation type NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_TYPE_BUILD_CLAS_FROM_TRIANGLES
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_MULTI_INDIRECT_TRIANGLE_CLUSTER_ARGS
{
    NvU32                        clusterId;                         //!< [in] The user specified cluster Id to encode in the CLAS.
    NvU32                        clusterFlags;                      //!< [in] Values of NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_CLUSTER_FLAGS to use as Cluster Flags.
    NvU32                        triangleCount : 9;                 //!< [in] The number of triangles used by the CLAS (max NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INPUT_TRIANGLES_DESC::maxTriangleCountPerArg).
    NvU32                        vertexCount : 9;                   //!< [in] The number of vertices used by the CLAS (max NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INPUT_TRIANGLES_DESC::maxVertexCountPerArg).
    NvU32                        positionTruncateBitCount : 6;      //!< [in] The number of bits to truncate from the position values (min NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INPUT_TRIANGLES_DESC::minPositionTruncateBitCount).
    NvU32                        indexFormat : 4;                   //!< [in] The index format to use for the indexBuffer, see NVAPI_3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INDEX_FORMAT for possible values.
    NvU32                        opacityMicromapIndexFormat : 4;    //!< [in] The index format to use for the opacityMicromapIndexBuffer, see NVAPI_3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INDEX_FORMAT for possible values.
    NvU32                        baseGeometryIndexAndFlags;         //!< [in] The base geometry index (lower 24 bit) and base geometry flags (NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_GEOMETRY_FLAGS), see geometryIndexBuffer.
    NvU16                        indexBufferStride;                 //!< [in] The stride of the elements of indexBuffer, in bytes. If set to 0, will use index size as stride.
    NvU16                        vertexBufferStride;                //!< [in] The stride of the elements of vertexBuffer, in bytes. If set to 0, will use vertex size as stride.
    NvU16                        geometryIndexAndFlagsBufferStride; //!< [in] The stride of the elements of geometryIndexBuffer, in bytes. If set to 0, will use 4 byte size as stride.
    NvU16                        opacityMicromapIndexBufferStride;  //!< [in] The stride of the elements of opacityMicromapIndexBuffer, in bytes. If set to 0, will use index size as stride.
    D3D12_GPU_VIRTUAL_ADDRESS    indexBuffer;                       //!< [in] The index buffer to construct the CLAS. The memory pointed to must be in state D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE.
    D3D12_GPU_VIRTUAL_ADDRESS    vertexBuffer;                      //!< [in] The vertex buffer to construct the CLAS. The memory pointed to must be in state D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE.
    D3D12_GPU_VIRTUAL_ADDRESS    geometryIndexAndFlagsBuffer;       //!< [in] (optional) Address of an array of 32-bit geometry indices and geometry flags with size equal to the triangle count.
                                                                    //!< Each 32-bit value is organized the same as baseGeometryIndexAndFlags.
                                                                    //!< If non-zero, the geometry indices of the CLAS triangles will be equal to the lower 24-bit of geometryIndexBuffer[triangleIndex] + baseGeometryIndex.
                                                                    //!< If non-zero, the geometry flags for each triangle will be the bitwise OR of the flags in the upper 8 bits of baseGeometryIndex and geometryIndexBuffer[triangleIndex].
                                                                    //!< Otherwise all triangles will have a geometry index equal to baseGeometryIndexAndFlags.
                                                                    //!< The number of unique elements may not exceed NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INPUT_TRIANGLES_DESC::maxUniqueGeometryCountPerArg.
                                                                    //!< If used, the memory pointed to must be in state D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE.
    D3D12_GPU_VIRTUAL_ADDRESS    opacityMicromapArray;              //!< [in] (optional) Address of a valid OMM array, if used NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_FLAG_ALLOW_OMM must be set on this and all other cluster operation calls interacting with the object(s) constructed.
    D3D12_GPU_VIRTUAL_ADDRESS    opacityMicromapIndexBuffer;        //!< [in] (optional) Address of an array of indices into the OMM array. Note that an additional OMM special index is reserved and can be used to turn off OMM for specific triangles.
} NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_MULTI_INDIRECT_TRIANGLE_CLUSTER_ARGS;

//! Argument structure used on device for operation type NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_TYPE_BUILD_CLUSTER_TEMPLATES_FROM_TRIANGLES
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_MULTI_INDIRECT_TRIANGLE_TEMPLATE_ARGS
{
    NvU32                        clusterId;                         //!< [in] The user specified cluster Id to encode in the cluster template.
    NvU32                        clusterFlags;                      //!< [in] Values of NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_CLUSTER_FLAGS to use as Cluster Flags.
    NvU32                        triangleCount : 9;                 //!< [in] The number of triangles used by the cluster template (max NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INPUT_TRIANGLES_DESC::maxTriangleCountPerArg).
    NvU32                        vertexCount : 9;                   //!< [in] The number of vertices used by the cluster template (max NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INPUT_TRIANGLES_DESC::maxTriangleCountPerArg).
    NvU32                        positionTruncateBitCount : 6;      //!< [in] The number of bits to truncate from the position values (min NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INPUT_TRIANGLES_DESC::minPositionTruncateBitCount).
    NvU32                        indexFormat : 4;                   //!< [in] The index format to use for the indexBuffer, see NVAPI_3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INDEX_FORMAT for possible values.
    NvU32                        opacityMicromapIndexFormat : 4;    //!< [in] The index format to use for the opacityMicromapIndexBuffer, see NVAPI_3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INDEX_FORMAT for possible values.
    NvU32                        baseGeometryIndexAndFlags;         //!< [in] The base geometry index (lower 24 bit) and base geometry flags (NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_GEOMETRY_FLAGS), see geometryIndexBuffer.
    NvU16                        indexBufferStride;                 //!< [in] The stride of the elements of indexBuffer, in bytes. If set to 0, will use index size as stride.
    NvU16                        vertexBufferStride;                //!< [in] The stride of the elements of vertexBuffer, in bytes. If set to 0, will use vertex size as stride.
    NvU16                        geometryIndexAndFlagsBufferStride; //!< [in] The stride of the elements of geometryIndexBuffer, in bytes. If set to 0, will use 4 byte size as stride.
    NvU16                        opacityMicromapIndexBufferStride;  //!< [in] The stride of the elements of opacityMicromapIndexBuffer, in bytes. If set to 0, will use index size as stride.
    D3D12_GPU_VIRTUAL_ADDRESS    indexBuffer;                       //!< [in] The index buffer to construct the cluster template. The memory pointed to must be in state D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE.
    D3D12_GPU_VIRTUAL_ADDRESS    vertexBuffer;                      //!< [in] (optional) The vertex buffer to optimize the cluster template, the vertices will not be stored in the cluster template. If used, the memory pointed to must be in state D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE.
    D3D12_GPU_VIRTUAL_ADDRESS    geometryIndexAndFlagsBuffer;       //!< [in] (optional) Address of an array of 32-bit geometry indices and geometry flags with size equal to the triangle count.
                                                                    //!< Each 32-bit value is organized the same as baseGeometryIndexAndFlags.
                                                                    //!< If non-zero, the geometry indices of the CLAS triangles will be equal to the lower 24-bit of geometryIndexBuffer[triangleIndex] + baseGeometryIndex + geometryIndexOffset.
                                                                    //!< If non-zero, the geometry flags for each triangle will be the bitwise OR of the flags in the upper 8 bits of baseGeometryIndex and geometryIndexBuffer[triangleIndex].
                                                                    //!< Otherwise all triangles will have a geometry index equal to baseGeometryIndexAndFlags + geometryIndexOffset.
                                                                    //!< The number of unique elements may not exceed NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INPUT_TRIANGLES_DESC::maxUniqueGeometryCountPerArg.
                                                                    //!< If used, the memory pointed to must be in state D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE.
    D3D12_GPU_VIRTUAL_ADDRESS    opacityMicromapArray;              //!< [in] (optional) Address of a valid OMM array, if used NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_FLAG_ALLOW_OMM must be set on this and all other cluster operation calls interacting with the object(s) constructed.
    D3D12_GPU_VIRTUAL_ADDRESS    opacityMicromapIndexBuffer;        //!< [in] (optional) Address of an array of indices into the OMM array. Note that an additional OMM special index is reserved and can be used to turn off OMM for specific triangles.
    D3D12_GPU_VIRTUAL_ADDRESS    instantiationBoundingBoxLimit;     //!< [in] (optional) Pointer to 6 floats with alignment NVAPI_D3D12_RAYTRACING_CLUSTER_TEMPLATE_BOUNDS_BYTE_ALIGNMENT representing the limits of the positions of any vertices the template will ever be instantiated with. If used, the memory pointed to must be in state D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE.
} NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_MULTI_INDIRECT_TRIANGLE_TEMPLATE_ARGS;

//! Argument structure used on device for operation type NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_TYPE_INSTANTIATE_CLUSTER_TEMPLATES
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_MULTI_INDIRECT_INSTANTIATE_TEMPLATE_ARGS
{
    NvU32                                clusterIdOffset;      //!< [in] The offset added to the clusterId stored in the Cluster template to calculate the final clusterId that will be written to the instantiated CLAS
    NvU32                                geometryIndexOffset;  //!< [in] The offset added to the geometry index stored for each triangle in the Cluster template to calculate the final geometry index that will be written to the triangles of the instantiated CLAS, the resulting value may not exceed maxGeometryIndexValue both of this call, and the call used to construct the original cluster template referenced
    D3D12_GPU_VIRTUAL_ADDRESS            clusterTemplate;      //!< [in] Address of a previously built cluster template to be instantiated.
    D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE vertexBuffer;         //!< [in] Vertex buffer with stride to use to fetch the vertex positions used for instantiation. May be NULL only when used with NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_MODE_GET_SIZES, which will cause the maximum size for all possible vertex inputs to be returned. If used, the memory pointed to must be in state D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE.
} NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_MULTI_INDIRECT_INSTANTIATE_TEMPLATE_ARGS;

//! Argument structure used on device for operation type NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_TYPE_MOVE_CLUSTER_OBJECT
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_MULTI_INDIRECT_MOVE_ARGS
{
    D3D12_GPU_VIRTUAL_ADDRESS            srcAccelerationStructure;  //!< [in] The address of the object to copy/move. The source object will not become clobbered unless the destinations of the call overlap with it.
} NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_MULTI_INDIRECT_MOVE_ARGS;

//! Enumeration listing permitted address resolution flag values for NvAPI_D3D12_RaytracingMultiIndirectClusterOperation
//! Unless flags are set, each address in NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_DESC will point directly to the data value or array of data values
//! By setting these flags the behavior is changed (one flag per field) for the field to be interpreted as containing the address of a piece of memory holding the address to the data value or array of data values.
//! If used, the memory for any intermediate references must be in state D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE. The requirements for the final argument contents remain unchanged.
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_ADDRESS_RESOLUTION_FLAGS
{
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_ADDRESS_RESOLUTION_FLAG_NONE                                 = 0x0,         //!< Interpret all addresses as direct references to the destination data
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_ADDRESS_RESOLUTION_FLAG_INDIRECTED_BATCH_RESULT              = NV_BIT(0),   //!< Interpret the batchResultData as containing the device address of a D3D12_GPU_VIRTUAL_ADDRESS containing the address of data
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_ADDRESS_RESOLUTION_FLAG_INDIRECTED_BATCH_SCRATCH             = NV_BIT(1),   //!< Interpret the batchScratchData as containing the device address of a D3D12_GPU_VIRTUAL_ADDRESS containing the address of data
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_ADDRESS_RESOLUTION_FLAG_INDIRECTED_DESTINATION_ADDRESS_ARRAY = NV_BIT(2),   //!< Interpret the destinationAddressArray as containing the device address of a D3D12_GPU_VIRTUAL_ADDRESS containing the address of data
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_ADDRESS_RESOLUTION_FLAG_INDIRECTED_RESULT_SIZE_ARRAY         = NV_BIT(3),   //!< Interpret the resultSizeArray as containing the device address of a D3D12_GPU_VIRTUAL_ADDRESS containing the address of data
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_ADDRESS_RESOLUTION_FLAG_INDIRECTED_INDIRECT_ARG_ARRAY        = NV_BIT(4),   //!< Interpret the indirectArgArray as containing the device address of a D3D12_GPU_VIRTUAL_ADDRESS containing the address of data
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_ADDRESS_RESOLUTION_FLAG_INDIRECTED_INDIRECT_ARG_COUNT        = NV_BIT(5),   //!< Interpret the indirectArgCount as containing the device address of a D3D12_GPU_VIRTUAL_ADDRESS containing the address of data
} NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_ADDRESS_RESOLUTION_FLAGS;

//! Describes the parameters for a call to NvAPI_D3D12_RaytracingExecuteMultiIndirectClusterOperation
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_DESC
{
    NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_INPUTS inputs;                  //!< [in] The inputs previously used with NvAPI_D3D12_GetRaytracingMultiIndirectClusterOperationRequirementsInfo to determine the memory requirement for the operation
    NvU32                                                          addressResolutionFlags;  //!< [in] Flags to control the resolution of address references by this structure (NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_ADDRESS_RESOLUTION_FLAGS)
    D3D12_GPU_VIRTUAL_ADDRESS                                      batchResultData;         //!< [out] If inputs.mode is equal to NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_MODE_IMPLICIT_DESTINATIONS this must point to an memory that is sufficient for resultDataMaxSizeInBytes, otherwise ignored. If set, must be in D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE state, and aligned depending on the object type being processed.
    D3D12_GPU_VIRTUAL_ADDRESS                                      batchScratchData;        //!< [in] Must point to memory that is sufficient for scratchDataSizeInBytes, with alignment of D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BYTE_ALIGNMENT and in D3D12_RESOURCE_STATE_UNORDERED_ACCESS state. May be NULL only if scratchDataSizeInBytes was 0
    D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE                           destinationAddressArray; //!< [inout] Address and stride of an array of D3D12_GPU_VIRTUAL_ADDRESS. If inputs.mode is NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_MODE_IMPLICIT_DESTINATIONS this will be filled out by the call, otherwise if inputs.mode is NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_MODE_EXPLICIT_DESTINATIONS each element of the array must contain the destination address with sufficient memory for either resultDataMaxSizeInBytes or a previous call with NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_MODE_GET_SIZES.
                                                                                            //!< The array must be in D3D12_RESOURCE_STATE_UNORDERED_ACCESS state. If inputs.mode is NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_MODE_EXPLICIT_DESTINATIONS the addresses referenced by the array must be in D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE state.
    D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE                           resultSizeArray;         //!< [out] Address and stride of an array of 32bit values. If inputs.mode is equal to NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_MODE_EXPLICIT_DESTINATIONS, will be populated by the call with the projected sizes of each result object based on the provided input. Otherwise, this field is optional and will be populated with the sizes of the objects written to destinationAddressArray. Must be in D3D12_RESOURCE_STATE_UNORDERED_ACCESS state.
    D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE                           indirectArgArray;        //!< [in] Address and stride of an array of type determined by inputs.type, see NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_MULTI_INDIRECT_*_ARGS. Structures must be tightly packed and aligned to the default C structure alignment of the structures. The memory pointed to must be in state D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE.
    D3D12_GPU_VIRTUAL_ADDRESS                                      indirectArgCount;        //!< [in] Determines the argument count, if 0 the value of inputs.maxArgCount will be used instead. If non-zero, the arrays in destinationAddressArray, resultSizeArray and indirectArgArray must all be equal to the argument count. The memory pointed to must be in state D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE.
} NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_DESC;

//! Parameters given to NvAPI_D3D12_RaytracingMultiIndirectClusterOperation().
//!
//! \ingroup dx
typedef struct _NVAPI_RAYTRACING_EXECUTE_MULTI_INDIRECT_CLUSTER_OPERATION_PARAMS_V1
{
    NvU32                                                                        version;               //!< [in] Structure version; it should be set to #NVAPI_RAYTRACING_EXECUTE_MULTI_INDIRECT_CLUSTER_OPERATION_PARAMS_VER.
    const NVAPI_D3D12_RAYTRACING_MULTI_INDIRECT_CLUSTER_OPERATION_DESC*          pDesc;                 //!< [in] Description of the multi indirect operation.
} NVAPI_RAYTRACING_EXECUTE_MULTI_INDIRECT_CLUSTER_OPERATION_PARAMS_V1;
#define NVAPI_RAYTRACING_EXECUTE_MULTI_INDIRECT_CLUSTER_OPERATION_PARAMS_VER1          MAKE_NVAPI_VERSION(NVAPI_RAYTRACING_EXECUTE_MULTI_INDIRECT_CLUSTER_OPERATION_PARAMS_V1, 1)
typedef NVAPI_RAYTRACING_EXECUTE_MULTI_INDIRECT_CLUSTER_OPERATION_PARAMS_V1            NVAPI_RAYTRACING_EXECUTE_MULTI_INDIRECT_CLUSTER_OPERATION_PARAMS;
#define NVAPI_RAYTRACING_EXECUTE_MULTI_INDIRECT_CLUSTER_OPERATION_PARAMS_VER           NVAPI_RAYTRACING_EXECUTE_MULTI_INDIRECT_CLUSTER_OPERATION_PARAMS_VER1

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D12_RaytracingExecuteMultiIndirectClusterOperation
//
//! DESCRIPTION: Execute a multi indirect cluster operation
//!              The CPU-side input buffers are not referenced after this call.
//!              The GPU-side input resources are not referenced after the build has concluded after <tt>ExecuteCommandList()</tt>.
//!
//! SUPPORTED OS:  Windows 10 and higher
//!
//!
//! \since Release: 560
//!
//! \param [in]     pCommandList         DX command list
//! \param [in]     pParams              API parameters
//!
//! \return This API can return any of the error codes enumerated in #NvAPI_Status.
//!         If there are return error codes with specific meaning for this API, they are listed below.
//!
//! \retval ::NVAPI_OK                   Completed request
//! \retval ::NVAPI_INVALID_POINTER      A null pointer was passed as command list, pParams or a required field within the pParams argument
//! \retval ::NVAPI_INVALID_ARGUMENT     The pParams parameter was set in an invalid way
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D12_RaytracingExecuteMultiIndirectClusterOperation(
    __in ID3D12GraphicsCommandList4* pCommandList,
    __in const NVAPI_RAYTRACING_EXECUTE_MULTI_INDIRECT_CLUSTER_OPERATION_PARAMS* pParams);

//! Enumeration listing permitted flag values for NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_INPUTS
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_FLAGS
{
    NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_FLAG_NONE                         = 0x0,        //!< No option specified for the the partitioned TLAS
    NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_FLAG_FAST_TRACE                   = NV_BIT(0),  //!< Optimize the Partitioned TLAS for fast trace performance, mutually exclusive with NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_FLAG_FAST_BUILD
    NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_FLAG_FAST_BUILD                   = NV_BIT(1),  //!< Optimize the Partitioned TLAS for fast update/build performance, mutually exclusive with NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_FLAG_FAST_TRACE
    NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_FLAG_ENABLE_PARTITION_TRANSLATION = NV_BIT(2),  //!< Enable the partition translation feature of the Partitioned TLAS
} NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_FLAGS;

//! Inputs describing the configuration of a Partitioned TLAS, used to determine the memory requirement structure and updates
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_INPUTS
{
    NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_FLAGS                           flags;                             //!< See NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_FLAGS
    NvU32                                                                   instanceCount;                     //!< The instance count of the Partitioned TLAS. Maximum supported value is 2^24.
    NvU32                                                                   maxInstancePerPartitionCount;      //!< The maximum number of instances that will ever be referenced by any single partition (excluding the global partition) of the Partitioned TLAS. Maximum supported value is 2^24.
    NvU32                                                                   partitionCount;                    //!< The number of partitions of the Partitioned TLAS. Maximum supported value is 2^24.
    NvU32                                                                   maxInstanceInGlobalPartitionCount; //!< The maximum number of instances that will ever be referenced by the global partition of the Partitioned TLAS. Maximum supported value is 2^24.
} NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_INPUTS;

//! Structure describing the memory requirement of a Partitioned TLAS
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_PREBUILD_INFO
{
    NvU64 resultDataMaxSizeInBytes; //!< Size of the resulting Partitioned TLAS in bytes based on the specified inputs
    NvU64 scratchDataSizeInBytes;   //!< Scratch storage on GPU required during builds/updates of the Partitioned TLAS based on the specified inputs
} NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_PREBUILD_INFO;

//! Parameter structure for NvAPI_D3D12_GetRaytracingPartitionedTlasIndirectPrebuildInfo
//!
//! \ingroup dx
typedef struct _NVAPI_GET_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_PREBUILD_INFO_PARAMS_V1
{
    NvU32                                                                 version; //!< [in]  Structure version; it should be set to #NVAPI_GET_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_PREBUILD_INFO_PARAMS_VER.
    const NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_INPUTS*  pInput;  //!< [in]  Description of the partitioned TLAS build
    NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_PREBUILD_INFO* pInfo;   //!< [out] Result of the query.
} NVAPI_GET_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_PREBUILD_INFO_PARAMS_V1;
#define NVAPI_GET_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_PREBUILD_INFO_PARAMS_VER1          MAKE_NVAPI_VERSION(NVAPI_GET_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_PREBUILD_INFO_PARAMS_V1, 1)
typedef NVAPI_GET_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_PREBUILD_INFO_PARAMS_V1            NVAPI_GET_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_PREBUILD_INFO_PARAMS;
#define NVAPI_GET_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_PREBUILD_INFO_PARAMS_VER           NVAPI_GET_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_PREBUILD_INFO_PARAMS_VER1

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D12_GetRaytracingPartitionedTlasIndirectPrebuildInfo
//
//! DESCRIPTION: Function call used to determine the memory requirements for a Partitioned TLAS
//!
//! SUPPORTED OS:  Windows 10 and higher
//!
//!
//! \since Release: 560
//!
//! \param [in]     pDevice              The D3D device that will own the Partitioned TLAS
//! \param [in,out] pParams              API parameters
//!
//! \return This API can return any of the error codes enumerated in #NvAPI_Status.
//!         If there are return error codes with specific meaning for this API, they are listed below.
//!
//! \retval ::NVAPI_OK                   Completed request
//! \retval ::NVAPI_INVALID_POINTER      A null pointer was passed as device or pParams argument
//! \retval ::NVAPI_INVALID_ARGUMENT     The pParams parameter was set in an invalid way
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D12_GetRaytracingPartitionedTlasIndirectPrebuildInfo(
    __in    ID3D12Device5* pDevice,
    __inout const NVAPI_GET_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_PREBUILD_INFO_PARAMS* pParams);

//! Enumeration listing permitted instance flag values for NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_OP_ARG_WRITE_INSTANCE
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_INSTANCE_FLAGS
{
    NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_INSTANCE_FLAG_NONE                            = 0x0,        //!< [in] No options specified.
    NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_INSTANCE_FLAG_TRIANGLE_CULL_DISABLE           = NV_BIT(0),  //!< [in] Identical to D3D12_RAYTRACING_INSTANCE_FLAG_TRIANGLE_CULL_DISABLE
    NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_INSTANCE_FLAG_TRIANGLE_FRONT_COUNTERCLOCKWISE = NV_BIT(1),  //!< [in] Identical to D3D12_RAYTRACING_INSTANCE_FLAG_TRIANGLE_FRONT_COUNTERCLOCKWISE
    NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_INSTANCE_FLAG_FORCE_OPAQUE                    = NV_BIT(2),  //!< [in] Identical to D3D12_RAYTRACING_INSTANCE_FLAG_FORCE_OPAQUE
    NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_INSTANCE_FLAG_FORCE_NON_OPAQUE                = NV_BIT(3),  //!< [in] Identical to D3D12_RAYTRACING_INSTANCE_FLAG_FORCE_NON_OPAQUE
    NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_INSTANCE_FLAG_ENABLE_EXPLICIT_AABB            = NV_BIT(4),  //!< [in] Enables the usage of explicitly provided partition-space (if partition translation is enabled) or world-space bounds, reduces cost of NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_OP_UPDATE_PARTITION for affected instances
} NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_INSTANCE_FLAGS;

//! Enumeration listing special reserved values for partition indices
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_PARTITION_INDEX
{
    NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_PARTITION_INDEX_GLOBAL_PARTITION  = 0xffffffff, //!< [in] Used to select the global partition for a partition write operation
} NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_PARTITION_INDEX;

//! Type determining what the type of an operation to apply to a partitioned TLAS, determines which argument structure is used
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_OP_TYPE
{
    NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_OP_WRITE_INSTANCE   = 0, //!< [in] Write instance data, use with NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_OP_ARG_WRITE_INSTANCE
    NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_OP_UPDATE_INSTANCE  = 1, //!< [in] Update instance data, use with NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_OP_ARG_UPDATE_INSTANCE
    NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_OP_WRITE_PARTITION  = 2, //!< [in] Write partition data, use with NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_OP_ARG_WRITE_PARTITION
} NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_OP_TYPE;

//! Argument structure for operation type NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_OP_WRITE_INSTANCE
//!
//! \ingroup dx
struct NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_OP_ARG_WRITE_INSTANCE
{
    NvF32                      transform[3][4];                          //!< [in] Identical to Transform in D3D12_RAYTRACING_INSTANCE_DESC, except if set to all zero or if any value is NaN the instance is considered degenerate and will not be added to the resulting accelerations structure.
    NvF32                      userAABB[6];                              //!< [in] 6 floating point values representing the min/max bounds of a world or partition space bounds of the vertices of the acceleration structure, ignored if NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_INSTANCE_FLAG_ENABLE_EXPLICIT_AABB is not set
    NvU32                      instanceID;                               //!< [in] Identical to InstanceID in D3D12_RAYTRACING_INSTANCE_DESC
    NvU32                      instanceMask;                             //!< [in] Identical to InstanceMask in D3D12_RAYTRACING_INSTANCE_DESC
    NvU32                      instanceContributionToHitGroupIndex;      //!< [in] Identical to InstanceContributionToHitGroupIndex in D3D12_RAYTRACING_INSTANCE_DESC
    NvU32                      instanceFlags;                            //!< [in] See NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_INSTANCE_FLAGS
    NvU32                      instanceIndex;                            //!< [in] Select which instance to write with this argument struct, must be less than the instanceCount of the Partitioned TLAS. Each partition index may only be referenced by one instance write or update argument for each build call.
    NvU32                      partitionIndex;                           //!< [in] Select the partition the instance is part of. Must be less than the partitionCount of the Partitioned TLAS.
    D3D12_GPU_VIRTUAL_ADDRESS  accelerationStructure;                    //!< [in] Acceleration structure to set, see AccelerationStructure in D3D12_RAYTRACING_INSTANCE_DESC. If NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_INSTANCE_FLAG_ENABLE_EXPLICIT_AABB was used, the existing bounds must cover the assigned acceleration structure (after transform is applied)
                                                                         //!< When NULL the instance is inactive but still included in the build, it will not participate in any trace operations but may become active again when a non-NULL accelerationStructure is assigned to it.
};

//! Argument structure for operation type NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_OP_UPDATE_INSTANCE
//!
//! \ingroup dx
struct NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_OP_ARG_UPDATE_INSTANCE
{
    NvU32                      instanceIndex;                            //!< [in] Select which instance to update with this argument struct, must be less than the instanceCount of the Partitioned TLAS. Each partition index may only be referenced by one instance write or update argument for each build call.
    NvU32                      instanceContributionToHitGroupIndex;      //!< [in] Identical to InstanceContributionToHitGroupIndex in D3D12_RAYTRACING_INSTANCE_DESC
    D3D12_GPU_VIRTUAL_ADDRESS  accelerationStructure;                    //!< [in] New acceleration structure to set, see AccelerationStructure in D3D12_RAYTRACING_INSTANCE_DESC. If NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_INSTANCE_FLAG_ENABLE_EXPLICIT_AABB was used, the existing bounds must cover the newly assigned acceleration structure (after transform is applied)
                                                                         //!< When NULL the instance is inactive but still included in the build, it will not participate in any trace operations but may become active again when a non-NULL accelerationStructure is assigned to it.
};

//! Argument structure for operation type NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_OP_WRITE_PARTITION
//!
//! \ingroup dx
typedef struct NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_OP_ARG_WRITE_PARTITION
{
    NvU32                                partitionIndex;          //!< [in] Select which partition to write with this argument struct, must be either less than partition count or equal to NVAPI_D3D12_RAYTRACING_PARTITIONED_TLAS_PARTITION_INDEX_GLOBAL_PARTITION. Each partition index may only be referenced by one argument for each build call.
    NvF32                                partitionTranslation[3]; //!< [in] The partition translation, all instances within this partition are translated by the X, Y, Z coordinates provided by this vector
} NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_OP_ARG_WRITE_PARTITION;

//! Describes an individual operation described by a type and array of parameters to apply as a modification to a Partitioned TLAS
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_OP
{
    NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_OP_TYPE  type;   //!< [in] Identify the type of operation to apply, determines the type of the array referenced by data. See NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_OP_TYPE. Each type may only be referenced once by each call to NvAPI_D3D12_BuildRaytracingPartitionedTlasIndirect
    NvU32                                                  count;  //!< [in] The number of elements of the argument array referenced by data
    D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE                   data;   //!< [in] The address and stride of a device array of argument structures determined by type. Must be aligned based on C structure alignment requirements of the referenced structure.
} NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_OP;

//! Describes the parameters for building a Partitioned TLAS
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_DESC
{
    NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_INPUTS      inputs;                           //!< [in] The inputs previously used with NvAPI_D3D12_GetRaytracingPartitionedTlasIndirectPrebuildInfo to determine the memory requirement for the Partitioned TLAS
    D3D12_GPU_VIRTUAL_ADDRESS                                          srcAccelerationStructureData;     //!< [in] Either 0 to construct a new Partitioned TLAS or the pointer to a previously constructed Partitioned TLAS, all its content will be inherited. If set, must be in state D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE and aligned to D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BYTE_ALIGNMENT.
    D3D12_GPU_VIRTUAL_ADDRESS                                          destAccelerationStructureData;    //!< [in] The destination address to construct the new Partitioned TLAS, if it overlaps with the srcAccelerationStructureData address, the previous Partitioned TLAS will become invalid. Must have enough memory as determined by NvAPI_D3D12_GetRaytracingPartitionedTlasIndirectPrebuildInfo. Must be in state D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE and aligned to D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BYTE_ALIGNMENT.
    D3D12_GPU_VIRTUAL_ADDRESS                                          scratchAccelerationStructureData; //!< [in] Address of scratch memory used during the build call, size must be determined by NvAPI_D3D12_GetRaytracingPartitionedTlasIndirectPrebuildInfo. Must be in state D3D12_RESOURCE_STATE_UNORDERED_ACCESS and aligned to D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BYTE_ALIGNMENT.
    D3D12_GPU_VIRTUAL_ADDRESS                                          indirectOpCount;                  //!< [in] Address of device memory containing the 32-bit unsigned integer containing the size of the indirectOps array. The memory pointed to must be in state D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE.
    D3D12_GPU_VIRTUAL_ADDRESS                                          indirectOps;                      //!< [in] Address of device memory containing the array of NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_OP with size equal to the value referenced by indirectOpCount. The memory pointed to must be in state D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE.
} NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_DESC; 

//! Parameters given to NvAPI_D3D12_BuildRaytracingPartitionedTlasIndirect().
//!
//! \ingroup dx
typedef struct _NVAPI_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_PARAMS_V1
{
    NvU32                                                                              version;               //!< [in] Structure version; it should be set to #NVAPI_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_PARAMS_VER.
    const NVAPI_D3D12_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_DESC*                 pDesc;                 //!< [in] Description of the Partitioned TLAS build.
} NVAPI_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_PARAMS_V1;
#define NVAPI_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_PARAMS_VER1          MAKE_NVAPI_VERSION(NVAPI_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_PARAMS_V1, 1)
typedef NVAPI_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_PARAMS_V1            NVAPI_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_PARAMS;
#define NVAPI_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_PARAMS_VER           NVAPI_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_PARAMS_VER1

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTION NAME: NvAPI_D3D12_BuildRaytracingPartitionedTlasIndirect
//
//! DESCRIPTION: Builds a Partitioned TLAS
//!              The CPU-side input buffers are not referenced after this call.
//!              The GPU-side input resources are not referenced after the build has concluded after <tt>ExecuteCommandList()</tt>.
//!
//! SUPPORTED OS:  Windows 10 and higher
//!
//!
//! \since Release: 560
//!
//! \param [in]     pCommandList         DX command list
//! \param [in]     pParams              API parameters
//!
//! \return This API can return any of the error codes enumerated in #NvAPI_Status.
//!         If there are return error codes with specific meaning for this API, they are listed below.
//!
//! \retval ::NVAPI_OK                   Completed request
//! \retval ::NVAPI_INVALID_POINTER      A null pointer was passed as command list or pParams argument
//! \retval ::NVAPI_INVALID_ARGUMENT     The pParams parameter was set in an invalid way
//! \ingroup dx
///////////////////////////////////////////////////////////////////////////////
NVAPI_INTERFACE NvAPI_D3D12_BuildRaytracingPartitionedTlasIndirect(
    __in ID3D12GraphicsCommandList4* pCommandList,
    __in const NVAPI_BUILD_RAYTRACING_PARTITIONED_TLAS_INDIRECT_PARAMS* pParams);

#endif // defined(__cplusplus) && defined(__d3d12_h__) && defined(__ID3D12Device5_INTERFACE_DEFINED__)

#undef __cplusplus
#undef __d3d12_h__

#include"nvapi_lite_salend.h"
#ifdef __cplusplus
}
#endif
#pragma pack(pop)