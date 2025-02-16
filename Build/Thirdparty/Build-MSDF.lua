project "Msdf"
	kind "StaticLib"
	language "C++"
	staticruntime "off"
	location "%{OutputDirs.Solution}"

	--- OUTPUT
	targetdir "%{OutputDirs.Bin}%{cfg.buildcfg}/"
	debugdir "%{OutputDirs.Bin}%{cfg.buildcfg}/"
	objdir "%{OutputDirs.BinInt}%{prj.name}-%{cfg.buildcfg}"

	--- GLOBAL INCLUDES
	includedirs { 
		"%{IncludeDirs.Freetype}include/",
		"%{IncludeDirs.Msdf}" 
	}

	externalincludedirs { 
		"%{IncludeDirs.Freetype}include/",
		"%{IncludeDirs.Msdf}" 
	}

	--- GLOBAL SOURCE FILES
	files {
		"%{IncludeDirs.Msdf}msdfgen/core/**.h",
		"%{IncludeDirs.Msdf}msdfgen/core/**.hpp",
		"%{IncludeDirs.Msdf}msdfgen/core/**.cpp",
		"%{IncludeDirs.Msdf}msdfgen/ext/**.h",
		"%{IncludeDirs.Msdf}msdfgen/ext/**.hpp",
		"%{IncludeDirs.Msdf}msdfgen/ext/**.cpp",
		"%{IncludeDirs.Msdf}msdfgen/msdfgen.h",
		"%{IncludeDirs.Msdf}msdfgen/msdfgen-ext.h",
		"%{IncludeDirs.Msdf}msdfgen/resource.h"
	}

	--- GLOBAL LINKS
	links { "Freetype" }

	prebuildmessage "Copy Msdf configuration file"
	prebuildcommands {
		"{COPYFILE} %{IncludeDirs.Msdf}../Configs/msdfgen-config.h %{IncludeDirs.Msdf}msdfgen/"
	}

	--- LINUX
	filter "system:linux"
		--- LINUX SPECIFIC DEFINES
		defines { "LINUX" }

		--- LINUX SPECIFIC SOURCE FILES
		-- files { }

	--- WINDOWS
	filter "system:windows"
		cppdialect "C++20"
		flags "MultiProcessorCompile"

		--- WINDOWS SPECIFIC DEFINES
		defines { 
			"WINDOWS",
			"_CRT_SECURE_NO_WARNINGS"
		}

		-- files { "%{IncludeDirs.Msdf}msdfgen/msdfgen.rc" }

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
