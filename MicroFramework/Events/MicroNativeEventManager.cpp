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
MicroNativeEventManager::MicroNativeEventManager( )
	: MicroManager{ },
    m_callbacks{ }
{ }

bool MicroNativeEventManager::Create( ) {
	return true;
}

void MicroNativeEventManager::Register( 
    const SDL_EventType type, 
    EventCallback callback 
) {
    if ( m_callbacks.find( type ) == m_callbacks.end( ) ) {
        const auto pair = std::make_pair( type, std::vector<EventCallback>{ } );

        m_callbacks.emplace( pair );
    }

    m_callbacks[ type ].emplace_back( callback );
}

void MicroNativeEventManager::Register(
    const SDL_EventType type,
    const std::vector<EventCallback>& callbacks
) {
    if ( m_callbacks.find( type ) == m_callbacks.end( ) ) {
        const auto pair = std::make_pair( type, EventCallbackList{ } );

        m_callbacks.emplace( pair );
    }

    const auto where = m_callbacks[ type ].end( );
    const auto first = callbacks.begin( );
    const auto last  = callbacks.end( );

    m_callbacks[ type ].insert( where, first, last );
}

void MicroNativeEventManager::Register(
    const SDL_EventType type,
    std::initializer_list<EventCallback> callbacks
) {
    if ( m_callbacks.find( type ) == m_callbacks.end( ) ) {
        const auto pair = std::make_pair( type, EventCallbackList{ } );

        m_callbacks.emplace( pair );
    }

    const auto where = m_callbacks[ type ].end( );

    m_callbacks[ type ].insert( where, callbacks );
}

bool MicroNativeEventManager::PollEvents(
	std::initializer_list<MicroNativeEventObserver*> observers
) {
    auto should_run = true;
    auto sdl_event  = SDL_Event{ };

    while ( should_run && SDL_PollEvent( micro_ptr( sdl_event ) ) ) {
        if ( GetShouldClose( sdl_event.type ) )
            should_run = false;

        PollObservers( sdl_event, observers );
        PollCallback( sdl_event );
    }

    return should_run;
}

void MicroNativeEventManager::Terminate( ) {
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PRIVATE ===
////////////////////////////////////////////////////////////////////////////////////////////
void MicroNativeEventManager::PollObservers( 
    const SDL_Event& sdl_event,
    std::initializer_list<MicroNativeEventObserver*> observers 
) {
    for ( auto* observer : observers ) {
        if ( observer == nullptr )
            continue;

        observer->PollEvent( sdl_event );
    }
}

void MicroNativeEventManager::PollCallback( const SDL_Event& sdl_event ) {
    for ( const auto& callback_pair : m_callbacks ) {
        if ( callback_pair.first != sdl_event.type )
            continue;

        for ( auto& callback : callback_pair.second )
            std::invoke( callback, sdl_event );
    }
}

////////////////////////////////////////////////////////////////////////////////////////////
//		===	PRIVATE GET ===
////////////////////////////////////////////////////////////////////////////////////////////
bool MicroNativeEventManager::GetShouldClose( const uint32_t event_type ) const {
    return  event_type == SDL_EVENT_WINDOW_CLOSE_REQUESTED ||
            event_type == SDL_EVENT_WINDOW_DESTROYED       ||
            event_type == SDL_EVENT_QUIT;
}
