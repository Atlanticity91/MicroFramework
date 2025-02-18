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

#include "__micro_framework_pch.h"

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC ===
////////////////////////////////////////////////////////////////////////////////////////////
MicroGraphicManager::MicroGraphicManager( )
	: MicroNativeEventObserver{ },
	m_vulkan{ },
	m_render_context{ },
	m_should_resize{ false },
	m_should_render{ true }
{ }

bool MicroGraphicManager::Create( MicroWindow& window ) {
	return m_vulkan.Create( window, { } );
}

void MicroGraphicManager::PollEvent( const SDL_Event& event ) {
	if ( event.type == SDL_EVENT_WINDOW_RESTORED )
		m_should_render = true;

	if ( event.type == SDL_EVENT_WINDOW_MINIMIZED || event.type == SDL_EVENT_WINDOW_HIDDEN )
		m_should_render = false;

    if (
		event.type == SDL_EVENT_WINDOW_ENTER_FULLSCREEN || 
		event.type == SDL_EVENT_WINDOW_LEAVE_FULLSCREEN ||
		event.type == SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED 
	)
		MarkResize( );
}

void MicroGraphicManager::MarkResize( ) {
	m_should_resize = true;
}

bool MicroGraphicManager::Acquire( const MicroWindow& window ) {
	return m_should_render && m_vulkan.Acquire( window, m_render_context, m_should_resize );
}

void MicroGraphicManager::Present( const MicroWindow& window ) {
	m_vulkan.Present( window, m_render_context, m_should_resize );
}

void MicroGraphicManager::Destroy( ) {
	m_vulkan.Destroy( );
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
MicroVulkan MicroGraphicManager::GetVulkan( ) { 
	return m_vulkan;
}

const MicroVulkan& MicroGraphicManager::GetVulkan( ) const {
	return m_vulkan;
}

MicroVulkanRenderContext& MicroGraphicManager::GetRenderContext( ) {
	return m_render_context;
}

bool MicroGraphicManager::GetShouldResize( ) const {
	return m_should_resize;
}

bool MicroGraphicManager::GetShouldRender( ) const {
	return m_should_render;
}
