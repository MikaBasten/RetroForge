# Game configuration

# Add executable target for game
add_executable(RetroForge
    src/main.cpp
)

# Include directories for game (if necessary)
target_include_directories(RetroForge PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/core  # Include core directory
    ${SDL2_INCLUDE_DIR}
    ${GLM_INCLUDE_DIR}
)

# Link game executable with engine library and necessary libraries
target_link_libraries(RetroForge 
    engine                # Link with engine library
    ${SDL2_LIBRARY}       # Link with SDL2 library
    opengl32              # Link with OpenGL library
    ${GLEW_LIBRARY}       # Link with GLEW library if needed
)