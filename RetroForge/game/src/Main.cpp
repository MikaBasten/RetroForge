/*#include <SDL.h>
#include <glew/glew.h>
#include <glm/glm.hpp>
#include <iostream>
*/


#include "core/Engine.h"
#include "rendering/Mesh.h"
#include <iostream>

int main(int argc, char* argv[])
{
    
    std::cout << "Hello, World!" << std::endl;
    Engine engine;
    engine.hello("it works");


    std::vector<Vertex> vertices = {
       {{-0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}},
       {{0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
       {{0.0f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.5f, 1.0f}}
    };

    std::vector<unsigned int> indices = {
        0, 1, 2
    };

    std::vector<Vertex> icosahedronVertices = {
    {{-0.525731112119133606f, 0.0f, 0.850650808352039932f}, {1.0f, 0.0f, 0.0f}}, // Red
    {{0.525731112119133606f, 0.0f, 0.850650808352039932f}, {0.0f, 1.0f, 0.0f}}, // Green
    {{-0.525731112119133606f, 0.0f, -0.850650808352039932f}, {0.0f, 0.0f, 1.0f}}, // Blue
    {{0.525731112119133606f, 0.0f, -0.850650808352039932f}, {1.0f, 1.0f, 1.0f}}, // White
    {{0.0f, 0.850651f, 0.525731f}, {1.0f, 0.0f, 0.0f}}, // Red
    {{0.0f, 0.850651f, -0.525731f}, {0.0f, 1.0f, 0.0f}}, // Green
    {{0.0f, -0.850651f, 0.525731f}, {0.0f, 0.0f, 1.0f}}, // Blue
    {{0.0f, -0.850651f, -0.525731f}, {1.0f, 1.0f, 1.0f}}, // White
    {{0.850651f, 0.525731f, 0.0f}, {1.0f, 0.0f, 0.0f}}, // Red
    {{-0.850651f, 0.525731f, 0.0f}, {0.0f, 1.0f, 0.0f}}, // Green
    {{0.850651f, -0.525731f, 0.0f}, {0.0f, 0.0f, 1.0f}}, // Blue
    {{-0.850651f, -0.525731f, 0.0f}, {1.0f, 1.0f, 1.0f}} // White
    };

    std::vector<unsigned int> icosahedronIndices = {
        0, 4, 1,
        0, 9, 4,
        9, 5, 4,
        4, 5, 8,
        4, 8, 1,
        8, 10, 1,
        8, 3, 10,
        5, 3, 8,
        5, 2, 3,
        2, 7, 3,
        7, 10, 3,
        7, 6, 10,
        7, 11, 6,
        11, 0, 6,
        0, 1, 6,
        6, 1, 10,
        9, 0, 11,
        9, 11, 2,
        9, 2, 5,
        7, 2, 11
    };

    std::shared_ptr<Mesh> triangleMesh = std::make_shared<Mesh>(vertices, indices);
    std::shared_ptr<Mesh> icosahedronMesh = std::make_shared<Mesh>(icosahedronVertices, icosahedronIndices);
    engine.Initialize();

    engine.RenderObject(icosahedronMesh);

    engine.Run();
    return 0;
}

/*
int main() {
    Engine engine;
    engine.hello("from game");
    return 0;
}
*/
/*
int main() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow("Test Window", 100, 100, 640, 480, SDL_WINDOW_OPENGL);
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }vc

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "glewInit Error" << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Use GLM
    glm::vec3 v(1.0f, 2.0f, 3.0f);
    std::cout << "GLM vector: " << v.x << ", " << v.y << ", " << v.z << std::endl;

    // Cleanup and quit
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
*/