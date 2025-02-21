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

#include "Extensions/MicroImTextExtension.h"

micro_class MicroImManager final : public MicroNativeEventObserver {

private:
	bool m_is_gl_backend;
	MicroImTheme m_theme;
	MicroImFontManager m_fonts;
	MicroImContext m_context;
	MicroImBackend* m_backend;
	MicroImWindowManager m_windows;

public:
	MicroImManager( );

	~MicroImManager( ) = default;

	micro_implement( void PollEvent( const SDL_Event& event ) );

	MicroImTheme& SetTheme( ImGuiStyleVar variable, const float value );

	MicroImTheme& SetTheme( ImGuiStyleVar variable, const ImVec2& value );

	MicroImTheme& SetTheme( ImGuiCol color, const ImVec4& value );

	MicroImTheme& ResetTheme( );

	bool LoadFont( const MicroImFont& font );

	bool LoadFonts( const std::vector<MicroImFont>& fonts );

	bool LoadFonts( std::initializer_list<MicroImFont> fonts );

	bool LoadFont( MicroFilesystem& filesystem, const MicroImFont& font );

	bool LoadFonts(
		MicroFilesystem& filesystem,
		const std::vector<MicroImFont>& fonts
	);

	bool LoadFonts(
		MicroFilesystem& filesystem,
		std::initializer_list<MicroImFont> fonts
	);

	bool AddFont(
		const std::string& alias,
		const uint32_t length,
		const uint32_t* data,
		const float size
	);

	bool CreateFont(
		const std::string& name,
		const float size,
		const MicroImFontEmbedded& font
	);

	bool CreateFonts(
		const std::string& name,
		const float size,
		const std::vector<MicroImFontEmbedded> fonts
	);

	bool CreateFonts(
		const std::string& name,
		const float size,
		std::initializer_list<MicroImFontEmbedded> fonts
	);

	void SetFont( const std::string& name );

	void Show( );

	void Hide( );

	void ShowExemples( );

	void HideExemples( );

	void ShowWindow( const std::string& name, void* user_data );

	void HideWindow( const std::string& name, void* user_data );

	void ToggleWindow( const std::string& name, void* user_data );

	void DeleteWindow( const std::string& name, void* user_data );

	void Submit(
		MicroVulkan& graphics_api,
		MicroVulkanRenderContext& render_context,
		void* user_data
	);

	void Submit(
		MicroOpenGL& graphics_api,
		MicroOpenGLRenderContext& render_context,
		void* user_data
	);

	void Destroy( MicroVulkan& graphics, void* user_data );

	void Destroy( MicroOpenGL& graphics, void* user_data );

public:
	template<typename GraphicsAPI>
		requires ( std::is_same_v<GraphicsAPI, MicroOpenGL> || std::is_same_v<GraphicsAPI, MicroVulkan> )
	bool Create(
		const MicroWindow& window,
		const MicroImSpecification& specification,
		GraphicsAPI& graphics
	) {
		auto result = false;

		if ( m_context.Create( ) ) {
			micro_compile_if( std::is_same_v<GraphicsAPI, MicroOpenGL> )
				m_backend = new MicroImGLBackend{ };
			micro_compile_elif( std::is_same_v<GraphicsAPI, MicroVulkan> )
				m_backend = new MicroImVKBackend{ };

			if ( m_backend != nullptr ) {
				if ( result = m_backend->Create( window, specification, micro_ptr_as( graphics, void* ) ) ) {
					m_theme.Initialize( );
					m_fonts.Initialize( );
				}
			} else
				m_context.Destroy( );
		}

		return result;
	};

	template<typename Window, typename... Args>
		requires ( std::is_base_of_v<MicroImWindow, Window> )
	void CreateImWindow( void* user_data, Args&&... args ) { 
		m_windows.Create<Window, Args...>( user_data, std::forward<Args>( args )... );
	};

private:
	void Submit( void* graphics_api, void* render_context, void* user_data );

	void Destroy( void* graphics, void* user_data );

public:
	bool GetIsValid( ) const;

	bool GetIsGlBackend( ) const;

	bool GetIsVisible( ) const;

	MicroImTheme& GetTheme( );

	const MicroImTheme& GetTheme( ) const;

	bool GetHasFont( const std::string& name ) const;

	MicroImContext& GetContext( );

	MicroImBackend* GetBackend( ) const;

	MicroImWindowManager& GetImWindowManager( );

	bool GetIsExemplesVisivle( ) const;

	bool GetHasImWindow( const std::string& name ) const;

	MicroImWindow* GetImWindow( const std::string& name ) const;

public:
	template<typename ImBackend>
		requires ( std::is_base_of_v<MicroImBackend, ImBackend> )
	ImBackend* GetBackendAs( ) const {
		return micro_cast( GetBackend( ), ImBackend* );
	};

	template<typename ImWindow>
		requires ( std::is_base_of_v<MicroImWindow, ImWindow> )
	ImWindow* GetImWindowAs( const std::string& name ) const { 
		return m_windows.GetAs<ImWindow>( name );
	};

public:
	operator bool ( ) const;

};
