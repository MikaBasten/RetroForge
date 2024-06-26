# Editor configuration

# Add executable target for editor
add_executable(Editor
    src/Editor.cpp
)

# Include directories for editor (if necessary)
target_include_directories(Editor PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${SDL2_INCLUDE_DIR}  # Assuming SDL2_INCLUDE_DIR is set correctly
    ${GLM_INCLUDE_DIR}   # Assuming GLM_INCLUDE_DIR is set correctly
)

# Link editor executable with engine library
target_link_libraries(Editor engine ${SDL2_LIBRARY} opengl32)
