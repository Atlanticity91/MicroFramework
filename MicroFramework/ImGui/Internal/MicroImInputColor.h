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

#include "MicroImInputDrag.h"

namespace micro_im {

	MICRO_API float convert_srgb_from_linear( const float theLinearValue );

	MICRO_API float convert_srgb_to_linear( const float thesRGBValue );

	MICRO_API ImVec4 convert_from_srgb( const ImVec4 colour );

	MICRO_API ImVec4 convert_to_srgb( const ImVec4 colour );

	MICRO_API ImU32 color_with_value( const ImColor& color, const float value );

	MICRO_API ImU32 color_with_saturation(
		const ImColor& color, 
		const float saturation 
	);

	MICRO_API ImU32 color_with_hue( const ImColor& color, const float hue );

	MICRO_API ImU32 color_with_multiplied_value(
		const ImColor& color, 
		const float multiplier 
	);

	MICRO_API ImU32 color_with_multiplied_saturation(
		const ImColor& color, 
		const float multiplier 
	);

	MICRO_API ImU32 color_with_multiplied_hue( 
		const ImColor& color, 
		const float multiplier 
	);

	MICRO_API bool input_color( const std::string& label, uint8_t* color );

	MICRO_API void input_color_disabled( const std::string& label, const uint8_t* color );

	MICRO_API bool input_color( const std::string& label, float* color );
	
	MICRO_API void input_color_disabled( const std::string& label, const float* color );

	MICRO_API bool input_color( const std::string& label, MicroColor* color );

	MICRO_API void input_color_disabled( const std::string& label, const MicroColor* color );

	MICRO_API bool input_color( const std::string& label, MicroColor& color );

	MICRO_API void input_color_disabled( const std::string& label, const MicroColor& color );

};
