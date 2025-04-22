/*
Copyright (c) 2023 - 2025 Advanced Micro Devices, Inc. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#pragma once

#include <iostream>
#include <va/va.h>
#include <va/va_dec_hevc.h>
#include <va/va_dec_vp9.h>
#include <va/va_dec_av1.h>

static void PrintAv1PicParams(VADecPictureParameterBufferAV1 *p_pic_param);
static void DumpAvcPicParams(VAPictureParameterBufferH264 *p_pic_params);
static void DumpAvcSliceParam(VASliceParameterBufferH264 *p_slice_param);
static void PrintVp9PicParams(VADecPictureParameterBufferVP9 *p_pic_param);
static void PrintVp9STileInfo(VASliceParameterBufferVP9 *p_tile_param);
static void DumpHevcPicParams(VAPictureParameterBufferHEVC *p_pic_params);
static void DumpHevcSliceParams(VASliceParameterBufferHEVC *p_slice_param);