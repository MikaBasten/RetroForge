cmake_minimum_required(VERSION 3.10)

project(RetroForge)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add engine, game, and editor subdirectories
add_subdirectory(engine)
add_subdirectory(game)
add_subdirectory(editor)

# Third party includes and libraries
include_directories(third_party/include)
link_directories(third_party/lib)

# SDL2 and OpenGL libraries
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS})
