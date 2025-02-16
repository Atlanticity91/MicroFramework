project "RenderDoc"
	kind "Utility"
	language "C"
	staticruntime "off"
	location "%{OutputDirs.Solution}"

	--- GLOBAL INCLUDES
	includedirs { "%{IncludeDirs.RenderDoc}" }

	externalincludedirs { "%{IncludeDirs.RenderDoc}" }

	--- GLOBAL SOURCE FILES
	files { "%{IncludeDirs.RenderDoc}renderdoc_app.h" }

	--- LINUX
	filter "system:linux"
		--- LINUX SPECIFIC DEFINES
		defines { "LINUX" }

	--- WINDOWS
	filter "system:Windows"
		systemversion "latest"
		system "windows"
		flags "MultiProcessorCompile"
		cdialect "C17"

		--- WINDOWS SPECIFIC DEFINES
		defines { "WINDOWS" }
