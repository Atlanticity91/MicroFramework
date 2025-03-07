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

#include "MicroStack.h"

template<typename Type, uint32_t Capacity>
class micro_stack_fixed final {

private:
	uint32_t m_cursor;
	std::array<Type, Capacity> m_values;

public:
	constexpr micro_stack_fixed( )
		: m_cursor{ 0 },
		m_values{ }
	{ };

	constexpr micro_stack_fixed( const micro_stack_fixed& other )
		: m_cursor{ other.m_cursor },
		m_values{ }
	{ 
		auto count = other.m_cursor;

		while ( count-- > 0 )
			m_values[ count ] = other.m_values[ count ];
	};

	constexpr micro_stack_fixed( micro_stack_fixed&& other ) noexcept
		: m_cursor{ other.m_cursor }, 
		m_values{ std::move( other.m_values ) }
	{ };

	~micro_stack_fixed( ) = default;

	constexpr void push( const Type& element ) {
		if ( full( ) )
			return;

		m_values[ m_cursor++ ] = element;
	};

	constexpr void push( Type&& element ) {
		if ( full( ) )
			return;

		m_values[ m_cursor++ ] = std::move( element );
	};

	constexpr void clear( ) {
		m_cursor = 0;
	};

public:
	template<typename... Args>
	constexpr void emplace( Args&&... args ) {
		push( { std::forward<Args>( args )... } );
	};

public:
	constexpr uint32_t size( ) const {
		return m_cursor;
	};

	constexpr uint32_t capacity( ) const {
		return Capacity;
	};

	constexpr uint32_t available( ) const {
		return Capacity - m_cursor;
	};

	constexpr bool full( ) const {
		return m_cursor == Capacity;
	};

	constexpr bool empty( ) const {
		return m_cursor == 0;
	};

	micro_nodiscard_cause( "Returned boolean give information on pop operation success." )
	constexpr std::optional<Type> pop( ) {
		if ( !empty( ) )
			return std::move( m_values[ --m_cursor ] );

		return { };
	};

	micro_nodiscard_cause( "Returned boolean give information on peek operation success." )
	constexpr std::optional<Type> peek( ) {
		if ( !empty( ) )
			return m_values[ m_cursor - 1 ];

		return { };
	};

};
