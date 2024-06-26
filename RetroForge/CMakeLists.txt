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
include_directories(${CMAKE_SOURCE_DIR}/third_party/include)
link_directories(${CMAKE_SOURCE_DIR}/third_party/lib)

# SDL2, GLEW, GLM paths
set(SDL2_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/third_party/include/SDL2")
set(SDL2_LIBRARY "${CMAKE_SOURCE_DIR}/third_party/lib/SDL2.lib")
set(GLEW_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/third_party/include/glew")
set(GLEW_LIBRARY "${CMAKE_SOURCE_DIR}/third_party/lib/glew32.lib")
set(GLM_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/third_party/include/glm")

# Include directories
include_directories(${SDL2_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} ${GLM_INCLUDE_DIR})

# Link libraries
link_libraries(${SDL2_LIBRARY} ${GLEW_LIBRARY} opengl32)

# Add the test executable
add_executable(test_program main.cpp)
target_link_libraries(test_program ${SDL2_LIBRARY} ${GLEW_LIBRARY} opengl32)