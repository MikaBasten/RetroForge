#include "core/engine.h"
#include <iostream>

void Engine::hello(const std::string& word) {
    std::cout << "Hello, " << word << "!" << std::endl;
}

Engine::Engine()
    : m_Window("Game Title", 800, 600), m_Renderer(), m_Running(true)
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
    m_Renderer.Initialize();
    for (const auto& system : m_Systems) {
        system->Initialize();
    }
}

void Engine::Run()
{
    // Main game loop
    while (m_Running) {
        HandleEvents();
        Update();
        Render();
    }
}

void Engine::Shutdown()
{
    // Shutdown Window and Renderer
    for (const auto& system : m_Systems) {
        system->Shutdown();
    }
    m_Window.Close();
    m_Renderer.Shutdown();
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

void Engine::Update()
{
    // Update game logic, physics, etc.
    // Example: m_Physics.Update();
}

void Engine::Render()
{
    // Render the game
    m_Window.Clear();
    m_Renderer.Render(); // Assuming Render() method in CoreRenderer handles actual rendering
    m_Window.SwapBuffers();
}
