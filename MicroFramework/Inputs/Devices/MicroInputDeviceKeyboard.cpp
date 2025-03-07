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
MicroInputDeviceKeyboard::MicroInputDeviceKeyboard( )
	: MicroInputDevice{ },
	m_old_states{ },
	m_new_states{ }
{ }

void MicroInputDeviceKeyboard::PollEvent( const SDL_Event& sdl_event ) {
	if ( sdl_event.type != SDL_EVENT_KEY_DOWN || sdl_event.type != SDL_EVENT_KEY_UP || sdl_event.key.repeat )
		return;

	const auto key_scancode = SDL_GetScancodeFromKey( sdl_event.key.key, nullptr );
	const auto state_id		= key_scancode / BitSize;
	const auto bit_id		= key_scancode % BitSize;

	m_new_states[ state_id ] ^= ( 1 << bit_id );
}

void MicroInputDeviceKeyboard::Tick( ) {
	auto state_id = Count;

	while ( state_id-- > 0 )
		m_old_states[ state_id ] = m_new_states[ state_id ];
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
bool MicroInputDeviceKeyboard::Evaluate( const MicroInputQueryButton& button ) const {
	SDL_Keymod key_modifier;
	const auto scancode = SDL_GetScancodeFromKey( button.Key, micro_ptr( key_modifier ) );
	auto key_state		= false;
	
	switch ( button.State ) {
		case MicroInputStates::Pressed  : key_state = !GetIsDown( m_old_states, scancode ) &&  GetIsDown( m_new_states, scancode ); break;
		case MicroInputStates::Released : key_state =  GetIsDown( m_old_states, scancode ) && !GetIsDown( m_new_states, scancode ); break;
		case MicroInputStates::Down		: key_state =  GetIsDown( m_old_states, scancode ) &&  GetIsDown( m_new_states, scancode ); break;
		case MicroInputStates::Up		: key_state = !GetIsDown( m_old_states, scancode ) && !GetIsDown( m_new_states, scancode ); break;

		default : break;
	}

	return key_state && ( key_modifier & button.Modifier );
}

micro_vec2 MicroInputDeviceKeyboard::EvaluateAxis( const MicroInputQueryAxis& axis ) const {
	const auto scancode = SDL_GetScancodeFromKey( axis.Key, nullptr );

	return { GetIsDown( m_old_states, scancode ) * 1.f, 0.f };
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PRIVATE GET ===
////////////////////////////////////////////////////////////////////////////////////////////
bool MicroInputDeviceKeyboard::GetIsDown( 
	const uint64_t* states,
	const uint32_t scancode 
) const {
	const auto state_id = scancode / BitSize;
	const auto bit_id   = scancode % BitSize;

	return ( ( states[ state_id ] ) >> bit_id ) & 0x0000000000000001;
}
