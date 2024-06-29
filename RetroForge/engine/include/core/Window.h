#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <glew/glew.h>
#include <string>

class CoreRenderer; // Forward declaration of CoreRenderer class

class Window {
public:
    Window(const std::string& title, int width, int height);
    ~Window();

    void Clear();
    void SwapBuffers();
    bool IsClosed() const;

    // Method to set CoreRenderer
    void SetRenderer(CoreRenderer* renderer);

private:
    SDL_Window* m_Window;
    SDL_GLContext m_Context;
    bool m_IsClosed;
    CoreRenderer* m_Renderer; // Pointer to CoreRenderer

    // Private method to initialize OpenGL context
    void InitOpenGLContext();
};

#endif // WINDOW_H
