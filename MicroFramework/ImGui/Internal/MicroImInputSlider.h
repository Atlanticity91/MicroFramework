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

#include "MicroImInputScalar.h"

namespace micro_im {

	MICRO_API bool input_slider(
		const std::string& label,
		const ImGuiDataType type,
		const uint32_t component,
		micro_string format,
		void* data,
		void* min,
		void* max
	);

	MICRO_API void input_slider_disabled(
		const std::string& label,
		const ImGuiDataType type,
		const uint32_t component,
		micro_string format,
		const void* data
	);

	MICRO_API bool input_slider(
		const std::string& label, 
		const int32_t min, 
		const int32_t max, 
		micro_point& point
	);

	MICRO_API void input_slider_disabled(
		const std::string& label, 
		const micro_point& point
	);

	MICRO_API bool input_slider(
		const std::string& label, 
		const uint32_t min, 
		const uint32_t max, 
		micro_upoint& point
	);

	MICRO_API void input_slider_disabled(
		const std::string& label, 
		const micro_upoint& point
	);

	MICRO_API bool input_slider(
		const std::string& label, 
		const float min, 
		const float max, 
		micro_vec2& vector
	);

	MICRO_API void input_slider_disabled(
		const std::string& label, 
		const micro_vec2& vector
	);

	MICRO_API bool input_slider(
		const std::string& label, 
		const float min, 
		const float max, 
		micro_vec3& vector 
	);

	MICRO_API void input_slider_disabled(
		const std::string& label, 
		const micro_vec3& vector 
	);

	MICRO_API bool input_slider(
		const std::string& label, 
		const float min, 
		const float max, 
		micro_vec4& vector
	);

	MICRO_API void input_slider_disabled(
		const std::string& label,
		const micro_vec4& vector
	);

	template<typename Type>
		requires ( micro_im::is_scalar<Type> )
	bool input_slider(
		const std::string& label,
		const uint32_t component,
		const Type min,
		const Type max,
		Type& data
	) {
		const auto type   = micro_im::get_imgui_type<Type>;
		const auto format = std::is_integral_v<Type> ? micro_im::get_int_format( ) : micro_im::get_float_format( );

		return micro_im::input_slider( label, type, 1, format, micro_ptr_as( data, void* ), micro_ptr_as( min, void* ), micro_ptr_as( max, void* ) );
	};

	template<typename Type>
		requires ( micro_im::is_scalar<Type> )
	void input_slider_disabled(
		const std::string& label,
		const uint32_t component,
		const Type data
	) {
		const auto type   = micro_im::get_imgui_type<Type>;
		const auto format = std::is_integral_v<Type> ? micro_im::get_int_format( ) : micro_im::get_float_format( );

		return micro_im::input_slider_disabled( label, type, 1, format, micro_ptr_as( data, void* ) );
	};

	template<typename Type>
		requires ( micro_im::is_scalar<Type> )
	bool input_slider( 
		const std::string& label,
		const uint32_t component,
		const Type min,
		const Type max,
		Type* data
	) { 
		const auto type   = micro_im::get_imgui_type<Type>;
		const auto format = std::is_integral_v<Type> ? micro_im::get_int_format( ) : micro_im::get_float_format( );

		return micro_im::input_slider( label, type, 1, format, micro_cast( data, void* ), micro_ptr_as( min, void* ), micro_ptr_as( max, void* ) );
	};

	template<typename Type>
		requires ( micro_im::is_scalar<Type> )
	void input_slider_disabled(
		const std::string& label,
		const uint32_t component,
		const Type* data
	) {
		const auto type   = micro_im::get_imgui_type<Type>;
		const auto format = std::is_integral_v<Type> ? micro_im::get_int_format( ) : micro_im::get_float_format( );

		return micro_im::input_slider_disabled( label, type, 1, format, micro_cast( data, void* ) );
	};

};
