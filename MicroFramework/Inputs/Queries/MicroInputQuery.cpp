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
MicroInputQuery::MicroInputQuery( )
	: Filters{ },
	Buttons{ },
	Axis{ }
{ }

MicroInputQuery::MicroInputQuery( const MicroInputQuery& other )
	: Filters{ other.Filters },
	Buttons{ other.Buttons },
	Axis{ other.Axis }
{ }

MicroInputQuery::MicroInputQuery( MicroInputQuery&& other ) noexcept
	: Filters{ other.Filters },
	Buttons{ std::move( other.Buttons ) },
	Axis{ std::move( other.Axis ) }
{ }

MicroInputQuery::MicroInputQuery(
	const uint32_t filters,
	const std::vector<MicroInputQueryButton>& buttons,
	const std::vector<MicroInputQueryAxis>& axis
)
	: Filters{ filters },
	Buttons{ buttons },
	Axis{ axis }
{ }

MicroInputQuery::MicroInputQuery(
	const uint32_t filters,
	std::vector<MicroInputQueryButton>&& buttons,
	std::vector<MicroInputQueryAxis>&& axis
)
	: Filters{ filters },
	Buttons{ std::move( buttons ) },
	Axis{ std::move( axis ) }
{ }
