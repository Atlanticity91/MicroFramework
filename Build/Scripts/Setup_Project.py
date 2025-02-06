#!/usr/bin/env python

# --- INCLUDES
import os
import platform
import subprocess
import shutil
import sys

# --- REQUIREMENTS
sys.path.append( 'Thirdparty/MicroVulkan/Build/Scripts/' )

from Setup_VulkanSDK import VulkanRequirements

# --- GLOBALS
FILE_EXT = [
	'.sln',
	'.vcxproj',
	'.filters',
	'.user',
]

FOLDERS = [
	'bin',
	'bin-int',
	'Solution',
	'.vs'
]

# --- FUNCTIONS
def try_validate_renderdoc( ) :
	render_doc_path = os.environ.get( 'RENDERDOC_PATH' )

	if not render_doc_path :
		print( '> Please install Render doc and define \'RENDERDOC_PATH\' as environement variable.' )
	else :
		print( f'> Render Doc path : {render_doc_path}')

'''
	clear_paths method
	@note : Delete output folders and solution files to regenerated clean solution.
'''
def clear_paths( ) :
	print( '\n> Clearing output folders :' )

	for path in os.listdir( '.' ) :
		if path in FOLDERS :
			print( f'> Deleted Folder : {path}' )

			shutil.rmtree( path )
		elif os.path.splitext( path )[ -1 ].lower( ) in FILE_EXT :
			print( f'> Deleted File : {path}' )

			os.remove( path )

'''
	call_premake method
	@note : Call premake for solution file generation.
'''
def call_premake( ) :
	print( '\n> Calling Premake5 :')

	premake_call = [ 
		'--file=Build\\Build.lua', 
		f'--vk_version={VulkanRequirements.SDK_Version}' 
	] + sys.argv[ 1: ]

	if platform.system( ) == 'Windows' :
		premake_call.insert( 0, 'Build\\Premake\\Windows\\premake5.exe' )
	elif platform.system( ) == 'Linux' :
		premake_call.insert( 0, 'Build\\Premake\\Linux\\premake5' )

	subprocess.call( premake_call )

# --- MAIN LOGIC
if __name__ == "__main__" :
	print( '=== Setup Micro ===' )

	VulkanRequirements.TryValidate( )

	try_validate_renderdoc( )

	clear_paths( )
	call_premake( )
