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
		"%{IncludeDirs.MicroCore}",
		"%{IncludeDirs.MicroFramework}",
		"%{IncludeDirs.Glm}",
		"%{IncludeDirs.Libclang}",
		"%{IncludeDirs.Spdlog}include/",
		"%{IncludeDirs.Yaml}include/",
		"%{IncludeDirs.MicroOpenGL}",
		"%{IncludeDirs.Glew}include/",
		"%{IncludeDirs.Glw}",
		"%{IncludeDirs.MicroVulkan}",
		"%{IncludeDirs.Vulkan}",
		"%{IncludeDirs.Freetype}include/",
		"%{IncludeDirs.Imgui}",
		"%{IncludeDirs.Lz4}",
		"%{IncludeDirs.Msdf}",
		"%{IncludeDirs.Msdf}msdfgen/",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/",
		"%{IncludeDirs.Nvidia}",
		"%{IncludeDirs.Sdl}include/",
		"%{IncludeDirs.SdlMixer}include/",
		"%{IncludeDirs.Thorvg}"
	}
	
	externalincludedirs {
		"%{IncludeDirs.MicroCore}",
		"%{IncludeDirs.MicroFramework}",
		"%{IncludeDirs.Glm}",
		"%{IncludeDirs.Libclang}",
		"%{IncludeDirs.Spdlog}include/",
		"%{IncludeDirs.Yaml}include/",
		"%{IncludeDirs.MicroOpenGL}",
		"%{IncludeDirs.Glew}include/",
		"%{IncludeDirs.Glw}",
		"%{IncludeDirs.MicroVulkan}",
		"%{IncludeDirs.Vulkan}",
		"%{IncludeDirs.Freetype}include/",
		"%{IncludeDirs.Imgui}",
		"%{IncludeDirs.Lz4}",
		"%{IncludeDirs.Msdf}",
		"%{IncludeDirs.Msdf}msdfgen/",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/",
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
		"%{IncludeDirs.MicroFramework}**.h", 
		"%{IncludeDirs.MicroFramework}**.cpp" 
	}

	--- GLOBAL LINK
	links {
		"MicroCore",
		"MicroOpenGL",
		"MicroVulkan",
		"Nsight",
		"SDL_Mixer",
		"Imgui",
		"Lz4",
		"MsdfAtlas",
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
		pchsource "../MicroFramework/__micro_framework_pch.cpp"

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
