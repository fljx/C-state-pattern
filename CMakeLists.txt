cmake_minimum_required(VERSION 3.1.0)

## ==== -------- Project -------- ==== ##

# Lazy set project name based on directory name.
get_filename_component( PRJ ${CMAKE_CURRENT_SOURCE_DIR} NAME )
string( REPLACE " " "_" PRJ ${PRJ} )
project( ${PRJ} )

## ==== -------- Tune CMake -------- ==== ##

#set (CMAKE_C_STANDARD 99)
set( CMAKE_BUILD_DIR ${PROJECT_SOURCE_DIR}/build )
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/" )
set( CMAKE_INCLUDE_CURRENT_DIR ON ) 	# Find includes in corresponding build directories
set( CMAKE_BUILD_TYPE Debug )

# Relative file name.
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D__FILENAME__='\"$(subst ${CMAKE_SOURCE_DIR}/,,$(abspath \$<))\"'" )

## ==== -------- Libraries -------- ==== ##
## ==== -------- Sources -------- ==== ##

# Lazy adding sources in this draft project.
file( GLOB_RECURSE prj_SRC "src/*.c" "include/*.h" )

include_directories( include )

## ==== -------- Output -------- ==== ##

add_executable( ${PRJ} ${prj_SRC} )
target_link_libraries( ${PRJ} )

# Install the executable and libraries.
install( TARGETS ${PRJ} DESTINATION ${CMAKE_INSTALL_PREFIX}/bin )

## ======================================
