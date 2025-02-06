# MicroFramework
---
This repository contains the code for the Micro Framework Library, this project defined [SDL](https://www.libsdl.org/) wrapper, code for graphics, audio, input and time management, 
some basic importer for image, geometry, sounds and musics but also font with [Msdf](https://github.com/Chlumsky/msdfgen) library. This repository also give [ImGui](https://github.com/ocornut/imgui) wrapper pre-initialized with OpenGL or Vulkan 
for debugging or in application edit UI.

> [!CAUTION]
> Current repository documentation is not updated with actual code version.

# Cloning
> [!WARNING]
> This repository use submodules for Thirdparty. Make sure to setup submodules before any action. 

Using [git-cli](https://git-scm.com/) :

```
git clone --recursive https://github.com/Atlanticity91/MicroFramework.git
```

Existing repositories submodules can be updated manually :

```
git submodule init
git submodule update
```

# Build System
MicroFramework as part of the Micro project use the [Premake5](https://github.com/premake/premake-core) build system. [Premake5](https://github.com/premake/premake-core) instance is present in this repository under Build/[Premake5](https://github.com/premake/premake-core).

Build files for [Premake5](https://github.com/premake/premake-core) are inside Build folder under :

| File 									  	 	| Usage 								 					     					   |
| --------------------------------------------- | ------------------------------------------------------------------------------------ |
| `Build/Build.lua` 					  	 	| Define global solution. 		 					     					   		   |
| `Build/Build-Dependencies.lua` 		  	 	| Define dependencies solution.  	 					 						   	   |
| `Build/Build-MicroFramework.lua` 			 	| Define MicroFramework solution. 							 				   		   |
| `Build/Thirdparty/Build-Freetype.lua` 	 	| Define [Freetype](https://freetype.org/) thirdparty solution. 				 	   |
| `Build/Thirdparty/Build-Header-Nsight.lua` 	| Define [Nsight](https://developer.nvidia.com/nsight-systems) thirdparty solution.	   |
| `Build/Thirdparty/Build-Header-RenderDoc.lua` | Define [RenderDoc](https://renderdoc.org/) thirdparty solution. 					   |
| `Build/Thirdparty/Build-Lz4.lua`   			| Define [Lz4](https://github.com/lz4/lz4) thirdparty solution. 					   |
| `Build/Thirdparty/Build-MSDF.lua`  	 		| Define [Msdf](https://github.com/Chlumsky/msdfgen) thirdparty solution. 			   |
| `Build/Thirdparty/Build-MSDF-Atlas.lua`  		| Define [Msdf-Atlas](https://github.com/Chlumsky/msdf-atlas-gen) thirdparty solution. |
| `Build/Thirdparty/Build-SDL.lua`  	 		| Define [SDL](https://www.libsdl.org/) thirdparty solution. 						   |
| `Build/Thirdparty/Build-Thorvg.lua`  	 		| Define [Thorvg](https://www.thorvg.org/) thirdparty solution. 					   |

## Windows
For Windows build you need at least visual studio 2022 community edition or visual studio C++.

To build the project files simply run Setup-Windows.bat

## Linux
> [!CAUTION]
> Linux isn't implemented yet.

To build the project files simply run Setup-Linux.sh

## Macos
> [!CAUTION]
> Macos isn't implemented yet.

To build the project files simply run Setup-Macos.sh

# Documentation
Documentation for the library can be found under [Documentation/index.html](https://atlanticity91.github.io/MicroFramework/)
