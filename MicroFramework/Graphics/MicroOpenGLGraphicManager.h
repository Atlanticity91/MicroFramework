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

#include "MicroGraphicManager.h"

micro_class MicroOpenGLGraphicManager final 
	: public MicroGraphicManager<MicroOpenGLSpecification> 
{

private:
	MicroOpenGL m_opengl;
	MicroOpenGLRenderContext m_render_context;
	
public:
	MicroOpenGLGraphicManager( );

	~MicroOpenGLGraphicManager( ) = default;

	micro_implement( bool Create( 
		MicroWindow& window,
		const MicroOpenGLSpecification& specification
	) );

	micro_implement( bool Acquire( const MicroWindow& window ) );

	micro_implement( void Present( const MicroWindow& window ) );

	micro_implement( void Destroy( MicroWindow& window ) );

public:
	MicroOpenGL& GetOpenGL( );

	const MicroOpenGL& GetOpenGL( ) const;
	
	MicroOpenGLRenderContext& GetRenderContext( );
	
	const MicroOpenGLRenderContext& GetRenderContext( ) const;

public:
	operator MicroOpenGL& ( );

	operator const MicroOpenGL& ( ) const;

	operator MicroOpenGLRenderContext& ( );

	operator const MicroOpenGLRenderContext& ( ) const;

};
