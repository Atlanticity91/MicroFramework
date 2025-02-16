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
MicroWindow::MicroWindow( )
	: MicroOpenGLWindow{ },
	MicroVulkanWindow{ },
	m_window{ NULL }
{ }

bool MicroWindow::Create( const MicroWindowSpecification& specification ) {
	const auto sdl_flags = GetInitializeFlags( );

	if ( SDL_Init( sdl_flags ) == SDL_OK ) {
		const auto* title_handle = specification.Title.c_str( );
		const auto window_flags  = GetWindowFlags( specification );

		m_window = SDL_CreateWindow( title_handle, specification.Width, specification.Height, window_flags );

		if ( GetIsValid( ) ) {
			SDL_ShowWindow( m_window );
		}
	}

	return GetIsValid( );
}

bool MicroWindow::CreateSurface( VkInstance& instance, VkSurfaceKHR& surface ) const {
	const auto* allocator = micro_ptr( vk::GetAllocationCallback( ) );

	return SDL_Vulkan_CreateSurface( m_window, instance, allocator, micro_ptr( surface ) );
}

void MicroWindow::SetTitle( std::string&& title ) {
	micro_assert( m_window != NULL, "Window handle can't be null to use this function, check if the window was created." );
	micro_assert( !title.empty( ), "Window title can't be null" );

	const auto* title_handle = title.c_str( );

	SDL_SetWindowTitle( m_window, title_handle );
}

void MicroWindow::SetDimensions( const micro_upoint& dimensions ) {
	SetDimensions( dimensions.x, dimensions.y );
}

void MicroWindow::SetDimensions( const uint32_t width, const uint32_t height ) {
	micro_assert( m_window != NULL, "Window handle can't be null to use this function, check if the window was created." );
	micro_assert( width > 0, "Window title can't be null" );
	micro_assert( height > 0, "Window title can't be null" );

	SDL_SetWindowSize( m_window, width, height );
}

void MicroWindow::SetFullscreen( bool full_screen ) {
	micro_assert( m_window != NULL, "Window handle can't be null to use this function, check if the window was created." );

	SDL_SetWindowFullscreen( m_window, full_screen );
}

void MicroWindow::Destroy( ) {
	if ( GetIsValid( ) )
		SDL_DestroyWindow( m_window );

	SDL_Quit( );
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
void MicroWindow::GetExtensions( std::vector<micro_string>& extension_list ) const {
	auto extension_count  = (uint32_t)0;
	const auto* extension = SDL_Vulkan_GetInstanceExtensions( micro_ptr( extension_count ) );
	
	extension_list.resize( extension_count );

	while ( extension_count-- > 0 )
		extension_list[ extension_count ] = extension[ extension_count ];
}

SDL_Window* MicroWindow::Get( ) const {
	return m_window;
}

bool MicroWindow::GetIsValid( ) const {
	return ( m_window != NULL );
}

bool MicroWindow::GetIsFullScreen( ) const {
	return false;
}

uint32_t MicroWindow::GetWidth( ) const {
	auto width = (int32_t)0;

	SDL_GetWindowSizeInPixels( m_window, micro_ptr( width ), NULL );

	return (uint32_t)width;
}

uint32_t MicroWindow::GetHeight( ) const {
	auto height = (int32_t)0;

	SDL_GetWindowSizeInPixels( m_window, NULL, micro_ptr( height ) );

	return (uint32_t)height;
}

micro_upoint MicroWindow::GetVKDimensions( ) const {
	auto width  = (int32_t)0;
	auto height = (int32_t)0;

	SDL_GetWindowSizeInPixels( m_window, micro_ptr( width ), micro_ptr( height ) );

	return { width, height };
}

glm::vec2 MicroWindow::GetGLDimensions( ) const {
	return { 0.f, 0.f };
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PRIVATE GET ===
////////////////////////////////////////////////////////////////////////////////////////////
SDL_InitFlags MicroWindow::GetInitializeFlags( ) const {
	return  SDL_INIT_EVENTS   | 
			SDL_INIT_VIDEO    |
			SDL_INIT_AUDIO    | 
			SDL_INIT_GAMEPAD  | 
			SDL_INIT_JOYSTICK | 
			SDL_INIT_HAPTIC;
}

SDL_WindowFlags MicroWindow::GetWindowFlags(
	const MicroWindowSpecification& specification 
) const {
	auto flags = specification.Flags.Resizable * SDL_WINDOW_RESIZABLE;

	flags |= specification.Flags.FullScreen * SDL_WINDOW_FULLSCREEN;
	flags |= specification.Flags.Borderless * SDL_WINDOW_BORDERLESS;
	flags |= specification.Flags.UseOpenGL ? SDL_WINDOW_OPENGL : SDL_WINDOW_VULKAN;

	return flags;
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	OPERATOR ===
////////////////////////////////////////////////////////////////////////////////////////////
MicroWindow::operator SDL_Window* ( ) const {
	return Get( );
}

MicroWindow::operator bool ( ) const {
	return GetIsValid( );
}
