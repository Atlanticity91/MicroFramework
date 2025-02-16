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

	float convert_srgb_from_linear( const float theLinearValue ) {
		return theLinearValue <= 0.0031308f ? theLinearValue * 12.92f : glm::pow( theLinearValue, 1.0f / 2.2f ) * 1.055f - 0.055f;
	}

	float convert_srgb_to_linear( const float thesRGBValue ) {
		return thesRGBValue <= 0.04045f ?  thesRGBValue / 12.92f : glm::pow( ( thesRGBValue + 0.055f ) / 1.055f, 2.2f );
	}

	ImVec4 ConvertFromSRGB( const ImVec4 colour ) {
		return { 
			micro_im::convert_srgb_from_linear( colour.x ),
			micro_im::convert_srgb_from_linear( colour.y ),
			micro_im::convert_srgb_from_linear( colour.z ),
			colour.w 
		};
	}

	ImVec4 convert_to_srgb( const ImVec4 colour ) {
		return {
			std::pow( colour.x, 2.2f ),
			glm::pow( colour.y, 2.2f ),
			glm::pow( colour.z, 2.2f ),
			colour.w 
		};
	}

	ImU32 color_with_value( const ImColor& color, const float value ) {
		auto hue = 0.f;
		auto sat = 0.f;
		auto val = 0.f;

		ImGui::ColorConvertRGBtoHSV( color.Value.x, color.Value.y, color.Value.z, hue, sat, val );

		return ImColor::HSV( hue, sat, std::min( value, 1.0f ) );
	}

	ImU32 color_with_saturation( const ImColor& color, const float saturation ) {
		auto hue = 0.f;
		auto sat = 0.f;
		auto val = 0.f;

		ImGui::ColorConvertRGBtoHSV( color.Value.x, color.Value.y, color.Value.z, hue, sat, val );

		return ImColor::HSV( hue, std::min( saturation, 1.0f ), val );
	}

	ImU32 color_with_hue( const ImColor& color, const float hue ) {
		auto h = 0.f;
		auto sat = 0.f;
		auto val = 0.f;

		ImGui::ColorConvertRGBtoHSV( color.Value.x, color.Value.y, color.Value.z, h, sat, val );

		return ImColor::HSV( std::min( hue, 1.0f ), sat, val );
	}

	ImU32 color_with_multiplied_value(
		const ImColor& color,
		const float multiplier
	) {
		auto hue = 0.f;
		auto sat = 0.f;
		auto val = 0.f;

		ImGui::ColorConvertRGBtoHSV( color.Value.x, color.Value.y, color.Value.z, hue, sat, val );

		return ImColor::HSV( hue, sat, std::min( val * multiplier, 1.0f ) );
	}

	ImU32 color_with_multiplied_saturation(
		const ImColor& color,
		const float multiplier
	) {
		auto hue = 0.f;
		auto sat = 0.f;
		auto val = 0.f;

		ImGui::ColorConvertRGBtoHSV( color.Value.x, color.Value.y, color.Value.z, hue, sat, val );

		return ImColor::HSV( hue, std::min( sat * multiplier, 1.0f ), val );
	}

	ImU32 color_with_multiplied_hue(
		const ImColor& color,
		const float multiplier
	) {
		auto hue = 0.f;
		auto sat = 0.f;
		auto val = 0.f;

		ImGui::ColorConvertRGBtoHSV( color.Value.x, color.Value.y, color.Value.z, hue, sat, val );

		return ImColor::HSV( std::min( hue * multiplier, 1.0f ), sat, val );
	}

	bool input_color( const std::string& label, uint8_t* color ) {
		float channels[ 4 ] = { 
			color[ 0 ] / 255.f, 
			color[ 1 ] / 255.f, 
			color[ 2 ] / 255.f, 
			color[ 3 ] / 255.f
		};
		const auto state = micro_im::input_color( label, channels );

		if ( state ) {
			for ( auto channel_id = 0; channel_id < 4; channel_id++ )
				color[ channel_id ] = (uint8_t)( channels[ channel_id ] * 255.f );
		}

		return state;
	};

	void input_color_disabled( const std::string& label, const uint8_t* color ) {
		const float channels[ 4 ] = {
			color[ 0 ] / 255.f,
			color[ 1 ] / 255.f,
			color[ 2 ] / 255.f,
			color[ 3 ] / 255.f
		};

		micro_im::input_color_disabled( label, channels );
	}
	
	bool input_color( const std::string& label, float* color ) {
		micro_im::input_begin( label );

		micro_imgui_scope_id(
			const auto state = ImGui::ColorEdit4( micro_imgui_no_label, color, ImGuiColorEditFlags_DisplayRGB | ImGuiColorEditFlags_InputRGB | ImGuiColorEditFlags_AlphaPreviewHalf );
		);

		micro_im::input_end( );

		return state;
	}
	
	void input_color_disabled( const std::string& label, const float* color ) {
		ImGui::BeginDisabled( );

		micro_im::input_color( label, micro_cast( color, float* ) );

		ImGui::EndDisabled( );
	}

	bool input_color( const std::string& label, MicroColor* color ) {
		auto* channels = color->Get( );

		return micro_im::input_color( label, channels );
	}
	
	void input_color_disabled( const std::string& label, const MicroColor* color ) {
		const auto* channels = color->Get( );

		micro_im::input_color_disabled( label, channels );
	}

	bool input_color( const std::string& label, MicroColor& color ) {
		auto* channels = color.Get( );

		return micro_im::input_color( label, channels );
	}
	
	void input_color_disabled( const std::string& label, const MicroColor& color ) {
		const auto* channels = color.Get( );

		return micro_im::input_color_disabled( label, channels );
	}

};
