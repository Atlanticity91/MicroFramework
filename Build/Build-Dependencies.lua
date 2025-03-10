--- OPTIONS
--[[
	@brief Create an option for Vulkan SDK version specification.

	@note trigger using --vk_version=value
	@param value query vulkan sdk version ( default value : 1.3.296.0 ).
]]--
newoption {
	trigger = 'vk_version',
	value = '1.4.304.1',
	description = 'Set query minimal Vulkan SDK version'
}

--- ENVIRONEMENT VARIABLES
vulkan = os.getenv( 'VULKAN_PATH' )
render_doc = os.getenv( 'RENDERDOC_PATH' )
visual_studio = os.getenv( 'VS_PATH' )

--- OUTPUT DIRS
OutputDirs = { }

OutputDirs[ 'Solution' ] = '%{wks.location}Solution/'
OutputDirs[ 'Bin' ] = '%{wks.location}bin/'
OutputDirs[ 'BinInt' ] = '%{wks.location}bin-int/'

--- INCLUDE DIRS
IncludeDirs = { }

--- MICRO FRAMEWORK PROJECTS
local thirdparty = '%{wks.location}Thirdparty/'
IncludeDirs[ 'MicroFramework' ] = '%{wks.location}MicroFramework/'
IncludeDirs[ 'Nvidia' ] = ( thirdparty..'Nvidia/' )
IncludeDirs[ 'Amd' ] = ( thirdparty..'Amd/' )
IncludeDirs[ 'Freetype' ] = ( thirdparty..'Freetype/' )
IncludeDirs[ 'Msdf' ] = ( thirdparty..'Msdf/' )
IncludeDirs[ 'Sdl' ] = ( thirdparty..'Sdl/' )
IncludeDirs[ 'SdlMixer' ] = ( thirdparty..'SdlMixer/' )
IncludeDirs[ 'Thorvg' ] = ( thirdparty..'Thorvg/' )
IncludeDirs[ 'Imgui' ] = ( thirdparty..'Imgui/' )
IncludeDirs[ 'Lz4' ] = ( thirdparty..'Lz4/' )

if render_doc ~= nil then
	IncludeDirs[ 'RenderDoc' ] = ( render_doc..'/'  )
end

--- MICRO CORE PROJECTS
local core_path = '%{wks.location}/Thirdparty/MicroCore/'
IncludeDirs[ 'MicroCore' ] = ( core_path..'MicroCore/' )
IncludeDirs[ 'Glm' ] = ( core_path..'Thirdparty/glm/' )
IncludeDirs[ 'Libclang' ] = ( core_path..'Thirdparty/libclang/' )
IncludeDirs[ 'Spdlog' ] = ( core_path..'Thirdparty/spdlog/' )
IncludeDirs[ 'Yaml' ] = ( core_path..'Thirdparty/yaml-cpp/' )

--- MICRO OPENGL PROJECTS
local opengl_path = '%{wks.location}/Thirdparty/MicroOpenGL/'
IncludeDirs[ 'MicroOpenGL'] = ( opengl_path..'MicroOpenGL/' )
IncludeDirs[ 'Glew'] = ( opengl_path..'Thirdparty/GLW/Thirdparty/GLEW/' )
IncludeDirs[ 'Glw'] = ( opengl_path..'Thirdparty/GLW/' )

--- MICRO VULKAN PROJECTS
IncludeDirs[ 'MicroVulkan'] = ( thirdparty..'MicroVulkan/MicroVulkan/' )
IncludeDirs[ 'Vulkan' ] = ( vulkan..'/'.._OPTIONS[ 'vk_version' ]..'/' )
