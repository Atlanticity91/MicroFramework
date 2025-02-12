--- TOOL INCLUDES
include "Premake/CSExtensions.lua"
include "Premake/VSExtensions.lua"
include "Build-Dependencies.lua"

--- PROJECT CONFIGURATION
workspace "Micro Solution"
    startproject "MicroFramework"
    defaultplatform "x64_nvidia"
    location "../"
    configurations { 
        "Debug", 
        "Release", 
        "Dist" 
    }
    platforms {
        "x64_nvidia",
        "x64_amd"
    }

    --- GLOBAL DEFINES
    defines { 
        "IMGUI_DEFINE_MATH_OPERATORS",
        "MICRO_USE_CORE"
    }

    includedirs { 
        "%{wks.location}/Thirdparty/MicroCore/",
        "%{IncludeDirs.Glm}",
        "%{IncludeDirs.Libclang}",
        "%{IncludeDirs.Spdlog}include/",
        "%{IncludeDirs.Yaml}include/"
    }

    externalincludedirs {
        "%{wks.location}/Thirdparty/MicroCore/",
        "%{IncludeDirs.Glm}",
        "%{IncludeDirs.Libclang}",
        "%{IncludeDirs.Spdlog}include/",
        "%{IncludeDirs.Yaml}include/"
    }

    --- NVIDIA 
    filter "platforms:x64_nvidia"
        architecture "x64"

        --- GLOBAL DEFINES
        defines { "MICRO_USE_NVIDIA" }

    --- AMD
    filter "platforms:x64_amd"
        architecture "x64"

        --- GLOBAL DEFINES
        defines { "MICRO_USE_AMD" }

    --- WINDOWS
    filter "system:windows"
        --- GLOBAL FLAGS
        flags "MultiProcessorCompile"
        
        --- WORKSPACE-WIDE BUILD OPTIONS FOR MSVC
        buildoptions { 
            "/EHsc",
            "/Zc:preprocessor", 
            "/Zc:__cplusplus" 
        }

    --- MICRO PROJECTS
    group "Micro"
        include "../Thirdparty/MicroCore/Build/Build-MicroCore.lua"
        include "../Thirdparty/MicroOpenGL/Build/Build-MicroOpenGL.lua"
        include "../Thirdparty/MicroVulkan/Build/Build-MicroVulkan.lua"
    --- MICRO CORE PROJECTS
    group "Thirdparty/MicroCore"
        include "../Thirdparty/MicroCore/Build/Thirdparty/Build-Header-Glm.lua"
        include "../Thirdparty/MicroCore/Build/Thirdparty/Build-Header-Libclang.lua"
        include "../Thirdparty/MicroCore/Build/Thirdparty/Build-Header-Spdlog.lua"
        include "../Thirdparty/MicroCore/Build/Thirdparty/Build-Yaml.lua"
    --- MICRO OPENGL PROJECTS
    group "Thirdparty/MicroOpenGL"
        include "../Thirdparty/MicroOpenGL/Thirdparty/GLW/Build/Thirdparty/Build-GLEW.lua"
        include "../Thirdparty/MicroOpenGL/Thirdparty/GLW/Build/Build-GLW.lua"
    --- MICRO VULKAN PROJECTS
    group "Thirdparty/MicroVulkan"
        include "../Thirdparty/MicroVulkan/Build/Thirdparty/Build-Header-Shaderc.lua"
        include "../Thirdparty/MicroVulkan/Build/Thirdparty/Build-Header-Spirv.lua"
        include "../Thirdparty/MicroVulkan/Build/Thirdparty/Build-Header-Vulkan.lua"
    --- THIRDPARTY PROJECTS
    group "Thirdparty"
        include "Thirdparty/Build-Freetype.lua"
        include "Thirdparty/Build-Header-Nsight.lua"
        include "Thirdparty/Build-Imgui.lua"
        include "Thirdparty/Build-Lz4.lua"
        include "Thirdparty/Build-Msdf.lua"
        include "Thirdparty/Build-Msdf-Atlas.lua"
        include "Thirdparty/Build-SDL.lua"
        include "Thirdparty/Build-SDL_Mixer.lua"
        include "Thirdparty/Build-Thorvg.lua"

        if render_doc ~= nil then 
            include "Thirdparty/Build-Header-RenderDoc.lua"
        end
    --- TEST PROJECTS
    group "Test"
        include "Test/Build-Test-SDL.lua"
    group ""

    --- MAIN PROJECT
    include "Build-MicroFramework.lua"
