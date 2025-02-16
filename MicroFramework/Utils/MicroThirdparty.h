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

////////////////////////////////////////////////////////////////////////////////////////////
//		===	INCLUDES ===
////////////////////////////////////////////////////////////////////////////////////////////
#include "MicroCore.h"
#include "MicroOpenGL.h"
#include "MicroVulkan.h"

#if defined( MICRO_USE_x32 ) && !defined( MICRO_ARCH_x32 )
#	throw "Architecture unimplemented"
#endif

// DISABLE WARNINGS ON EXTERNAL LIBRARY FOR VISUAL STUDIO
#ifdef _MSC_VER
#	pragma warning( push, 0 )
#endif

#include "freetype/freetype.h"
#include "imgui.h"
#include "imgui_internal.h"
#include "backends/imgui_impl_sdl3.h"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_vulkan.h"
#include "lib/lz4.h"
#include "msdf-atlas-gen.h"

#ifdef WINDOWS
#	include "backends/imgui_impl_win32.h"
#	ifdef MICRO_USE_NVIDIA
#		include "nsight/windows/GFSDK_Aftermath.h"
#		include "nsight/windows/GFSDK_Aftermath_GpuCrashDump.h"
#		include "nsight/windows/GFSDK_Aftermath_GpuCrashDumpDecoding.h"
#	elif MICRO_USE_AMD
#	endif
#elif LINUX
#	ifdef MICRO_USE_NVIDIA
#		include "nsight/linux/GFSDK_Aftermath.h"
#		include "nsight/linux/GFSDK_Aftermath_GpuCrashDump.h"
#		include "nsight/linux/GFSDK_Aftermath_GpuCrashDumpDecoding.h"
#	elif MICRO_USE_AMD
#	endif
#elif MACOS
#	include "backends/imgui_impl_osx.h"
#else
#	throw "Platform is unimplemented"
#endif

#ifdef MICRO_USE_RENDER_DOC
#	include "renderdoc_app.h"
#endif

#include "SDL3/SDL_opengl.h"
#include "SDL3/SDL_vulkan.h"
#include "SDL3/SDL.h"
#include "SDL3_mixer/SDL_mixer.h"

// RE-ENABLE WARNINGS ON EXTERNAL LIBRARY FOR VISUAL STUDIO
#ifdef _MSC_VER
#	pragma warning( pop )
#endif

////////////////////////////////////////////////////////////////////////////////////////////
//		===	DEFINES ===
////////////////////////////////////////////////////////////////////////////////////////////
#define SDL_OK 0
#define SDL_INIT_INPUTS SDL_INIT_GAMEPAD | SDL_INIT_HAPTIC
