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

#include "MicroImInputVector.h"

namespace micro_im {

	MICRO_API bool InputDrag(
		const std::string& label,
		const uint32_t component,
		const float speed,
		const float min,
		const float max,
		float* vector
	);

	MICRO_API bool InputDrag(
		const std::string& label,
		const uint32_t component,
		const int8_t speed,
		const int8_t min,
		const int8_t max,
		int8_t* vector
	);

	MICRO_API bool InputDrag(
		const std::string& label,
		const uint32_t component,
		const int16_t speed,
		const int16_t min,
		const int16_t max,
		int16_t* vector
	);

	MICRO_API bool InputDrag(
		const std::string& label,
		const uint32_t component,
		const int32_t speed,
		const int32_t min,
		const int32_t max,
		int32_t* vector
	);

	MICRO_API bool InputDrag(
		const std::string& label,
		const uint32_t component,
		const int64_t speed,
		const int64_t min,
		const int64_t max,
		int64_t* vector
	);

	MICRO_API bool InputDrag(
		const std::string& label,
		const uint32_t component,
		const uint8_t speed,
		const uint8_t min,
		const uint8_t max,
		uint8_t* vector
	);

	MICRO_API bool InputDrag(
		const micro_string& label,
		const uint32_t component,
		const uint16_t speed,
		const uint16_t min,
		const uint16_t max,
		uint16_t* vector
	);

	MICRO_API bool InputDrag(
		const micro_string& label,
		const uint32_t component,
		const uint32_t speed,
		const uint32_t min,
		const uint32_t max,
		uint32_t* vector
	);

	MICRO_API bool InputDrag(
		const std::string& label,
		const uint32_t component,
		const uint64_t speed,
		const uint64_t min,
		const uint64_t max,
		uint64_t* vector
	);

};
