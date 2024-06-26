# Game configuration

# Add executable target for game
add_executable(RetroForge
    src/main.cpp
)

# Include directories for game (if necessary)
target_include_directories(RetroForge PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${SDL2_INCLUDE_DIR}  # Assuming SDL2_INCLUDE_DIR is set correctly
    ${GLM_INCLUDE_DIR}   # Assuming GLM_INCLUDE_DIR is set correctly
)

# Link game executable with engine library
target_link_libraries(RetroForge engine ${SDL2_LIBRARY} opengl32)
