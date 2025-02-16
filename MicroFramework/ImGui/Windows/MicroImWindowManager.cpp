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
MicroImWindowManager::MicroImWindowManager( )
	: m_show_exemples{ false },
	m_windows{ }
{ }

void MicroImWindowManager::ShowExemples( ) { 
	m_show_exemples = true;
}

void MicroImWindowManager::HideExemples( ) { 
	m_show_exemples = false; 
}

void MicroImWindowManager::Show( const std::string& name, void* user_data ) {
	if ( auto* window = Get( name ) )
		window->Show( user_data );
}

void MicroImWindowManager::Hide( const std::string& name, void* user_data ) {
	if ( auto* window = Get( name ) )
		window->Hide( user_data );
}

void MicroImWindowManager::Toggle( const std::string& name, void* user_data ) {
	if ( auto* window = Get( name ) )
		window->Toggle( user_data );
}

void MicroImWindowManager::Delete( const std::string& name, void* user_data ) {
	auto iterator = m_windows.find( name );

	if ( iterator != m_windows.end( ) ) {
		iterator->second->Delete( user_data );

		delete iterator->second;

		m_windows.erase( iterator );
	}
}

void MicroImWindowManager::Tick( 
	void* graphics_api, 
	void* render_context, 
	void* user_data 
) {
	ImGui::ShowDemoWindow( micro_ptr( m_show_exemples ) );

	for ( auto& pair : m_windows ) {
		auto* window = pair.second;

		if ( window->GetIsVisible( ) )
			window->Tick( graphics_api, render_context, user_data );
	}
}

void MicroImWindowManager::Terminate( void* user_data ) {
	for ( auto& pair : m_windows ) {
		auto* window = pair.second;

		window->Delete( user_data );

		delete window;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
bool MicroImWindowManager::GetIsExemplesVisivle( ) const { 
	return m_show_exemples; 
}

bool MicroImWindowManager::GetHas( const std::string& name ) const {
	return m_windows.find( name ) != m_windows.end( );
}

MicroImWindow* MicroImWindowManager::Get( const std::string& name ) const {
	auto iterator = m_windows.find( name );
	auto* window  = micro_cast( nullptr, MicroImWindow* );

	if ( iterator != m_windows.end( ) )
		window = iterator->second;

	return window;
}
