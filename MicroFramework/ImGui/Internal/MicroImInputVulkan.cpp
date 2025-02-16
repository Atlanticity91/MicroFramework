/**
 *
 *  __  __ _            ___                                  _
 * |  \/  (_)__ _ _ ___| __| _ __ _ _ __  _____ __ _____ _ _| |__
 * | |\/| | / _| '_/ _ \ _| '_/ _` | '  \/ -_) V  V / _ \ '_| / /
 * |_|  |_|_\__|_| \___/_||_| \__,_|_|_|_\___|\_/\_/\___/_| |_\_\
 *
 * MIT License
 *
 * Copyright (c) 2024- Alves Quentin
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 **/

#pragma once

#include "__micro_framework_pch.h"

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC ===
////////////////////////////////////////////////////////////////////////////////////////////
namespace micro_im {

	static std::vector<micro_im::EnumPair> Formats = {
		micro_im_enum( VK_FORMAT_UNDEFINED ),
		micro_im_enum( VK_FORMAT_R4G4_UNORM_PACK8 ),
		micro_im_enum( VK_FORMAT_R4G4B4A4_UNORM_PACK16 ),
		micro_im_enum( VK_FORMAT_B4G4R4A4_UNORM_PACK16 ),
		micro_im_enum( VK_FORMAT_R5G6B5_UNORM_PACK16 ),
		micro_im_enum( VK_FORMAT_B5G6R5_UNORM_PACK16 ),
		micro_im_enum( VK_FORMAT_R5G5B5A1_UNORM_PACK16 ),
		micro_im_enum( VK_FORMAT_B5G5R5A1_UNORM_PACK16 ),
		micro_im_enum( VK_FORMAT_A1R5G5B5_UNORM_PACK16 ),
		micro_im_enum( VK_FORMAT_R8_UNORM ),
		micro_im_enum( VK_FORMAT_R8_SNORM ),
		micro_im_enum( VK_FORMAT_R8_USCALED ),
		micro_im_enum( VK_FORMAT_R8_SSCALED ),
		micro_im_enum( VK_FORMAT_R8_UINT ),
		micro_im_enum( VK_FORMAT_R8_SINT ),
		micro_im_enum( VK_FORMAT_R8_SRGB ),
		micro_im_enum( VK_FORMAT_R8G8_UNORM ),
		micro_im_enum( VK_FORMAT_R8G8_SNORM ),
		micro_im_enum( VK_FORMAT_R8G8_USCALED ),
		micro_im_enum( VK_FORMAT_R8G8_SSCALED ),
		micro_im_enum( VK_FORMAT_R8G8_UINT ),
		micro_im_enum( VK_FORMAT_R8G8_SINT ),
		micro_im_enum( VK_FORMAT_R8G8_SRGB ),
		micro_im_enum( VK_FORMAT_R8G8B8_UNORM ),
		micro_im_enum( VK_FORMAT_R8G8B8_SNORM ),
		micro_im_enum( VK_FORMAT_R8G8B8_USCALED ),
		micro_im_enum( VK_FORMAT_R8G8B8_SSCALED ),
		micro_im_enum( VK_FORMAT_R8G8B8_UINT ),
		micro_im_enum( VK_FORMAT_R8G8B8_SINT ),
		micro_im_enum( VK_FORMAT_R8G8B8_SRGB ),
		micro_im_enum( VK_FORMAT_B8G8R8_UNORM ),
		micro_im_enum( VK_FORMAT_B8G8R8_SNORM ),
		micro_im_enum( VK_FORMAT_B8G8R8_USCALED ),
		micro_im_enum( VK_FORMAT_B8G8R8_SSCALED ),
		micro_im_enum( VK_FORMAT_B8G8R8_UINT ),
		micro_im_enum( VK_FORMAT_B8G8R8_SINT ),
		micro_im_enum( VK_FORMAT_B8G8R8_SRGB ),
		micro_im_enum( VK_FORMAT_R8G8B8A8_UNORM ),
		micro_im_enum( VK_FORMAT_R8G8B8A8_SNORM ),
		micro_im_enum( VK_FORMAT_R8G8B8A8_USCALED ),
		micro_im_enum( VK_FORMAT_R8G8B8A8_SSCALED ),
		micro_im_enum( VK_FORMAT_R8G8B8A8_UINT ),
		micro_im_enum( VK_FORMAT_R8G8B8A8_SINT ),
		micro_im_enum( VK_FORMAT_R8G8B8A8_SRGB ),
		micro_im_enum( VK_FORMAT_B8G8R8A8_UNORM ),
		micro_im_enum( VK_FORMAT_B8G8R8A8_SNORM ),
		micro_im_enum( VK_FORMAT_B8G8R8A8_USCALED ),
		micro_im_enum( VK_FORMAT_B8G8R8A8_SSCALED ),
		micro_im_enum( VK_FORMAT_B8G8R8A8_UINT ),
		micro_im_enum( VK_FORMAT_B8G8R8A8_SINT ),
		micro_im_enum( VK_FORMAT_B8G8R8A8_SRGB ),
		micro_im_enum( VK_FORMAT_A8B8G8R8_UNORM_PACK32 ),
		micro_im_enum( VK_FORMAT_A8B8G8R8_SNORM_PACK32 ),
		micro_im_enum( VK_FORMAT_A8B8G8R8_USCALED_PACK32 ),
		micro_im_enum( VK_FORMAT_A8B8G8R8_SSCALED_PACK32 ),
		micro_im_enum( VK_FORMAT_A8B8G8R8_UINT_PACK32 ),
		micro_im_enum( VK_FORMAT_A8B8G8R8_SINT_PACK32 ),
		micro_im_enum( VK_FORMAT_A8B8G8R8_SRGB_PACK32 ),
		micro_im_enum( VK_FORMAT_A2R10G10B10_UNORM_PACK32 ),
		micro_im_enum( VK_FORMAT_A2R10G10B10_SNORM_PACK32 ),
		micro_im_enum( VK_FORMAT_A2R10G10B10_USCALED_PACK32 ),
		micro_im_enum( VK_FORMAT_A2R10G10B10_SSCALED_PACK32 ),
		micro_im_enum( VK_FORMAT_A2R10G10B10_UINT_PACK32 ),
		micro_im_enum( VK_FORMAT_A2R10G10B10_SINT_PACK32 ),
		micro_im_enum( VK_FORMAT_A2B10G10R10_UNORM_PACK32 ),
		micro_im_enum( VK_FORMAT_A2B10G10R10_SNORM_PACK32 ),
		micro_im_enum( VK_FORMAT_A2B10G10R10_USCALED_PACK32 ),
		micro_im_enum( VK_FORMAT_A2B10G10R10_SSCALED_PACK32 ),
		micro_im_enum( VK_FORMAT_A2B10G10R10_UINT_PACK32 ),
		micro_im_enum( VK_FORMAT_A2B10G10R10_SINT_PACK32 ),
		micro_im_enum( VK_FORMAT_R16_UNORM ),
		micro_im_enum( VK_FORMAT_R16_SNORM ),
		micro_im_enum( VK_FORMAT_R16_USCALED ),
		micro_im_enum( VK_FORMAT_R16_SSCALED ),
		micro_im_enum( VK_FORMAT_R16_UINT ),
		micro_im_enum( VK_FORMAT_R16_SINT ),
		micro_im_enum( VK_FORMAT_R16_SFLOAT ),
		micro_im_enum( VK_FORMAT_R16G16_UNORM ),
		micro_im_enum( VK_FORMAT_R16G16_SNORM ),
		micro_im_enum( VK_FORMAT_R16G16_USCALED ),
		micro_im_enum( VK_FORMAT_R16G16_SSCALED ),
		micro_im_enum( VK_FORMAT_R16G16_UINT ),
		micro_im_enum( VK_FORMAT_R16G16_SINT ),
		micro_im_enum( VK_FORMAT_R16G16_SFLOAT ),
		micro_im_enum( VK_FORMAT_R16G16B16_UNORM ),
		micro_im_enum( VK_FORMAT_R16G16B16_SNORM ),
		micro_im_enum( VK_FORMAT_R16G16B16_USCALED ),
		micro_im_enum( VK_FORMAT_R16G16B16_SSCALED ),
		micro_im_enum( VK_FORMAT_R16G16B16_UINT ),
		micro_im_enum( VK_FORMAT_R16G16B16_SINT ),
		micro_im_enum( VK_FORMAT_R16G16B16_SFLOAT ),
		micro_im_enum( VK_FORMAT_R16G16B16A16_UNORM ),
		micro_im_enum( VK_FORMAT_R16G16B16A16_SNORM ),
		micro_im_enum( VK_FORMAT_R16G16B16A16_USCALED ),
		micro_im_enum( VK_FORMAT_R16G16B16A16_SSCALED ),
		micro_im_enum( VK_FORMAT_R16G16B16A16_UINT ),
		micro_im_enum( VK_FORMAT_R16G16B16A16_SINT ),
		micro_im_enum( VK_FORMAT_R16G16B16A16_SFLOAT ),
		micro_im_enum( VK_FORMAT_R32_UINT ),
		micro_im_enum( VK_FORMAT_R32_SINT ),
		micro_im_enum( VK_FORMAT_R32_SFLOAT ),
		micro_im_enum( VK_FORMAT_R32G32_UINT ),
		micro_im_enum( VK_FORMAT_R32G32_SINT ),
		micro_im_enum( VK_FORMAT_R32G32_SFLOAT ),
		micro_im_enum( VK_FORMAT_R32G32B32_UINT ),
		micro_im_enum( VK_FORMAT_R32G32B32_SINT ),
		micro_im_enum( VK_FORMAT_R32G32B32_SFLOAT ),
		micro_im_enum( VK_FORMAT_R32G32B32A32_UINT ),
		micro_im_enum( VK_FORMAT_R32G32B32A32_SINT ),
		micro_im_enum( VK_FORMAT_R32G32B32A32_SFLOAT ),
		micro_im_enum( VK_FORMAT_R64_UINT ),
		micro_im_enum( VK_FORMAT_R64_SINT ),
		micro_im_enum( VK_FORMAT_R64_SFLOAT ),
		micro_im_enum( VK_FORMAT_R64G64_UINT ),
		micro_im_enum( VK_FORMAT_R64G64_SINT ),
		micro_im_enum( VK_FORMAT_R64G64_SFLOAT ),
		micro_im_enum( VK_FORMAT_R64G64B64_UINT ),
		micro_im_enum( VK_FORMAT_R64G64B64_SINT ),
		micro_im_enum( VK_FORMAT_R64G64B64_SFLOAT ),
		micro_im_enum( VK_FORMAT_R64G64B64A64_UINT ),
		micro_im_enum( VK_FORMAT_R64G64B64A64_SINT ),
		micro_im_enum( VK_FORMAT_R64G64B64A64_SFLOAT ),
		micro_im_enum( VK_FORMAT_B10G11R11_UFLOAT_PACK32 ),
		micro_im_enum( VK_FORMAT_E5B9G9R9_UFLOAT_PACK32 ),
		micro_im_enum( VK_FORMAT_D16_UNORM ),
		micro_im_enum( VK_FORMAT_X8_D24_UNORM_PACK32 ),
		micro_im_enum( VK_FORMAT_D32_SFLOAT ),
		micro_im_enum( VK_FORMAT_S8_UINT ),
		micro_im_enum( VK_FORMAT_D16_UNORM_S8_UINT ),
		micro_im_enum( VK_FORMAT_D24_UNORM_S8_UINT ),
		micro_im_enum( VK_FORMAT_D32_SFLOAT_S8_UINT ),
		micro_im_enum( VK_FORMAT_BC1_RGB_UNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_BC1_RGB_SRGB_BLOCK ),
		micro_im_enum( VK_FORMAT_BC1_RGBA_UNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_BC1_RGBA_SRGB_BLOCK ),
		micro_im_enum( VK_FORMAT_BC2_UNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_BC2_SRGB_BLOCK ),
		micro_im_enum( VK_FORMAT_BC3_UNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_BC3_SRGB_BLOCK ),
		micro_im_enum( VK_FORMAT_BC4_UNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_BC4_SNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_BC5_UNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_BC5_SNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_BC6H_UFLOAT_BLOCK ),
		micro_im_enum( VK_FORMAT_BC6H_SFLOAT_BLOCK ),
		micro_im_enum( VK_FORMAT_BC7_UNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_BC7_SRGB_BLOCK ),
		micro_im_enum( VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK ),
		micro_im_enum( VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK ),
		micro_im_enum( VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK ),
		micro_im_enum( VK_FORMAT_EAC_R11_UNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_EAC_R11_SNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_EAC_R11G11_UNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_EAC_R11G11_SNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_4x4_UNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_4x4_SRGB_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_5x4_UNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_5x4_SRGB_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_5x5_UNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_5x5_SRGB_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_6x5_UNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_6x5_SRGB_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_6x6_UNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_6x6_SRGB_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_8x5_UNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_8x5_SRGB_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_8x6_UNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_8x6_SRGB_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_8x8_UNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_8x8_SRGB_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_10x5_UNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_10x5_SRGB_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_10x6_UNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_10x6_SRGB_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_10x8_UNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_10x8_SRGB_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_10x10_UNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_10x10_SRGB_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_12x10_UNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_12x10_SRGB_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_12x12_UNORM_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_12x12_SRGB_BLOCK ),
		micro_im_enum( VK_FORMAT_G8B8G8R8_422_UNORM ),
		micro_im_enum( VK_FORMAT_B8G8R8G8_422_UNORM ),
		micro_im_enum( VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM ),
		micro_im_enum( VK_FORMAT_G8_B8R8_2PLANE_420_UNORM ),
		micro_im_enum( VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM ),
		micro_im_enum( VK_FORMAT_G8_B8R8_2PLANE_422_UNORM ),
		micro_im_enum( VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM ),
		micro_im_enum( VK_FORMAT_R10X6_UNORM_PACK16 ),
		micro_im_enum( VK_FORMAT_R10X6G10X6_UNORM_2PACK16 ),
		micro_im_enum( VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16 ),
		micro_im_enum( VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16 ),
		micro_im_enum( VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16 ),
		micro_im_enum( VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16 ),
		micro_im_enum( VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16 ),
		micro_im_enum( VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16 ),
		micro_im_enum( VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16 ),
		micro_im_enum( VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16 ),
		micro_im_enum( VK_FORMAT_R12X4_UNORM_PACK16 ),
		micro_im_enum( VK_FORMAT_R12X4G12X4_UNORM_2PACK16 ),
		micro_im_enum( VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16 ),
		micro_im_enum( VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16 ),
		micro_im_enum( VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16 ),
		micro_im_enum( VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16 ),
		micro_im_enum( VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16 ),
		micro_im_enum( VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16 ),
		micro_im_enum( VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16 ),
		micro_im_enum( VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16 ),
		micro_im_enum( VK_FORMAT_G16B16G16R16_422_UNORM ),
		micro_im_enum( VK_FORMAT_B16G16R16G16_422_UNORM ),
		micro_im_enum( VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM ),
		micro_im_enum( VK_FORMAT_G16_B16R16_2PLANE_420_UNORM ),
		micro_im_enum( VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM ),
		micro_im_enum( VK_FORMAT_G16_B16R16_2PLANE_422_UNORM ),
		micro_im_enum( VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM ),
		micro_im_enum( VK_FORMAT_G8_B8R8_2PLANE_444_UNORM ),
		micro_im_enum( VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16 ),
		micro_im_enum( VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16 ),
		micro_im_enum( VK_FORMAT_G16_B16R16_2PLANE_444_UNORM ),
		micro_im_enum( VK_FORMAT_A4R4G4B4_UNORM_PACK16 ),
		micro_im_enum( VK_FORMAT_A4B4G4R4_UNORM_PACK16 ),
		micro_im_enum( VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK ),
		micro_im_enum( VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK ),
		micro_im_enum( VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG ),
		micro_im_enum( VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG ),
		micro_im_enum( VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG ),
		micro_im_enum( VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG ),
		micro_im_enum( VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG ),
		micro_im_enum( VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG ),
		micro_im_enum( VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG ),
		micro_im_enum( VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG ),
		micro_im_enum( VK_FORMAT_R16G16_SFIXED5_NV ),
		micro_im_enum( VK_FORMAT_A1B5G5R5_UNORM_PACK16_KHR ),
		micro_im_enum( VK_FORMAT_A8_UNORM_KHR )
	};

	static std::vector<micro_im::EnumPair> Layouts = {
		micro_im_enum( VK_IMAGE_LAYOUT_UNDEFINED ),
		micro_im_enum( VK_IMAGE_LAYOUT_GENERAL ),
		micro_im_enum( VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL ),
		micro_im_enum( VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL ),
		micro_im_enum( VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL ),
		micro_im_enum( VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL ),
		micro_im_enum( VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL ),
		micro_im_enum( VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL ),
		micro_im_enum( VK_IMAGE_LAYOUT_PREINITIALIZED ),
		micro_im_enum( VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL ),
		micro_im_enum( VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL ),
		micro_im_enum( VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL ),
		micro_im_enum( VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL ),
		micro_im_enum( VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL ),
		micro_im_enum( VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL ),
		micro_im_enum( VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL ),
		micro_im_enum( VK_IMAGE_LAYOUT_ATTACHMENT_OPTIMAL ),
		micro_im_enum( VK_IMAGE_LAYOUT_PRESENT_SRC_KHR ),
		micro_im_enum( VK_IMAGE_LAYOUT_VIDEO_DECODE_DST_KHR ),
		micro_im_enum( VK_IMAGE_LAYOUT_VIDEO_DECODE_SRC_KHR ),
		micro_im_enum( VK_IMAGE_LAYOUT_VIDEO_DECODE_DPB_KHR ),
		micro_im_enum( VK_IMAGE_LAYOUT_SHARED_PRESENT_KHR ),
		micro_im_enum( VK_IMAGE_LAYOUT_FRAGMENT_DENSITY_MAP_OPTIMAL_EXT ),
		micro_im_enum( VK_IMAGE_LAYOUT_FRAGMENT_SHADING_RATE_ATTACHMENT_OPTIMAL_KHR ),
		micro_im_enum( VK_IMAGE_LAYOUT_RENDERING_LOCAL_READ_KHR ),
		micro_im_enum( VK_IMAGE_LAYOUT_VIDEO_ENCODE_DST_KHR ),
		micro_im_enum( VK_IMAGE_LAYOUT_VIDEO_ENCODE_SRC_KHR ),
		micro_im_enum( VK_IMAGE_LAYOUT_VIDEO_ENCODE_DPB_KHR ),
		micro_im_enum( VK_IMAGE_LAYOUT_ATTACHMENT_FEEDBACK_LOOP_OPTIMAL_EXT )
	};

	static std::vector<micro_im::EnumPair> Aspects = {
		micro_im_enum( VK_IMAGE_ASPECT_NONE ),
		micro_im_enum( VK_IMAGE_ASPECT_COLOR_BIT ),
		micro_im_enum( VK_IMAGE_ASPECT_DEPTH_BIT ),
		micro_im_enum( VK_IMAGE_ASPECT_STENCIL_BIT ),
		micro_im_enum( VK_IMAGE_ASPECT_METADATA_BIT ),
		micro_im_enum( VK_IMAGE_ASPECT_PLANE_0_BIT ),
		micro_im_enum( VK_IMAGE_ASPECT_PLANE_1_BIT ),
		micro_im_enum( VK_IMAGE_ASPECT_PLANE_2_BIT ),
		micro_im_enum( VK_IMAGE_ASPECT_MEMORY_PLANE_0_BIT_EXT ),
		micro_im_enum( VK_IMAGE_ASPECT_MEMORY_PLANE_1_BIT_EXT ),
		micro_im_enum( VK_IMAGE_ASPECT_MEMORY_PLANE_2_BIT_EXT ),
		micro_im_enum( VK_IMAGE_ASPECT_MEMORY_PLANE_3_BIT_EXT )
	};

	static std::vector<micro_im::EnumPair> Mipmaps = {
		micro_im_enum( VK_SAMPLER_MIPMAP_MODE_NEAREST ),
		micro_im_enum( VK_SAMPLER_MIPMAP_MODE_LINEAR )
	};

	static std::vector<micro_im::EnumPair> Samples = {
		micro_im_enum( VK_SAMPLE_COUNT_1_BIT ),
		micro_im_enum( VK_SAMPLE_COUNT_2_BIT ),
		micro_im_enum( VK_SAMPLE_COUNT_4_BIT ),
		micro_im_enum( VK_SAMPLE_COUNT_8_BIT ),
		micro_im_enum( VK_SAMPLE_COUNT_16_BIT ),
		micro_im_enum( VK_SAMPLE_COUNT_32_BIT ),
		micro_im_enum( VK_SAMPLE_COUNT_64_BIT )
	};

	static std::vector<micro_im::EnumPair> ColorSpaces = {
		micro_im_enum( VK_COLOR_SPACE_SRGB_NONLINEAR_KHR ),
		micro_im_enum( VK_COLOR_SPACE_DISPLAY_P3_NONLINEAR_EXT ),
		micro_im_enum( VK_COLOR_SPACE_EXTENDED_SRGB_LINEAR_EXT ),
		micro_im_enum( VK_COLOR_SPACE_DISPLAY_P3_LINEAR_EXT ),
		micro_im_enum( VK_COLOR_SPACE_DCI_P3_NONLINEAR_EXT ),
		micro_im_enum( VK_COLOR_SPACE_BT709_LINEAR_EXT ),
		micro_im_enum( VK_COLOR_SPACE_BT709_NONLINEAR_EXT ),
		micro_im_enum( VK_COLOR_SPACE_BT2020_LINEAR_EXT ),
		micro_im_enum( VK_COLOR_SPACE_HDR10_ST2084_EXT ),
		micro_im_enum( VK_COLOR_SPACE_DOLBYVISION_EXT ),
		micro_im_enum( VK_COLOR_SPACE_HDR10_HLG_EXT ),
		micro_im_enum( VK_COLOR_SPACE_ADOBERGB_LINEAR_EXT ),
		micro_im_enum( VK_COLOR_SPACE_ADOBERGB_NONLINEAR_EXT ),
		micro_im_enum( VK_COLOR_SPACE_PASS_THROUGH_EXT ),
		micro_im_enum( VK_COLOR_SPACE_EXTENDED_SRGB_NONLINEAR_EXT ),
		micro_im_enum( VK_COLOR_SPACE_DISPLAY_NATIVE_AMD )
	};

	static std::vector<micro_im::EnumPair> Tilings = {
		micro_im_enum( VK_IMAGE_TILING_OPTIMAL ),
		micro_im_enum( VK_IMAGE_TILING_LINEAR ),
		micro_im_enum( VK_IMAGE_TILING_DRM_FORMAT_MODIFIER_EXT )
	};

	static std::vector<micro_im::EnumPair> Filters = {
		micro_im_enum( VK_FILTER_NEAREST ),
		micro_im_enum( VK_FILTER_LINEAR ),
		micro_im_enum( VK_FILTER_CUBIC_EXT )
	};
	
	static std::vector<micro_im::EnumPair> CompareOps = {
		micro_im_enum( VK_COMPARE_OP_NEVER ),
		micro_im_enum( VK_COMPARE_OP_LESS ),
		micro_im_enum( VK_COMPARE_OP_EQUAL ),
		micro_im_enum( VK_COMPARE_OP_LESS_OR_EQUAL ),
		micro_im_enum( VK_COMPARE_OP_GREATER ),
		micro_im_enum( VK_COMPARE_OP_NOT_EQUAL ),
		micro_im_enum( VK_COMPARE_OP_GREATER_OR_EQUAL ),
		micro_im_enum( VK_COMPARE_OP_ALWAYS )
	};

	static std::vector<micro_im::EnumPair> BorderColors = {
		micro_im_enum( VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK ),
		micro_im_enum( VK_BORDER_COLOR_INT_TRANSPARENT_BLACK ),
		micro_im_enum( VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK ),
		micro_im_enum( VK_BORDER_COLOR_INT_OPAQUE_BLACK ),
		micro_im_enum( VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE ),
		micro_im_enum( VK_BORDER_COLOR_INT_OPAQUE_WHITE ),
		micro_im_enum( VK_BORDER_COLOR_FLOAT_CUSTOM_EXT ),
		micro_im_enum( VK_BORDER_COLOR_INT_CUSTOM_EXT )
	};

	uint32_t find_vulkan_enum(
		const std::vector<micro_im::EnumPair>& enum_pairs,
		const uint32_t enum_value
	) {
		auto index = (uint32_t)0;

		while ( index-- > 0 && enum_pairs[ index ].Value != enum_value );

		return index;
	}

	bool input_vulkan( const std::string& label, VkFormat& format ) {
		return micro_im::input_vulkan( label, Formats, format );
	}

	void input_vulkan_disabled( const std::string& label, const VkFormat format ) {
		micro_im::input_vulkan_disabled( label, Formats, format );
	}

	bool input_vulkan( const std::string& label, VkImageLayout& layout ) {
		return micro_im::input_vulkan( label, Layouts, layout );
	}

	void input_vulkan_disabled( const std::string& label, const VkImageLayout layout ) {
		micro_im::input_vulkan_disabled( label, Layouts, layout );
	}

	bool input_vulkan( const std::string& label, VkImageAspectFlags& aspect ) {
		return micro_im::input_vulkan( label, Aspects, aspect );
	}

	void input_vulkan_disabled( 
		const std::string& label,
		const VkImageAspectFlags aspect 
	) {
		micro_im::input_vulkan_disabled( label, Aspects, aspect );
	}

	bool input_vulkan(
		const std::string& label,
		VkSamplerMipmapMode& mipmap_mode
	) {
		return micro_im::input_vulkan( label, Mipmaps, mipmap_mode );
	}

	void input_vulkan_disabled(
		const std::string& label,
		const VkSamplerMipmapMode mipmap_mode
	) {
		micro_im::input_vulkan_disabled( label, Mipmaps, mipmap_mode );
	}

	bool input_vulkan(
		const std::string& label,
		VkSampleCountFlagBits& samples
	) {
		return micro_im::input_vulkan( label, Samples, samples );
	}

	void input_vulkan_disabled(
		const std::string& label,
		const VkSampleCountFlagBits samples
	) {
		micro_im::input_vulkan_disabled( label, Samples, samples );
	}

	bool input_vulkan(
		const std::string& label,
		VkColorSpaceKHR& color_space
	) {
		return micro_im::input_vulkan( label, ColorSpaces, color_space );
	}

	void input_vulkan_disabled(
		const std::string& label,
		const VkColorSpaceKHR color_space
	) {
		micro_im::input_vulkan_disabled( label, ColorSpaces, color_space );
	}

	bool input_vulkan(
		const std::string& label,
		VkImageTiling& tiling
	) {
		return micro_im::input_vulkan( label, Tilings, tiling );
	}

	void input_vulkan_disabled(
		const std::string& label,
		const VkImageTiling tiling
	) {
		micro_im::input_vulkan_disabled( label, Tilings, tiling );
	}

	bool input_vulkan(
		const std::string& label,
		VkFilter& filter
	) {
		return micro_im::input_vulkan( label, Filters, filter );
	}

	void input_vulkan_disabled(
		const std::string& label,
		const VkFilter filter
	) {
		micro_im::input_vulkan_disabled( label, Filters, filter );
	}

	bool input_vulkan(
		const std::string& label,
		VkCompareOp& compare_op
	) {
		return micro_im::input_vulkan( label, CompareOps, compare_op );
	}

	void input_vulkan_disabled(
		const std::string& label,
		const VkCompareOp compare_op
	) {
		micro_im::input_vulkan_disabled( label, CompareOps, compare_op );
	}

	bool input_vulkan(
		const std::string& label,
		VkBorderColor& border_color
	) {
		return micro_im::input_vulkan( label, BorderColors, border_color );
	}

	void input_vulkan_disabled(
		const std::string& label,
		const VkBorderColor border_color
	) {
		micro_im::input_vulkan_disabled( label, BorderColors, border_color );
	}

	bool input_vulkan(
		const std::string& label,
		VkViewport& viewport
	) {
		micro_im::input_begin( label );
		micro_im::input_separator( );
		
		return  micro_im::input_vector( "Offset", 2, micro_ptr( viewport.x ) )	   ||
				micro_im::input_vector( "Extent", 2, micro_ptr( viewport.width ) ) ||
				micro_im::input_scalar( "Min Depth", viewport.minDepth )		   || 
				micro_im::input_scalar( "Max Depth", viewport.maxDepth );
	}

	void input_vulkan_disabled(
		const std::string& label,
		const VkViewport& viewport
	) {
		micro_im::input_separator( );

		micro_im::input_vector_disabled( "Offset", 2, micro_ptr( viewport.x ) );
		micro_im::input_vector_disabled( "Extent", 2, micro_ptr( viewport.width ) );
		micro_im::input_scalar_disabled( "Min Depth", viewport.minDepth );
		micro_im::input_scalar_disabled( "Max Depth", viewport.maxDepth );
	}

	bool input_vulkan(
		const std::string& label,
		VkScissor& scissor
	) {
		micro_im::input_separator( );

		return  micro_im::input_vector( "Offset", 2, micro_ptr( scissor.offset.x ) ) ||
				micro_im::input_vector( "Extent", 2, micro_ptr( scissor.extent.width ) );
	}

	void input_vulkan_disabled(
		const std::string& label,
		const VkScissor& scissor
	) {
		micro_im::input_separator( );

		micro_im::input_vector_disabled( "Offset", 2, micro_ptr( scissor.offset.x ) );
		micro_im::input_vector_disabled( "Extent", 2, micro_ptr( scissor.extent.width ) );
	}

};
