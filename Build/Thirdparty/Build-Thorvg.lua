project "Thorvg"
	kind "StaticLib"
	language "C++"
	staticruntime "off"
	location "%{OutputDirs.Solution}"

	--- GLOBAL INCLUDES
	-- includedirs { }

	-- externalincludedirs { }

    -- files { }

	--- LINUX
	filter "system:linux"
		--- LINUX SPECIFIC DEFINES
		defines { "LINUX" }

		--- LINUX SPECIFIC SOURCE FILES
		-- files { }

	--- WINDOWS
	filter "system:Windows"
		systemversion "latest"
		system "windows"
		flags "MultiProcessorCompile"
		cdialect "C17"

		--- WINDOWS SPECIFIC DEFINES
		defines { "WINDOWS" }

		--- WINDOWS SPECIFIC SOURCE FILES
		-- files { }
