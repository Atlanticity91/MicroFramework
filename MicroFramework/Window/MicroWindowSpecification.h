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

#include "MicroWindowFlags.h"

/**
 * MicroWindowSpecification struct
 * @note : Defined window creation specification.
 **/
struct MicroWindowSpecification {

	std::string Title;
	uint32_t Width;
	uint32_t Height;
	MicroWindowFlags Flags;

	/**
	 * Constructor
	 **/
	MicroWindowSpecification( );

	/**
	 * Constructor
	 * @param title : Query window title.
	 **/
	MicroWindowSpecification( const std::string& title );

	/**
	 * Constructor
	 * @param title : Query window title.
	 * @param witth : Query window width.
	 * @param height : Query window height.
	 **/
	MicroWindowSpecification(
		const std::string& title,
		const uint32_t width,
		const uint32_t height
	);

	/**
	 * Constructor
	 * @param title : Query window title.
	 * @param witth : Query window width.
	 * @param height : Query window height.
	 * @param flags : Query window flags.
	 **/
	MicroWindowSpecification(
		const std::string& title,
		const uint32_t width,
		const uint32_t height,
		const MicroWindowFlags& flags
	);

};
