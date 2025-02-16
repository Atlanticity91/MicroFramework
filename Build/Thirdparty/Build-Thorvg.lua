project "Thorvg"
	kind "StaticLib"
	language "C++"
	staticruntime "off"
	location "%{OutputDirs.Solution}"

	--- OUTPUT
	targetdir "%{OutputDirs.Bin}/%{cfg.buildcfg}/"
	debugdir "%{OutputDirs.Bin}/%{cfg.buildcfg}/"
	objdir "%{OutputDirs.BinInt}/%{prj.name}-%{cfg.buildcfg}"

	--- GLOBAL INCLUDES
	includedirs { "%{IncludeDirs.Thorvg}inc/" }

	externalincludedirs { "%{IncludeDirs.Thorvg}inc/" }

	--- GLOBAL DEFINES
	defines { 
		"TVG_STATIC", 
		"TVG_EXPORTS" 
	}

	--- GLOBAL FILES
    files {
    	"%{IncludeDirs.Thorvg}src/**.cpp",
        "%{IncludeDirs.Thorvg}src/**.c",
        "%{IncludeDirs.Thorvg}inc/**.hpp",
        "%{IncludeDirs.Thorvg}inc/**.h"
    }

	--- LINUX
	filter "system:linux"
		--- LINUX SPECIFIC DEFINES
		defines { "LINUX" }

		--- LINUX SPECIFIC LINKS
		links { "m" } 

	--- WINDOWS
	filter "system:Windows"
		systemversion "latest"
		system "windows"
		flags "MultiProcessorCompile"
		cppdialect "C++20"

		--- WINDOWS SPECIFIC DEFINES
		defines { "WINDOWS" }
