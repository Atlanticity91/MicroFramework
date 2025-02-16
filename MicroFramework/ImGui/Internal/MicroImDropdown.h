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

#include "MicroImCheckbox.h"

namespace micro_im {

	MICRO_API micro_string combo_string_getter( void* data, int32_t index );

	MICRO_API micro_string combo_enum_pair_getter( void* data, int32_t index );

	MICRO_API bool combo(
		const std::string& label,
		const void* data,
		const uint32_t size,
		micro_string( *getter )( void*, int32_t ),
		uint32_t& index
	);

	MICRO_API void combo_disabled(
		const std::string& label,
		const void* data,
		const uint32_t size,
		micro_string( *getter )( void*, int32_t ),
		const uint32_t index
	);

	MICRO_API bool dropdown(
		const std::string& label,
		const std::vector<micro_string>& values,
		uint32_t& index
	);

	MICRO_API void dropdown_disabled(
		const std::string& label,
		const std::vector<micro_string>& values,
		const uint32_t index
	);

	MICRO_API bool dropdown(
		const std::string& label,
		std::initializer_list<micro_string> values,
		uint32_t& index
	);

	MICRO_API void dropdown_disabled(
		const std::string& label,
		std::initializer_list<micro_string> values,
		const uint32_t index
	);

	MICRO_API bool dropdown(
		const std::string& label,
		const EnumPair* pairs,
		uint32_t& index
	);

	MICRO_API void dropdown_disabled(
		const std::string& label,
		const EnumPair* pairs,
		const uint32_t index
	);

	MICRO_API bool dropdown(
		const std::string& label,
		const std::vector<EnumPair>& pairs,
		uint32_t& index
	);

	MICRO_API void dropdown_disabled(
		const std::string& label,
		const std::vector<EnumPair>& pairs,
		const uint32_t index
	);

	MICRO_API bool dropdown(
		const std::string& label,
		std::initializer_list<EnumPair> pairs,
		uint32_t& index
	);

	MICRO_API void dropdown_disabled(
		const std::string& label,
		std::initializer_list<EnumPair> pairs,
		const uint32_t index
	);

};
