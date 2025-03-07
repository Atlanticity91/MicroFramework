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

#include "../Tools/MicroToolRenderDoc.h"

micro_enum_class MicroColorChannels : uint32_t {

	Red = 0,
	Green,
	Blue,
	Alpha,

	Count

};

micro_class MicroColor final {

private:
	uint8_t m_channels[ 4 ];

public:
	MicroColor( );

	MicroColor( const uint32_t color );

	MicroColor(
		const uint8_t red,
		const uint8_t green, 
		const uint8_t blue,
		const uint8_t alpha
	);

	MicroColor(
		const float red,
		const float green,
		const float blue,
		const float alpha
	);
	
	MicroColor( const micro_vec3& color );

	MicroColor( const micro_vec4& color );

	MicroColor( const micro_vec3& color, const float alpha );

	MicroColor( const MicroColor& other );

	MicroColor( MicroColor&& other ) noexcept;

	~MicroColor( ) = default;

	MicroColor& SetR( const uint8_t value );

	MicroColor& SetG( const uint8_t value );

	MicroColor& SetB( const uint8_t value );

	MicroColor& SetA( const uint8_t value );

	MicroColor& Set( const micro_vec3& other );

	MicroColor& Set( const micro_vec3& other, const float scalar );

	MicroColor& Set( const micro_vec4& other );

	MicroColor& Set( const MicroColor& other );

	MicroColor& Set( MicroColor&& other ) noexcept;

	MicroColor& Set( const MicroColorChannels channel, const uint8_t value );

	void Add( const micro_vec3& other );

	void Add( const micro_vec4& other );

	void Add( const MicroColor& other );

	void Add(
		const uint8_t red,
		const uint8_t green,
		const uint8_t blue,
		const uint8_t alpha
	);
	
	void Add(
		const float red,
		const float green,
		const float blue,
		const float alpha
	);

	void Subtract( const micro_vec3& other );

	void Subtract( const micro_vec4& other );

	void Subtract( const MicroColor& other );

	void Subtract(
		const uint8_t red,
		const uint8_t green,
		const uint8_t blue,
		const uint8_t alpha
	);

	void Subtract(
		const float red,
		const float green,
		const float blue,
		const float alpha
	);

	void Multiply( const float scalar );

	void Reverse( );

public:
	uint8_t* Get( ) const;

	uint8_t Get( const uint32_t channel ) const;

	uint8_t Get( const MicroColorChannels channel ) const;

	uint32_t AsUInt( ) const;

	micro_vec3 AsVec3( ) const;

	micro_vec4 AsVec4( ) const;

public:
	operator uint32_t ( ) const;

	operator micro_vec3 ( ) const;

	operator micro_vec4 ( ) const;

	MicroColor operator+( const micro_vec3& other ) const;

	MicroColor operator+( const micro_vec4& other ) const;

	MicroColor operator+( const MicroColor& other ) const;

	MicroColor operator-( const micro_vec3& other ) const;

	MicroColor operator-( const micro_vec4& other ) const;

	MicroColor operator-( const MicroColor& other ) const;

	MicroColor operator*( const float scalar ) const;

	MicroColor operator~( ) const;

	MicroColor& operator=( const micro_vec3& color );

	MicroColor& operator=( const micro_vec4& color );

	MicroColor& operator=( const MicroColor& other );

	MicroColor& operator=( MicroColor&& other ) noexcept;

	MicroColor& operator+=( const micro_vec3& other );

	MicroColor& operator+=( const micro_vec4& other );

	MicroColor& operator+=( const MicroColor& other );

	MicroColor& operator-=( const micro_vec3& other );

	MicroColor& operator-=( const micro_vec4& other );

	MicroColor& operator-=( const MicroColor& other );

	MicroColor& operator*=( const float scalar );

	uint8_t operator[]( const uint32_t channel ) const;

	uint8_t operator[]( const MicroColorChannels channel ) const;

	bool operator==( const micro_vec3& color ) const;

	bool operator==( const micro_vec4& color ) const;

	bool operator==( const MicroColor& other ) const;

	bool operator!=( const micro_vec3& color ) const;

	bool operator!=( const micro_vec4& color ) const;

	bool operator!=( const MicroColor& other ) const;

};
