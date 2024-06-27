#include "core/Window.h"
#include <iostream> // Include for testing purposes

Window::Window(const std::string& title, int width, int height)
    : m_Window(nullptr), m_Context(nullptr), m_IsClosed(false)
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return;
    }

    // Create SDL window
    m_Window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (!m_Window) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return;
    }

    // Create OpenGL context
    m_Context = SDL_GL_CreateContext(m_Window);
    if (!m_Context) {
        std::cerr << "Failed to create OpenGL context: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(m_Window);
        SDL_Quit();
        return;
    }

    // Set up GLEW (if needed)
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        SDL_GL_DeleteContext(m_Context);
        SDL_DestroyWindow(m_Window);
        SDL_Quit();
        return;
    }

    // Clear the window initially
    Clear();
    SwapBuffers();
}

Window::~Window()
{
    // Destroy OpenGL context and window
    SDL_GL_DeleteContext(m_Context);
    SDL_DestroyWindow(m_Window);

    // Quit SDL subsystems
    SDL_Quit();
}

void Window::Clear()
{
    // Clear color buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::SwapBuffers()
{
    // Swap front and back buffers
    SDL_GL_SwapWindow(m_Window);
}

bool Window::IsClosed() const
{
    return m_IsClosed;
}
