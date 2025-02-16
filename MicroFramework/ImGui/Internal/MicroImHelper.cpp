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

static micro_string img_int_format = "%d";
static micro_string img_float_format = "%.3f";
static ImVec2 img_tooltip = ImVec2{ 128.f, 128.f };
static micro_im::ImAxis img_axis[ 4 ] = {
	{ "X", IM_COL32( 168,  46,   2, 255 ) },
	{ "Y", IM_COL32( 112, 162,  22, 255 ) },
	{ "Z", IM_COL32(  51, 122, 210, 255 ) },
	{ "W", IM_COL32( 210, 183,  51, 255 ) }
};

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC ===
////////////////////////////////////////////////////////////////////////////////////////////
namespace micro_im {

	ImAxis::ImAxis(
		micro_string value,
		const ImU32 color
	)
		: Value{ value },
		Color{ color }
	{ }

	void set_int_format( micro_string format ) {
		img_int_format = format;
	}

	void set_float_format( micro_string format ) {
		img_float_format = format;
	}

	micro_string get_int_format( ) {
		return img_int_format;
	}

	micro_string get_float_format( ) {
		return img_float_format;
	}

	ImAxis get_axis( const uint32_t axis_id ) {
		micro_assert( axis_id < 4, "You can't get an axis value after 4 components." );

		return img_axis[ axis_id ];
	}

	void set_image_tooltip_size( const ImVec2& size ) { 
		img_tooltip = size; 
	}

	ImVec2 get_text_size( const std::string& text ) {
		const auto* string = text.c_str( );

		return micro_im::get_text_size( string );
	}

	ImVec2 get_text_size( micro_string text ) {
		auto& style = ImGui::GetStyle( );
		auto size   = ImGui::CalcTextSize( text );

		size.x += 2.f * style.FramePadding.x;
		size.y += 2.f * style.FramePadding.y;

		return size;
	}

	void shift_cursor_x( const float distance ) {
		const auto cursor_x = ImGui::GetCursorPosX( );

		ImGui::SetCursorPosX( cursor_x + distance );
	}

	void shift_cursor_y( const float distance ) {
		const auto cursor_y = ImGui::GetCursorPosY( );

		ImGui::SetCursorPosY( cursor_y + distance );
	}

	void shift_cursor( const float x, const float y ) {
		const auto cursor = ImGui::GetCursorPos( );

		ImGui::SetCursorPos( { cursor.x + x, cursor.y + y } );
	}

	void separator_text( const std::string& label ) {
		const auto* label_string = label.c_str( );

		micro_im::end_vars( );

		ImGui::SeparatorText( label_string );

		micro_im::begin_vars( );
	}

	bool begin_modal( const std::string& label ) {
		const auto* label_string = label.c_str( );
		const auto center		 = ImGui::GetMainViewport( )->GetCenter( );

		ImGui::SetNextWindowPos( center, ImGuiCond_Appearing, { .5f, .5f } );

		return ImGui::BeginPopupModal( label_string, nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize );
	}

	void end_modal( ) { 
		ImGui::EndPopup( ); 
	}

	void input_begin( const std::string& label ) {
		const auto* label_string = label.c_str( );

		ImGui::TableSetColumnIndex( 0 );
		ImGui::AlignTextToFramePadding( );
		ImGui::TextUnformatted( label_string );
		ImGui::NextColumn( );
		ImGui::PushItemWidth( -1.f );
	}

	void input_end( ) {
		ImGui::PopItemWidth( );
		ImGui::NextColumn( );
	}

	void input_separator( ) {
		ImGui::NextColumn( );
		ImGui::NextColumn( );

		const auto cursor = ImGui::GetCursorScreenPos( );
		const auto size   = ImGui::GetItemRectMax( );
		const auto min	  = ImVec2{ cursor.x, cursor.y };
		const auto max	  = ImVec2{ cursor.x + size.x, cursor.y + 1.f };

		ImGui::GetWindowDrawList( )->AddRectFilled( min, max, ImGui::GetColorU32( ImGuiCol_Separator ) );
		ImGui::Dummy( { 0.f, 2.f } );
	}

	void begin_vars( ) {
		const auto size = micro_im::get_text_size( "################" ).x;

		ImGui::Columns( 2 );
		ImGui::SetColumnWidth( 0, size );
	}

	void end_vars( ) { 
		ImGui::EndColumns( ); 
	}

};
