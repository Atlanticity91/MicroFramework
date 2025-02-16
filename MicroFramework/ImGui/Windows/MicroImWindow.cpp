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
MicroImWindow::MicroImWindow( )
	: MicroImWindow{ "", false, ImGuiWindowFlags_None }
{ }

MicroImWindow::MicroImWindow( const std::string& name )
	: MicroImWindow{ name, true, ImGuiWindowFlags_None }
{ }

MicroImWindow::MicroImWindow( const std::string& name, const ImGuiWindowFlags flags )
	: MicroImWindow{ name, true, flags }
{ }

MicroImWindow::MicroImWindow( const std::string& name, const bool is_visible )
	: MicroImWindow{ name, is_visible, ImGuiWindowFlags_None }
{ }

MicroImWindow::MicroImWindow( 
	const std::string& name,
	const bool is_visible, 
	const ImGuiWindowFlags flags
)
	: m_is_visible{ is_visible },
	m_name{ name },
	m_flags{ flags }
{ }

void MicroImWindow::AddFlag( const ImGuiWindowFlags flag ) {
	if ( flag > ImGuiWindowFlags_None )
		m_flags |= flag;
}

void MicroImWindow::DeleteFlag( const ImGuiWindowFlags flag ) {
	if ( flag > ImGuiWindowFlags_None )
		m_flags ^= flag;
}

void MicroImWindow::SetFlags( const ImGuiWindowFlags flag ) {
	m_flags = flag; 
}

void MicroImWindow::Show( void* user_data ) {
	m_is_visible = true;

	OnShow( user_data );
}

void MicroImWindow::Hide( void* user_data ) {
	m_is_visible = false; 
	
	OnHide( user_data );
}

void MicroImWindow::Toggle( void* user_data ) {
	m_is_visible = !m_is_visible;

	if ( m_is_visible )
		OnShow( user_data );
	else
		OnHide( user_data );
}

void MicroImWindow::Tick( void* graphics_api, void* render_context, void* user_data ) {
	const auto* name = m_name.c_str( );

	if ( ImGui::Begin( name, micro_ptr( m_is_visible ), m_flags ) )
		OnTick( graphics_api, render_context, user_data );

	ImGui::End( );
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
bool MicroImWindow::GetIsVisible( ) const { 
	return m_is_visible; 
}

std::string MicroImWindow::GetName( ) const { 
	return { m_name };
}

bool MicroImWindow::GetHasFlag( const ImGuiWindowFlags flags ) const {
	return micro_mask( m_flags, flags ) == flags;
}

ImGuiWindowFlags MicroImWindow::GetFlags( ) const { 
	return m_flags; 
}
