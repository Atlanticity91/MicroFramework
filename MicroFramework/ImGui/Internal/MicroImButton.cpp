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

	bool button( const std::string& label ) {
		return micro_im::button( label, { 0.f, 0.f } );
	}

	bool button( const std::string& label, const ImVec2& size ) {
		micro_imgui_scope_id(
			const auto* label_string = label.c_str( );
			const auto state = ImGui::Button( label_string, size );
		);

		return state;
	}

	bool button( const std::string& label, micro_string icon ) {
		return micro_im::button( label, { 0.f, 0.f }, icon );
	}

	bool button(
		const std::string& label,
		const ImVec2& size,
		micro_string icon
	) {
		auto button_label = std::string{ icon };

		button_label += " ";
		button_label += label;

		return micro_im::button( label, size );
	}

	bool button_left( const std::string& label ) {
		return micro_im::button_left( label, { -1.f, 0.f } );
	}

	bool button_left(
		const std::string& label,
		const ImVec2& size
	) {
		const auto cursor = ImGui::GetCursorPosX( );

		ImGui::SetCursorPosX( cursor );

		return micro_im::button( label, size );
	}

	bool button_left(
		const std::string& label,
		const ImVec2& size,
		micro_string icon
	) {
		auto button_label = std::string{ icon };

		button_label += " ";
		button_label += label;

		return micro_im::button_left( button_label, size );
	}

	bool button_right( const std::string& label ) {
		return micro_im::button_right( label, { -1.f, 0.f } );
	}

	bool button_right(
		const std::string& label,
		const ImVec2& size
	) {
		const auto offset = ImGui::CalcTextSize( "############" ).x;
		const auto cursor = ImGui::GetCursorPosX( ) + ImGui::GetContentRegionAvail( ).x;

		ImGui::SetCursorPosX( cursor - offset );

		return micro_im::button( label, size );
	}

	bool button_right(
		const std::string& label,
		const ImVec2& size,
		micro_string icon
	) {
		auto button_label = std::string{ icon };

		button_label += " ";
		button_label += label;

		return micro_im::button_right( button_label, size );
	}

	ImVec2 button_span_left( const uint32_t button_count ) {
		auto& style = ImGui::GetStyle( );
		const auto button_size = ImGui::CalcTextSize( "##############" ).x + style.FramePadding.x * 2.f;

		return { button_size, 0.f };
	}

	ImVec2 button_span_right( const uint32_t button_count ) {
		auto& style = ImGui::GetStyle( );
		const auto button_size = ImGui::CalcTextSize( "##############" ).x + style.FramePadding.x * 2.f;
		const auto span_width = ( button_size + style.ItemSpacing.x ) * button_count - style.ItemSpacing.x;
		const auto cusor_offset = ImGui::GetCursorPosX( ) + ImGui::GetContentRegionAvail( ).x - span_width;

		ImGui::SetCursorPosX( cusor_offset );

		return { button_size, 0.f };
	}

};
