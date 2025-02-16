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
MicroImManager::MicroImManager( )
	: m_is_gl_backend{ false },
	m_context{ },
	m_backend{ nullptr },
	m_windows{ }
{ }

void MicroImManager::Show( ) {
	m_context.Show( );
}

void MicroImManager::Hide( ) {
	m_context.Hide( );
}

void MicroImManager::ShowExemples( ) {
	m_windows.ShowExemples( );
}

void MicroImManager::HideExemples( ) {
	m_windows.HideExemples( );
}

void MicroImManager::ShowWindow( const std::string& name, void* user_data ) {
	m_windows.Show( name, user_data );
}

void MicroImManager::HideWindow( const std::string& name, void* user_data ) {
	m_windows.Hide( name, user_data );
}

void MicroImManager::ToggleWindow( const std::string& name, void* user_data ) {
	m_windows.Toggle( name, user_data );
}

void MicroImManager::DeleteWindow( const std::string& name, void* user_data ) {
	m_windows.Delete( name, user_data );
}

void MicroImManager::Flush( 
	MicroVulkan& graphics_api,
	MicroVulkanRenderContext& render_context,
	void* user_data
) {
	micro_assert( !m_is_gl_backend, "You can't Flush ImGui manager with Vulkan when ImGui backend is defined to OpenGL." );

	Flush( micro_ptr_as( graphics_api, void* ), micro_ptr_as( render_context, void* ), user_data );
}

void MicroImManager::Flush(
	MicroOpenGL& graphics_api,
	MicroGlRenderContext& render_context,
	void* user_data
) {
	Flush( micro_ptr_as( graphics_api, void* ), micro_ptr_as( render_context, void* ), user_data );
}

void MicroImManager::Terminate( MicroVulkan& graphics, void* user_data ) {
	micro_assert( !m_is_gl_backend, "You can't Terminate ImGui manager with Vulkan when ImGui backend is defined to OpenGL." );

	Terminate( micro_ptr_as( graphics, void* ), user_data );
}

void MicroImManager::Terminate( MicroOpenGL& graphics, void* user_data ) {
	Terminate( micro_ptr_as( graphics, void* ), user_data );
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PRIVATE ===
////////////////////////////////////////////////////////////////////////////////////////////
void MicroImManager::Flush( void* graphics_api, void* render_context, void* user_data ) {
	if ( !m_context.GetIsVisible( ) )
		return;
	
	m_backend->Prepare( );
	m_context.Prepare( );
	m_windows.Tick( graphics_api, render_context, user_data );
	m_context.Flush( );
	m_backend->Flush( render_context );
}

void MicroImManager::Terminate( void* graphics, void* user_data ) {
	m_windows.Terminate( user_data );

	if ( m_backend != nullptr ) {
		m_backend->Terminate( graphics );

		delete m_backend;

		m_backend = nullptr;
	}

	m_context.Terminate( );
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
bool MicroImManager::GetIsValid( ) const {
	return m_backend != nullptr;
}

bool MicroImManager::GetIsGlBackend( ) const {
	return m_is_gl_backend;
}

bool MicroImManager::GetIsVisible( ) const {
	return m_context.GetIsVisible( );
}

MicroImContext& MicroImManager::GetContext( ) {
	return m_context;
}

MicroImBackend* MicroImManager::GetBackend( ) const {
	return m_backend;
}

MicroImWindowManager& MicroImManager::GetWindowManager( ) {
	return m_windows;
}

bool MicroImManager::GetIsExemplesVisivle( ) const {
	return m_windows.GetIsExemplesVisivle( );
}

bool MicroImManager::GetHasWindow( const std::string& name ) const {
	return m_windows.GetHas( name );
}

MicroImWindow* MicroImManager::GetWindow( const std::string& name ) const {
	return m_windows.Get( name );
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	OPERATOR ===
////////////////////////////////////////////////////////////////////////////////////////////
MicroImManager::operator bool ( ) const {
	return GetIsValid( );
}
