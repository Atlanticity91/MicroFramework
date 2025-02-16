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

#include "__micro_framework_pch.h"

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC ===
////////////////////////////////////////////////////////////////////////////////////////////
namespace micro_im {

	micro_string combo_string_getter( void* data, int32_t idx ) {
		const auto* items = micro_cast( data, micro_string* );

		return items[ idx ];
	}

	micro_string combo_enum_pair_getter( void* data, int32_t index ) {
		const auto* items = micro_cast( data, const EnumPair* );

		return items[ index ].Text;
	}

	bool combo(
		const std::string& label,
		const void* data,
		const uint32_t size,
		micro_string( *getter )( void*, int32_t ),
		uint32_t& index
	) {
		micro_assert( data != nullptr, "You can't make a combo with no values." );
		micro_assert( size > 0, "You can't make a combo with no values." );
		micro_assert( getter != nullptr, "You can't make a combo without getter function." );

		micro_im::input_begin( label );

		micro_imgui_scope_id(
			const bool state = ImGui::Combo( micro_imgui_no_label, micro_ptr_as( index, int32_t* ), getter, micro_cast( data, void* ), (int32_t)size, -1 );
		);

		micro_im::input_end( );

		return state;
	}

	void combo_disabled(
		const std::string& label,
		const void* data,
		const uint32_t size,
		micro_string( *getter )( void*, int32_t ),
		const uint32_t index
	) {
		micro_assert( data != nullptr, "You can't make a combo with no values." );
		micro_assert( size > 0, "You can't make a combo with no values." );
		micro_assert( getter != nullptr, "You can't make a combo without getter function." );

		auto tmp_index = (uint32_t)index;

		ImGui::BeginDisabled( );

		micro_im::combo( label, data, size, getter, tmp_index );

		ImGui::EndDisabled( );
	}

	bool dropdown(
		const std::string& label,
		const std::initializer_list<micro_string> values,
		uint32_t& index
	) {
		const auto* data = micro_cast( values.begin( ), void* );
		const auto size  = (uint32_t)values.size( );

		return micro_im::combo( label, data, size, micro_im::combo_string_getter, index );
	}

	void dropdown_disabled(
		const std::string& label,
		const std::initializer_list<micro_string> values,
		const uint32_t index
	) {
		const auto* data = micro_cast( values.begin( ), void* );
		const auto size  = (uint32_t)values.size( );

		micro_im::combo_disabled( label, data, size, micro_im::combo_string_getter, index );
	}

	bool dropdown(
		const std::string& label,
		const std::vector<micro_string>& values,
		uint32_t& index
	) {
		const auto* data = micro_cast( values.data( ), void* );
		const auto size  = (uint32_t)values.size( );

		return micro_im::combo( label, data, size, micro_im::combo_string_getter, index );
	}

	void dropdown_disabled(
		const std::string& label,
		const std::vector<micro_string>& values,
		const uint32_t index
	) {
		const auto* data = micro_cast( values.data( ), void* );
		const auto size  = (uint32_t)values.size( );

		micro_im::combo_disabled( label, data, size, micro_im::combo_string_getter, index );
	}

	bool dropdown(
		const std::string& label,
		const EnumPair* pairs,
		uint32_t& index
	) {
		auto size = micro_array_size( pairs );

		return micro_im::combo( label, micro_cast( pairs, void* ), size, micro_im::combo_enum_pair_getter, index );
	}

	void dropdown_disabled(
		const std::string& label,
		const EnumPair* pairs,
		const uint32_t index
	) {
		auto size = micro_array_size( pairs );

		micro_im::combo_disabled( label, micro_cast( pairs, void* ), size, micro_im::combo_enum_pair_getter, index );
	}

	bool dropdown(
		const std::string& label,
		const std::vector<EnumPair>& pairs,
		uint32_t& index
	) {
		auto* data = micro_cast( pairs.data( ), void* );
		auto size  = micro_cast( pairs.size( ), int32_t );

		return micro_im::combo( label, data, size, micro_im::combo_enum_pair_getter, index );
	}

	void dropdown_disabled(
		const std::string& label,
		const std::vector<EnumPair>& pairs,
		const uint32_t index
	) {
		auto* data = micro_cast( pairs.data( ), void* );
		auto size  = micro_cast( pairs.size( ), int32_t );

		micro_im::combo_disabled( label, data, size, micro_im::combo_enum_pair_getter, index );
	}

	bool dropdown(
		const std::string& label,
		std::initializer_list<EnumPair> pairs,
		uint32_t& index
	) {
		auto* data = micro_cast( pairs.begin( ), void* );
		auto size = micro_cast( pairs.size( ), int32_t );

		return micro_im::combo( label, data, size, micro_im::combo_enum_pair_getter, index );
	}

	void dropdown_disabled(
		const std::string& label,
		std::initializer_list<EnumPair> pairs,
		const uint32_t index
	) {
		auto* data = micro_cast( pairs.begin( ), void* );
		auto size  = micro_cast( pairs.size( ), int32_t );

		micro_im::combo_disabled( label, data, size, micro_im::combo_enum_pair_getter, index );
	}

};
