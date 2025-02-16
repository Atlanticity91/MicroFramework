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
MicroRenderDoc::MicroRenderDoc( ) 
	: m_library{ },
	m_renderdoc_api{ nullptr }
{ }

MicroRenderDoc::~MicroRenderDoc( ) {
	Terminate( );
}

bool MicroRenderDoc::Initialize( ) {
	if ( m_library.Open( "renderdoc.dll", true ) )
		auto* get_api = m_library.AcquireAs<pRENDERDOC_GetAPI>( "RENDERDOC_GetAPI" );

	return GetIsValid( );
}

void MicroRenderDoc::BeginCapture( ){
	if ( GetIsValid( ) )
		m_renderdoc_api->StartFrameCapture( NULL, NULL) ;
}

bool MicroRenderDoc::EndCapture( ) {
	auto result = false;

	if ( GetIsValid( ) )
		result = ( m_renderdoc_api->EndFrameCapture( NULL, NULL ) == 1 );

	return result;
}

void MicroRenderDoc::Terminate( ) {
	m_library.Close( );
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
bool MicroRenderDoc::GetIsValid( ) const {
	return m_renderdoc_api != nullptr;
}

RENDERDOC_API_1_6_0* MicroRenderDoc::GetAPI( ) const {
	return m_renderdoc_api;
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	OPERATOR ===
////////////////////////////////////////////////////////////////////////////////////////////
MicroRenderDoc::operator bool ( ) const {
	return GetIsValid( );
}

MicroRenderDoc::operator RENDERDOC_API_1_6_0* ( ) const {
	return GetAPI( );
}
