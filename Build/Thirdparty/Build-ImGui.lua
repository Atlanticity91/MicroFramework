project "ImGui"
	kind "StaticLib"
	language "C++"
	location "%{OutputDirs.Solution}"

	--- OUTPUT
	targetdir "%{OutputDirs.Bin}%{cfg.buildcfg}/"
	debugdir "%{OutputDirs.Bin}%{cfg.buildcfg}/"
	objdir "%{OutputDirs.BinInt}%{prj.name}-%{cfg.buildcfg}/"

	--- GLOBAL INCLUDES
	includedirs {
		"%{IncludeDirs.Imgui}",
		"%{IncludeDirs.Sdl}include/",
		"%{IncludeDirs.Vulkan}Include/"
	}

	externalincludedirs {
		"%{IncludeDirs.Imgui}",
		"%{IncludeDirs.Sdl}include/",
		"%{IncludeDirs.Vulkan}Include/"
	}

	--- GLOBAL SOURCE FILES
	files { 
		"%{IncludeDirs.Imgui}imconfig.h", 
		"%{IncludeDirs.Imgui}imgui.cpp",
		"%{IncludeDirs.Imgui}imgui.h",
		"%{IncludeDirs.Imgui}imgui_demo.cpp",
		"%{IncludeDirs.Imgui}imgui_draw.cpp",
		"%{IncludeDirs.Imgui}imgui_internal.h",
		"%{IncludeDirs.Imgui}imgui_tables.cpp",
		"%{IncludeDirs.Imgui}imgui_widgets.cpp",
		"%{IncludeDirs.Imgui}imstb_rectpack.h",
		"%{IncludeDirs.Imgui}imstb_textedit.h",
		"%{IncludeDirs.Imgui}imstb_truetype.h",
		"%{IncludeDirs.Imgui}backends/imgui_impl_sdl3.h",
		"%{IncludeDirs.Imgui}backends/imgui_impl_sdl3.cpp",
		"%{IncludeDirs.Imgui}backends/imgui_impl_opengl3.h",
		"%{IncludeDirs.Imgui}backends/imgui_impl_opengl3.cpp",
		"%{IncludeDirs.Imgui}backends/imgui_impl_vulkan.h",
		"%{IncludeDirs.Imgui}backends/imgui_impl_vulkan.cpp"
	}

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

		--- WINDOWS SPECIFIC SOURCE FILES
		files {
			"%{IncludeDirs.Imgui}backends/imgui_impl_win32.h",
			"%{IncludeDirs.Imgui}backends/imgui_impl_win32.cpp"
		}
	
	--- CONFIGURATION
	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"
		
		--- DEFINES
		defines {
			"DEBUG",
            "FT_DEBUG_LEVEL_ERROR",
            "FT_DEBUG_LEVEL_TRACE"
        }

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
