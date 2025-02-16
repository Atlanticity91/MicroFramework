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

#include "MicroImInputOpenGL.h"

micro_class MicroImTheme final {

public:
	static constexpr auto FramePadding	  = ImVec2{ 4.f, 4.f };
	static constexpr auto FrameRounding   = 2.5f;
	static constexpr auto FrameBorderSize = 1.f;
	static constexpr auto IndentSpacing   = 11.f;

	static constexpr auto Dark			  = ImColor{   0,   0,   0,   0 };
	static constexpr auto Highlight		  = ImColor{  39, 185, 242, 255 };
	static constexpr auto NiceBlue		  = ImColor{  83, 232, 254, 255 };
	static constexpr auto Compliment	  = ImColor{  78, 151, 166, 255 };
	static constexpr auto Background	  = ImColor{  36,  36,  36, 255 };
	static constexpr auto BackgroundDark  = ImColor{  26,  26,  26, 255 };
	static constexpr auto Titlebar		  = ImColor{  21,  21,  21, 255 };
	static constexpr auto PropertyField   = ImColor{  15,  15,  15, 255 };
	static constexpr auto Text			  = ImColor{ 192, 192, 192, 255 };
	static constexpr auto TextBrighter	  = ImColor{ 210, 210, 210, 255 };
	static constexpr auto TextDarker	  = ImColor{ 128, 128, 128, 255 };
	static constexpr auto TextError		  = ImColor{ 230,  51,  51, 255 };
	static constexpr auto Muted			  = ImColor{  77,  77,  77, 255 };
	static constexpr auto GroupHeader	  = ImColor{  47,  47,  47, 255 };
	static constexpr auto Selection		  = ImColor{ 237, 192, 119, 255 };
	static constexpr auto SelectionMuted  = ImColor{ 237, 201, 142,  23 };
	static constexpr auto BackgroundPopup = ImColor{  50,  50,  50, 255 };
	static constexpr auto NotifBlue		  = ImColor{  82, 179, 222, 255 };
	static constexpr auto NotifYellow	  = ImColor{ 236, 158,  36, 255 };
	static constexpr auto NotifOrange	  = ImColor{ 250, 101,  23, 255 };
	static constexpr auto NotifRed		  = ImColor{ 222,  43,  43, 255 };
	static constexpr auto MissingMesh	  = ImColor{ 230, 102,  76, 255 };
	static constexpr auto HoverPurple	  = ImColor{ 125,  95, 255, 255 };
	static constexpr auto ActivePurple	  = ImColor{ 113,  88, 226, 255 };
	static constexpr auto HoverNeutral	  = ImColor{ 255, 225, 135,  30 };
	static constexpr auto ActiveNeutral   = ImColor{ 255, 225, 135,  60 };

public:
	MicroImTheme( );

	~MicroImTheme( ) = default;

	void Initialize( );

	MicroImTheme& Set( ImGuiStyleVar variable, const float value );

	MicroImTheme& Set( ImGuiStyleVar variable, const ImVec2& value );

	MicroImTheme& Set( ImGuiCol color, const ImVec4& value );

	MicroImTheme& Reset( );

public:
	ImVec4& GetColor( ImGuiCol color ) const;

public:
	ImVec4& operator[]( ImGuiCol color );

};
