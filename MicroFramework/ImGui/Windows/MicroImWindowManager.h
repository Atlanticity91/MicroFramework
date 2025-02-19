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

#include "MicroImWindow.h"

micro_class MicroImWindowManager final {

private:
	bool m_show_exemples;
	std::unordered_map<std::string, MicroImWindow*> m_windows;

public:
	MicroImWindowManager( );

	~MicroImWindowManager( ) = default;

	void ShowExemples( );

	void HideExemples( );

	void Show( const std::string& name, void* user_data );

	void Hide( const std::string& name, void* user_data );

	void Toggle( const std::string& name, void* user_data );

	void Delete( const std::string& name, void* user_data );

	void Tick( void* graphics_api, void* render_context, void* user_data );

	void Destroy( void* user_data );

public:
	template<typename Window, typename... Args>
		requires ( std::is_base_of_v<MicroImWindow, Window> )
	void Create( void* user_data, Args&&... args ) {
		if ( auto* window = new Window( std::forward<Args>( args )... ) ) {
			const auto name = window->GetName( );

			if ( !GetHas( name ) ) {
				window->OnCreate( user_data );

				m_windows.emplace( name, window );
			} else
				delete window;
		}
	};

public:
	bool GetIsExemplesVisivle( ) const;

	bool GetHas( const std::string& name ) const;

	MicroImWindow* Get( const std::string& name ) const;

public:
	template<typename ImWindow>
		requires ( std::is_base_of_v<MicroImWindow, ImWindow> )
	ImWindow* GetAs( const std::string& name ) const {
		return micro_cast( Get( name ), ImWindow* );
	};

};
