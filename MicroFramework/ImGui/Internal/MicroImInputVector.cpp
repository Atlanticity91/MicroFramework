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

	bool input_vector( 
		const std::string& label,
		const ImGuiDataType type,
		const uint32_t component,
		micro_string format,
		void* data
	) { 
		micro_assert( component < 4, "Vector only support to 4 components." );

		auto state = false;
		
		micro_im::input_begin( label );
		
		for ( auto axis_id = (uint32_t)0; axis_id < component; axis_id++ ) {
			micro_im::input_axis( axis_id, [ & ]( ) {
				state = ImGui::InputScalarN( micro_imgui_no_label, type, data, component, nullptr, nullptr, format );
			} );
		}

		if ( component > 1 )
			micro_im::input_separator( );

		micro_im::input_end( );

		return state;
	}

	void input_vector_disabled(
		const std::string& label,
		const ImGuiDataType type,
		const uint32_t component,
		micro_string format,
		const void* data
	) {
		ImGui::BeginDisabled( );

		micro_im::input_vector( label, type, component, format, micro_cast( data, void* ) );

		ImGui::EndDisabled( );
	}

	bool input_vector(
		const std::string& label,
		micro_point& point
	) {
		return micro_im::input_vector( label, 2, micro_ptr( point.x ) );
	}

	void input_vector_disabled(
		const std::string& label,
		const micro_point& point
	) {
		micro_im::input_vector_disabled( label, 2, micro_ptr( point.x ) );
	}

	bool input_vector(
		const std::string& label,
		micro_upoint& point
	) {
		return micro_im::input_vector( label, 2, micro_ptr( point.x ) );
	}

	void input_vector_disabled(
		const std::string& label,
		const micro_upoint& point
	) {
		micro_im::input_vector_disabled( label, 2, micro_ptr( point.x ) );
	}

	bool input_vector(
		const std::string& label,
		micro_vec2& vector
	) {
		return micro_im::input_vector( label, 2, micro_ptr( vector.x ) );
	}

	void input_vector_disabled(
		const std::string& label,
		const micro_vec2& vector
	) {
		micro_im::input_vector_disabled( label, 2, micro_ptr( vector.x ) );
	}

	bool input_vector(
		const std::string& label,
		micro_vec3& vector
	) {
		return micro_im::input_vector( label, 3, micro_ptr( vector.x ) );
	}

	void input_vector_disabled(
		const std::string& label,
		const micro_vec3& vector
	) {
		micro_im::input_vector_disabled( label, 3, micro_ptr( vector.x ) );
	}

	bool input_vector(
		const std::string& label,
		micro_vec4& vector
	) {
		return micro_im::input_vector( label, 4, micro_ptr( vector.x ) );
	}
	
	void input_vector_disabled(
		const std::string& label,
		const micro_vec4& vector
	) {
		micro_im::input_vector_disabled( label, 4, micro_ptr( vector.x ) );
	}

};
