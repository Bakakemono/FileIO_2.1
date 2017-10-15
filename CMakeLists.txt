cmake_minimum_required(VERSION 3.9)
project(FileIO_2.1)

file(GLOB_RECURSE FileIO_2.1_SRC src/*.cpp include/*.h)

include_directories(include/)

add_executable(FileIO_2.1 ${FileIO_2.1_SRC})
set(EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/externals)

#SFML
set(SFML_DIR ${EXTERNAL_DIR}/SFML)
set(SFML_BUILD_EXAMPLES FALSE)
add_subdirectory(${SFML_DIR})
include_directories(${SFML_DIR}/include)

LIST(APPEND FileIO_2.1_LIBRARIES
	sfml-system
	sfml-window
	sfml-graphics
	sfml-audio
	sfml-network)
	
target_link_libraries(FileIO_2.1 ${FileIO_2.1_LIBRARIES})
	