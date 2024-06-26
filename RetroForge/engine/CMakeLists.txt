# List all engine source files
set(ENGINE_SOURCES
    src/Camera2D.cpp
    src/Camera3D.cpp
    src/Engine.cpp
    src/Renderer.cpp
    src/Window.cpp
)

# List all engine header files
set(ENGINE_HEADERS
    include/Camera2D.h
    include/Camera3D.h
    include/Engine.h
    include/Renderer.h
    include/Window.h
)

# Add library target for engine
add_library(engine STATIC ${ENGINE_SOURCES} ${ENGINE_HEADERS})

# Include directories for engine
target_include_directories(engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${SDL2_INCLUDE_DIR}  # Assuming SDL2_INCLUDE_DIR is set correctly
    ${GLM_INCLUDE_DIR}   # Assuming GLM_INCLUDE_DIR is set correctly
)

# Link libraries for engine
target_link_libraries(engine ${SDL2_LIBRARY} opengl32)
