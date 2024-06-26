add_executable(Editor
    src/Editor.cpp
)

target_include_directories(Editor PUBLIC include)
target_link_libraries(Editor engine ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES})
