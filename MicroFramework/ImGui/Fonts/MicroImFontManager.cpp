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
MicroImFontManager::MicroImFontManager( ) 
	: m_fonts{ }
{ }

void MicroImFontManager::Initialize( ) {
    if ( AddFont( "Caskaydia", TinyCaskaydia_length, TinyCaskaydia_data, 16.f ) ) {
        CreateFont(
            "Caskaydia", 16.f,
            { TinyFontAwesome_900_length, TinyFontAwesome_900_data, MICRO_IM_ICON_MIN, MICRO_IM_ICON_MAX }
        );
    }
}

bool MicroImFontManager::LoadFont( const MicroImFont& font ) {
    const auto* path = font.Path.c_str( );
    auto state = false;

    if ( std::filesystem::is_regular_file( path ) )
        state = LoadFont( font.Alias, path, font.Size );

    return state;
}

bool MicroImFontManager::LoadFonts( const std::vector<MicroImFont>& fonts ) {
    auto state = false;

    for ( const auto& font : fonts ) {
        state = LoadFont( font );

        if ( !state )
            break;
    }

    return state;
}

bool MicroImFontManager::LoadFonts( std::initializer_list<MicroImFont> fonts ) {
    auto state = false;

    for ( const auto& font : fonts ) {
        state = LoadFont( font );

        if ( !state )
            break;
    }

    return state;
}

bool MicroImFontManager::LoadFont(
    MicroFilesystem& filesystem,
    const MicroImFont& font
) {
    const auto real_path = filesystem.GetRealPath( font.Path );
    auto state           = false;

    if ( real_path.size( ) > 0 ) {
        const auto* path = real_path.c_str( );

        state = LoadFont( font.Alias, path, font.Size );
    }

    return state;
}

bool MicroImFontManager::LoadFonts(
    MicroFilesystem& filesystem,
    const std::vector<MicroImFont>& fonts
) {
    auto state = false;

    for ( const auto& font : fonts ) {
        state = LoadFont( filesystem, font );

        if ( !state )
            break;
    }

    return state;
}

bool MicroImFontManager::LoadFonts(
    MicroFilesystem& filesystem,
    std::initializer_list<MicroImFont> fonts
) {
    auto state = false;

    for ( const auto& font : fonts ) {
        state = LoadFont( filesystem, font );

        if ( !state )
            break;
    }

    return state;
}

bool MicroImFontManager::AddFont(
    const std::string& alias,
    const uint32_t length,
    const uint32_t* data,
    const float size
) {
    auto& io = ImGui::GetIO( );

    if ( auto* im_font = io.Fonts->AddFontFromMemoryCompressedTTF( micro_cast( data, void* ), length, size ) )
        m_fonts.emplace( alias, im_font );

    return io.Fonts->Build( );
}

bool MicroImFontManager::CreateFont(
    const std::string& name,
    const float size,
    const MicroImFontEmbedded& font
) {
    return CreateFonts( name, size, 1, micro_ptr( font ) );
}

bool MicroImFontManager::CreateFonts(
    const std::string& name,
    const float size,
    const std::vector<MicroImFontEmbedded> fonts
) {
    const auto font_count = fonts.size( );
    const auto font_data  = fonts.data( );

    return CreateFonts( name, size, font_count, font_data );
}

bool MicroImFontManager::CreateFonts(
    const std::string& name,
    const float size,
    std::initializer_list<MicroImFontEmbedded> fonts
) {
    const auto font_count = fonts.size( );
    const auto font_data  = fonts.begin( );

    return CreateFonts( name, size, font_count, font_data );
}

void MicroImFontManager::SetFont( const std::string& name ) {
    auto iterator = m_fonts.find( name );

    if ( iterator != m_fonts.end( ) )
        ImGui::SetCurrentFont( iterator->second );
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PRIVATE ===
////////////////////////////////////////////////////////////////////////////////////////////
bool MicroImFontManager::LoadFont(
    const std::string& alias,
    micro_string font_path,
    const float font_size
) {
    auto& io   = ImGui::GetIO( );
    auto state = false;

    if ( auto* im_font = io.Fonts->AddFontFromFileTTF( font_path, font_size ) ) {
        m_fonts.emplace( alias, im_font );

        state = io.Fonts->Build( );
    }

    return state;
}

bool MicroImFontManager::CreateFonts(
    const std::string& name,
    const float size,
    const uint32_t font_count,
    const MicroImFontEmbedded* font_data
) {
    auto& io     = ImGui::GetIO( );
    auto font_id = font_count;
    auto config  = ImFontConfig{ };
    auto state   = false;

    config.MergeMode = true;

    while ( font_id-- > 0 ) {
        const auto& font       = font_data[ font_id ];
        const ImWchar ranges[] = { font.Min, font.Max, 0 };

        io.Fonts->AddFontFromMemoryCompressedTTF( font.Glyphs, font.Length, size, micro_ptr( config ), ranges );
    }

    if ( state = io.Fonts->Build( ) ) {
        auto* im_font = ImGui::GetFont( );

        m_fonts.emplace( name, im_font );
    }

    return state;
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
bool MicroImFontManager::GetHasFont( const std::string& name ) const {
	return m_fonts.find( name ) != m_fonts.end( );
}
