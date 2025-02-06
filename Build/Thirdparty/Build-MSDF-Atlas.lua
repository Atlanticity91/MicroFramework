project "Msdf-Atlas"
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
		"%{IncludeDirs.Msdf}msdf-atlas-gen/",
		"%{IncludeDirs.Msdf}msdfgen/"
	}

	externalincludedirs {
		"%{IncludeDirs.Msdf}msdf-atlas-gen/",
		"%{IncludeDirs.Msdf}msdfgen/"
	}

	--- GLOBAL SOURCE FILES
	files { 
		"%{IncludeDirs.Msdf}msdf-atlas-gen/AtlasGenerator.h",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/AtlasStorage.h",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/BitmapAtlasStorage.h",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/BitmapAtlasStorage.hpp",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/Charset.h",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/DynamicAtlas.h",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/DynamicAtlas.hpp",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/FontGeometry.h",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/GlyphBox.h",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/GlyphGeometry.h",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/ImmediateAtlasGenerator.h",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/ImmediateAtlasGenerator.hpp",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/Rectangle.h",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/RectanglePacker.h",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/Remap.h",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/TightAtlasPacker.h",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/Workload.h",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/bitmap-blit.h",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/csv-export.h",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/glyph-generators.h",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/image-encode.h",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/image-save.h",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/image-save.hpp",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/json-export.h",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/%{IncludeDirs.Msdf}msdf-atlas-gen.h",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/rectangle-packing.h",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/rectangle-packing.hpp",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/shadron-preview-generator.h",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/size-selectors.h",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/types.h",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/utf8.h",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/Charset.cpp",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/FontGeometry.cpp",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/GlyphGeometry.cpp",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/RectanglePacker.cpp",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/TightAtlasPacker.cpp",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/Workload.cpp",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/bitmap-blit.cpp",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/charset-parser.cpp",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/csv-export.cpp",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/glyph-generators.cpp",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/image-encode.cpp",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/json-export.cpp",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/main.cpp",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/shadron-preview-generator.cpp",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/size-selectors.cpp",
		"%{IncludeDirs.Msdf}msdf-atlas-gen/utf8.cpp"
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
