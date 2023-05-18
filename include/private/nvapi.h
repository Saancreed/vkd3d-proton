/*********************************************************************************************************\
|*                                                                                                        *|
|* SPDX-FileCopyrightText: Copyright (c) 2019-2026 NVIDIA CORPORATION & AFFILIATES. All rights reserved.  *|
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
#elif defined(__clang__)
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

#define NVAPI_SDK_VERSION 61050
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

#define NVAPI_UUID_LEN                      16 

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