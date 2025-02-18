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

#include "MicroWindowSpecification.h"

micro_class MicroWindow final 
	: public MicroNativeEventObserver, public MicroOpenGLWindow, public MicroVulkanWindow
{

private:
	SDL_Window* m_window;

public:
	MicroWindow( );

	~MicroWindow( ) = default;

	bool Create( const MicroWindowSpecification& specification );

	micro_implement( bool CreateSurface( 
		VkInstance& instance, 
		VkSurfaceKHR& surface 
	) const );

	void SetTitle( std::string&& title );
	
	void SetDimensions( const micro_upoint& dimensions );

	void SetDimensions( const uint32_t width, const uint32_t height );

	void SetFullscreen( bool full_screen );

	micro_implement( void PollEvent( const SDL_Event& event ) );

	void Destroy( );

public:
	micro_implement( void GetExtensions( 
		std::vector<micro_string>& extension_list
	) const );

	SDL_Window* Get( ) const;

	bool GetIsValid( ) const;

	bool GetIsFullScreen( ) const;
	
	uint32_t GetWidth( ) const;

	uint32_t GetHeight( ) const;

	micro_implement( micro_upoint GetVKDimensions( ) const );

	micro_implement( glm::vec2 GetGLDimensions( ) const );

private:
	SDL_InitFlags GetInitializeFlags( ) const;

	SDL_WindowFlags GetWindowFlags( 
		const MicroWindowSpecification& specification
	) const;

public:
	operator SDL_Window* ( ) const;

	operator bool ( ) const;

};
