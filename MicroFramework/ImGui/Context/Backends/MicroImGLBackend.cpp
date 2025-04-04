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
MicroImGLBackend::MicroImGLBackend( )
	: MicroImBackend{ } 
{ }

bool MicroImGLBackend::Create(
	const MicroWindow& window,
	const MicroImSpecification& specification,
	void* graphics
) {
	const auto* gl_graphics  = micro_cast( graphics, MicroOpenGL* );
	const auto* glsl_version = gl_graphics->GetGLSLVersion( ).c_str( );
	auto* context			 = SDL_GL_GetCurrentContext( );

	return  ImGui_ImplSDL3_InitForOpenGL( window, context ) &&
			ImGui_ImplOpenGL3_Init( glsl_version );	
}

void MicroImGLBackend::Prepare( ) {
	ImGui_ImplOpenGL3_NewFrame( );
	ImGui_ImplSDL3_NewFrame( );
}

void MicroImGLBackend::Submit( void* context ) {
	auto* draw_data = ImGui::GetDrawData( );

	ImGui_ImplOpenGL3_RenderDrawData( draw_data );
}

void MicroImGLBackend::Destroy( void* graphics ) {
	ImGui_ImplOpenGL3_Shutdown( );
	ImGui_ImplSDL3_Shutdown( );
}
