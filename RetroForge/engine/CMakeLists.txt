# List all engine source files
set(ENGINE_SOURCES
    src/Engine.cpp
    src/Camera2D.cpp
    src/Camera3D.cpp
    src/Window.cpp
)

# List all engine header files
set(ENGINE_HEADERS
    include/Engine.h
    include/Camera2D.h
    include/Camera3D.h
    include/Window.h
)

# Add library target for engine
add_library(engine STATIC ${ENGINE_SOURCES} ${ENGINE_HEADERS})

# Include directories for engine
target_include_directories(engine PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src   # Include source directory for internal headers (if needed)
    ${SDL2_INCLUDE_DIR}                # Assuming SDL2_INCLUDE_DIR is set correctly
    ${GLM_INCLUDE_DIR}                 # Assuming GLM_INCLUDE_DIR is set correctly
)

# Link libraries for engine
target_link_libraries(engine ${SDL2_LIBRARY} ${GLEW_LIBRARY} opengl32)