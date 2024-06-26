add_library(engine STATIC
    src/Camera2D.cpp
    src/Camera3D.cpp
    src/Engine.cpp
    src/Renderer.cpp
    src/Window.cpp
)

target_include_directories(engine PUBLIC include)
target_link_libraries(engine ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES})
