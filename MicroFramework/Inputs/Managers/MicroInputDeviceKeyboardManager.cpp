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

#include "__micro_framework_pch.h"

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC ===
////////////////////////////////////////////////////////////////////////////////////////////
MicroInputDeviceKeyboardManager::MicroInputDeviceKeyboardManager( )
	: MicroInputDeviceManager{ }
{ }

void MicroInputDeviceKeyboardManager::PollEvent( const SDL_Event& sdl_event ) {
	if ( sdl_event.type == SDL_EVENT_KEYBOARD_ADDED ) {
		auto device = std::make_pair( sdl_event.kdevice.which, MicroInputDeviceKeyboard{ } );

		m_devices.emplace( device );

		return;
	}

	if ( sdl_event.type == SDL_EVENT_KEYBOARD_REMOVED ) {
		m_devices.erase( sdl_event.kdevice.which );

		return;
	}

	if ( sdl_event.type == SDL_EVENT_KEY_DOWN || sdl_event.type == SDL_EVENT_KEY_UP )
		m_devices[ sdl_event.key.key ].PollEvent( sdl_event );
}
