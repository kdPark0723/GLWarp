# CMake entry point
cmake_minimum_required (VERSION 3.0)
project (GLWarper)

set(OpenGL_GL_PREFERENCE GLVND)

find_package(OpenGL REQUIRED)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
	message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like bin_Visual2012_64bits/)" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()



# Compile external dependencies
add_subdirectory (external)

if(INCLUDE_DISTRIB)
	add_subdirectory(distrib)
endif(INCLUDE_DISTRIB)



include_directories(
	include
	.
)

set(GL_WARP_SOURSE
    src/Initializer.cpp
	src/Shader-inc.h
	src/Program-inc.h
	src/ErrorHandel-inc.h
	src/Renderer.cpp
	src/Window.cpp
	src/VertexArray-inc.h
	src/Buffer-inc.h
	src/Point-inc.h)

set(GL_WARP_HEADERS
	include/ErrorHandel.h
	include/Initializer.h
	include/Window.h
	include/Renderer.h
	include/Shader.h
	include/FragmentShader.h
	include/VertexShader.h
	include/Program.h
	include/VertexArray.h
	include/InternalGraphicLib.h
	include/Buffer.h
	include/Point.h
	include/ColorBuffer.h)

add_library(GL_WARP STATIC
	${GL_WARP_SOURSE}
	${GL_WARP_HEADERS}
	)

target_link_libraries(GL_WARP
	${OPENGL_LIBRARY}
	glfw
	gl3w
	)

set(ALL_LIBS
	GL_WARP
	)

add_definitions(
	-D_CRT_SECURE_NO_WARNINGS
)

# Tutorial 1
add_executable(tutorial01_first_window
	tutorial01_first_window/tutorial01.cpp
	)
target_link_libraries(tutorial01_first_window
	${ALL_LIBS}
	)

# Tutorial 2
add_executable(tutorial02_fill_window_red
	tutorial02_fill_window_red/tutorial02.cpp
	tutorial02_fill_window_red/Renderer.h tutorial02_fill_window_red/Renderer.cpp
	)
target_link_libraries(tutorial02_fill_window_red
	${ALL_LIBS}
	)

# Tutorial 3
add_executable(tutorial03_fill_window_raindow
	tutorial03_fill_window_raindow/tutorial03.cpp
	tutorial03_fill_window_raindow/Renderer.h tutorial03_fill_window_raindow/Renderer.cpp
	)
target_link_libraries(tutorial03_fill_window_raindow
	${ALL_LIBS}
	)

# Tutorial 4
add_executable(tutorial04_draw_dot
	tutorial04_draw_dot/tutorial04.cpp
	tutorial04_draw_dot/Renderer.h tutorial04_draw_dot/Renderer.cpp
	)
target_link_libraries(tutorial04_draw_dot
	${ALL_LIBS}
	)

# Tutorial 5
add_executable(tutorial05_draw_triangle
	tutorial05_draw_triangle/tutorial05.cpp
	tutorial05_draw_triangle/Renderer.h tutorial05_draw_triangle/Renderer.cpp
	)
target_link_libraries(tutorial05_draw_triangle
	${ALL_LIBS}
	)

# Xcode and Visual working directories
set_target_properties(tutorial01_first_window PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tutorial01_first_window/")
# create_target_launcher(tutorial01_first_window WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/tutorial01_first_window/")

set_target_properties(tutorial02_fill_window_red PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tutorial02_fill_window_red/")
# create_target_launcher(tutorial01_first_window WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/tutorial01_first_window/")

set_target_properties(tutorial03_fill_window_raindow PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tutorial03_fill_window_raindow/")
# create_target_launcher(tutorial01_first_window WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/tutorial01_first_window/")

set_target_properties(tutorial04_draw_dot PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tutorial04_draw_dot/")
# create_target_launcher(tutorial01_first_window WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/tutorial01_first_window/")

set_target_properties(tutorial05_draw_triangle PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tutorial05_draw_triangle")
# create_target_launcher(tutorial01_first_window WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/tutorial01_first_window/")








SOURCE_GROUP(common REGULAR_EXPRESSION ".*/common/.*" )
SOURCE_GROUP(shaders REGULAR_EXPRESSION ".*/.*shader$" )

#
if (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )
#add_custom_command(
#   TARGET tutorial01_first_window POST_BUILD
#   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/tutorial01_first_window${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/tutorial01_first_window/"
#)
#add_custom_command(
#	TARGET tutorial02_fill_window_red POST_BUILD
#	COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/tutorial02_fill_window_red${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/tutorial02_fill_window_red/"
#)
#add_custom_command(
#	TARGET tutorial03_fill_window_raindow POST_BUILD
#	COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/tutorial03_fill_window_raindow${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/tutorial03_fill_window_raindow/"
#)
#add_custom_command(
#	TARGET tutorial04_draw_dot POST_BUILD
#	COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/tutorial04_draw_dot${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/tutorial04_draw_dot/"
#)

elseif (${CMAKE_GENERATOR} MATCHES "Xcode" )

endif (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )

