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

#include "../Devices/MicroInputDeviceGamepad.h"

template<typename InputDevice>
	requires ( std::is_base_of_v<MicroInputDevice, InputDevice> )
class MicroInputDeviceManager : public MicroInputDevice {

protected:
	std::map<uint32_t, InputDevice> m_devices;

public:
	MicroInputDeviceManager( )
		: MicroInputDevice{ },
		m_devices{ }
	{ };

	virtual ~MicroInputDeviceManager( ) = default;

	micro_implement( void Tick( ) ) { 
		for ( auto& pair : m_devices )
			pair.second.Tick( );
	};

public:
	uint32_t GetCount( ) const {
		return (uint32_t)m_devices.size( );
	};

	virtual InputDevice* Get( const uint32_t which ) const { 
		const auto iterator = m_devices.find( which );
		auto input_device   = micro_cast( nullptr, InputDevice* );

		if ( iterator != m_devices.end( ) )
			input_device = micro_ptr_as( iterator->second, InputDevice* );

		return input_device;
	};

	micro_implement( bool Evaluate(
		const MicroInputQueryButton& button 
	) const ) {
		auto state = false;

		for ( auto& pair : m_devices ) {
			if ( state = pair.second.Evaluate( button ) )
				break;
		}

		return state;
	};

	micro_implement( micro_vec2 EvaluateAxis(
		const MicroInputQueryAxis& axis
	) const ) {
		auto result = micro_vec2{ };

		for ( auto& pair : m_devices ) {
			result = pair.second.EvaluateAxis( axis );

			if ( result != 0.f )
				break;
		}

		return result;
	};

	bool Evaluate(
		const MicroInputQueryButton& button,
		const uint32_t which
	) const {
		auto state = false;

		if ( auto* device = Get( which ) )
			state = device->Evaluate( button );

		return state;
	};

	micro_vec2 EvaluateAxis(
		const MicroInputQueryAxis& axis,
		const uint32_t which
	) const {
		auto result = micro_vec2{ };

		if ( auto* device = Get( which ) )
			result = device->EvaluateAxis( axis );

		return result;
	};

};
