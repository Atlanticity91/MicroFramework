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

#include "../Memory/MicroMemoryManager.h"

template<typename Type>
class micro_stack final {

private:
	std::vector<Type> m_values;

public:
	constexpr micro_stack( )
		: m_values{ }
	{ };

	constexpr micro_stack( const micro_stack& other )
		: m_values{ other.m_values }
	{ };

	constexpr micro_stack( micro_stack&& other ) noexcept
		: m_values{ std::move( other.m_values ) }
	{ };

	~micro_stack( ) = default;

	constexpr void push( const Type& element ) {
		m_values.push_back( element );
	};

	constexpr void push( Type&& element ) {
		m_values.push_back( std::move( element ) );
	};

	constexpr void clear( ) {
		m_values.clear( );
	};

public:
	template<typename... Args>
	constexpr void emplace( Args&&... args ) {
		push( { std::forward<Args>( args )... } );
	};

public:
	constexpr uint32_t size( ) const {
		return (uint32_t)m_values.size( );
	};

	constexpr bool empty( ) const {
		return m_values.empty( );
	};

	micro_nodiscard_cause( "Returned boolean give information on pop operation success." )
	constexpr std::optional<Type> pop( ) {
		if ( !empty( ) ) {
			auto local = std::move( m_values.back( ) );
			
			m_values.pop_back( );

			return local;
		}

		return { };
	};

	micro_nodiscard_cause( "Returned boolean give information on peek operation success." )
	constexpr std::optional<Type> peek( ) {
		if ( !empty( ) ) {
			auto local = std::move( m_values.back( ) );

			return local;
		}

		return { };
	};

};
