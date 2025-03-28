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

#include "Camera/MicroCameraManager.h"

struct MicroTexture { };

template<typename GraphicSpecification>
class MicroGraphicManager : public MicroNativeEventObserver {

protected:
	bool m_should_resize;
	bool m_should_render;

public:
	MicroGraphicManager( )
		: m_should_resize{ false },
		m_should_render{ true }
	{ };

	virtual ~MicroGraphicManager( ) = default;

	micro_abstract( bool Create( 
		MicroWindow& window, 
		const GraphicSpecification& specification 
	) );

	micro_implement( void PollEvent( const SDL_Event& event ) ) {
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
	};

	void MarkResize( ) {
		m_should_resize = true;
	};

	micro_abstract( bool Acquire( const MicroWindow& window ) );

	micro_abstract( void Present( const MicroWindow& window ) );

	micro_abstract( void Destroy( MicroWindow& window ) );

public:
	bool GetShouldResize( ) const { 
		return m_should_resize;
	};

	bool GetShouldRender( ) const { 
		return m_should_render;
	};

};
