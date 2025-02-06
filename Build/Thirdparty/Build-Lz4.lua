project "Lz4"
	kind "StaticLib"
	language "C"
	location "%{OutputDirs.Solution}"

	--- OUTPUT
	targetdir "%{OutputDirs.Bin}/%{cfg.buildcfg}/"
	debugdir "%{OutputDirs.Bin}/%{cfg.buildcfg}/"
	objdir "%{OutputDirs.BinInt}/%{prj.name}-%{cfg.buildcfg}"

	--- GLOBAL INCLUDES
	includedirs {
		"%{IncludeDirs.Lz4}lib/"
	}

	externalincludedirs {
		"%{IncludeDirs.Lz4}lib/"
	}

	--- GLOBAL DEFINES
	defines { "LZ4_DLL_EXPORT" }
	
	--- GLOBAL SOURCE FILES
	files {
		"%{IncludeDirs.Lz4}lib/**.h",
		"%{IncludeDirs.Lz4}lib/**.c"
	}

	--- LINUX
	filter "system:linux"
		--- LINUX SPECIFIC DEFINES
		defines { "LINUX" }

	--- WINDOWS
	filter "system:windows"
		cdialect "C17"
		flags "MultiProcessorCompile"

		--- WINDOWS SPECIFIC DEFINES
		defines { "WINDOWS" }

		--- WINDOWS SPECIFIC SOURCE FILES
		files { "%{IncludeDirs.Lz4}build/VS2022/lz4/lz4.rc" }

    --- CONFIGURATION
	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"
		
		--- DEFINES
		defines { "DEBUG" }

	filter "configurations:Release"
		runtime "Release"
		optimize "On"
		symbols "On"

		--- DEFINES
		defines { "RELEASE" }

	filter "configurations:Dist"
		runtime "Release"
		optimize "On"
		symbols "Off"

		--- DEFINES
		defines { "DIST" }
