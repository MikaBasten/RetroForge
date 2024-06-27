#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <glew/glew.h>
#include <string>

class Window {
public:
    Window(const std::string& title, int width, int height);
    ~Window();

    void Clear();
    void SwapBuffers();
    bool IsClosed() const;

private:
    SDL_Window* m_Window;
    SDL_GLContext m_Context;
    bool m_IsClosed;
};

#endif // WINDOW_H