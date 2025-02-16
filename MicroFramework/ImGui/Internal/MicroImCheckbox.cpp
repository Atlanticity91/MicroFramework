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

	bool checkbox( const std::string& label, bool* value ) {
		micro_assert( value != nullptr, "" );

		micro_im::input_begin( label );

		micro_imgui_scope_id(
			const auto state = ImGui::Checkbox( micro_imgui_no_label, value );
		);

		micro_im::input_end( );

		return state;
	}

	void checkbox_disabled( const std::string& label, const bool* value ) {
		ImGui::BeginDisabled( );

		micro_im::checkbox( label, micro_cast( value, bool* ) );

		ImGui::EndDisabled( );
	}

	bool checkbox( const std::string& label, bool& value ) {
		return micro_im::checkbox( label, micro_ptr( value ) );
	}

	void checkbox_disabled( const std::string& label, const bool& value ) {
		micro_im::checkbox_disabled( label, micro_ptr( value ) );
	}

	bool checkbox( const std::string& label, int8_t& value ) {
		return micro_im::checkbox( label, micro_ptr_as( value, bool* ) );
	}

	void checkbox_disabled(
		const std::string& label,
		const int8_t value
	) {
		micro_im::checkbox_disabled( label, micro_ptr_as( value, const bool* ) );
	}

	bool checkbox( const std::string& label, int8_t* value ) {
		return micro_im::checkbox( label, micro_cast( value, bool* ) );
	}

	void checkbox_disabled(
		const std::string& label,
		const int8_t* value
	) {
		micro_im::checkbox_disabled( label, micro_cast( value, const bool* ) );
	}

	bool checkbox( const std::string& label, uint8_t& value ) {
		return micro_im::checkbox( label, micro_ptr_as( value, bool* ) );
	}

	void checkbox_disabled(
		const std::string& label,
		const uint8_t value
	) {
		micro_im::checkbox_disabled( label, micro_ptr_as( value, const bool* ) );
	}

	bool checkbox( const std::string& label, uint8_t* value ) {
		return micro_im::checkbox( label, micro_cast( value, bool* ) );
	}

	void checkbox_disabled(
		const std::string& label,
		const uint8_t* value
	) {
		micro_im::checkbox_disabled( label, micro_cast( value, const bool* ) );
	}

	bool checkbox( const std::string& label, int32_t& value ) {
		return micro_im::checkbox( label, micro_ptr_as( value, bool* ) );
	}

	void checkbox_disabled(
		const std::string& label,
		const int32_t value
	) {
		micro_im::checkbox_disabled( label, micro_ptr_as( value, const bool* ) );
	}

	bool checkbox( const std::string& label, int32_t* value ) {
		return micro_im::checkbox( label, micro_cast( value, bool* ) );
	}

	void checkbox_disabled(
		const std::string& label,
		const int32_t* value
	) {
		micro_im::checkbox_disabled( label, micro_cast( value, const bool* ) );
	}
	
	bool checkbox( const std::string& label, uint32_t& value ) {
		return micro_im::checkbox( label, micro_ptr_as( value, bool* ) );
	}

	void checkbox_disabled(
		const std::string& label,
		const uint32_t value
	) {
		micro_im::checkbox_disabled( label, micro_ptr_as( value, const bool* ) );
	}

	bool checkbox( const std::string& label, uint32_t* value ) {
		return micro_im::checkbox( label, micro_cast( value, bool* ) );
	}

	void checkbox_disabled(
		const std::string& label,
		const uint32_t* value
	) {
		micro_im::checkbox_disabled( label, micro_cast( value, const bool* ) );
	}

};
