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
MicroInputDeviceMouseManager::MicroInputDeviceMouseManager( )
	: MicroInputDeviceManager{ }
{ }

void MicroInputDeviceMouseManager::PollEvent( const SDL_Event& sdl_event ) {
	if ( sdl_event.mdevice.type == SDL_EVENT_MOUSE_ADDED ) {
		auto device = std::make_pair( sdl_event.mdevice.which, MicroInputDeviceMouse{ } );

		m_devices.emplace( device );

		return;
	}

	if ( sdl_event.mdevice.type == SDL_EVENT_MOUSE_REMOVED ) {
		m_devices.erase( sdl_event.mdevice.which );

		return;
	}

	auto device_id = (uint32_t)0;

	if ( sdl_event.type == SDL_EVENT_MOUSE_MOTION )
		device_id = sdl_event.motion.which;

	if ( sdl_event.type == SDL_EVENT_MOUSE_BUTTON_DOWN || sdl_event.type == SDL_EVENT_MOUSE_BUTTON_UP )
		device_id = sdl_event.button.which;

	if ( sdl_event.type == SDL_EVENT_MOUSE_WHEEL )
		device_id = sdl_event.wheel.which;

	m_devices[ device_id ].PollEvent( sdl_event );
}
