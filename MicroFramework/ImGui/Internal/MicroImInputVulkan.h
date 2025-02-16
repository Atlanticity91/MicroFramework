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

#include "MicroImInputColor.h"

namespace micro_im {

	MICRO_API uint32_t find_vulkan_enum( 
		const std::vector<micro_im::EnumPair>& enum_pairs, 
		const uint32_t enum_value 
	);

	MICRO_API bool input_vulkan( const std::string& label, VkFormat& format );

	MICRO_API void input_vulkan_disabled(
		const std::string& label,
		const VkFormat& format
	);

	MICRO_API bool input_vulkan( 
		const std::string& label, 
		VkImageLayout& layout 
	);

	MICRO_API void input_vulkan_disabled(
		const std::string& label, 
		const VkImageLayout layout 
	);

	MICRO_API bool input_vulkan( 
		const std::string& label, 
		VkImageAspectFlags& aspect 
	);

	MICRO_API void input_vulkan_disabled(
		const std::string& label, 
		const VkImageAspectFlags aspect 
	);

	MICRO_API bool input_vulkan(
		const std::string& label,
		VkSamplerMipmapMode& mipmap_mode
	);

	MICRO_API void input_vulkan_disabled(
		const std::string& label,
		const VkSamplerMipmapMode mipmap_mode
	);

	MICRO_API bool input_vulkan( 
		const std::string& label, 
		VkSampleCountFlagBits& samples 
	);

	MICRO_API void input_vulkan_disabled(
		const std::string& label, 
		const VkSampleCountFlagBits samples 
	);

	MICRO_API bool input_vulkan(
		const std::string& label,
		VkColorSpaceKHR& color_space
	);

	MICRO_API void input_vulkan_disabled(
		const std::string& label,
		const VkColorSpaceKHR color_space
	);

	MICRO_API bool input_vulkan( 
		const std::string& label, 
		VkImageTiling& tiling 
	);

	MICRO_API void input_vulkan_disabled(
		const std::string& label, 
		const VkImageTiling tiling 
	);

	MICRO_API bool input_vulkan( 
		const std::string& label, 
		VkFilter& filter 
	);

	MICRO_API void input_vulkan_disabled(
		const std::string& label, 
		const VkFilter filter 
	);

	MICRO_API bool input_vulkan( 
		const std::string& label, 
		VkCompareOp& compare_op 
	);

	MICRO_API void input_vulkan_disabled(
		const std::string& label, 
		const VkCompareOp compare_op 
	);

	MICRO_API bool input_vulkan( 
		const std::string& label, 
		VkBorderColor& border_color 
	);

	MICRO_API void input_vulkan_disabled(
		const std::string& label, 
		const VkBorderColor border_color 
	);

	MICRO_API bool input_vulkan( 
		const std::string& label, 
		VkViewport& viewport 
	);

	MICRO_API void input_vulkan_disabled(
		const std::string& label, 
		const VkViewport& viewport 
	);

	MICRO_API bool input_vulkan( 
		const std::string& label, 
		VkScissor& scissor 
	);

	MICRO_API void input_vulkan_disabled(
		const std::string& label, 
		const VkScissor& scissor 
	);

	template<typename VkType>
		requires ( vk::IsVkObject<VkType> )
	void input_vulkan( const std::string& label, const VkType& object ) {
		const auto state = vk::IsValid( object );

		micro_im::checkbox_disabled( label, state );
	};

	template<typename Type>
	bool input_vulkan(
		const std::string& label,
		const std::vector<micro_im::EnumPair>& enum_pairs,
		Type& enum_value
	) {
		auto index		 = micro_im::find_vulkan_enum( enum_pairs, (uint32_t)enum_value );
		const auto state = micro_im::dropdown( label, enum_pairs, index );

		if ( state )
			enum_value = (Type)enum_pairs[ index ].Value;

		return state;
	};

	template<typename Type>
	void input_vulkan_disabled(
		const std::string& label,
		const std::vector<micro_im::EnumPair>& enum_pairs,
		const Type enum_value
	) {
		const auto index = micro_im::find_vulkan_enum( enum_pairs, (uint32_t)enum_value );
		
		micro_im::dropdown_disabled( label, enum_pairs, index );
	};

};
