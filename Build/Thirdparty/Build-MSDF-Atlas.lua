project "MsdfAtlas"
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
		"%{IncludeDirs.Msdf}",
		"%{IncludeDirs.Msdf}msdfgen/",
		"%{IncludeDirs.Msdf}artery-font-format"
	}

	externalincludedirs { 
		"%{IncludeDirs.Freetype}include/",
		"%{IncludeDirs.Msdf}",
		"%{IncludeDirs.Msdf}msdfgen/",
		"%{IncludeDirs.Msdf}artery-font-format"
	}

	--- GLOBAL SOURCE FILES
	files {
		"%{IncludeDirs.Msdf}msdf-atlas-gen/**.h",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/**.hpp",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/**.cpp"
	}

	--- GLOBAL LINKS
	links { "Msdf" }

	--- LINUX
	filter "system:linux"
		--- LINUX SPECIFIC DEFINES
		defines { "LINUX" }

	--- WINDOWS
	filter "system:windows"
		cppdialect "C++20"
		flags "MultiProcessorCompile"

		--- WINDOWS SPECIFIC DEFINES
		defines { "WINDOWS" }

		-- files { "%{IncludeDirs.Msdf}msdf-atlas-gen.rc" }

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
