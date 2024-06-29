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
    // Cleanup Engine resources
}

void Engine::initialize()
{
    // Initialize other components if needed
}

void Engine::run()
{
    // Main game loop
    while (!m_Window.IsClosed()) {
        // Handle input, update game state, etc.

        // Render game
        m_Window.Clear();
        // Call renderer methods or render game objects here using m_Renderer
        m_Window.SwapBuffers();
    }
}

void Engine::shutdown()
{
    // Shutdown Window and Renderer
    // m_Renderer.shutdown(); // Implement shutdown method if necessary in CoreRenderer
    // m_Window.shutdown(); // Implement shutdown method if necessary in Window
}
