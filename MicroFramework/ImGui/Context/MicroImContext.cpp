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
MicroImContext::MicroImContext( )
	: m_is_visible{ true },
	m_context{ nullptr }
{ }

bool MicroImContext::Create( ) {
	IMGUI_CHECKVERSION( );

	if ( m_context = ImGui::CreateContext( ) ) {
		auto& io = ImGui::GetIO( );

		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
	}

	return GetIsValid( );
}

void MicroImContext::Show( ) {
	m_is_visible = true; 
}

void MicroImContext::Hide( ) {
	m_is_visible = false; 
}

void MicroImContext::Toggle( ) {
	m_is_visible = !m_is_visible; 
}

void MicroImContext::EnableDocking( ) {
	auto& io = ImGui::GetIO( );

	//io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
}

void MicroImContext::DisableDocking( ) {
	auto& io = ImGui::GetIO( );

	//io.ConfigFlags ^= ImGuiConfigFlags_DockingEnable;
}

void MicroImContext::ToggleDocking( ) {
	auto& io = ImGui::GetIO( );

	/*
	if ( micro_mask( io.ConfigFlags, ImGuiConfigFlags_DockingEnable ) )
		DisableDocking( );
	else
		EnableDocking( );
	*/
}

void MicroImContext::Prepare( ) {
	ImGui::NewFrame( ); 
}

void MicroImContext::Submit( ) {
	ImGui::Render( );
}

void MicroImContext::Destroy( ) {
	if ( GetIsValid( ) )
		ImGui::DestroyContext( );
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
bool MicroImContext::GetIsValid( ) const {
	return m_context != nullptr;
}

bool MicroImContext::GetIsVisible( ) const {
	return m_is_visible; 
}

bool MicroImContext::GetIsDockingEnabled( ) const {
	const auto& io = ImGui::GetIO( );

	return false;//return micro_mask( io.ConfigFlags, ImGuiConfigFlags_DockingEnable );
}

ImGuiContext* MicroImContext::Get( ) const {
	return m_context; 
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	OPERATOR ===
////////////////////////////////////////////////////////////////////////////////////////////
MicroImContext::operator bool ( ) const {
	return GetIsValid( );
}

MicroImContext::operator ImGuiContext* ( ) const {
	return Get( );
}
