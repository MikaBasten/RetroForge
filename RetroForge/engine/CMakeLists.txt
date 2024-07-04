# List all engine source files
set(ENGINE_SOURCES
    src/core/Engine.cpp
    src/rendering/Shader.cpp
    src/rendering/Renderable.cpp
    src/rendering/CoreRenderer.cpp
    src/rendering/VoxelGrid.cpp
    src/rendering/VoxelRenderer.cpp
    src/rendering/Mesh.cpp
    src/rendering/MeshRenderer.cpp
    src/utilities/Logger.cpp
    src/core/Camera2D.cpp
    src/core/Camera3D.cpp
    src/core/Window.cpp
)

# List all engine header files
set(ENGINE_HEADERS
    include/core/Engine.h
    include/rendering/Shader.h
    include/rendering/Renderable.h
    include/rendering/CoreRenderer.h
    include/rendering/VoxelGrid.h
    include/rendering/VoxelRenderer.h
    include/rendering/Mesh.h
    include/rendering/MeshRenderer.h
    include/utilities/Logger.h
    include/core/Camera2D.h
    include/core/Camera3D.h
    include/core/Window.h
)

# Add library target for engine
add_library(engine STATIC ${ENGINE_SOURCES} ${ENGINE_HEADERS})

# Include directories for engine
target_include_directories(engine PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${SDL2_INCLUDE_DIR}
    ${GLEW_INCLUDE_DIR}
    ${GLM_INCLUDE_DIR}
)

# Link libraries for engine
target_link_libraries(engine ${SDL2_LIBRARY} ${SDL2MAIN_LIBRARY} ${GLEW_LIBRARY} opengl32)
