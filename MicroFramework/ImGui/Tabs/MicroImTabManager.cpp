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
MicroImTabManager::MicroImTabManager( )
	: MicroImTabManager{ "", "_", false, ImGuiTabBarFlags_None }
{ }

MicroImTabManager::MicroImTabManager(
	const std::string& name,
	const std::string& tab_alias,
	const ImGuiTabBarFlags tab_flags
)
	: MicroImTabManager{ name, tab_alias, true, tab_flags }
{ }

MicroImTabManager::MicroImTabManager(
	const std::string& name,
	const std::string& tab_alias,
	const bool is_visible,
	const ImGuiTabBarFlags tab_flags
)
	: m_tab_alias{ tab_alias },
	m_tab_flags{ tab_flags },
	m_current{ 0 },
	m_tabs{ }
{ }

void MicroImTabManager::RemoveTab( const std::string& name ) {
	auto iterator = m_tabs.find( name );

	if ( iterator != m_tabs.end( ) ) {
		delete iterator->second;

		m_tabs.erase( iterator );
	}
}

void MicroImTabManager::OnTick(
	void* graphics_api,
	void* render_context,
	void* user_data
) {
	const auto* tab_name = m_tab_alias.c_str( );

	if ( ImGui::BeginTabBar( tab_name, m_tab_flags ) ) {
		auto tab_id = (uint32_t)0;

		for ( auto& pair : m_tabs ) {
			if ( !pair.second->Tick( graphics_api, render_context, user_data ) )
				tab_id += 1;
			else
				m_current = tab_id;
		}

		ImGui::EndTabBar( );
	}
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
uint32_t MicroImTabManager::GetCurrentTabID( ) const { 
	return m_current;
}

bool MicroImTabManager::GetHasTab( const std::string& name ) const {
	return m_tabs.find( name ) != m_tabs.end( );
}

MicroImTab* MicroImTabManager::GetTab( const std::string& name ) {
	auto iterator = m_tabs.find( name );
	auto* tab	  = micro_cast( nullptr, MicroImTab* );

	if ( iterator != m_tabs.end( ) )
		tab = iterator->second;

	return tab;
}
