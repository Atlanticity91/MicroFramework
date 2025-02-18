project 'Test-SDL'
	kind 'SharedLib'
	language 'C++'
	location '%{OutputDirs.Solution}'

	--- OUTPUT
	targetdir '%{OutputDirs.Bin}%{cfg.buildcfg}/'
	debugdir '%{OutputDirs.Bin}%{cfg.buildcfg}/'
	objdir '%{OutputDirs.BinInt}%{prj.name}-%{cfg.buildcfg}'

	--- GLOBAL INCLUDES
	includedirs {
		'%{IncludeDirs.Sdl}include/',
		'%{IncludeDirs.Sdl}include/build_config/',
		'%{IncludeDirs.Sdl}src/'
	}

	externalincludedirs {
		'%{IncludeDirs.Sdl}include/',
		'%{IncludeDirs.Sdl}include/build_config/',
		'%{IncludeDirs.Sdl}src/'
	}

	--- GLOBAL LINKS
	links'SDL'

	--- WINDOWS
	filter 'system:windows'
		systemversion 'latest'
		cppdialect 'C++20'
		staticruntime 'off'
		
		--- DEFINES
		defines { 
			'WINDOWS',
			'_CRT_SECURE_NO_WARNINGS'
		}

		--- SOURCES FILES
		files {
            '%{IncludeDirs.Sdl}src/test/SDL_test_assert.c',
            '%{IncludeDirs.Sdl}src/test/SDL_test_common.c',
            '%{IncludeDirs.Sdl}src/test/SDL_test_compare.c',
            '%{IncludeDirs.Sdl}src/test/SDL_test_crc32.c',
            '%{IncludeDirs.Sdl}src/test/SDL_test_font.c',
            '%{IncludeDirs.Sdl}src/test/SDL_test_fuzzer.c',
            '%{IncludeDirs.Sdl}src/test/SDL_test_harness.c',
            '%{IncludeDirs.Sdl}src/test/SDL_test_log.c',
            '%{IncludeDirs.Sdl}src/test/SDL_test_md5.c',
            '%{IncludeDirs.Sdl}src/test/SDL_test_memory.c'
		}

	--- LINUX
	filter 'system:linux'
		systemversion 'latest'
		defines { 'LINUX' }

		--- SOURCES FILES
		files {
		}

	--- CONFIGURATION
	filter 'configurations:Debug'
		defines { 'DEBUG' }
		runtime 'Debug'
		symbols 'On'

	filter 'configurations:Release'
		defines { 'RELEASE' }
		runtime 'Release'
		optimize 'On'
		symbols 'On'

	filter 'configurations:Dist'
		defines { 'DIST' }
		runtime 'Release'
		optimize 'On'
		symbols 'Off'
