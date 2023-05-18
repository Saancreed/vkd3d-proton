/*****************************************************************************\
|*                                                                             *|
|* Copyright (c) 2019-2022, NVIDIA CORPORATION. All rights reserved.           *|
|*                                                                             *|
|* Permission is hereby granted, free of charge, to any person obtaining a     *|
|* copy of this software and associated documentation files (the "Software"),  *|
|* to deal in the Software without restriction, including without limitation   *|
|* the rights to use, copy, modify, merge, publish, distribute, sublicense,    *|
|* and/or sell copies of the Software, and to permit persons to whom the       *|
|* Software is furnished to do so, subject to the following conditions:        *|
|*                                                                             *|
|* The above copyright notice and this permission notice shall be included in  *|
|* all copies or substantial portions of the Software.                         *|
|*                                                                             *|
|* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  *|
|* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,    *|
|* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL    *|
|* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  *|
|* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING     *| 
|* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER         *|
|* DEALINGS IN THE SOFTWARE.                                                   *|
|*                                                                             *|
|*                                                                             *|
\*****************************************************************************/
///////////////////////////////////////////////////////////////////////////////
//
// Date: Feb 27, 2023 
// File: nvapi.h
//
// NvAPI provides an interface to NVIDIA devices. This file contains the 
// interface constants, structure definitions and function prototypes.
//
//   Target Profile: Open-Source
//  Target Platform: windows
//
///////////////////////////////////////////////////////////////////////////////
#ifndef _NVAPI_H
#define _NVAPI_H

#include "vkd3d_d3d12.h"

#pragma pack(push,8) // Make sure we have consistent structure packings

#ifdef __cplusplus
extern "C" {
#endif
// ====================================================
// Universal NvAPI Definitions
// ====================================================
#ifndef _WIN32
#define __cdecl
#endif

// ====================================================
// SAL related support
// ====================================================

#ifndef __ecount
    #define __nvapi_undef__ecount
    #define __ecount(size)
#endif
#ifndef __bcount
    #define __nvapi_undef__bcount
    #define __bcount(size)
#endif
#ifndef __in
    #define __nvapi_undef__in
    #define __in
#endif
#ifndef __in_ecount
    #define __nvapi_undef__in_ecount
    #define __in_ecount(size)
#endif
#ifndef __in_bcount
    #define __nvapi_undef__in_bcount
    #define __in_bcount(size)
#endif
#ifndef __in_z
    #define __nvapi_undef__in_z
    #define __in_z
#endif
#ifndef __in_ecount_z
    #define __nvapi_undef__in_ecount_z
    #define __in_ecount_z(size)
#endif
#ifndef __in_bcount_z
    #define __nvapi_undef__in_bcount_z
    #define __in_bcount_z(size)
#endif
#ifndef __in_nz
    #define __nvapi_undef__in_nz
    #define __in_nz
#endif
#ifndef __in_ecount_nz
    #define __nvapi_undef__in_ecount_nz
    #define __in_ecount_nz(size)
#endif
#ifndef __in_bcount_nz
    #define __nvapi_undef__in_bcount_nz
    #define __in_bcount_nz(size)
#endif
#ifndef __out
    #define __nvapi_undef__out
    #define __out
#endif
#ifndef __out_ecount
    #define __nvapi_undef__out_ecount
    #define __out_ecount(size)
#endif
#ifndef __out_bcount
    #define __nvapi_undef__out_bcount
    #define __out_bcount(size)
#endif
#ifndef __out_ecount_part
    #define __nvapi_undef__out_ecount_part
    #define __out_ecount_part(size,length)
#endif
#ifndef __out_bcount_part
    #define __nvapi_undef__out_bcount_part
    #define __out_bcount_part(size,length)
#endif
#ifndef __out_ecount_full
    #define __nvapi_undef__out_ecount_full
    #define __out_ecount_full(size)
#endif
#ifndef __out_bcount_full
    #define __nvapi_undef__out_bcount_full
    #define __out_bcount_full(size)
#endif
#ifndef __out_z
    #define __nvapi_undef__out_z
    #define __out_z
#endif
#ifndef __out_z_opt
    #define __nvapi_undef__out_z_opt
    #define __out_z_opt
#endif
#ifndef __out_ecount_z
    #define __nvapi_undef__out_ecount_z
    #define __out_ecount_z(size)
#endif
#ifndef __out_bcount_z
    #define __nvapi_undef__out_bcount_z
    #define __out_bcount_z(size)
#endif
#ifndef __out_ecount_part_z
    #define __nvapi_undef__out_ecount_part_z
    #define __out_ecount_part_z(size,length)
#endif
#ifndef __out_bcount_part_z
    #define __nvapi_undef__out_bcount_part_z
    #define __out_bcount_part_z(size,length)
#endif
#ifndef __out_ecount_full_z
    #define __nvapi_undef__out_ecount_full_z
    #define __out_ecount_full_z(size)
#endif
#ifndef __out_bcount_full_z
    #define __nvapi_undef__out_bcount_full_z
    #define __out_bcount_full_z(size)
#endif
#ifndef __out_nz
    #define __nvapi_undef__out_nz
    #define __out_nz
#endif
#ifndef __out_nz_opt
    #define __nvapi_undef__out_nz_opt
    #define __out_nz_opt
#endif
#ifndef __out_ecount_nz
    #define __nvapi_undef__out_ecount_nz
    #define __out_ecount_nz(size)
#endif
#ifndef __out_bcount_nz
    #define __nvapi_undef__out_bcount_nz
    #define __out_bcount_nz(size)
#endif
#ifndef __inout
    #define __nvapi_undef__inout
    #define __inout
#endif
#ifndef __inout_ecount
    #define __nvapi_undef__inout_ecount
    #define __inout_ecount(size)
#endif
#ifndef __inout_bcount
    #define __nvapi_undef__inout_bcount
    #define __inout_bcount(size)
#endif
#ifndef __inout_ecount_part
    #define __nvapi_undef__inout_ecount_part
    #define __inout_ecount_part(size,length)
#endif
#ifndef __inout_bcount_part
    #define __nvapi_undef__inout_bcount_part
    #define __inout_bcount_part(size,length)
#endif
#ifndef __inout_ecount_full
    #define __nvapi_undef__inout_ecount_full
    #define __inout_ecount_full(size)
#endif
#ifndef __inout_bcount_full
    #define __nvapi_undef__inout_bcount_full
    #define __inout_bcount_full(size)
#endif
#ifndef __inout_z
    #define __nvapi_undef__inout_z
    #define __inout_z
#endif
#ifndef __inout_ecount_z
    #define __nvapi_undef__inout_ecount_z
    #define __inout_ecount_z(size)
#endif
#ifndef __inout_bcount_z
    #define __nvapi_undef__inout_bcount_z
    #define __inout_bcount_z(size)
#endif
#ifndef __inout_nz
    #define __nvapi_undef__inout_nz
    #define __inout_nz
#endif
#ifndef __inout_ecount_nz
    #define __nvapi_undef__inout_ecount_nz
    #define __inout_ecount_nz(size)
#endif
#ifndef __inout_bcount_nz
    #define __nvapi_undef__inout_bcount_nz
    #define __inout_bcount_nz(size)
#endif
#ifndef __ecount_opt
    #define __nvapi_undef__ecount_opt
    #define __ecount_opt(size)
#endif
#ifndef __bcount_opt
    #define __nvapi_undef__bcount_opt
    #define __bcount_opt(size)
#endif
#ifndef __in_opt
    #define __nvapi_undef__in_opt
    #define __in_opt
#endif
#ifndef __in_ecount_opt
    #define __nvapi_undef__in_ecount_opt
    #define __in_ecount_opt(size)
#endif
#ifndef __in_bcount_opt
    #define __nvapi_undef__in_bcount_opt
    #define __in_bcount_opt(size)
#endif
#ifndef __in_z_opt
    #define __nvapi_undef__in_z_opt
    #define __in_z_opt
#endif
#ifndef __in_ecount_z_opt
    #define __nvapi_undef__in_ecount_z_opt
    #define __in_ecount_z_opt(size)
#endif
#ifndef __in_bcount_z_opt
    #define __nvapi_undef__in_bcount_z_opt
    #define __in_bcount_z_opt(size)
#endif
#ifndef __in_nz_opt
    #define __nvapi_undef__in_nz_opt
    #define __in_nz_opt
#endif
#ifndef __in_ecount_nz_opt
    #define __nvapi_undef__in_ecount_nz_opt
    #define __in_ecount_nz_opt(size)
#endif
#ifndef __in_bcount_nz_opt
    #define __nvapi_undef__in_bcount_nz_opt
    #define __in_bcount_nz_opt(size)
#endif
#ifndef __out_opt
    #define __nvapi_undef__out_opt
    #define __out_opt
#endif
#ifndef __out_ecount_opt
    #define __nvapi_undef__out_ecount_opt
    #define __out_ecount_opt(size)
#endif
#ifndef __out_bcount_opt
    #define __nvapi_undef__out_bcount_opt
    #define __out_bcount_opt(size)
#endif
#ifndef __out_ecount_part_opt
    #define __nvapi_undef__out_ecount_part_opt
    #define __out_ecount_part_opt(size,length)
#endif
#ifndef __out_bcount_part_opt
    #define __nvapi_undef__out_bcount_part_opt
    #define __out_bcount_part_opt(size,length)
#endif
#ifndef __out_ecount_full_opt
    #define __nvapi_undef__out_ecount_full_opt
    #define __out_ecount_full_opt(size)
#endif
#ifndef __out_bcount_full_opt
    #define __nvapi_undef__out_bcount_full_opt
    #define __out_bcount_full_opt(size)
#endif
#ifndef __out_ecount_z_opt
    #define __nvapi_undef__out_ecount_z_opt
    #define __out_ecount_z_opt(size)
#endif
#ifndef __out_bcount_z_opt
    #define __nvapi_undef__out_bcount_z_opt
    #define __out_bcount_z_opt(size)
#endif
#ifndef __out_ecount_part_z_opt
    #define __nvapi_undef__out_ecount_part_z_opt
    #define __out_ecount_part_z_opt(size,length)
#endif
#ifndef __out_bcount_part_z_opt
    #define __nvapi_undef__out_bcount_part_z_opt
    #define __out_bcount_part_z_opt(size,length)
#endif
#ifndef __out_ecount_full_z_opt
    #define __nvapi_undef__out_ecount_full_z_opt
    #define __out_ecount_full_z_opt(size)
#endif
#ifndef __out_bcount_full_z_opt
    #define __nvapi_undef__out_bcount_full_z_opt
    #define __out_bcount_full_z_opt(size)
#endif
#ifndef __out_ecount_nz_opt
    #define __nvapi_undef__out_ecount_nz_opt
    #define __out_ecount_nz_opt(size)
#endif
#ifndef __out_bcount_nz_opt
    #define __nvapi_undef__out_bcount_nz_opt
    #define __out_bcount_nz_opt(size)
#endif
#ifndef __inout_opt
    #define __nvapi_undef__inout_opt
    #define __inout_opt
#endif
#ifndef __inout_ecount_opt
    #define __nvapi_undef__inout_ecount_opt
    #define __inout_ecount_opt(size)
#endif
#ifndef __inout_bcount_opt
    #define __nvapi_undef__inout_bcount_opt
    #define __inout_bcount_opt(size)
#endif
#ifndef __inout_ecount_part_opt
    #define __nvapi_undef__inout_ecount_part_opt
    #define __inout_ecount_part_opt(size,length)
#endif
#ifndef __inout_bcount_part_opt
    #define __nvapi_undef__inout_bcount_part_opt
    #define __inout_bcount_part_opt(size,length)
#endif
#ifndef __inout_ecount_full_opt
    #define __nvapi_undef__inout_ecount_full_opt
    #define __inout_ecount_full_opt(size)
#endif
#ifndef __inout_bcount_full_opt
    #define __nvapi_undef__inout_bcount_full_opt
    #define __inout_bcount_full_opt(size)
#endif
#ifndef __inout_z_opt
    #define __nvapi_undef__inout_z_opt
    #define __inout_z_opt
#endif
#ifndef __inout_ecount_z_opt
    #define __nvapi_undef__inout_ecount_z_opt
    #define __inout_ecount_z_opt(size)
#endif
#ifndef __inout_ecount_z_opt
    #define __nvapi_undef__inout_ecount_z_opt
    #define __inout_ecount_z_opt(size)
#endif
#ifndef __inout_bcount_z_opt
    #define __nvapi_undef__inout_bcount_z_opt
    #define __inout_bcount_z_opt(size)
#endif
#ifndef __inout_nz_opt
    #define __nvapi_undef__inout_nz_opt
    #define __inout_nz_opt
#endif
#ifndef __inout_ecount_nz_opt
    #define __nvapi_undef__inout_ecount_nz_opt
    #define __inout_ecount_nz_opt(size)
#endif
#ifndef __inout_bcount_nz_opt
    #define __nvapi_undef__inout_bcount_nz_opt
    #define __inout_bcount_nz_opt(size)
#endif
#ifndef __deref_ecount
    #define __nvapi_undef__deref_ecount
    #define __deref_ecount(size)
#endif
#ifndef __deref_bcount
    #define __nvapi_undef__deref_bcount
    #define __deref_bcount(size)
#endif
#ifndef __deref_out
    #define __nvapi_undef__deref_out
    #define __deref_out
#endif
#ifndef __deref_out_ecount
    #define __nvapi_undef__deref_out_ecount
    #define __deref_out_ecount(size)
#endif
#ifndef __deref_out_bcount
    #define __nvapi_undef__deref_out_bcount
    #define __deref_out_bcount(size)
#endif
#ifndef __deref_out_ecount_part
    #define __nvapi_undef__deref_out_ecount_part
    #define __deref_out_ecount_part(size,length)
#endif
#ifndef __deref_out_bcount_part
    #define __nvapi_undef__deref_out_bcount_part
    #define __deref_out_bcount_part(size,length)
#endif
#ifndef __deref_out_ecount_full
    #define __nvapi_undef__deref_out_ecount_full
    #define __deref_out_ecount_full(size)
#endif
#ifndef __deref_out_bcount_full
    #define __nvapi_undef__deref_out_bcount_full
    #define __deref_out_bcount_full(size)
#endif
#ifndef __deref_out_z
    #define __nvapi_undef__deref_out_z
    #define __deref_out_z
#endif
#ifndef __deref_out_ecount_z
    #define __nvapi_undef__deref_out_ecount_z
    #define __deref_out_ecount_z(size)
#endif
#ifndef __deref_out_bcount_z
    #define __nvapi_undef__deref_out_bcount_z
    #define __deref_out_bcount_z(size)
#endif
#ifndef __deref_out_nz
    #define __nvapi_undef__deref_out_nz
    #define __deref_out_nz
#endif
#ifndef __deref_out_ecount_nz
    #define __nvapi_undef__deref_out_ecount_nz
    #define __deref_out_ecount_nz(size)
#endif
#ifndef __deref_out_bcount_nz
    #define __nvapi_undef__deref_out_bcount_nz
    #define __deref_out_bcount_nz(size)
#endif
#ifndef __deref_inout
    #define __nvapi_undef__deref_inout
    #define __deref_inout
#endif
#ifndef __deref_inout_z
    #define __nvapi_undef__deref_inout_z
    #define __deref_inout_z
#endif
#ifndef __deref_inout_ecount
    #define __nvapi_undef__deref_inout_ecount
    #define __deref_inout_ecount(size)
#endif
#ifndef __deref_inout_bcount
    #define __nvapi_undef__deref_inout_bcount
    #define __deref_inout_bcount(size)
#endif
#ifndef __deref_inout_ecount_part
    #define __nvapi_undef__deref_inout_ecount_part
    #define __deref_inout_ecount_part(size,length)
#endif
#ifndef __deref_inout_bcount_part
    #define __nvapi_undef__deref_inout_bcount_part
    #define __deref_inout_bcount_part(size,length)
#endif
#ifndef __deref_inout_ecount_full
    #define __nvapi_undef__deref_inout_ecount_full
    #define __deref_inout_ecount_full(size)
#endif
#ifndef __deref_inout_bcount_full
    #define __nvapi_undef__deref_inout_bcount_full
    #define __deref_inout_bcount_full(size)
#endif
#ifndef __deref_inout_z
    #define __nvapi_undef__deref_inout_z
    #define __deref_inout_z
#endif
#ifndef __deref_inout_ecount_z
    #define __nvapi_undef__deref_inout_ecount_z
    #define __deref_inout_ecount_z(size)
#endif
#ifndef __deref_inout_bcount_z
    #define __nvapi_undef__deref_inout_bcount_z
    #define __deref_inout_bcount_z(size)
#endif
#ifndef __deref_inout_nz
    #define __nvapi_undef__deref_inout_nz
    #define __deref_inout_nz
#endif
#ifndef __deref_inout_ecount_nz
    #define __nvapi_undef__deref_inout_ecount_nz
    #define __deref_inout_ecount_nz(size)
#endif
#ifndef __deref_inout_bcount_nz
    #define __nvapi_undef__deref_inout_bcount_nz
    #define __deref_inout_bcount_nz(size)
#endif
#ifndef __deref_ecount_opt
    #define __nvapi_undef__deref_ecount_opt
    #define __deref_ecount_opt(size)
#endif
#ifndef __deref_bcount_opt
    #define __nvapi_undef__deref_bcount_opt
    #define __deref_bcount_opt(size)
#endif
#ifndef __deref_out_opt
    #define __nvapi_undef__deref_out_opt
    #define __deref_out_opt
#endif
#ifndef __deref_out_ecount_opt
    #define __nvapi_undef__deref_out_ecount_opt
    #define __deref_out_ecount_opt(size)
#endif
#ifndef __deref_out_bcount_opt
    #define __nvapi_undef__deref_out_bcount_opt
    #define __deref_out_bcount_opt(size)
#endif
#ifndef __deref_out_ecount_part_opt
    #define __nvapi_undef__deref_out_ecount_part_opt
    #define __deref_out_ecount_part_opt(size,length)
#endif
#ifndef __deref_out_bcount_part_opt
    #define __nvapi_undef__deref_out_bcount_part_opt
    #define __deref_out_bcount_part_opt(size,length)
#endif
#ifndef __deref_out_ecount_full_opt
    #define __nvapi_undef__deref_out_ecount_full_opt
    #define __deref_out_ecount_full_opt(size)
#endif
#ifndef __deref_out_bcount_full_opt
    #define __nvapi_undef__deref_out_bcount_full_opt
    #define __deref_out_bcount_full_opt(size)
#endif
#ifndef __deref_out_z_opt
    #define __nvapi_undef__deref_out_z_opt
    #define __deref_out_z_opt
#endif
#ifndef __deref_out_ecount_z_opt
    #define __nvapi_undef__deref_out_ecount_z_opt
    #define __deref_out_ecount_z_opt(size)
#endif
#ifndef __deref_out_bcount_z_opt
    #define __nvapi_undef__deref_out_bcount_z_opt
    #define __deref_out_bcount_z_opt(size)
#endif
#ifndef __deref_out_nz_opt
    #define __nvapi_undef__deref_out_nz_opt
    #define __deref_out_nz_opt
#endif
#ifndef __deref_out_ecount_nz_opt
    #define __nvapi_undef__deref_out_ecount_nz_opt
    #define __deref_out_ecount_nz_opt(size)
#endif
#ifndef __deref_out_bcount_nz_opt
    #define __nvapi_undef__deref_out_bcount_nz_opt
    #define __deref_out_bcount_nz_opt(size)
#endif
#ifndef __deref_inout_opt
    #define __nvapi_undef__deref_inout_opt
    #define __deref_inout_opt
#endif
#ifndef __deref_inout_ecount_opt
    #define __nvapi_undef__deref_inout_ecount_opt
    #define __deref_inout_ecount_opt(size)
#endif
#ifndef __deref_inout_bcount_opt
    #define __nvapi_undef__deref_inout_bcount_opt
    #define __deref_inout_bcount_opt(size)
#endif
#ifndef __deref_inout_ecount_part_opt
    #define __nvapi_undef__deref_inout_ecount_part_opt
    #define __deref_inout_ecount_part_opt(size,length)
#endif
#ifndef __deref_inout_bcount_part_opt
    #define __nvapi_undef__deref_inout_bcount_part_opt
    #define __deref_inout_bcount_part_opt(size,length)
#endif
#ifndef __deref_inout_ecount_full_opt
    #define __nvapi_undef__deref_inout_ecount_full_opt
    #define __deref_inout_ecount_full_opt(size)
#endif
#ifndef __deref_inout_bcount_full_opt
    #define __nvapi_undef__deref_inout_bcount_full_opt
    #define __deref_inout_bcount_full_opt(size)
#endif
#ifndef __deref_inout_z_opt
    #define __nvapi_undef__deref_inout_z_opt
    #define __deref_inout_z_opt
#endif
#ifndef __deref_inout_ecount_z_opt
    #define __nvapi_undef__deref_inout_ecount_z_opt
    #define __deref_inout_ecount_z_opt(size)
#endif
#ifndef __deref_inout_bcount_z_opt
    #define __nvapi_undef__deref_inout_bcount_z_opt
    #define __deref_inout_bcount_z_opt(size)
#endif
#ifndef __deref_inout_nz_opt
    #define __nvapi_undef__deref_inout_nz_opt
    #define __deref_inout_nz_opt
#endif
#ifndef __deref_inout_ecount_nz_opt
    #define __nvapi_undef__deref_inout_ecount_nz_opt
    #define __deref_inout_ecount_nz_opt(size)
#endif
#ifndef __deref_inout_bcount_nz_opt
    #define __nvapi_undef__deref_inout_bcount_nz_opt
    #define __deref_inout_bcount_nz_opt(size)
#endif
#ifndef __deref_opt_ecount
    #define __nvapi_undef__deref_opt_ecount
    #define __deref_opt_ecount(size)
#endif
#ifndef __deref_opt_bcount
    #define __nvapi_undef__deref_opt_bcount
    #define __deref_opt_bcount(size)
#endif
#ifndef __deref_opt_out
    #define __nvapi_undef__deref_opt_out
    #define __deref_opt_out
#endif
#ifndef __deref_opt_out_z
    #define __nvapi_undef__deref_opt_out_z
    #define __deref_opt_out_z
#endif
#ifndef __deref_opt_out_ecount
    #define __nvapi_undef__deref_opt_out_ecount
    #define __deref_opt_out_ecount(size)
#endif
#ifndef __deref_opt_out_bcount
    #define __nvapi_undef__deref_opt_out_bcount
    #define __deref_opt_out_bcount(size)
#endif
#ifndef __deref_opt_out_ecount_part
    #define __nvapi_undef__deref_opt_out_ecount_part
    #define __deref_opt_out_ecount_part(size,length)
#endif
#ifndef __deref_opt_out_bcount_part
    #define __nvapi_undef__deref_opt_out_bcount_part
    #define __deref_opt_out_bcount_part(size,length)
#endif
#ifndef __deref_opt_out_ecount_full
    #define __nvapi_undef__deref_opt_out_ecount_full
    #define __deref_opt_out_ecount_full(size)
#endif
#ifndef __deref_opt_out_bcount_full
    #define __nvapi_undef__deref_opt_out_bcount_full
    #define __deref_opt_out_bcount_full(size)
#endif
#ifndef __deref_opt_inout
    #define __nvapi_undef__deref_opt_inout
    #define __deref_opt_inout
#endif
#ifndef __deref_opt_inout_ecount
    #define __nvapi_undef__deref_opt_inout_ecount
    #define __deref_opt_inout_ecount(size)
#endif
#ifndef __deref_opt_inout_bcount
    #define __nvapi_undef__deref_opt_inout_bcount
    #define __deref_opt_inout_bcount(size)
#endif
#ifndef __deref_opt_inout_ecount_part
    #define __nvapi_undef__deref_opt_inout_ecount_part
    #define __deref_opt_inout_ecount_part(size,length)
#endif
#ifndef __deref_opt_inout_bcount_part
    #define __nvapi_undef__deref_opt_inout_bcount_part
    #define __deref_opt_inout_bcount_part(size,length)
#endif
#ifndef __deref_opt_inout_ecount_full
    #define __nvapi_undef__deref_opt_inout_ecount_full
    #define __deref_opt_inout_ecount_full(size)
#endif
#ifndef __deref_opt_inout_bcount_full
    #define __nvapi_undef__deref_opt_inout_bcount_full
    #define __deref_opt_inout_bcount_full(size)
#endif
#ifndef __deref_opt_inout_z
    #define __nvapi_undef__deref_opt_inout_z
    #define __deref_opt_inout_z
#endif
#ifndef __deref_opt_inout_ecount_z
    #define __nvapi_undef__deref_opt_inout_ecount_z
    #define __deref_opt_inout_ecount_z(size)
#endif
#ifndef __deref_opt_inout_bcount_z
    #define __nvapi_undef__deref_opt_inout_bcount_z
    #define __deref_opt_inout_bcount_z(size)
#endif
#ifndef __deref_opt_inout_nz
    #define __nvapi_undef__deref_opt_inout_nz
    #define __deref_opt_inout_nz
#endif
#ifndef __deref_opt_inout_ecount_nz
    #define __nvapi_undef__deref_opt_inout_ecount_nz
    #define __deref_opt_inout_ecount_nz(size)
#endif
#ifndef __deref_opt_inout_bcount_nz
    #define __nvapi_undef__deref_opt_inout_bcount_nz
    #define __deref_opt_inout_bcount_nz(size)
#endif
#ifndef __deref_opt_ecount_opt
    #define __nvapi_undef__deref_opt_ecount_opt
    #define __deref_opt_ecount_opt(size)
#endif
#ifndef __deref_opt_bcount_opt
    #define __nvapi_undef__deref_opt_bcount_opt
    #define __deref_opt_bcount_opt(size)
#endif
#ifndef __deref_opt_out_opt
    #define __nvapi_undef__deref_opt_out_opt
    #define __deref_opt_out_opt
#endif
#ifndef __deref_opt_out_ecount_opt
    #define __nvapi_undef__deref_opt_out_ecount_opt
    #define __deref_opt_out_ecount_opt(size)
#endif
#ifndef __deref_opt_out_bcount_opt
    #define __nvapi_undef__deref_opt_out_bcount_opt
    #define __deref_opt_out_bcount_opt(size)
#endif
#ifndef __deref_opt_out_ecount_part_opt
    #define __nvapi_undef__deref_opt_out_ecount_part_opt
    #define __deref_opt_out_ecount_part_opt(size,length)
#endif
#ifndef __deref_opt_out_bcount_part_opt
    #define __nvapi_undef__deref_opt_out_bcount_part_opt
    #define __deref_opt_out_bcount_part_opt(size,length)
#endif
#ifndef __deref_opt_out_ecount_full_opt
    #define __nvapi_undef__deref_opt_out_ecount_full_opt
    #define __deref_opt_out_ecount_full_opt(size)
#endif
#ifndef __deref_opt_out_bcount_full_opt
    #define __nvapi_undef__deref_opt_out_bcount_full_opt
    #define __deref_opt_out_bcount_full_opt(size)
#endif
#ifndef __deref_opt_out_z_opt
    #define __nvapi_undef__deref_opt_out_z_opt
    #define __deref_opt_out_z_opt
#endif
#ifndef __deref_opt_out_ecount_z_opt
    #define __nvapi_undef__deref_opt_out_ecount_z_opt
    #define __deref_opt_out_ecount_z_opt(size)
#endif
#ifndef __deref_opt_out_bcount_z_opt
    #define __nvapi_undef__deref_opt_out_bcount_z_opt
    #define __deref_opt_out_bcount_z_opt(size)
#endif
#ifndef __deref_opt_out_nz_opt
    #define __nvapi_undef__deref_opt_out_nz_opt
    #define __deref_opt_out_nz_opt
#endif
#ifndef __deref_opt_out_ecount_nz_opt
    #define __nvapi_undef__deref_opt_out_ecount_nz_opt
    #define __deref_opt_out_ecount_nz_opt(size)
#endif
#ifndef __deref_opt_out_bcount_nz_opt
    #define __nvapi_undef__deref_opt_out_bcount_nz_opt
    #define __deref_opt_out_bcount_nz_opt(size)
#endif
#ifndef __deref_opt_inout_opt
    #define __nvapi_undef__deref_opt_inout_opt
    #define __deref_opt_inout_opt
#endif
#ifndef __deref_opt_inout_ecount_opt
    #define __nvapi_undef__deref_opt_inout_ecount_opt
    #define __deref_opt_inout_ecount_opt(size)
#endif
#ifndef __deref_opt_inout_bcount_opt
    #define __nvapi_undef__deref_opt_inout_bcount_opt
    #define __deref_opt_inout_bcount_opt(size)
#endif
#ifndef __deref_opt_inout_ecount_part_opt
    #define __nvapi_undef__deref_opt_inout_ecount_part_opt
    #define __deref_opt_inout_ecount_part_opt(size,length)
#endif
#ifndef __deref_opt_inout_bcount_part_opt
    #define __nvapi_undef__deref_opt_inout_bcount_part_opt
    #define __deref_opt_inout_bcount_part_opt(size,length)
#endif
#ifndef __deref_opt_inout_ecount_full_opt
    #define __nvapi_undef__deref_opt_inout_ecount_full_opt
    #define __deref_opt_inout_ecount_full_opt(size)
#endif
#ifndef __deref_opt_inout_bcount_full_opt
    #define __nvapi_undef__deref_opt_inout_bcount_full_opt
    #define __deref_opt_inout_bcount_full_opt(size)
#endif
#ifndef __deref_opt_inout_z_opt
    #define __nvapi_undef__deref_opt_inout_z_opt
    #define __deref_opt_inout_z_opt
#endif
#ifndef __deref_opt_inout_ecount_z_opt
    #define __nvapi_undef__deref_opt_inout_ecount_z_opt
    #define __deref_opt_inout_ecount_z_opt(size)
#endif
#ifndef __deref_opt_inout_bcount_z_opt
    #define __nvapi_undef__deref_opt_inout_bcount_z_opt
    #define __deref_opt_inout_bcount_z_opt(size)
#endif
#ifndef __deref_opt_inout_nz_opt
    #define __nvapi_undef__deref_opt_inout_nz_opt
    #define __deref_opt_inout_nz_opt
#endif
#ifndef __deref_opt_inout_ecount_nz_opt
    #define __nvapi_undef__deref_opt_inout_ecount_nz_opt
    #define __deref_opt_inout_ecount_nz_opt(size)
#endif
#ifndef __deref_opt_inout_bcount_nz_opt
    #define __nvapi_undef__deref_opt_inout_bcount_nz_opt
    #define __deref_opt_inout_bcount_nz_opt(size)
#endif
#ifndef __success
    #define __nvapi_success
    #define __success(epxr)
#endif
#ifndef _Ret_notnull_
    #define __nvapi__Ret_notnull_
    #define _Ret_notnull_
#endif
#ifndef _Post_writable_byte_size_
    #define __nvapi__Post_writable_byte_size_
    #define _Post_writable_byte_size_(n)
#endif
#ifndef _Outptr_ 
    #define __nvapi_Outptr_ 
    #define _Outptr_ 
#endif


#define NVAPI_INTERFACE extern __success(return == NVAPI_OK) NvAPI_Status __cdecl

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


/* 64-bit types for compilers that support them, plus some obsolete variants */
#if defined(__GNUC__) || defined(__arm) || defined(__IAR_SYSTEMS_ICC__) || defined(__ghs__) || defined(_WIN64)
typedef unsigned long long NvU64; /* 0 to 18446744073709551615  */
typedef long long          NvS64; /* -9223372036854775808 to 9223372036854775807  */
#else
typedef unsigned __int64   NvU64; /* 0 to 18446744073709551615  */
typedef __int64            NvS64; /* -9223372036854775808 to 9223372036854775807  */
#endif

// mac os 32-bit still needs this
#if (defined(macintosh) || defined(__APPLE__)) && !defined(__LP64__)
typedef signed long        NvS32; /* -2147483648 to 2147483647  */   
#else
typedef signed int         NvS32; /* -2147483648 to 2147483647 */  
#endif

#ifndef __unix
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
} NvAPI_Status;


//! @}

#if defined(__vkd3d_d3d12_h__)
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

//! List of Raytracing CAPS types that can be queried.
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_CAPS_TYPE
{
    NVAPI_D3D12_RAYTRACING_CAPS_TYPE_THREAD_REORDERING      =  0,
    NVAPI_D3D12_RAYTRACING_CAPS_TYPE_OPACITY_MICROMAP       =  1,
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
#endif // defined(__vkd3d_d3d12_h__)

//! SUPPORTED OS:  Windows 10 and higher
//!
#if defined(__vkd3d_d3d12_h__) && (defined(__ID3D12Device5_INTERFACE_DEFINED__) || defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__))

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

#endif // defined(__vkd3d_d3d12_h__) && (defined(__ID3D12Device5_INTERFACE_DEFINED__) || defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__))

#if defined(__vkd3d_d3d12_h__) && defined(__ID3D12Device5_INTERFACE_DEFINED__)

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

#endif // defined(__vkd3d_d3d12_h__) && defined(__ID3D12Device5_INTERFACE_DEFINED__)

#if defined(__vkd3d_d3d12_h__) && defined(__ID3D12Device5_INTERFACE_DEFINED__)

//! Pipeline creation state flags.
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_PIPELINE_CREATION_STATE_FLAGS
{
    NVAPI_D3D12_PIPELINE_CREATION_STATE_FLAGS_NONE               = 0,         //!< [in] No pipeline flags.
    NVAPI_D3D12_PIPELINE_CREATION_STATE_FLAGS_ENABLE_OMM_SUPPORT = NV_BIT(0), //!< [in] Change whether raytracing pipelines are created with support for Opacity Micromaps.
                                                                              //!<      If a triangle with an OMM is encountered during traversal and the pipeline was not created with support for them, behavior is undefined.
                                                                              //!<      Support should only be enabled if there are OMMs present, since it may incur a small penalty on traversal performance overall.
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

#endif // defined(__vkd3d_d3d12_h__) && defined(__ID3D12Device5_INTERFACE_DEFINED__)

#if defined(__vkd3d_d3d12_h__) && defined(__ID3D12Device5_INTERFACE_DEFINED__)

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

#endif // defined(__vkd3d_d3d12_h__) && defined(__ID3D12Device5_INTERFACE_DEFINED__)

#if defined(__vkd3d_d3d12_h__) && defined(__ID3D12Device5_INTERFACE_DEFINED__)

//! This enum extends \c D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS with modified and additional values.
//! Only modified/new values are fully described; for more information on the other values, please check Microsoft's DirectX Raytracing Specification.
//!
//! \ingroup dx
typedef enum _NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS_EX
{
    // D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS flags
    NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_NONE_EX                            = 0x0,       //!< No options specified for the acceleration structure build.
    NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_UPDATE_EX                    = NV_BIT(0), //!< Allow the acceleration structure to later be updated (via the flag #NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PERFORM_UPDATE_EX), rather than always requiring a full rebuild.
    NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_COMPACTION_EX                = NV_BIT(1), //!< Allow for the acceleration structure to later be compacted.
    NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PREFER_FAST_TRACE_EX               = NV_BIT(2), //!< Favorize higher raytracing performance at the cost of longer build times.
    NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PREFER_FAST_BUILD_EX               = NV_BIT(3), //!< Favorize faster build times at the cost of lower raytracing performance.
    NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_MINIMIZE_MEMORY_EX                 = NV_BIT(4), //!< Minimize the memory footprint of the produced acceleration structure, potentially at the cost of longer build time or lower raytracing performance.
    NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PERFORM_UPDATE_EX                  = NV_BIT(5), //!< Instead of rebuilding the acceleration structure from scratch, the existing acceleration structure will be updated.
                                                                                                             //!< Added behaviour: If #NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_OMM_UPDATE_EX is specified, OMM references may be changed along with positions when an update is performed.

    // NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS_EX specific flags
    NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_OMM_UPDATE_EX                = NV_BIT(6), //!< The acceleration structure (AS) supports updating OMM contents (base OMM Array and/or indices).
                                                                                                             //!< Specifying this flag may result in larger AS size and may reduce traversal performance.
    NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_DISABLE_OMMS_EX              = NV_BIT(7), //!< Only applicable for BLAS builds. If enabled, any instances referencing this BLAS are allowed to disable the OMM test through the #NVAPI_D3D12_RAYTRACING_INSTANCE_FLAG_DISABLE_OMMS_EX flag.
                                                                                                             //!< Specifying this build flag may result in some reductions in traversal performance.
    NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_OMM_OPACITY_STATES_UPDATE_EX = NV_BIT(8), //!< The acceleration structure (AS) supports updating OMM data (encoded opacity values).
                                                                                                             //!< Specifying this flag may reduce traversal performance.

} NVAPI_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS_EX;

//! This enum extends \c D3D12_RAYTRACING_GEOMETRY_TYPE with additional values.
//! Only new values are fully described below; for more information on the other values, please check Microsoft's DirectX Raytracing Specification.
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
    NVAPI_D3D12_RAYTRACING_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_UNKNOWN_OPAQUE      = -4  //!< Uniform unknown-opaque OMM state.
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

//! Geometry triangle descriptor with attached augmented Opacity Micromaps.
//!
//! \ingroup dx
typedef struct _NVAPI_D3D12_RAYTRACING_GEOMETRY_OMM_TRIANGLES_DESC
{
    D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC            triangles;     //!< Triangle mesh descriptor.
    NVAPI_D3D12_RAYTRACING_GEOMETRY_OMM_ATTACHMENT_DESC ommAttachment; //!< Opacity Micromap attachment descriptor.
} NVAPI_D3D12_RAYTRACING_GEOMETRY_OMM_TRIANGLES_DESC;

//! This structure extends \c D3D12_RAYTRACING_GEOMETRY_DESC by supporting additional geometry types.
//! Only new members are fully described below; for more information on the other members, please check Microsoft's DirectX Raytracing Specification.
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
    };
} NVAPI_D3D12_RAYTRACING_GEOMETRY_DESC_EX;

//! This enum extends \c D3D12_RAYTRACING_INSTANCE_FLAGS with additional values.
//! Only new values are fully described below; for more information on the other values, please check Microsoft's DirectX Raytracing Specification.
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

#endif // defined(__vkd3d_d3d12_h__) && defined(__ID3D12Device5_INTERFACE_DEFINED__)

#if defined(__vkd3d_d3d12_h__) && defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__)

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

#endif // defined(__vkd3d_d3d12_h__) && defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__)

#if defined(__vkd3d_d3d12_h__) && defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__)

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

#endif // defined(__vkd3d_d3d12_h__) && defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__)

#if defined(__vkd3d_d3d12_h__) && defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__)

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

#endif // defined(__vkd3d_d3d12_h__) && defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__)

#if defined(__vkd3d_d3d12_h__) && defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__)

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

#endif // defined(__vkd3d_d3d12_h__) && defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__)

#if defined(__vkd3d_d3d12_h__) && defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__)

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
//! Only new or modified values are fully described below; for more information on the other values, please check Microsoft's DirectX Raytracing Specification.
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

#endif // defined(__vkd3d_d3d12_h__) && defined(__ID3D12GraphicsCommandList4_INTERFACE_DEFINED__)

#ifndef __NVAPI_EMPTY_SAL
#ifdef __nvapi_undef__ecount
    #undef __ecount
    #undef __nvapi_undef__ecount
#endif
#ifdef __nvapi_undef__bcount
    #undef __bcount
    #undef __nvapi_undef__bcount
#endif
#ifdef __nvapi_undef__in
    #undef __in
    #undef __nvapi_undef__in
#endif
#ifdef __nvapi_undef__in_ecount
    #undef __in_ecount
    #undef __nvapi_undef__in_ecount
#endif
#ifdef __nvapi_undef__in_bcount
    #undef __in_bcount
    #undef __nvapi_undef__in_bcount
#endif
#ifdef __nvapi_undef__in_z
    #undef __in_z
    #undef __nvapi_undef__in_z
#endif
#ifdef __nvapi_undef__in_ecount_z
    #undef __in_ecount_z
    #undef __nvapi_undef__in_ecount_z
#endif
#ifdef __nvapi_undef__in_bcount_z
    #undef __in_bcount_z
    #undef __nvapi_undef__in_bcount_z
#endif
#ifdef __nvapi_undef__in_nz
    #undef __in_nz
    #undef __nvapi_undef__in_nz
#endif
#ifdef __nvapi_undef__in_ecount_nz
    #undef __in_ecount_nz
    #undef __nvapi_undef__in_ecount_nz
#endif
#ifdef __nvapi_undef__in_bcount_nz
    #undef __in_bcount_nz
    #undef __nvapi_undef__in_bcount_nz
#endif
#ifdef __nvapi_undef__out
    #undef __out
    #undef __nvapi_undef__out
#endif
#ifdef __nvapi_undef__out_ecount
    #undef __out_ecount
    #undef __nvapi_undef__out_ecount
#endif
#ifdef __nvapi_undef__out_bcount
    #undef __out_bcount
    #undef __nvapi_undef__out_bcount
#endif
#ifdef __nvapi_undef__out_ecount_part
    #undef __out_ecount_part
    #undef __nvapi_undef__out_ecount_part
#endif
#ifdef __nvapi_undef__out_bcount_part
    #undef __out_bcount_part
    #undef __nvapi_undef__out_bcount_part
#endif
#ifdef __nvapi_undef__out_ecount_full
    #undef __out_ecount_full
    #undef __nvapi_undef__out_ecount_full
#endif
#ifdef __nvapi_undef__out_bcount_full
    #undef __out_bcount_full
    #undef __nvapi_undef__out_bcount_full
#endif
#ifdef __nvapi_undef__out_z
    #undef __out_z
    #undef __nvapi_undef__out_z
#endif
#ifdef __nvapi_undef__out_z_opt
    #undef __out_z_opt
    #undef __nvapi_undef__out_z_opt
#endif
#ifdef __nvapi_undef__out_ecount_z
    #undef __out_ecount_z
    #undef __nvapi_undef__out_ecount_z
#endif
#ifdef __nvapi_undef__out_bcount_z
    #undef __out_bcount_z
    #undef __nvapi_undef__out_bcount_z
#endif
#ifdef __nvapi_undef__out_ecount_part_z
    #undef __out_ecount_part_z
    #undef __nvapi_undef__out_ecount_part_z
#endif
#ifdef __nvapi_undef__out_bcount_part_z
    #undef __out_bcount_part_z
    #undef __nvapi_undef__out_bcount_part_z
#endif
#ifdef __nvapi_undef__out_ecount_full_z
    #undef __out_ecount_full_z
    #undef __nvapi_undef__out_ecount_full_z
#endif
#ifdef __nvapi_undef__out_bcount_full_z
    #undef __out_bcount_full_z
    #undef __nvapi_undef__out_bcount_full_z
#endif
#ifdef __nvapi_undef__out_nz
    #undef __out_nz
    #undef __nvapi_undef__out_nz
#endif
#ifdef __nvapi_undef__out_nz_opt
    #undef __out_nz_opt
    #undef __nvapi_undef__out_nz_opt
#endif
#ifdef __nvapi_undef__out_ecount_nz
    #undef __out_ecount_nz
    #undef __nvapi_undef__out_ecount_nz
#endif
#ifdef __nvapi_undef__out_bcount_nz
    #undef __out_bcount_nz
    #undef __nvapi_undef__out_bcount_nz
#endif
#ifdef __nvapi_undef__inout
    #undef __inout
    #undef __nvapi_undef__inout
#endif
#ifdef __nvapi_undef__inout_ecount
    #undef __inout_ecount
    #undef __nvapi_undef__inout_ecount
#endif
#ifdef __nvapi_undef__inout_bcount
    #undef __inout_bcount
    #undef __nvapi_undef__inout_bcount
#endif
#ifdef __nvapi_undef__inout_ecount_part
    #undef __inout_ecount_part
    #undef __nvapi_undef__inout_ecount_part
#endif
#ifdef __nvapi_undef__inout_bcount_part
    #undef __inout_bcount_part
    #undef __nvapi_undef__inout_bcount_part
#endif
#ifdef __nvapi_undef__inout_ecount_full
    #undef __inout_ecount_full
    #undef __nvapi_undef__inout_ecount_full
#endif
#ifdef __nvapi_undef__inout_bcount_full
    #undef __inout_bcount_full
    #undef __nvapi_undef__inout_bcount_full
#endif
#ifdef __nvapi_undef__inout_z
    #undef __inout_z
    #undef __nvapi_undef__inout_z
#endif
#ifdef __nvapi_undef__inout_ecount_z
    #undef __inout_ecount_z
    #undef __nvapi_undef__inout_ecount_z
#endif
#ifdef __nvapi_undef__inout_bcount_z
    #undef __inout_bcount_z
    #undef __nvapi_undef__inout_bcount_z
#endif
#ifdef __nvapi_undef__inout_nz
    #undef __inout_nz
    #undef __nvapi_undef__inout_nz
#endif
#ifdef __nvapi_undef__inout_ecount_nz
    #undef __inout_ecount_nz
    #undef __nvapi_undef__inout_ecount_nz
#endif
#ifdef __nvapi_undef__inout_bcount_nz
    #undef __inout_bcount_nz
    #undef __nvapi_undef__inout_bcount_nz
#endif
#ifdef __nvapi_undef__ecount_opt
    #undef __ecount_opt
    #undef __nvapi_undef__ecount_opt
#endif
#ifdef __nvapi_undef__bcount_opt
    #undef __bcount_opt
    #undef __nvapi_undef__bcount_opt
#endif
#ifdef __nvapi_undef__in_opt
    #undef __in_opt
    #undef __nvapi_undef__in_opt
#endif
#ifdef __nvapi_undef__in_ecount_opt
    #undef __in_ecount_opt
    #undef __nvapi_undef__in_ecount_opt
#endif
#ifdef __nvapi_undef__in_bcount_opt
    #undef __in_bcount_opt
    #undef __nvapi_undef__in_bcount_opt
#endif
#ifdef __nvapi_undef__in_z_opt
    #undef __in_z_opt
    #undef __nvapi_undef__in_z_opt
#endif
#ifdef __nvapi_undef__in_ecount_z_opt
    #undef __in_ecount_z_opt
    #undef __nvapi_undef__in_ecount_z_opt
#endif
#ifdef __nvapi_undef__in_bcount_z_opt
    #undef __in_bcount_z_opt
    #undef __nvapi_undef__in_bcount_z_opt
#endif
#ifdef __nvapi_undef__in_nz_opt
    #undef __in_nz_opt
    #undef __nvapi_undef__in_nz_opt
#endif
#ifdef __nvapi_undef__in_ecount_nz_opt
    #undef __in_ecount_nz_opt
    #undef __nvapi_undef__in_ecount_nz_opt
#endif
#ifdef __nvapi_undef__in_bcount_nz_opt
    #undef __in_bcount_nz_opt
    #undef __nvapi_undef__in_bcount_nz_opt
#endif
#ifdef __nvapi_undef__out_opt
    #undef __out_opt
    #undef __nvapi_undef__out_opt
#endif
#ifdef __nvapi_undef__out_ecount_opt
    #undef __out_ecount_opt
    #undef __nvapi_undef__out_ecount_opt
#endif
#ifdef __nvapi_undef__out_bcount_opt
    #undef __out_bcount_opt
    #undef __nvapi_undef__out_bcount_opt
#endif
#ifdef __nvapi_undef__out_ecount_part_opt
    #undef __out_ecount_part_opt
    #undef __nvapi_undef__out_ecount_part_opt
#endif
#ifdef __nvapi_undef__out_bcount_part_opt
    #undef __out_bcount_part_opt
    #undef __nvapi_undef__out_bcount_part_opt
#endif
#ifdef __nvapi_undef__out_ecount_full_opt
    #undef __out_ecount_full_opt
    #undef __nvapi_undef__out_ecount_full_opt
#endif
#ifdef __nvapi_undef__out_bcount_full_opt
    #undef __out_bcount_full_opt
    #undef __nvapi_undef__out_bcount_full_opt
#endif
#ifdef __nvapi_undef__out_ecount_z_opt
    #undef __out_ecount_z_opt
    #undef __nvapi_undef__out_ecount_z_opt
#endif
#ifdef __nvapi_undef__out_bcount_z_opt
    #undef __out_bcount_z_opt
    #undef __nvapi_undef__out_bcount_z_opt
#endif
#ifdef __nvapi_undef__out_ecount_part_z_opt
    #undef __out_ecount_part_z_opt
    #undef __nvapi_undef__out_ecount_part_z_opt
#endif
#ifdef __nvapi_undef__out_bcount_part_z_opt
    #undef __out_bcount_part_z_opt
    #undef __nvapi_undef__out_bcount_part_z_opt
#endif
#ifdef __nvapi_undef__out_ecount_full_z_opt
    #undef __out_ecount_full_z_opt
    #undef __nvapi_undef__out_ecount_full_z_opt
#endif
#ifdef __nvapi_undef__out_bcount_full_z_opt
    #undef __out_bcount_full_z_opt
    #undef __nvapi_undef__out_bcount_full_z_opt
#endif
#ifdef __nvapi_undef__out_ecount_nz_opt
    #undef __out_ecount_nz_opt
    #undef __nvapi_undef__out_ecount_nz_opt
#endif
#ifdef __nvapi_undef__out_bcount_nz_opt
    #undef __out_bcount_nz_opt
    #undef __nvapi_undef__out_bcount_nz_opt
#endif
#ifdef __nvapi_undef__inout_opt
    #undef __inout_opt
    #undef __nvapi_undef__inout_opt
#endif
#ifdef __nvapi_undef__inout_ecount_opt
    #undef __inout_ecount_opt
    #undef __nvapi_undef__inout_ecount_opt
#endif
#ifdef __nvapi_undef__inout_bcount_opt
    #undef __inout_bcount_opt
    #undef __nvapi_undef__inout_bcount_opt
#endif
#ifdef __nvapi_undef__inout_ecount_part_opt
    #undef __inout_ecount_part_opt
    #undef __nvapi_undef__inout_ecount_part_opt
#endif
#ifdef __nvapi_undef__inout_bcount_part_opt
    #undef __inout_bcount_part_opt
    #undef __nvapi_undef__inout_bcount_part_opt
#endif
#ifdef __nvapi_undef__inout_ecount_full_opt
    #undef __inout_ecount_full_opt
    #undef __nvapi_undef__inout_ecount_full_opt
#endif
#ifdef __nvapi_undef__inout_bcount_full_opt
    #undef __inout_bcount_full_opt
    #undef __nvapi_undef__inout_bcount_full_opt
#endif
#ifdef __nvapi_undef__inout_z_opt
    #undef __inout_z_opt
    #undef __nvapi_undef__inout_z_opt
#endif
#ifdef __nvapi_undef__inout_ecount_z_opt
    #undef __inout_ecount_z_opt
    #undef __nvapi_undef__inout_ecount_z_opt
#endif
#ifdef __nvapi_undef__inout_ecount_z_opt
    #undef __inout_ecount_z_opt
    #undef __nvapi_undef__inout_ecount_z_opt
#endif
#ifdef __nvapi_undef__inout_bcount_z_opt
    #undef __inout_bcount_z_opt
    #undef __nvapi_undef__inout_bcount_z_opt
#endif
#ifdef __nvapi_undef__inout_nz_opt
    #undef __inout_nz_opt
    #undef __nvapi_undef__inout_nz_opt
#endif
#ifdef __nvapi_undef__inout_ecount_nz_opt
    #undef __inout_ecount_nz_opt
    #undef __nvapi_undef__inout_ecount_nz_opt
#endif
#ifdef __nvapi_undef__inout_bcount_nz_opt
    #undef __inout_bcount_nz_opt
    #undef __nvapi_undef__inout_bcount_nz_opt
#endif
#ifdef __nvapi_undef__deref_ecount
    #undef __deref_ecount
    #undef __nvapi_undef__deref_ecount
#endif
#ifdef __nvapi_undef__deref_bcount
    #undef __deref_bcount
    #undef __nvapi_undef__deref_bcount
#endif
#ifdef __nvapi_undef__deref_out
    #undef __deref_out
    #undef __nvapi_undef__deref_out
#endif
#ifdef __nvapi_undef__deref_out_ecount
    #undef __deref_out_ecount
    #undef __nvapi_undef__deref_out_ecount
#endif
#ifdef __nvapi_undef__deref_out_bcount
    #undef __deref_out_bcount
    #undef __nvapi_undef__deref_out_bcount
#endif
#ifdef __nvapi_undef__deref_out_ecount_part
    #undef __deref_out_ecount_part
    #undef __nvapi_undef__deref_out_ecount_part
#endif
#ifdef __nvapi_undef__deref_out_bcount_part
    #undef __deref_out_bcount_part
    #undef __nvapi_undef__deref_out_bcount_part
#endif
#ifdef __nvapi_undef__deref_out_ecount_full
    #undef __deref_out_ecount_full
    #undef __nvapi_undef__deref_out_ecount_full
#endif
#ifdef __nvapi_undef__deref_out_bcount_full
    #undef __deref_out_bcount_full
    #undef __nvapi_undef__deref_out_bcount_full
#endif
#ifdef __nvapi_undef__deref_out_z
    #undef __deref_out_z
    #undef __nvapi_undef__deref_out_z
#endif
#ifdef __nvapi_undef__deref_out_ecount_z
    #undef __deref_out_ecount_z
    #undef __nvapi_undef__deref_out_ecount_z
#endif
#ifdef __nvapi_undef__deref_out_bcount_z
    #undef __deref_out_bcount_z
    #undef __nvapi_undef__deref_out_bcount_z
#endif
#ifdef __nvapi_undef__deref_out_nz
    #undef __deref_out_nz
    #undef __nvapi_undef__deref_out_nz
#endif
#ifdef __nvapi_undef__deref_out_ecount_nz
    #undef __deref_out_ecount_nz
    #undef __nvapi_undef__deref_out_ecount_nz
#endif
#ifdef __nvapi_undef__deref_out_bcount_nz
    #undef __deref_out_bcount_nz
    #undef __nvapi_undef__deref_out_bcount_nz
#endif
#ifdef __nvapi_undef__deref_inout
    #undef __deref_inout
    #undef __nvapi_undef__deref_inout
#endif
#ifdef __nvapi_undef__deref_inout_z
    #undef __deref_inout_z
    #undef __nvapi_undef__deref_inout_z
#endif
#ifdef __nvapi_undef__deref_inout_ecount
    #undef __deref_inout_ecount
    #undef __nvapi_undef__deref_inout_ecount
#endif
#ifdef __nvapi_undef__deref_inout_bcount
    #undef __deref_inout_bcount
    #undef __nvapi_undef__deref_inout_bcount
#endif
#ifdef __nvapi_undef__deref_inout_ecount_part
    #undef __deref_inout_ecount_part
    #undef __nvapi_undef__deref_inout_ecount_part
#endif
#ifdef __nvapi_undef__deref_inout_bcount_part
    #undef __deref_inout_bcount_part
    #undef __nvapi_undef__deref_inout_bcount_part
#endif
#ifdef __nvapi_undef__deref_inout_ecount_full
    #undef __deref_inout_ecount_full
    #undef __nvapi_undef__deref_inout_ecount_full
#endif
#ifdef __nvapi_undef__deref_inout_bcount_full
    #undef __deref_inout_bcount_full
    #undef __nvapi_undef__deref_inout_bcount_full
#endif
#ifdef __nvapi_undef__deref_inout_z
    #undef __deref_inout_z
    #undef __nvapi_undef__deref_inout_z
#endif
#ifdef __nvapi_undef__deref_inout_ecount_z
    #undef __deref_inout_ecount_z
    #undef __nvapi_undef__deref_inout_ecount_z
#endif
#ifdef __nvapi_undef__deref_inout_bcount_z
    #undef __deref_inout_bcount_z
    #undef __nvapi_undef__deref_inout_bcount_z
#endif
#ifdef __nvapi_undef__deref_inout_nz
    #undef __deref_inout_nz
    #undef __nvapi_undef__deref_inout_nz
#endif
#ifdef __nvapi_undef__deref_inout_ecount_nz
    #undef __deref_inout_ecount_nz
    #undef __nvapi_undef__deref_inout_ecount_nz
#endif
#ifdef __nvapi_undef__deref_inout_bcount_nz
    #undef __deref_inout_bcount_nz
    #undef __nvapi_undef__deref_inout_bcount_nz
#endif
#ifdef __nvapi_undef__deref_ecount_opt
    #undef __deref_ecount_opt
    #undef __nvapi_undef__deref_ecount_opt
#endif
#ifdef __nvapi_undef__deref_bcount_opt
    #undef __deref_bcount_opt
    #undef __nvapi_undef__deref_bcount_opt
#endif
#ifdef __nvapi_undef__deref_out_opt
    #undef __deref_out_opt
    #undef __nvapi_undef__deref_out_opt
#endif
#ifdef __nvapi_undef__deref_out_ecount_opt
    #undef __deref_out_ecount_opt
    #undef __nvapi_undef__deref_out_ecount_opt
#endif
#ifdef __nvapi_undef__deref_out_bcount_opt
    #undef __deref_out_bcount_opt
    #undef __nvapi_undef__deref_out_bcount_opt
#endif
#ifdef __nvapi_undef__deref_out_ecount_part_opt
    #undef __deref_out_ecount_part_opt
    #undef __nvapi_undef__deref_out_ecount_part_opt
#endif
#ifdef __nvapi_undef__deref_out_bcount_part_opt
    #undef __deref_out_bcount_part_opt
    #undef __nvapi_undef__deref_out_bcount_part_opt
#endif
#ifdef __nvapi_undef__deref_out_ecount_full_opt
    #undef __deref_out_ecount_full_opt
    #undef __nvapi_undef__deref_out_ecount_full_opt
#endif
#ifdef __nvapi_undef__deref_out_bcount_full_opt
    #undef __deref_out_bcount_full_opt
    #undef __nvapi_undef__deref_out_bcount_full_opt
#endif
#ifdef __nvapi_undef__deref_out_z_opt
    #undef __deref_out_z_opt
    #undef __nvapi_undef__deref_out_z_opt
#endif
#ifdef __nvapi_undef__deref_out_ecount_z_opt
    #undef __deref_out_ecount_z_opt
    #undef __nvapi_undef__deref_out_ecount_z_opt
#endif
#ifdef __nvapi_undef__deref_out_bcount_z_opt
    #undef __deref_out_bcount_z_opt
    #undef __nvapi_undef__deref_out_bcount_z_opt
#endif
#ifdef __nvapi_undef__deref_out_nz_opt
    #undef __deref_out_nz_opt
    #undef __nvapi_undef__deref_out_nz_opt
#endif
#ifdef __nvapi_undef__deref_out_ecount_nz_opt
    #undef __deref_out_ecount_nz_opt
    #undef __nvapi_undef__deref_out_ecount_nz_opt
#endif
#ifdef __nvapi_undef__deref_out_bcount_nz_opt
    #undef __deref_out_bcount_nz_opt
    #undef __nvapi_undef__deref_out_bcount_nz_opt
#endif
#ifdef __nvapi_undef__deref_inout_opt
    #undef __deref_inout_opt
    #undef __nvapi_undef__deref_inout_opt
#endif
#ifdef __nvapi_undef__deref_inout_ecount_opt
    #undef __deref_inout_ecount_opt
    #undef __nvapi_undef__deref_inout_ecount_opt
#endif
#ifdef __nvapi_undef__deref_inout_bcount_opt
    #undef __deref_inout_bcount_opt
    #undef __nvapi_undef__deref_inout_bcount_opt
#endif
#ifdef __nvapi_undef__deref_inout_ecount_part_opt
    #undef __deref_inout_ecount_part_opt
    #undef __nvapi_undef__deref_inout_ecount_part_opt
#endif
#ifdef __nvapi_undef__deref_inout_bcount_part_opt
    #undef __deref_inout_bcount_part_opt
    #undef __nvapi_undef__deref_inout_bcount_part_opt
#endif
#ifdef __nvapi_undef__deref_inout_ecount_full_opt
    #undef __deref_inout_ecount_full_opt
    #undef __nvapi_undef__deref_inout_ecount_full_opt
#endif
#ifdef __nvapi_undef__deref_inout_bcount_full_opt
    #undef __deref_inout_bcount_full_opt
    #undef __nvapi_undef__deref_inout_bcount_full_opt
#endif
#ifdef __nvapi_undef__deref_inout_z_opt
    #undef __deref_inout_z_opt
    #undef __nvapi_undef__deref_inout_z_opt
#endif
#ifdef __nvapi_undef__deref_inout_ecount_z_opt
    #undef __deref_inout_ecount_z_opt
    #undef __nvapi_undef__deref_inout_ecount_z_opt
#endif
#ifdef __nvapi_undef__deref_inout_bcount_z_opt
    #undef __deref_inout_bcount_z_opt
    #undef __nvapi_undef__deref_inout_bcount_z_opt
#endif
#ifdef __nvapi_undef__deref_inout_nz_opt
    #undef __deref_inout_nz_opt
    #undef __nvapi_undef__deref_inout_nz_opt
#endif
#ifdef __nvapi_undef__deref_inout_ecount_nz_opt
    #undef __deref_inout_ecount_nz_opt
    #undef __nvapi_undef__deref_inout_ecount_nz_opt
#endif
#ifdef __nvapi_undef__deref_inout_bcount_nz_opt
    #undef __deref_inout_bcount_nz_opt
    #undef __nvapi_undef__deref_inout_bcount_nz_opt
#endif
#ifdef __nvapi_undef__deref_opt_ecount
    #undef __deref_opt_ecount
    #undef __nvapi_undef__deref_opt_ecount
#endif
#ifdef __nvapi_undef__deref_opt_bcount
    #undef __deref_opt_bcount
    #undef __nvapi_undef__deref_opt_bcount
#endif
#ifdef __nvapi_undef__deref_opt_out
    #undef __deref_opt_out
    #undef __nvapi_undef__deref_opt_out
#endif
#ifdef __nvapi_undef__deref_opt_out_z
    #undef __deref_opt_out_z
    #undef __nvapi_undef__deref_opt_out_z
#endif
#ifdef __nvapi_undef__deref_opt_out_ecount
    #undef __deref_opt_out_ecount
    #undef __nvapi_undef__deref_opt_out_ecount
#endif
#ifdef __nvapi_undef__deref_opt_out_bcount
    #undef __deref_opt_out_bcount
    #undef __nvapi_undef__deref_opt_out_bcount
#endif
#ifdef __nvapi_undef__deref_opt_out_ecount_part
    #undef __deref_opt_out_ecount_part
    #undef __nvapi_undef__deref_opt_out_ecount_part
#endif
#ifdef __nvapi_undef__deref_opt_out_bcount_part
    #undef __deref_opt_out_bcount_part
    #undef __nvapi_undef__deref_opt_out_bcount_part
#endif
#ifdef __nvapi_undef__deref_opt_out_ecount_full
    #undef __deref_opt_out_ecount_full
    #undef __nvapi_undef__deref_opt_out_ecount_full
#endif
#ifdef __nvapi_undef__deref_opt_out_bcount_full
    #undef __deref_opt_out_bcount_full
    #undef __nvapi_undef__deref_opt_out_bcount_full
#endif
#ifdef __nvapi_undef__deref_opt_inout
    #undef __deref_opt_inout
    #undef __nvapi_undef__deref_opt_inout
#endif
#ifdef __nvapi_undef__deref_opt_inout_ecount
    #undef __deref_opt_inout_ecount
    #undef __nvapi_undef__deref_opt_inout_ecount
#endif
#ifdef __nvapi_undef__deref_opt_inout_bcount
    #undef __deref_opt_inout_bcount
    #undef __nvapi_undef__deref_opt_inout_bcount
#endif
#ifdef __nvapi_undef__deref_opt_inout_ecount_part
    #undef __deref_opt_inout_ecount_part
    #undef __nvapi_undef__deref_opt_inout_ecount_part
#endif
#ifdef __nvapi_undef__deref_opt_inout_bcount_part
    #undef __deref_opt_inout_bcount_part
    #undef __nvapi_undef__deref_opt_inout_bcount_part
#endif
#ifdef __nvapi_undef__deref_opt_inout_ecount_full
    #undef __deref_opt_inout_ecount_full
    #undef __nvapi_undef__deref_opt_inout_ecount_full
#endif
#ifdef __nvapi_undef__deref_opt_inout_bcount_full
    #undef __deref_opt_inout_bcount_full
    #undef __nvapi_undef__deref_opt_inout_bcount_full
#endif
#ifdef __nvapi_undef__deref_opt_inout_z
    #undef __deref_opt_inout_z
    #undef __nvapi_undef__deref_opt_inout_z
#endif
#ifdef __nvapi_undef__deref_opt_inout_ecount_z
    #undef __deref_opt_inout_ecount_z
    #undef __nvapi_undef__deref_opt_inout_ecount_z
#endif
#ifdef __nvapi_undef__deref_opt_inout_bcount_z
    #undef __deref_opt_inout_bcount_z
    #undef __nvapi_undef__deref_opt_inout_bcount_z
#endif
#ifdef __nvapi_undef__deref_opt_inout_nz
    #undef __deref_opt_inout_nz
    #undef __nvapi_undef__deref_opt_inout_nz
#endif
#ifdef __nvapi_undef__deref_opt_inout_ecount_nz
    #undef __deref_opt_inout_ecount_nz
    #undef __nvapi_undef__deref_opt_inout_ecount_nz
#endif
#ifdef __nvapi_undef__deref_opt_inout_bcount_nz
    #undef __deref_opt_inout_bcount_nz
    #undef __nvapi_undef__deref_opt_inout_bcount_nz
#endif
#ifdef __nvapi_undef__deref_opt_ecount_opt
    #undef __deref_opt_ecount_opt
    #undef __nvapi_undef__deref_opt_ecount_opt
#endif
#ifdef __nvapi_undef__deref_opt_bcount_opt
    #undef __deref_opt_bcount_opt
    #undef __nvapi_undef__deref_opt_bcount_opt
#endif
#ifdef __nvapi_undef__deref_opt_out_opt
    #undef __deref_opt_out_opt
    #undef __nvapi_undef__deref_opt_out_opt
#endif
#ifdef __nvapi_undef__deref_opt_out_ecount_opt
    #undef __deref_opt_out_ecount_opt
    #undef __nvapi_undef__deref_opt_out_ecount_opt
#endif
#ifdef __nvapi_undef__deref_opt_out_bcount_opt
    #undef __deref_opt_out_bcount_opt
    #undef __nvapi_undef__deref_opt_out_bcount_opt
#endif
#ifdef __nvapi_undef__deref_opt_out_ecount_part_opt
    #undef __deref_opt_out_ecount_part_opt
    #undef __nvapi_undef__deref_opt_out_ecount_part_opt
#endif
#ifdef __nvapi_undef__deref_opt_out_bcount_part_opt
    #undef __deref_opt_out_bcount_part_opt
    #undef __nvapi_undef__deref_opt_out_bcount_part_opt
#endif
#ifdef __nvapi_undef__deref_opt_out_ecount_full_opt
    #undef __deref_opt_out_ecount_full_opt
    #undef __nvapi_undef__deref_opt_out_ecount_full_opt
#endif
#ifdef __nvapi_undef__deref_opt_out_bcount_full_opt
    #undef __deref_opt_out_bcount_full_opt
    #undef __nvapi_undef__deref_opt_out_bcount_full_opt
#endif
#ifdef __nvapi_undef__deref_opt_out_z_opt
    #undef __deref_opt_out_z_opt
    #undef __nvapi_undef__deref_opt_out_z_opt
#endif
#ifdef __nvapi_undef__deref_opt_out_ecount_z_opt
    #undef __deref_opt_out_ecount_z_opt
    #undef __nvapi_undef__deref_opt_out_ecount_z_opt
#endif
#ifdef __nvapi_undef__deref_opt_out_bcount_z_opt
    #undef __deref_opt_out_bcount_z_opt
    #undef __nvapi_undef__deref_opt_out_bcount_z_opt
#endif
#ifdef __nvapi_undef__deref_opt_out_nz_opt
    #undef __deref_opt_out_nz_opt
    #undef __nvapi_undef__deref_opt_out_nz_opt
#endif
#ifdef __nvapi_undef__deref_opt_out_ecount_nz_opt
    #undef __deref_opt_out_ecount_nz_opt
    #undef __nvapi_undef__deref_opt_out_ecount_nz_opt
#endif
#ifdef __nvapi_undef__deref_opt_out_bcount_nz_opt
    #undef __deref_opt_out_bcount_nz_opt
    #undef __nvapi_undef__deref_opt_out_bcount_nz_opt
#endif
#ifdef __nvapi_undef__deref_opt_inout_opt
    #undef __deref_opt_inout_opt
    #undef __nvapi_undef__deref_opt_inout_opt
#endif
#ifdef __nvapi_undef__deref_opt_inout_ecount_opt
    #undef __deref_opt_inout_ecount_opt
    #undef __nvapi_undef__deref_opt_inout_ecount_opt
#endif
#ifdef __nvapi_undef__deref_opt_inout_bcount_opt
    #undef __deref_opt_inout_bcount_opt
    #undef __nvapi_undef__deref_opt_inout_bcount_opt
#endif
#ifdef __nvapi_undef__deref_opt_inout_ecount_part_opt
    #undef __deref_opt_inout_ecount_part_opt
    #undef __nvapi_undef__deref_opt_inout_ecount_part_opt
#endif
#ifdef __nvapi_undef__deref_opt_inout_bcount_part_opt
    #undef __deref_opt_inout_bcount_part_opt
    #undef __nvapi_undef__deref_opt_inout_bcount_part_opt
#endif
#ifdef __nvapi_undef__deref_opt_inout_ecount_full_opt
    #undef __deref_opt_inout_ecount_full_opt
    #undef __nvapi_undef__deref_opt_inout_ecount_full_opt
#endif
#ifdef __nvapi_undef__deref_opt_inout_bcount_full_opt
    #undef __deref_opt_inout_bcount_full_opt
    #undef __nvapi_undef__deref_opt_inout_bcount_full_opt
#endif
#ifdef __nvapi_undef__deref_opt_inout_z_opt
    #undef __deref_opt_inout_z_opt
    #undef __nvapi_undef__deref_opt_inout_z_opt
#endif
#ifdef __nvapi_undef__deref_opt_inout_ecount_z_opt
    #undef __deref_opt_inout_ecount_z_opt
    #undef __nvapi_undef__deref_opt_inout_ecount_z_opt
#endif
#ifdef __nvapi_undef__deref_opt_inout_bcount_z_opt
    #undef __deref_opt_inout_bcount_z_opt
    #undef __nvapi_undef__deref_opt_inout_bcount_z_opt
#endif
#ifdef __nvapi_undef__deref_opt_inout_nz_opt
    #undef __deref_opt_inout_nz_opt
    #undef __nvapi_undef__deref_opt_inout_nz_opt
#endif
#ifdef __nvapi_undef__deref_opt_inout_ecount_nz_opt
    #undef __deref_opt_inout_ecount_nz_opt
    #undef __nvapi_undef__deref_opt_inout_ecount_nz_opt
#endif
#ifdef __nvapi_undef__deref_opt_inout_bcount_nz_opt
    #undef __deref_opt_inout_bcount_nz_opt
    #undef __nvapi_undef__deref_opt_inout_bcount_nz_opt
#endif
#ifdef __nvapi_success
    #undef __success
    #undef __nvapi_success
#endif
#ifdef __nvapi__Ret_notnull_
    #undef __nvapi__Ret_notnull_
    #undef _Ret_notnull_
#endif
#ifdef __nvapi__Post_writable_byte_size_
    #undef __nvapi__Post_writable_byte_size_
    #undef _Post_writable_byte_size_
#endif
#ifdef __nvapi_Outptr_ 
    #undef __nvapi_Outptr_ 
    #undef _Outptr_ 
#endif

#endif // __NVAPI_EMPTY_SAL

#ifdef __cplusplus
}; //extern "C" {

#endif

#pragma pack(pop)

#endif // _NVAPI_H