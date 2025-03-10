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

#include "../../Graphics/MicroVulkanGraphicManager.h"

#define micro_imgui_no_label "##micro_imgui_no_label"
#define micro_imgui_scope_id( ... )\
    ImGui::PushID( (int32_t)( ImGui::GetCursorPosX( ) + ImGui::GetCursorPosY( ) ) );\
    __VA_ARGS__\
    ImGui::PopID( )

#define micro_im_enum( ENUM_VALUE )\
	EnumPair{ (uint32_t)ENUM_VALUE, micro_stringify( ENUM_VALUE ) }

namespace micro_im {

	#define micro_imgui_type( TYPE, VALUE )\
		template<> constexpr ImGuiDataType get_imgui_type<TYPE> = (ImGuiDataType) VALUE

	micro_struct ImAxis final {

		micro_string Value;
		ImU32 Color;

		ImAxis( micro_string value, const ImU32 color );

	};

	micro_struct EnumPair final {

		uint32_t Value;
		micro_string Text;

		EnumPair( const uint32_t value, micro_string text );

	};

	MICRO_API void set_int_format( micro_string format );
	
	MICRO_API void set_float_format( micro_string format );

	MICRO_API micro_string get_int_format( );

	MICRO_API micro_string get_float_format( );

	MICRO_API ImAxis get_axis( const uint32_t axis_id );

	MICRO_API void set_image_tooltip_size( const ImVec2& size );

	MICRO_API ImVec2 get_text_size( const std::string& text );

	MICRO_API ImVec2 get_text_size( micro_string text );

	MICRO_API void shift_cursor_x( const float distance );

	MICRO_API void shift_cursor_y( const float distance );

	MICRO_API void shift_cursor( const float x, const float y );

	MICRO_API void separator_text( const std::string& label );

	MICRO_API bool begin_modal( const std::string& label );

	MICRO_API void end_modal( );

	MICRO_API void input_begin( const std::string& label );

	MICRO_API void input_end( );

	MICRO_API void input_separator( );

	MICRO_API void begin_vars( );

	MICRO_API void end_vars( );

	template<typename Type>
	constexpr ImGuiDataType get_imgui_type = (ImGuiDataType)ImGuiDataType_COUNT;

	micro_imgui_type( int8_t, ImGuiDataType_S8 );
	micro_imgui_type( uint8_t, ImGuiDataType_U8 );
	micro_imgui_type( int16_t, ImGuiDataType_S16 );
	micro_imgui_type( uint16_t, ImGuiDataType_U16 );
	micro_imgui_type( int32_t, ImGuiDataType_S32 );
	micro_imgui_type( uint32_t, ImGuiDataType_U32 );
	micro_imgui_type( int64_t, ImGuiDataType_S64 );
	micro_imgui_type( uint64_t, ImGuiDataType_U64 ); 
	micro_imgui_type( float, ImGuiDataType_Float );
	micro_imgui_type( double, ImGuiDataType_Double );
	micro_imgui_type( bool, ImGuiDataType_Bool );
	micro_imgui_type( micro_string, ImGuiDataType_String );

	template<typename Type>
	concept is_scalar = std::is_integral_v<Type> || std::is_floating_point_v<Type>;

	template<typename ImFunc>
	void input_axis( const uint32_t axis_id, ImFunc&& im_function ) {
		const auto& style = ImGui::GetStyle( );
		const auto axis   = micro_im::get_axis( axis_id );
		const auto size   = micro_im::get_text_size( axis.Value );

		ImGui::AlignTextToFramePadding( );
		ImGui::TextUnformatted( axis.Value );
		ImGui::SameLine( size.x + style.ItemSpacing.x * 1.25f );

		const auto cursor = ImGui::GetCursorScreenPos( );
		const auto axis_offset = ImVec2{

			cursor.x - style.FramePadding.x,
			cursor.y

		};
		const auto axis_background = ImRect{

		   axis_offset.x,
		   axis_offset.y,
		   axis_offset.x + size.x * .25f,
		   axis_offset.y + size.y

		};

		ImGui::GetWindowDrawList( )->AddRectFilled( axis_background.Min, axis_background.Max, axis.Color, style.FrameRounding );
		ImGui::PushItemWidth( -1 );

		micro_imgui_scope_id(
			std::invoke( im_function );
		);

		ImGui::PopItemWidth( );
	}

	template<typename Functor, typename... Args>
	void collapsing_header( 
		const std::string& name,
		const ImGuiTreeNodeFlags flags,
		Functor&& collapsing_content,
		Args&&... args 
	) {
		const auto* name_str = name.c_str( );

		if ( ImGui::CollapsingHeader( name_str, flags ) ) {
			std::invoke( std::forward<Functor>( collapsing_content ), std::forward<Args>( args )... );

			ImGui::Separator( );
		}
	};

};
