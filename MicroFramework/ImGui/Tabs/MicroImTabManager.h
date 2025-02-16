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

#include "MicroImTab.h"

micro_class MicroImTabManager final {

protected:
	std::unordered_map<std::string, MicroImTab*> m_tabs;
	std::string m_tab_alias;
	ImGuiTabBarFlags m_tab_flags;
	uint32_t m_current;

public:
	MicroImTabManager( );

	MicroImTabManager(
		const std::string& name,
		const std::string& tab_alias,
		const ImGuiTabBarFlags tab_flags
	);

	MicroImTabManager(
		const std::string& name,
		const std::string& tab_alias,
		const bool is_visible,
		const ImGuiTabBarFlags tab_flags
	);

	virtual ~MicroImTabManager( ) = default;

	void RemoveTab( const std::string& name );

	void OnTick(
		void* graphics_api,
		void* render_context,
		void* user_data
	);

public:
	template<typename Tab, typename... Args>
		requires ( std::is_base_of_v<MicroImTab, Tab> )
	void AddTab( void* user_data, Args&&... args ) {
		auto* tab = new Tab( std::forward<Args>( args )... );

		if ( tab ) {
			const auto& name = tab->GetName( );

			if ( !GetHasTab( name ) ) {
				tab->OnCreate( user_data );

				m_tabs.emplace( name, tab );
			} else
				delete tab;
		}
	};

public:
	uint32_t GetCurrentTabID( ) const;

	bool GetHasTab( const std::string& name ) const;

	MicroImTab* GetTab( const std::string& name );

public:
	template<typename ImTab, typename... Args>
		requires ( std::is_base_of_v<MicroImTab, ImTab> )
	ImTab* GetTabAs( const std::string& name ) {
		return micro_cast( GetTab( name ), ImTab* );
	};

};
