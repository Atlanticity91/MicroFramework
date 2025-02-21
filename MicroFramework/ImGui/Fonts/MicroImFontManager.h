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

#include "MicroImFontEmbedded.h"

micro_class MicroFilesystem {

public:
	std::string GetRealPath( const std::string& path ) const {
		return path;
	};

};

micro_class MicroImFontManager final {

private:
	std::map<std::string, ImFont*> m_fonts;

public:
	MicroImFontManager( );

	~MicroImFontManager( ) = default;

	void Initialize( );
	
	bool LoadFont( const MicroImFont& font );

	bool LoadFonts( const std::vector<MicroImFont>& fonts );

	bool LoadFonts( std::initializer_list<MicroImFont> fonts );

	bool LoadFont( MicroFilesystem& filesystem, const MicroImFont& font );

	bool LoadFonts(
		MicroFilesystem& filesystem,
		const std::vector<MicroImFont>& fonts
	);

	bool LoadFonts(
		MicroFilesystem& filesystem,
		std::initializer_list<MicroImFont> fonts
	);

	bool AddFont(
		const std::string& alias,
		const uint32_t length,
		const uint32_t* data,
		const float size
	);

	bool CreateFont(
		const std::string& name,
		const float size,
		const MicroImFontEmbedded& font
	);

	bool CreateFonts(
		const std::string& name,
		const float size,
		const std::vector<MicroImFontEmbedded> fonts
	);

	bool CreateFonts(
		const std::string& name,
		const float size,
		std::initializer_list<MicroImFontEmbedded> fonts
	);

	void SetFont( const std::string& name );

private:
	bool LoadFont( 
		const std::string& alias,
		micro_string font_path, 
		const float font_size
	);

	bool CreateFonts(
		const std::string& name,
		const float size,
		const uint32_t font_count,
		const MicroImFontEmbedded* font_data
	);

public:
	bool GetHasFont( const std::string& name ) const;

};
