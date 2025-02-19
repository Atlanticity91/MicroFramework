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
	MicroImContext m_context;
	MicroImBackend* m_backend;
	MicroImWindowManager m_windows;

public:
	MicroImManager( );

	~MicroImManager( ) = default;

	micro_implement( void PollEvent( const SDL_Event& event ) );

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
		MicroGlRenderContext& render_context,
		void* user_data
	);

	void Destroy( MicroVulkan& graphics, void* user_data );

	void Destroy( MicroOpenGL& graphics, void* user_data );

public:
	template<typename ImBackend, typename GraphicsAPI>
		requires ( std::is_base_of_v<MicroImBackend, ImBackend> )
	bool Create(
		const MicroWindow& window,
		const MicroImSpecification& specification,
		GraphicsAPI& graphics
	) {
		micro_assert( m_backend == nullptr, "You can't create an ImGui mannager backend when one is already defined." );

		auto result = false;

		if ( m_context.Create( ) ) {
			if ( m_backend = new ImBackend{ } )
				result = m_backend->Create( window, specification, micro_ptr_as( graphics, void* ) );
			else
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
