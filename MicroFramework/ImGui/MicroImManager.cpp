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
	: MicroNativeEventObserver{ },
	m_is_gl_backend{ false },
	m_theme{ },
	m_fonts{ },
	m_context{ },
	m_backend{ nullptr },
	m_windows{ }
{ }

bool MicroImManager::Create( 
	const MicroWindow& window, 
	const MicroImSpecification& specification,
	MicroVulkan& graphics
) {
	auto result = false;

	if ( m_context.Create( ) ) {
		if ( m_backend = new MicroImVKBackend{ } ) {
			if ( result = m_backend->Create( window, specification, micro_ptr_as( graphics, void* ) ) ) {
				m_theme.Initialize( );
				m_fonts.Initialize( );
			}
		} else
			m_context.Destroy( );
	}

	return result;
}

bool MicroImManager::Create(
	const MicroWindow& window,
	const MicroImSpecification& specification,
	MicroOpenGL& graphics
) {
	auto result = false;

	if ( m_context.Create( ) ) {
		if ( m_backend = new MicroImGLBackend{ } ) {
			if ( result = m_backend->Create( window, specification, micro_ptr_as( graphics, void* ) ) ) {
				m_theme.Initialize( );
				m_fonts.Initialize( );
			}
		} else
			m_context.Destroy( );
	}

	return result;
}

void MicroImManager::PollEvent( const SDL_Event& event ) {
	ImGui_ImplSDL3_ProcessEvent( micro_ptr( event ) );
}

MicroImTheme& MicroImManager::SetTheme( ImGuiStyleVar variable, const float value ) {
	return m_theme.Set( variable, value );
}

MicroImTheme& MicroImManager::SetTheme( ImGuiStyleVar variable, const ImVec2& value ) {
	return m_theme.Set( variable, value );
}

MicroImTheme& MicroImManager::SetTheme( ImGuiCol color, const ImVec4& value ) {
	return m_theme.Set( color, value );
}

MicroImTheme& MicroImManager::ResetTheme( ) {
	return m_theme.Reset( );
}

bool MicroImManager::LoadFont( const MicroImFont& font ) {
	return m_fonts.LoadFont( font );
}

bool MicroImManager::LoadFonts( const std::vector<MicroImFont>& fonts ) {
	return m_fonts.LoadFonts( fonts );
}

bool MicroImManager::LoadFonts( std::initializer_list<MicroImFont> fonts ) {
	return m_fonts.LoadFonts( fonts );
}

bool MicroImManager::LoadFont( MicroFilesystem& filesystem, const MicroImFont& font ) {
	return m_fonts.LoadFont( filesystem, font );
}

bool MicroImManager::LoadFonts(
	MicroFilesystem& filesystem,
	const std::vector<MicroImFont>& fonts
) {
	return m_fonts.LoadFonts( filesystem, fonts );
}

bool MicroImManager::LoadFonts(
	MicroFilesystem& filesystem,
	std::initializer_list<MicroImFont> fonts
) {
	return m_fonts.LoadFonts( filesystem, fonts );
}

bool MicroImManager::AddFont(
	const std::string& alias,
	const uint32_t length,
	const uint32_t* data,
	const float size
) {
	return m_fonts.AddFont( alias, length, data, size );
}

bool MicroImManager::CreateFont(
	const std::string& name,
	const float size,
	const MicroImFontEmbedded& font
) {
	return m_fonts.CreateFont( name, size, font );
}

bool MicroImManager::CreateFonts(
	const std::string& name,
	const float size,
	const std::vector<MicroImFontEmbedded> fonts
) {
	return m_fonts.CreateFonts( name, size, fonts );
}

bool MicroImManager::CreateFonts(
	const std::string& name,
	const float size,
	std::initializer_list<MicroImFontEmbedded> fonts
) {
	return m_fonts.CreateFonts( name, size, fonts );
}

void MicroImManager::SetFont( const std::string& name ) {
	m_fonts.SetFont( name );
}

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

void MicroImManager::Submit(
	MicroVulkan& graphics_api,
	MicroVulkanRenderContext& render_context,
	void* user_data
) {
	micro_assert( !m_is_gl_backend, "You can't Flush ImGui manager with Vulkan when ImGui backend is defined to OpenGL." );

	Submit( micro_ptr_as( graphics_api, void* ), micro_ptr_as( render_context, void* ), user_data );
}

void MicroImManager::Submit(
	MicroOpenGL& graphics_api,
	MicroOpenGLRenderContext& render_context,
	void* user_data
) {
	Submit( micro_ptr_as( graphics_api, void* ), micro_ptr_as( render_context, void* ), user_data );
}

void MicroImManager::Destroy( MicroVulkan& graphics, void* user_data ) {
	micro_assert( !m_is_gl_backend, "You can't Terminate ImGui manager with Vulkan when ImGui backend is defined to OpenGL." );

	Destroy( micro_ptr_as( graphics, void* ), user_data );
}

void MicroImManager::Destroy( MicroOpenGL& graphics, void* user_data ) {
	Destroy( micro_ptr_as( graphics, void* ), user_data );
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PRIVATE ===
////////////////////////////////////////////////////////////////////////////////////////////
void MicroImManager::Submit( void* graphics_api, void* render_context, void* user_data ) {
	if ( !m_context.GetIsVisible( ) )
		return;
	
	m_backend->Prepare( );
	m_context.Prepare( );
	m_windows.Tick( graphics_api, render_context, user_data );
	m_context.Submit( );
	m_backend->Submit( render_context );
}

void MicroImManager::Destroy( void* graphics, void* user_data ) {
	m_windows.Destroy( user_data );

	if ( m_backend != nullptr ) {
		m_backend->Destroy( graphics );

		delete m_backend;

		m_backend = nullptr;
	}

	m_context.Destroy( );
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

MicroImTheme& MicroImManager::GetTheme( ) {
	return m_theme;
}

const MicroImTheme& MicroImManager::GetTheme( ) const {
	return m_theme;
}

bool MicroImManager::GetHasFont( const std::string& name ) const {
	return m_fonts.GetHasFont( name );
}

MicroImContext& MicroImManager::GetContext( ) {
	return m_context;
}

MicroImBackend* MicroImManager::GetBackend( ) const {
	return m_backend;
}

MicroImWindowManager& MicroImManager::GetImWindowManager( ) {
	return m_windows;
}

bool MicroImManager::GetIsExemplesVisivle( ) const {
	return m_windows.GetIsExemplesVisivle( );
}

bool MicroImManager::GetHasImWindow( const std::string& name ) const {
	return m_windows.GetHas( name );
}

MicroImWindow* MicroImManager::GetImWindow( const std::string& name ) const {
	return m_windows.Get( name );
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	OPERATOR ===
////////////////////////////////////////////////////////////////////////////////////////////
MicroImManager::operator bool ( ) const {
	return GetIsValid( );
}
