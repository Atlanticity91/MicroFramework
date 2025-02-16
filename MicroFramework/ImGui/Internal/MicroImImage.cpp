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

	ImTextureID create_texture( const MicroVulkanTexture* texture ) {
		auto texture_id = (ImTextureID)0;

		if ( texture != nullptr ) {
			const auto sampler = texture->GetSampler( );
			const auto view    = texture->GetView( );

			texture_id = micro_cast( ImGui_ImplVulkan_AddTexture( sampler, view, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL ), ImTextureID );
		}

		return texture_id;
	}

	ImTextureID create_texture( const MicroVulkanTexture& texture ) {
		return micro_im::create_texture( micro_ptr( texture ) );
	}

	ImTextureID create_texture( const GlwTexture2D* texture ) {
		auto texture_id = (ImTextureID)0;

		if ( texture != nullptr )
			texture_id = texture->Get( );

		return texture_id;
	}

	ImTextureID create_texture( const GlwTexture2D& texture ) {
		return micro_im::create_texture( micro_ptr( texture ) );
	}

	ImTextureID create_texture( const MicroTexture* texture ) {
		auto texture_id = (ImTextureID)0;

		if ( texture != nullptr ) {
			/*
			const auto sampler = texture->GetSampler( );
			const auto view    = texture->GetView( );

			texture_id = ImGui_ImplVulkan_AddTexture( sampler, view, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL );
			*/
		}

		return texture_id;
	}

	ImTextureID create_texture( const MicroTexture& texture ) {
		return create_texture( micro_ptr( texture ) );
	}

	void destroy_texture( ImTextureID& texture_id ) {
		if ( texture_id == 0 )
			return;

		ImGui_ImplVulkan_RemoveTexture( micro_cast( texture_id, VkDescriptorSet ) );

		texture_id = 0;
	}

};
