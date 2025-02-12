--- OPTIONS
--[[
	@brief Create an option for Vulkan SDK version specification.

	@note trigger using --vk_version=value
	@param value query vulkan sdk version ( default value : 1.3.296.0 ).
]]--
newoption {
	trigger = 'vk_version',
	value = '1.3.296.0',
	description = 'Set query minimal Vulkan SDK version'
}

--- ENVIRONEMENT VARIABLES
vulkan = os.getenv( 'VULKAN_PATH' )
render_doc = os.getenv( 'RENDERDOC_PATH' )
visual_studio = os.getenv( 'VS_PATH' )

--- OUTPUT DIRS
OutputDirs = { }

OutputDirs[ 'Solution' ] = '%{wks.location}/Solution/'
OutputDirs[ 'Bin' ] = '%{wks.location}/bin/'
OutputDirs[ 'BinInt' ] = '%{wks.location}/bin-int/'

--- INCLUDE DIRS
IncludeDirs = { }

IncludeDirs[ 'MicroFramework' ] = '%{wks.location}/MicroFramework/'

--- MICRO CORE PROJECTS
IncludeDirs[ 'MicroCore' ] = '%{wks.location}/Thirdparty/MicroCore/MicroCore/'
IncludeDirs[ 'Glm' ] = '%{wks.location}/Thirdparty/MicroCore/Thirdparty/glm/'
IncludeDirs[ 'Libclang' ] = '%{wks.location}/Thirdparty/MicroCore/Thirdparty/libclang/'
IncludeDirs[ 'Spdlog' ] = '%{wks.location}/Thirdparty/MicroCore/Thirdparty/spdlog/'
IncludeDirs[ 'Yaml' ] = '%{wks.location}/Thirdparty/MicroCore/Thirdparty/yaml-cpp/'

--- MICRO OPENGL PROJECTS
IncludeDirs[ 'MicroOpenGL'] = '%{wks.location}/Thirdparty/MicroOpenGL/MicroOpenGL/'
IncludeDirs[ 'Glew'] = '%{wks.location}/Thirdparty/MicroOpenGL/Thirdparty/GLW/Thirdparty/GLEW/'
IncludeDirs[ 'Glw'] = '%{wks.location}/Thirdparty/MicroOpenGL/Thirdparty/GLW/'

--- MICRO VULKAN PROJECTS
IncludeDirs[ 'MicroVulkan'] = '%{wks.location}/Thirdparty/MicroVulkan/MicroVulkan/'
IncludeDirs[ 'Vulkan' ] = ( vulkan..'/'.._OPTIONS[ 'vk_version' ]..'/Include/' )

--- THIRDPARTY PROJECTS
IncludeDirs[ 'Nvidia' ] = '%{wks.location}Thirdparty/Nvidia/'
IncludeDirs[ 'Amd' ] = '%{wks.location}Thirdparty/Amd/'
IncludeDirs[ 'Freetype' ] = '%{wks.location}/Thirdparty/Freetype/'
IncludeDirs[ 'Msdf' ] = '%{wks.location}/Thirdparty/Msdf/'
IncludeDirs[ 'Sdl' ] = '%{wks.location}/Thirdparty/Sdl/'
IncludeDirs[ 'SdlMixer' ] = '%{wks.location}/Thirdparty/SdlMixer/'
IncludeDirs[ 'Thorvg' ] = '%{wks.location}/Thirdparty/Thorvg/'
IncludeDirs[ 'Imgui' ] = '%{wks.location}/Thirdparty/Imgui/'
IncludeDirs[ 'Lz4' ] = '%{wks.location}/Thirdparty/Lz4/'

if render_doc ~= nil then
	IncludeDirs[ 'RenderDoc' ] = ( render_doc..'/'  )
end
