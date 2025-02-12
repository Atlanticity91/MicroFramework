project "Freetype"
	kind "StaticLib"
	language "C"
	location "%{OutputDirs.Solution}"

	--- OUTPUT
	targetdir "%{OutputDirs.Bin}/%{cfg.buildcfg}/"
	debugdir "%{OutputDirs.Bin}/%{cfg.buildcfg}/"
	objdir "%{OutputDirs.BinInt}/%{prj.name}-%{cfg.buildcfg}"

	--- GLOBAL INCLUDES
	includedirs {
		"%{IncludeDirs.Freetype}/include/",
		"%{IncludeDirs.Freetype}/subprojects/dlg/include/"
	}

	externalincludedirs {
		"%{IncludeDirs.Freetype}/include/",
		"%{IncludeDirs.Freetype}/subprojects/dlg/include/"
	}

	--- GLOBAL DEFINES
	defines {
		"FT2_BUILD_LIBRARY",
		"DLG_STATIC" 
	}
	
	--- GLOBAL SOURCE FILES
	files {
		"%{IncludeDirs.Freetype}/include/**.h",
		"%{IncludeDirs.Freetype}/src/autofit/autofit.c",
        "%{IncludeDirs.Freetype}/src/base/ftbase.c",
        "%{IncludeDirs.Freetype}/src/base/ftbbox.c",
        "%{IncludeDirs.Freetype}/src/base/ftbdf.c",
        "%{IncludeDirs.Freetype}/src/base/ftbitmap.c",
        "%{IncludeDirs.Freetype}/src/base/ftcid.c",
        "%{IncludeDirs.Freetype}/src/base/ftfstype.c",
        "%{IncludeDirs.Freetype}/src/base/ftgasp.c",
        "%{IncludeDirs.Freetype}/src/base/ftglyph.c",
        "%{IncludeDirs.Freetype}/src/base/ftgxval.c",
        "%{IncludeDirs.Freetype}/src/base/ftinit.c",
        "%{IncludeDirs.Freetype}/src/base/ftmm.c",
        "%{IncludeDirs.Freetype}/src/base/ftotval.c",
        "%{IncludeDirs.Freetype}/src/base/ftpatent.c",
        "%{IncludeDirs.Freetype}/src/base/ftpfr.c",
        "%{IncludeDirs.Freetype}/src/base/ftstroke.c",
        "%{IncludeDirs.Freetype}/src/base/ftsynth.c",
        "%{IncludeDirs.Freetype}/src/base/fttype1.c",
        "%{IncludeDirs.Freetype}/src/base/ftwinfnt.c",
        "%{IncludeDirs.Freetype}/src/bdf/bdf.c",
        "%{IncludeDirs.Freetype}/src/cache/ftcache.c",
        "%{IncludeDirs.Freetype}/src/cff/cff.c",
        "%{IncludeDirs.Freetype}/src/cid/type1cid.c",
        "%{IncludeDirs.Freetype}/src/dlg/dlgwrap.c",
        "%{IncludeDirs.Freetype}/src/gzip/ftgzip.c",
        "%{IncludeDirs.Freetype}/src/lzw/ftlzw.c",
        "%{IncludeDirs.Freetype}/src/pcf/pcf.c",
        "%{IncludeDirs.Freetype}/src/pfr/pfr.c",
        "%{IncludeDirs.Freetype}/src/psaux/psaux.c",
        "%{IncludeDirs.Freetype}/src/pshinter/pshinter.c",
        "%{IncludeDirs.Freetype}/src/psnames/psmodule.c",
        "%{IncludeDirs.Freetype}/src/raster/raster.c",
        "%{IncludeDirs.Freetype}/src/sfnt/sfnt.c",
        "%{IncludeDirs.Freetype}/src/smooth/smooth.c",
        "%{IncludeDirs.Freetype}/src/sdf/sdf.c",
        "%{IncludeDirs.Freetype}/src/svg/svg.c",
        "%{IncludeDirs.Freetype}/src/truetype/truetype.c",
        "%{IncludeDirs.Freetype}/src/type1/type1.c",
        "%{IncludeDirs.Freetype}/src/type42/type42.c",
		"%{IncludeDirs.Freetype}/subprojects/dlg/include/dlg/output.h",
		"%{IncludeDirs.Freetype}/subprojects/dlg/include/dlg/dlg.h",
		"%{IncludeDirs.Freetype}/subprojects/dlg/src/dlg/dlg.c"
	}

	--- LINUX
	filter "system:linux"
		defines { "LINUX" }

	--- WINDOWS
	filter "system:windows"
		cdialect "C17"
		flags "MultiProcessorCompile"

		--- WINDOWS SPECIFIC DEFINES
		defines { 
			"WINDOWS", 
			"_LIB",
			"_CRT_SECURE_NO_WARNINGS",
			"_CRT_NONSTDC_NO_WARNINGS",
            "DLL_EXPORT"
		}

		--- WINDOWS SPECIFIC SOURCE FILES
		files {
			"%{IncludeDirs.Freetype}/src/base/ftver.rc",
			"%{IncludeDirs.Freetype}/src/winfonts/winfnt.c",
			"%{IncludeDirs.Freetype}/builds/windows/ftdebug.c",
			"%{IncludeDirs.Freetype}/builds/windows/ftsystem.c"
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
