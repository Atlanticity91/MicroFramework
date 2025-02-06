project "Nsight"
	kind "StaticLib"
	language "C"
	staticruntime "off"
	location "%{OutputDirs.Solution}"

	--- GLOBAL INCLUDES
	includedirs {
		"%{IncludeDirs.Sdl}include/",
		"%{IncludeDirs.Sdl}include/build_config/",
		"%{IncludeDirs.Sdl}src/"
	}

	externalincludedirs {
		"%{IncludeDirs.Sdl}include/",
		"%{IncludeDirs.Sdl}include/build_config/",
		"%{IncludeDirs.Sdl}src/"
	}

	--- LINUX
	filter "system:linux"
		--- LINUX SPECIFIC DEFINES
		defines { "LINUX" }

		--- LINUX SPECIFIC SOURCE FILES
		files {
			"%{IncludeDirs.Nvidia}nsight/linux/GFSDK_Aftermath.h",
			"%{IncludeDirs.Nvidia}nsight/linux/GFSDK_Aftermath_Defines.h",
			"%{IncludeDirs.Nvidia}nsight/linux/GFSDK_Aftermath_GpuCrashDump.h",
			"%{IncludeDirs.Nvidia}nsight/linux/GFSDK_Aftermath_GpuCrashDumpDecoding.h"
		}

		--- LINUX SPECIFIC PRE-BUILD COMMAND
		prebuildmessage "Copy Nsight"
		prebuildcommands { 
			"{COPYFILE} %{IncludeDirs.Nvidia}nsight/linux/libGFSDK_Aftermath_Lib.x64.so %{OutputDirs.Bin}%{cfg.buildcfg}/" 
		}

	--- WINDOWS
	filter "system:Windows"
		systemversion "latest"
		system "windows"
		flags "MultiProcessorCompile"
		cdialect "C17"

		--- WINDOWS SPECIFIC DEFINES
		defines { "WINDOWS" }

		--- WINDOWS SPECIFIC SOURCE FILES
		files {
			"%{IncludeDirs.Nvidia}nsight/windows/GFSDK_Aftermath.h",
			"%{IncludeDirs.Nvidia}nsight/windows/GFSDK_Aftermath_Defines.h",
			"%{IncludeDirs.Nvidia}nsight/windows/GFSDK_Aftermath_GpuCrashDump.h",
			"%{IncludeDirs.Nvidia}nsight/windows/GFSDK_Aftermath_GpuCrashDumpDecoding.h"
		}

		--- WINDOWS SPECIFIC PREBUILD COMMAND
		prebuildmessage "Copy Nsight"
		prebuildcommands {
			"{COPYFILE} %{IncludeDirs.Nvidia}nsight/windows/GFSDK_Aftermath_Lib.x64.lib %{OutputDirs.Bin}%{cfg.buildcfg}/",
			"{COPYFILE} %{IncludeDirs.Nvidia}nsight/windows/GFSDK_Aftermath_Lib.x64.dll %{OutputDirs.Bin}%{cfg.buildcfg}/"
		}
