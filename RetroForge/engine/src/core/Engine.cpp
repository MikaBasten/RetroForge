#include "core/engine.h"
#include <iostream>


void Engine::hello(const std::string& word) {
    std::cout << "Hello, " << word << "!" << std::endl;
}

Engine::Engine()
    : m_Window("Game Title", 800, 600) // Initialize Window in constructor initializer list
{
    // Initialize other components of Engine if needed
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
        // Call renderer methods or render game objects here
        m_Window.SwapBuffers();
    }
}

void Engine::shutdown()
{
    // Cleanup resources
}
