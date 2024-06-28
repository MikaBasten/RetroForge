cmake_minimum_required(VERSION 3.10)
project(RetroForge)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Third-party includes and libraries
include_directories(${CMAKE_SOURCE_DIR}/third_party/include)
link_directories(${CMAKE_SOURCE_DIR}/third_party/lib)


# GLEW, GLM paths
set(GLEW_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/third_party/include/glew")
set(GLEW_LIBRARY "${CMAKE_SOURCE_DIR}/third_party/lib/glew32.lib")
set(GLM_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/third_party/include/glm")
set(SDL2_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/third_party/include/SDL2")
set(SDL2_LIBRARY "${CMAKE_SOURCE_DIR}/third_party/lib/SDL2.lib")
set(SDL2MAIN_LIBRARY "${CMAKE_SOURCE_DIR}/third_party/lib/SDL2main.lib")

# Include directories
include_directories(${SDL2_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} ${GLM_INCLUDE_DIR})

# Link libraries
link_libraries(${SDL2_LIBRARY} ${SDL2MAIN_LIBRARY} ${GLEW_LIBRARY} opengl32)

# Add engine, game, and editor subdirectories
add_subdirectory(engine)
add_subdirectory(editor)
add_subdirectory(game)

