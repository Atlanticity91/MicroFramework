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
MicroOpenGLGraphicManager::MicroOpenGLGraphicManager( )
	: MicroGraphicManager{ },
	m_opengl{ },
	m_render_context{ }
{ }

bool MicroOpenGLGraphicManager::Create( 
	MicroWindow& window,
	const MicroOpenGLSpecification& specification
) {
	return m_opengl.Create( window, specification );
}

bool MicroOpenGLGraphicManager::Acquire( const MicroWindow& window ) {
	return m_should_render && m_opengl.Acquire( window, m_render_context, m_should_resize );
}

void MicroOpenGLGraphicManager::Present( const MicroWindow& window ) {
	m_opengl.Present( window, m_render_context, m_should_resize );
}

void MicroOpenGLGraphicManager::Destroy( MicroWindow& window ) {
	m_opengl.Destroy( window );
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
MicroOpenGL& MicroOpenGLGraphicManager::GetOpenGL( ) {
	return m_opengl;
}

const MicroOpenGL& MicroOpenGLGraphicManager::GetOpenGL( ) const {
	return m_opengl;
}

MicroOpenGLRenderContext& MicroOpenGLGraphicManager::GetRenderContext( ) {
	return m_render_context;
}

const MicroOpenGLRenderContext& MicroOpenGLGraphicManager::GetRenderContext( ) const {
	return m_render_context;
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	OPERATOR ===
////////////////////////////////////////////////////////////////////////////////////////////
MicroOpenGLGraphicManager::operator MicroOpenGL& ( ) {
	return GetOpenGL( );
}

MicroOpenGLGraphicManager::operator const MicroOpenGL& ( ) const {
	return GetOpenGL( );
}

MicroOpenGLGraphicManager::operator MicroOpenGLRenderContext& ( ) {
	return GetRenderContext( );
}

MicroOpenGLGraphicManager::operator const MicroOpenGLRenderContext& ( ) const {
	return GetRenderContext( );
}
