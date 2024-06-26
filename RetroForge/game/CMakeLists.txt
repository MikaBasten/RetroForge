add_executable(RetroForge
    src/main.cpp
)

target_include_directories(RetroForge PUBLIC include)
target_link_libraries(RetroForge engine ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES})
