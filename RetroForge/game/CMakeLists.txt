# Add executable target for game
add_executable(RetroForge
    src/main.cpp
)

# Include directories for game
target_include_directories(RetroForge PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/engine/include  
    ${SDL2_INCLUDE_DIR}  # Assuming SDL2_INCLUDE_DIR is set correctly
    ${GLM_INCLUDE_DIR}   # Assuming GLM_INCLUDE_DIR is set correctly
)

# Link game executable with engine library and necessary libraries
target_link_libraries(RetroForge 
    engine                # Link with engine library
    ${SDL2_LIBRARY}       # Link with SDL2 library
    ${SDL2MAIN_LIBRARY}   # Link with SDL2main library
    opengl32              # Link with OpenGL library
    ${GLEW_LIBRARY}       # Link with GLEW library if needed
)

# Path to SDL2.dll
set(SDL2_DLL_PATH "${CMAKE_SOURCE_DIR}/third_party/lib/SDL2.dll")
set(GLEW_DLL_PATH "${CMAKE_SOURCE_DIR}/third_party/lib/glew32.dll")

# Add a post-build step to copy SDL2.dll and glew32.dll to the output directory
add_custom_command(TARGET RetroForge POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Copying SDL2.dll and glew32.dll to $<TARGET_FILE_DIR:RetroForge>"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${SDL2_DLL_PATH}"
    $<TARGET_FILE_DIR:RetroForge>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${GLEW_DLL_PATH}"
    $<TARGET_FILE_DIR:RetroForge>
)