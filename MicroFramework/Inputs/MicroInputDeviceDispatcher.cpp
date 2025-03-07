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
MicroInputDeviceDispatcher::MicroInputDeviceDispatcher( )
	: MicroNativeEventObserver{ },
	m_keyboards{ },
	m_mouses{ },
	m_gamepads{ }
{ }

void MicroInputDeviceDispatcher::PollEvent( const SDL_Event& sdl_event ) {
	m_keyboards.PollEvent( sdl_event );
	m_mouses.PollEvent( sdl_event );
	m_gamepads.PollEvent( sdl_event );
}

void MicroInputDeviceDispatcher::Tick( ) {
	m_keyboards.Tick( );
	m_mouses.Tick( );
	m_gamepads.Tick( );
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PUBLIC GET ===
////////////////////////////////////////////////////////////////////////////////////////////
MicroInputDevice* MicroInputDeviceDispatcher::Get(
	const MicroInputDeviceTypes type,
	const uint32_t witch
) const {
	auto* device = micro_cast( nullptr, MicroInputDevice* );

	switch ( type ) {
		case MicroInputDeviceTypes::Keyboard : device = m_keyboards.Get( witch ); break;
		case MicroInputDeviceTypes::Mouse	 : device = m_mouses.Get( witch );	  break;
		case MicroInputDeviceTypes::Gamepad  : device = m_gamepads.Get( witch );  break;

		default : break;
	}

	return device;
}

bool MicroInputDeviceDispatcher::Evaluate( const MicroInputQueryButton& button ) const {
	auto state = false;

	switch ( button.Type ) {
		case MicroInputDeviceTypes::Keyboard : state = m_keyboards.Evaluate( button ); break;
		case MicroInputDeviceTypes::Mouse	 : state = m_mouses.Evaluate( button );	   break;
		case MicroInputDeviceTypes::Gamepad  : state = m_gamepads.Evaluate( button );  break;

		default : break;
	}

	return state;
}

micro_vec2 MicroInputDeviceDispatcher::EvaluateAxis( 
	const MicroInputQueryAxis& axis 
) const {
	auto result = micro_vec2{ };

	switch ( axis.Type ) {
		case MicroInputDeviceTypes::Keyboard : result = m_keyboards.EvaluateAxis( axis ); break;
		case MicroInputDeviceTypes::Mouse	 : result = m_keyboards.EvaluateAxis( axis ); break;
		case MicroInputDeviceTypes::Gamepad  : result = m_keyboards.EvaluateAxis( axis ); break;

		default : break;
	}

	return result;
}


bool MicroInputDeviceDispatcher::Evaluate(
	const MicroInputQueryButton& button,
	const uint32_t witch
) const {
	auto state = false;

	switch ( button.Type ) {
		case MicroInputDeviceTypes::Keyboard : state = m_keyboards.Evaluate( button, witch ); break;
		case MicroInputDeviceTypes::Mouse	 : state = m_mouses.Evaluate( button, witch );	  break;
		case MicroInputDeviceTypes::Gamepad  : state = m_gamepads.Evaluate( button, witch );  break;

		default: break;
	}

	return state;
}

micro_vec2 MicroInputDeviceDispatcher::EvaluateAxis(
	const MicroInputQueryAxis& axis,
	const uint32_t witch
) const {
	auto result = micro_vec2{ };

	switch ( axis.Type ) {
		case MicroInputDeviceTypes::Keyboard : result = m_keyboards.EvaluateAxis( axis, witch ); break;
		case MicroInputDeviceTypes::Mouse	 : result = m_keyboards.EvaluateAxis( axis, witch ); break;
		case MicroInputDeviceTypes::Gamepad  : result = m_keyboards.EvaluateAxis( axis, witch ); break;

		default : break;
	}

	return result;
}
