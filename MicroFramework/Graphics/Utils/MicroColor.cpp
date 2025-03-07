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
MicroColor::MicroColor( )
	: MicroColor{ 0x000000FF }
{ }

MicroColor::MicroColor( const uint32_t color )
{ 
	micro_ref_as( m_channels, uint32_t ) = color;
}

MicroColor::MicroColor(
	const uint8_t red,
	const uint8_t green,
	const uint8_t blue,
	const uint8_t alpha
)
	: m_channels{ red, green, blue, alpha }
{ }

MicroColor::MicroColor(
	const float red,
	const float green,
	const float blue,
	const float alpha
) 
	: m_channels{ 
		(uint8_t)( 255 * red   ), 
		(uint8_t)( 255 * green ),
		(uint8_t)( 255 * blue  ),
		(uint8_t)( 255 * alpha )
	}
{ }

MicroColor::MicroColor( const micro_vec3& color )
	: MicroColor{ color.x, color.y, color.z, 1.f }
{ }

MicroColor::MicroColor( const micro_vec4& color )
	: MicroColor{ color.x, color.y, color.z, color.w }
{ }

MicroColor::MicroColor( const micro_vec3& color, const float alpha )
	: MicroColor{ color.x, color.y, color.z, alpha } 
{ }

MicroColor::MicroColor( const MicroColor& color )
	: MicroColor{ (uint32_t)color }
{ }

MicroColor::MicroColor( MicroColor&& color ) noexcept
	: MicroColor{ (uint32_t)color }
{ }

MicroColor& MicroColor::SetR( const uint8_t value ) {
	m_channels[ 0 ] = value;

	return micro_self;
}

MicroColor& MicroColor::SetG( const uint8_t value ) {
	m_channels[ 1 ] = value;

	return micro_self;
}

MicroColor& MicroColor::SetB( const uint8_t value ) {
	m_channels[ 2 ] = value;

	return micro_self;
}

MicroColor& MicroColor::SetA( const uint8_t value ) {
	m_channels[ 3 ] = value;

	return micro_self;
}

MicroColor& MicroColor::Set( const micro_vec3& other ) {
	m_channels[ 0 ] = (uint8_t)( 255 * other.x );
	m_channels[ 1 ] = (uint8_t)( 255 * other.y );
	m_channels[ 2 ] = (uint8_t)( 255 * other.z );

	return micro_self;
}

MicroColor& MicroColor::Set( const micro_vec3& other, const float scalar ) {
	m_channels[ 0 ] = (uint8_t)( 255 * other.x );
	m_channels[ 1 ] = (uint8_t)( 255 * other.y );
	m_channels[ 2 ] = (uint8_t)( 255 * other.z );
	m_channels[ 3 ] = (uint8_t)( 255 * scalar  );

	return micro_self;
}

MicroColor& MicroColor::Set( const micro_vec4& other ) {
	m_channels[ 0 ] = (uint8_t)( 255 * other.x );
	m_channels[ 1 ] = (uint8_t)( 255 * other.y );
	m_channels[ 2 ] = (uint8_t)( 255 * other.z );
	m_channels[ 3 ] = (uint8_t)( 255 * other.w );

	return micro_self;
}

MicroColor& MicroColor::Set( const MicroColor& other ) {
	micro_ref_as( m_channels, uint32_t ) = other.AsUInt( );

	return micro_self;
}

MicroColor& MicroColor::Set( MicroColor&& other ) noexcept {
	micro_ref_as( m_channels, uint32_t ) = other.AsUInt( );

	return micro_self;
}

MicroColor& MicroColor::Set( const MicroColorChannels channel, const uint8_t value ) {
	m_channels[ (uint32_t)channel ] = value;

	return micro_self;
}

void MicroColor::Add( const micro_vec3& color ) {
	m_channels[ 0 ] += (uint8_t)( color.x );
	m_channels[ 1 ] += (uint8_t)( color.y );
	m_channels[ 2 ] += (uint8_t)( color.z );
}

void MicroColor::Add( const micro_vec4& color ) {
	m_channels[ 0 ] += (uint8_t)( color.x );
	m_channels[ 1 ] += (uint8_t)( color.y );
	m_channels[ 2 ] += (uint8_t)( color.z );
	m_channels[ 3 ] += (uint8_t)( color.w );
}

void MicroColor::Add( const MicroColor& color ) { 
	micro_ref_as( m_channels, uint32_t ) += color.AsUInt( );
}

void MicroColor::Add(
	const uint8_t red,
	const uint8_t green,
	const uint8_t blue,
	const uint8_t alpha
) { 
	const auto color = ( red << 24 ) | ( green << 16 ) | ( blue << 8 ) | alpha;

	micro_ref_as( m_channels, uint32_t ) += color;
}

void MicroColor::Add(
	const float red,
	const float green,
	const float blue,
	const float alpha
) { 
	m_channels[ 0 ] += (uint8_t)( 255 * red   );
	m_channels[ 1 ] += (uint8_t)( 255 * green );
	m_channels[ 2 ] += (uint8_t)( 255 * blue  );
	m_channels[ 3 ] += (uint8_t)( 255 * alpha );
}

void MicroColor::Subtract( const micro_vec3& color ) {
	m_channels[ 0 ] -= (uint8_t)( color.x );
	m_channels[ 1 ] -= (uint8_t)( color.y );
	m_channels[ 2 ] -= (uint8_t)( color.z );
}

void MicroColor::Subtract( const micro_vec4& color ) {
	m_channels[ 0 ] -= (uint8_t)( color.x );
	m_channels[ 1 ] -= (uint8_t)( color.y );
	m_channels[ 2 ] -= (uint8_t)( color.z );
	m_channels[ 3 ] -= (uint8_t)( color.w );
}

void MicroColor::Subtract( const MicroColor& color ) {
	micro_ref_as( m_channels, uint32_t ) -= color.AsUInt( );
}

void MicroColor::Subtract(
	const uint8_t red,
	const uint8_t green,
	const uint8_t blue,
	const uint8_t alpha
) {
	const auto color = ( red << 24 ) | ( green << 16 ) | ( blue << 8 ) | alpha;

	micro_ref_as( m_channels, uint32_t ) -= color;
}

void MicroColor::Subtract(
	const float red,
	const float green,
	const float blue,
	const float alpha
) {
	m_channels[ 0 ] -= (uint8_t)( 255 * red   );
	m_channels[ 1 ] -= (uint8_t)( 255 * green );
	m_channels[ 2 ] -= (uint8_t)( 255 * blue  );
	m_channels[ 3 ] -= (uint8_t)( 255 * alpha );
}

void MicroColor::Multiply( const float scalar ) {
	for ( auto channel = 0; channel < 4; channel++ )
		m_channels[ channel ] = (uint8_t)( m_channels[ channel ] * scalar );
}

void MicroColor::Reverse( ) { 
	for ( auto channel = 0; channel < 4; channel++ )
		m_channels[ channel ] = 255 - m_channels[ channel ];
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
uint8_t* MicroColor::Get( ) const {
	return micro_cast( m_channels, uint8_t* );
}

uint8_t MicroColor::Get( const uint32_t channel ) const {
	return m_channels[ channel ];
}

uint8_t MicroColor::Get( const MicroColorChannels channel ) const {
	return Get( (uint32_t)channel );
}

uint32_t MicroColor::AsUInt( ) const {
	return micro_ref_as( m_channels, uint32_t );
}

micro_vec3 MicroColor::AsVec3( ) const {
	return {
		m_channels[ 0 ] * 255.f,
		m_channels[ 1 ] * 255.f,
		m_channels[ 2 ] * 255.f
	};
}

micro_vec4 MicroColor::AsVec4( ) const {
	return {
		m_channels[ 0 ] * 255.f,
		m_channels[ 1 ] * 255.f,
		m_channels[ 2 ] * 255.f,
		m_channels[ 3 ] * 255.f
	};
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	OPERATOR ===
////////////////////////////////////////////////////////////////////////////////////////////
MicroColor::operator uint32_t ( ) const {
	return AsUInt( );
}

MicroColor::operator micro_vec3 ( ) const {
	return AsVec3( );
}

MicroColor::operator micro_vec4 ( ) const {
	return AsVec4( );
}

MicroColor MicroColor::operator+( const micro_vec3& other ) const {
	return { };
}

MicroColor MicroColor::operator+( const micro_vec4& other ) const {
	return {};
}

MicroColor MicroColor::operator+( const MicroColor& other ) const {
	return { AsUInt( ) + other.AsUInt( ) };
}

MicroColor MicroColor::operator-( const micro_vec3& other ) const {
	return {};
}

MicroColor MicroColor::operator-( const micro_vec4& other ) const {
	return {};
}

MicroColor MicroColor::operator-( const MicroColor& other ) const {
	return { AsUInt( ) - other.AsUInt( ) };
}

MicroColor MicroColor::operator*( const float scalar ) const {
	return {};
}

MicroColor MicroColor::operator~( ) const {
	return {};
	/*
	return {
		255 - m_channels[ 0 ],
		255 - m_channels[ 1 ],
		255 - m_channels[ 2 ],
		255 - m_channels[ 3 ]
	};
	*/
}

MicroColor& MicroColor::operator=( const micro_vec3& color ) {
	Set( color );
	
	return micro_self;
}

MicroColor& MicroColor::operator=( const micro_vec4& color ) {
	Set( color );

	return micro_self;
}

MicroColor& MicroColor::operator=( const MicroColor& color ) {
	Set( color );

	return micro_self;
}

MicroColor& MicroColor::operator=( MicroColor&& color ) noexcept {
	Set( color );

	return micro_self;
}

MicroColor& MicroColor::operator+=( const micro_vec3& other ) {
	Add( other );

	return micro_self;
}

MicroColor& MicroColor::operator+=( const micro_vec4& other ) {
	Add( other );

	return micro_self;
}

MicroColor& MicroColor::operator+=( const MicroColor& other ) {
	Add( other );

	return micro_self;
}

MicroColor& MicroColor::operator-=( const micro_vec3& other ) {
	Subtract( other );

	return micro_self;
}

MicroColor& MicroColor::operator-=( const micro_vec4& other ) {
	Subtract( other );

	return micro_self;
}

MicroColor& MicroColor::operator-=( const MicroColor& other ) {
	Subtract( other );

	return micro_self;
}

MicroColor& MicroColor::operator*=( const float scalar ) {
	Multiply( scalar );

	return micro_self;
}

uint8_t MicroColor::operator[]( const uint32_t channel ) const {
	return Get( channel );
}

uint8_t MicroColor::operator[]( const MicroColorChannels channel ) const {
	return Get( channel );
}

bool MicroColor::operator==( const micro_vec3& color ) const {
	return micro_self == MicroColor{ color };
}

bool MicroColor::operator==( const micro_vec4& color ) const {
	return micro_self == MicroColor{ color };
}

bool MicroColor::operator==( const MicroColor& color ) const {
	return AsUInt( ) == color.AsUInt( );
}

bool MicroColor::operator!=( const micro_vec3& color ) const {
	return !( micro_self == color );
}

bool MicroColor::operator!=( const micro_vec4& color ) const {
	return !( micro_self == color );
}

bool MicroColor::operator!=( const MicroColor& color ) const {
	return !( micro_self == color );
}
