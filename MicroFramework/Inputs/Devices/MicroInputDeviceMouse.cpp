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
MicroInputDeviceMouse::MicroInputDeviceMouse( )
	: MicroInputDevice{ },
	m_old_states{ },
	m_new_states{ },
	m_position{ },
	m_wheel{ }
{ }

void MicroInputDeviceMouse::PollEvent( const SDL_Event& sdl_event ) {
	if ( sdl_event.type == SDL_EVENT_MOUSE_MOTION ) {
		m_position.x = sdl_event.motion.x;
		m_position.y = sdl_event.motion.y;
	}

	if ( sdl_event.type == SDL_EVENT_MOUSE_WHEEL ) {
		m_wheel.x = sdl_event.wheel.x;
		m_wheel.y = sdl_event.wheel.y;
	}

	if ( sdl_event.type == SDL_EVENT_MOUSE_BUTTON_DOWN || sdl_event.type == SDL_EVENT_MOUSE_BUTTON_UP )
		m_new_states ^= ( 1 << ( sdl_event.button.button - 1 ) );
}

void MicroInputDeviceMouse::Tick( ) {
	m_old_states = m_new_states;
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
bool MicroInputDeviceMouse::Evaluate( const MicroInputQueryButton& button ) const {
	const auto key = button.Key - 1;
	auto result	   = false;

	switch ( button.State ) {
		case MicroInputStates::Pressed  : result = !GetIsDown( m_old_states, key ) && GetIsDown( m_new_states, key ); break;
		case MicroInputStates::Released : result =  GetIsDown( m_old_states, key ) && !GetIsDown( m_new_states, key ); break;
		case MicroInputStates::Down		: result =  GetIsDown( m_old_states, key ) &&  GetIsDown( m_new_states, key ); break;
		case MicroInputStates::Up		: result = !GetIsDown( m_old_states, key ) && !GetIsDown( m_new_states, key ); break;

		default: break;
	}

	return result;
}

micro_vec2 MicroInputDeviceMouse::EvaluateAxis( const MicroInputQueryAxis& axis ) const {
	auto value = micro_vec2{ };

	switch ( axis.Key ) {
		case 0 : value = m_position; break;
		case 1 : value = m_wheel; break;

		default : break;
	}

	return value;
}

const micro_vec2 MicroInputDeviceMouse::GetPosition( ) const {
	return m_position;
}

const micro_vec2 MicroInputDeviceMouse::GetWheel( ) const {
	return m_wheel;
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PRIVATE GET ===
////////////////////////////////////////////////////////////////////////////////////////////
bool MicroInputDeviceMouse::GetIsDown( const uint8_t states, const uint32_t button ) const {
	return ( states >> button ) & 0b00000001;
}
