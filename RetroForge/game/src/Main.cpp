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

    std::shared_ptr<Mesh> triangleMesh = std::make_shared<Mesh>(vertices, indices);

    engine.Initialize();

    engine.RenderObject(triangleMesh);

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