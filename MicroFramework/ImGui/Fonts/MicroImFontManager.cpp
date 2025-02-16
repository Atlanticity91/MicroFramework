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
            { { TinyFontAwesome_900_length, TinyFontAwesome_900_data, MICRO_IM_ICON_MIN, MICRO_IM_ICON_MAX } }
        );
    }
}

bool MicroImFontManager::LoadFont(
    TinyFilesystem& filesystem,
    MicroGraphicManager& graphics,
    const MicroImFont& font
) {
    auto state = false;//filesystem.GetFileExist( font.Path );

    if ( state ) {
        auto* path = font.Path.c_str( );
        auto& io   = ImGui::GetIO( );

        if ( auto* im_font = io.Fonts->AddFontFromFileTTF( path, font.Size ) ) {
            m_fonts.emplace( font.Alias, im_font );

            state = io.Fonts->Build( );
        }
    }

    return state;
}

bool MicroImFontManager::LoadFonts(
    TinyFilesystem& filesystem,
    MicroGraphicManager& graphics,
    std::initializer_list<MicroImFont> fonts
) {
    auto state = fonts.size( ) > 0;

    if ( state ) {
        for ( auto& font : fonts ) {
            state = LoadFont( filesystem, graphics, font );

            if ( !state ) 
                break;
        }
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

    if ( auto* im_font = io.Fonts->AddFontFromMemoryCompressedTTF( micro_ptr_as( data, void* ), length, size ) )
        m_fonts.emplace( alias, im_font );

    return io.Fonts->Build( );
}

bool MicroImFontManager::CreateFont(
    const std::string& name,
    const float size,
    std::initializer_list<MicroImFontEmbedded> fonts
) {
    auto state = fonts.size( );

    if ( state ) {
        auto config = ImFontConfig{ };
        auto& io = ImGui::GetIO( );

        config.MergeMode = true;

        for ( auto& font : fonts ) {
            ImWchar icons_ranges[] = { font.Min, font.Max, 0 };

            io.Fonts->AddFontFromMemoryCompressedTTF( font.Glyphs, font.Length, size, micro_ptr( config ), icons_ranges );
        }

        state = io.Fonts->Build( );

        if ( state )
            m_fonts.emplace( name, ImGui::GetFont( ) );
    }

    return state;
}

void MicroImFontManager::SetFont( const std::string& name ) {
    auto iterator = m_fonts.find( name );

    if ( iterator != m_fonts.end( ) )
        ImGui::SetCurrentFont( iterator->second );
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
bool MicroImFontManager::GetHasFont( const std::string& name ) const {
	return m_fonts.find( name ) != m_fonts.end( );
}
