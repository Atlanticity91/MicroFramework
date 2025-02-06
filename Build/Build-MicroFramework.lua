project "MicroFramework"
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
		"%{IncludeDirs.MicroFramework}",
		"%{IncludeDirs.MicroCore}",
		"%{IncludeDirs.Glm}",
		"%{IncludeDirs.Libclang}",
		"%{IncludeDirs.Spdlog}",
		"%{IncludeDirs.Yaml}",
		"%{IncludeDirs.MicroOpenGL}",
		"%{IncludeDirs.Glew}",
		"%{IncludeDirs.Glw}",
		"%{IncludeDirs.MicroVulkan}",
		"%{IncludeDirs.Vulkan}",
		"%{IncludeDirs.Freetype}",
		"%{IncludeDirs.Imgui}",
		"%{IncludeDirs.Lz4}",
		"%{IncludeDirs.Msdf}",
		"%{IncludeDirs.MsdfAtlas}",
		"%{IncludeDirs.Nvidia}",
		"%{IncludeDirs.Sdl}include/",
		"%{IncludeDirs.SdlMixer}include/",
		"%{IncludeDirs.Thorvg}"
	}
	
	externalincludedirs {
		"%{IncludeDirs.MicroFramework}",
		"%{IncludeDirs.MicroCore}",
		"%{IncludeDirs.Glm}",
		"%{IncludeDirs.Libclang}",
		"%{IncludeDirs.Spdlog}",
		"%{IncludeDirs.Yaml}",
		"%{IncludeDirs.MicroOpenGL}",
		"%{IncludeDirs.Glew}",
		"%{IncludeDirs.Glw}",
		"%{IncludeDirs.MicroVulkan}",
		"%{IncludeDirs.Vulkan}",
		"%{IncludeDirs.Freetype}",
		"%{IncludeDirs.Imgui}",
		"%{IncludeDirs.Lz4}",
		"%{IncludeDirs.Msdf}",
		"%{IncludeDirs.MsdfAtlas}",
		"%{IncludeDirs.Nvidia}",
		"%{IncludeDirs.Sdl}include/",
		"%{IncludeDirs.SdlMixer}include/",
		"%{IncludeDirs.Thorvg}"
	}

	--- CONDITIONAL ADD RENDER DOC
	if render_doc ~= nil then
		defines { "MICRO_USE_RENDER_DOC" }
		
		includedirs { "%{IncludeDirs.RenderDoc}" }
		
		externalincludedirs { "%{IncludeDirs.RenderDoc}" }
	end

	--- PRECOMPILED HEADER
	pchheader "__micro_framework_pch.h"

	--- GLOBAL SOURCE FILES
	files { 
		"%{IncludeDirs.MicroFramework}/**.h", 
		"%{IncludeDirs.MicroFramework}/**.cpp" 
	}

	--- GLOBAL LINK
	links {
		"Freetype",
		"Imgui",
		"Lz4",
		"Msdf",
		"MsdfAtlas",
		"SDL",
		"SDL_Mixer",
		"Thorvg",
		"Nsight",
		"MicroCore",
		"MicroOpenGL",
		"MicroVulkan",
		"Thorvg"
	}

	-- LINUX
	filter "system:linux"
		systemversion "latest"

		--- LINUX SPECIFIC DEFINES
		defines { "LINUX" }

	-- WINDOWS
	filter "system:windows"
		systemversion "latest"
		cppdialect "C++20"
		flags "MultiProcessorCompile"
		
		--- WINDOWS SPECIFIC DEFINES
		defines { 
			"WINDOWS",
			"_CRT_SECURE_NO_WARNINGS"
		}

		-- PRECOMPILED SOURCE
		pchsource "%{IncludeDirs.MicroFramework}__micro_framework_pch.cpp"

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
