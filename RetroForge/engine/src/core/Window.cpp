#include "core/Window.h"
#include "rendering/CoreRenderer.h" // Include CoreRenderer header
#include <iostream>

Window::Window(const std::string& title, int width, int height)
    : m_Window(nullptr), m_Context(nullptr), m_IsClosed(false), m_Renderer(nullptr)
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

    // Set up OpenGL context
    InitOpenGLContext();

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
    // Set clear color to white (R=1, G=1, B=1, A=1)
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Clear color buffer and depth buffer
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

void Window::Close() {
    m_IsClosed = true;
}

void Window::InitOpenGLContext()
{
    // Create OpenGL context
    m_Context = SDL_GL_CreateContext(m_Window);
    if (!m_Context) {
        std::cerr << "Failed to create OpenGL context: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(m_Window);
        SDL_Quit();
        return;
    }

    // Initialize GLEW (if needed)
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        SDL_GL_DeleteContext(m_Context);
        SDL_DestroyWindow(m_Window);
        SDL_Quit();
        return;
    }
}

void Window::SetRenderer(CoreRenderer* renderer)
{
    m_Renderer = renderer;
}
