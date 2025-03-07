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
MicroInputQueryManager::MicroInputQueryManager( )
	: m_filters{ },
	m_queries{ }
{ }

void MicroInputQueryManager::Register(
	const std::string& name,
	const MicroInputQuery& query
) {
	if ( m_queries.find( name ) != m_queries.end( ) )
		return;

	auto pair = std::make_pair( name, query );

	m_queries.emplace( pair );
}

void MicroInputQueryManager::Register( const std::string& name, MicroInputQuery&& query ) {
	if ( m_queries.find( name ) != m_queries.end( ) )
		return;

	auto pair = std::make_pair( name, std::move( query ) );

	m_queries.emplace( pair );
}

void MicroInputQueryManager::Register(
	const std::string& name,
	const uint32_t filters,
	std::initializer_list<MicroInputQueryButton> buttons
) {
	Register( name, { filters, buttons, { } } );
}

void MicroInputQueryManager::Register(
	const std::string& name,
	const uint32_t filters,
	std::initializer_list<MicroInputQueryAxis> axis
) {
	Register( name, { filters, { }, axis } );
}

void MicroInputQueryManager::Register(
	const std::string& name,
	const uint32_t filters,
	std::initializer_list<MicroInputQueryButton> buttons,
	std::initializer_list<MicroInputQueryAxis> axis
) {
	Register( name, { filters, buttons, axis } );
}

void MicroInputQueryManager::Extend(
	const std::string& name,
	std::initializer_list<MicroInputQueryButton> buttons
) {
	Extend( name, buttons, { } );
}

void MicroInputQueryManager::Extend(
	const std::string& name,
	std::initializer_list<MicroInputQueryAxis> axis
) {
	Extend( name, { }, axis );
}

void MicroInputQueryManager::Extend(
	const std::string& name,
	std::initializer_list<MicroInputQueryButton> buttons,
	std::initializer_list<MicroInputQueryAxis> axis
) {
	auto iterator = m_queries.find( name );

	if ( iterator != m_queries.end( ) ) {
		//iterator->second.Axis.push_back( axis );
	} 
}

void MicroInputQueryManager::Add( const uint32_t filters ) {
	m_filters |= filters;
}

void MicroInputQueryManager::Remove( const uint32_t filters ) {
	m_filters ^= filters;
}

void MicroInputQueryManager::Set( const uint32_t filters ) {
	m_filters = filters;
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
uint32_t MicroInputQueryManager::GetFilters( ) const {
	return m_filters;
}

bool MicroInputQueryManager::GetHasFilters( const uint32_t filters ) const {
	return m_filters & filters;
}

const std::map<std::string, MicroInputQuery>& MicroInputQueryManager::GetQueries( ) const {
	return m_queries;
}

const MicroInputQuery* MicroInputQueryManager::Get( const std::string& name ) const {
	const auto iterator = m_queries.find( name );

	return iterator != m_queries.end( ) ? micro_ptr( iterator->second ) : nullptr;
}
