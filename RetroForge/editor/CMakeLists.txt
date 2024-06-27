# Editor configuration

# Add executable target for editor
add_executable(Editor
    src/Editor.cpp
)

# Include directories for editor
target_include_directories(Editor PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include   # Include directory for editor headers
    ${CMAKE_SOURCE_DIR}/engine/include    # Include directory for engine headers
    ${SDL2_INCLUDE_DIR}                   # Assuming SDL2_INCLUDE_DIR is set correctly
    ${GLM_INCLUDE_DIR}                    # Assuming GLM_INCLUDE_DIR is set correctly
)

# Link editor executable with engine library and necessary libraries
target_link_libraries(Editor 
    engine                # Link with engine library
    ${SDL2_LIBRARY}       # Link with SDL2 library
    opengl32              # Link with OpenGL library
    ${GLEW_LIBRARY}       # Link with GLEW library if needed
)
