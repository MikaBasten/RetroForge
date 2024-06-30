#include "core/engine.h"
#include <iostream>

void Engine::hello(const std::string& word) {
    std::cout << "Hello, " << word << "!" << std::endl;
}

Engine::Engine()
    : m_Window("Game Title", 800, 600), m_Renderer()
{
    // Pass CoreRenderer instance to Window
    m_Window.SetRenderer(&m_Renderer);
}

Engine::~Engine()
{
    Shutdown();
}

void Engine::Initialize()
{
    // Initialize other components if needed
}

void Engine::Run()
{
    // Main game loop
    SDL_Event event;
    while (!m_Window.IsClosed()) {
        // Handle events
        while (SDL_PollEvent(&event)) {
            // Handle specific events
            switch (event.type) {
            case SDL_QUIT:
                m_Window.Close();
                break;
            case SDL_KEYDOWN:
                // Handle key press events
                // Example: if (event.key.keysym.sym == SDLK_UP) { /* Move player up */ }
                break;
                // Add more cases as needed (mouse events, etc.)
            }
        }

        // Update game logic, physics, etc.
        // Example: m_Physics.Update();

        // Render the game
        m_Window.Clear();
        m_Renderer.Render(); // Assuming Render() method in CoreRenderer handles actual rendering
        m_Window.SwapBuffers();

        // Optional: Implement frame rate limiting or synchronization here
    }
}




void Engine::HandleEvents()
{
    while (SDL_PollEvent(&m_Event)) {
        switch (m_Event.type) {
        case SDL_QUIT:
            m_Running = false;
            break;
        }
    }
}

void Engine::Shutdown()
{
    // Shutdown Window and Renderer
    // m_Renderer.shutdown(); // Implement shutdown method if necessary in CoreRenderer
    // m_Window.shutdown(); // Implement shutdown method if necessary in Window
}
