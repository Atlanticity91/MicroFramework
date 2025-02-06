project 'SDL_Mixer'
	kind 'StaticLib'
	language 'C'
	staticruntime 'off'
	location '%{OutputDirs.Solution}'

	--- OUTPUT
	targetdir '%{OutputDirs.Bin}/%{cfg.buildcfg}/'
	debugdir '%{OutputDirs.Bin}/%{cfg.buildcfg}/'
	objdir '%{OutputDirs.BinInt}/%{prj.name}-%{cfg.buildcfg}'

    --- GLOBAL DEFINES
    defines {
        'HAVE_WAVPACK_H',
        'MUSIC_WAVPACK',
        'MUSIC_WAV',
        'MUSIC_FLAC_DRFLAC',
        'MUSIC_MOD_XMP',
        'MUSIC_MP3_MINIMP3',
        'MUSIC_OGG',
        'OGG_USE_STB',
        'MUSIC_OPUS',
        'MUSIC_MID_TIMIDITY',
        'MUSIC_MID_NATIVE',
        'MUSIC_GME'
    }

	--- GLOBAL INCLUDES
	includedirs {
        "%{IncludeDirs.Sdl}include/",
		'%{IncludeDirs.SdlMixer}include/',
		'%{IncludeDirs.SdlMixer}src/',
        '%{IncludeDirs.SdlMixer}src/codecs/',
        '%{IncludeDirs.SdlMixer}src/codecs/native_midi/',
        '%{IncludeDirs.SdlMixer}VisualC/external/include/',
        '%{IncludeDirs.SdlMixer}VisualC/external/include/wavpack/'
	}

	externalincludedirs {
        "%{IncludeDirs.Sdl}include/",
		'%{IncludeDirs.SdlMixer}include/',
		'%{IncludeDirs.SdlMixer}src/',
        '%{IncludeDirs.SdlMixer}src/codecs/',
        '%{IncludeDirs.SdlMixer}src/codecs/native_midi/',
        '%{IncludeDirs.SdlMixer}VisualC/external/include/',
        '%{IncludeDirs.SdlMixer}VisualC/external/include/wavpack/'
	}

	--- GLOBAL SOURCE FILES
	files {
		'%{IncludeDirs.SdlMixer}include/SDL3_Mixer/**.h',
        "%{IncludeDirs.SdlMixer}src/effects_internal.h",
        "%{IncludeDirs.SdlMixer}src/mixer.h",
        "%{IncludeDirs.SdlMixer}src/music.h",
        "%{IncludeDirs.SdlMixer}src/utils.h",
        "%{IncludeDirs.SdlMixer}src/codecs/load_aiff.h",
        "%{IncludeDirs.SdlMixer}src/codecs/load_sndfile.h",
        "%{IncludeDirs.SdlMixer}src/codecs/load_voc.h",
        "%{IncludeDirs.SdlMixer}src/codecs/mp3utils.h",
        "%{IncludeDirs.SdlMixer}src/codecs/music_drflac.h",
        "%{IncludeDirs.SdlMixer}src/codecs/music_flac.h",
        "%{IncludeDirs.SdlMixer}src/codecs/music_fluidsynth.h",
        "%{IncludeDirs.SdlMixer}src/codecs/music_gme.h",
        "%{IncludeDirs.SdlMixer}src/codecs/music_minimp3.h",
        "%{IncludeDirs.SdlMixer}src/codecs/music_modplug.h",
        "%{IncludeDirs.SdlMixer}src/codecs/music_mpg123.h",
        "%{IncludeDirs.SdlMixer}src/codecs/music_nativemidi.h",
        "%{IncludeDirs.SdlMixer}src/codecs/music_ogg.h",
        "%{IncludeDirs.SdlMixer}src/codecs/music_opus.h",
        "%{IncludeDirs.SdlMixer}src/codecs/music_timidity.h",
        "%{IncludeDirs.SdlMixer}src/codecs/music_wav.h",
        "%{IncludeDirs.SdlMixer}src/codecs/music_wavpack.h",
        "%{IncludeDirs.SdlMixer}src/codecs/music_xmp.h",
        "%{IncludeDirs.SdlMixer}src/effect_position.c",
        "%{IncludeDirs.SdlMixer}src/effect_stereoreverse.c",
        "%{IncludeDirs.SdlMixer}src/effects_internal.c",
        "%{IncludeDirs.SdlMixer}src/mixer.c",
        "%{IncludeDirs.SdlMixer}src/music.c",
        "%{IncludeDirs.SdlMixer}src/utils.c",
        "%{IncludeDirs.SdlMixer}src/codecs/load_aiff.c",
        "%{IncludeDirs.SdlMixer}src/codecs/load_sndfile.c",
        "%{IncludeDirs.SdlMixer}src/codecs/load_voc.c",
        "%{IncludeDirs.SdlMixer}src/codecs/mp3utils.c",
        "%{IncludeDirs.SdlMixer}src/codecs/music_drflac.c",
        "%{IncludeDirs.SdlMixer}src/codecs/music_flac.c",
        "%{IncludeDirs.SdlMixer}src/codecs/music_fluidsynth.c",
        "%{IncludeDirs.SdlMixer}src/codecs/music_gme.c",
        "%{IncludeDirs.SdlMixer}src/codecs/music_minimp3.c",
        "%{IncludeDirs.SdlMixer}src/codecs/music_modplug.c",
        "%{IncludeDirs.SdlMixer}src/codecs/music_mpg123.c",
        "%{IncludeDirs.SdlMixer}src/codecs/music_nativemidi.c",
        "%{IncludeDirs.SdlMixer}src/codecs/music_ogg.c",
        "%{IncludeDirs.SdlMixer}src/codecs/music_ogg_stb.c",
        "%{IncludeDirs.SdlMixer}src/codecs/music_opus.c",
        "%{IncludeDirs.SdlMixer}src/codecs/music_timidity.c",
        "%{IncludeDirs.SdlMixer}src/codecs/music_wav.c",
        "%{IncludeDirs.SdlMixer}src/codecs/music_wavpack.c",
        "%{IncludeDirs.SdlMixer}src/codecs/music_xmp.c"
	}

	--- LINUX
	filter 'system:linux'
		--- LINUX SPECIFIC DEFINES	
		defines { 'LINUX' }
		
		--- LINUX SPECIFIC SOURCE FILES
		-- files { }

		--- LINUX SPECIFIC LINK
		-- link { }

	--- WINDOWS
	filter 'system:Windows'
		systemversion 'latest'
		system 'windows'
		flags 'MultiProcessorCompile'
		cdialect 'C17'

		--- WINDOWS SPECIFIC DEFINES
		defines {
			'WINDOWS', 
			'_CRT_SECURE_NO_WARNINGS',
            'XMP_DYNAMIC="libxmp.dll"',
            'OGG_DYNAMIC="libogg-0"',
            'OPUS_DYNAMIC="libopusfile-0.dll"',
            'WAVPACK_DYNAMIC="libwavpack-1.dll"',
            'GME_DYNAMIC="libgme.dll"'
		}

		--- WINDOWS SPECIFIC LINK
        links { 'winmm.lib', 'SDL' }

		--- PRECOMPILED SOURCE
		pchsource '%{IncludeDirs.Sdl}src/core/windows/pch.c'

		--- WINDOWS SPECIFIC SOURCE FILES
		files {
			'%{IncludeDirs.SdlMixer}src/version.rc',
		}

        --- WINDOWS SPECIFIC PRE-BUILD COMMAND
        prebuildmessage 'Copy SDL_Mixer dependencies'
        prebuildcommands {
           '{COPYDIR} %{IncludeDirs.SdlMixer}VisualC/external/optional/x64/ %{OutputDirs.Bin}/%{cfg.buildcfg}/'
        }

    --- CONFIGURATION
	filter 'configurations:Debug'
		runtime 'Debug'
		symbols 'On'

		--- DEFINES
		defines {
			'DEBUG',
            'FT_DEBUG_LEVEL_ERROR',
            'FT_DEBUG_LEVEL_TRACE'
        }

	filter 'configurations:Release'
		runtime 'Release'
		optimize 'On'
		symbols 'On'

		--- DEFINES
		defines { 'RELEASE' }

	filter 'configurations:Dist'
		runtime 'Release'
		optimize 'On'
		symbols 'Off'

		--- DEFINES
		defines { 'DIST' }
