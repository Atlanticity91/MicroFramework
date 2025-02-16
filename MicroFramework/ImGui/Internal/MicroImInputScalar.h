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

#include "MicroImInputText.h"

namespace micro_im {

	MICRO_API bool input_scalar( 
		const std::string& label, 
		const ImGuiDataType type,
		void* scalar 
	);

	MICRO_API void input_scalar_disabled(
		const std::string& label,
		const ImGuiDataType type,
		const void* scalar
	);

	template<typename Literal>
		requires ( micro_im::is_scalar<Literal> )
	bool input_scalar( const std::string& label, Literal& scalar ) {
		constexpr auto type = get_imgui_type<Literal>;

		return micro_im::input_scalar( label, type, micro_ptr_as( scalar, void* ) );
	};

	template<typename Literal>
		requires ( micro_im::is_scalar<Literal> )
	void input_scalar_disabled( 
		const std::string& label, 
		const Literal scalar 
	) {
		constexpr auto type = get_imgui_type<Literal>;

		micro_im::input_scalar_disabled( label, type, micro_ptr_as( scalar, const void* ) );
	};

	template<typename Literal>
		requires ( micro_im::is_scalar<Literal> )
	bool input_scalar( const std::string& label, Literal* scalar ) {
		constexpr auto type = get_imgui_type<Literal>;

		return micro_im::input_scalar( label, type, micro_cast( scalar, void* ) );
	};

	template<typename Literal>
		requires ( micro_im::is_scalar<Literal> )
	void input_scalar_disabled( 
		const std::string& label, 
		const Literal* scalar
	) {
		constexpr auto type = get_imgui_type<Literal>;

		micro_im::input_scalar_disabled( label, type, micro_cast( scalar, const void* ) );
	};

};
