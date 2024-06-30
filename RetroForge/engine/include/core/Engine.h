#ifndef ENGINE_H
#define ENGINE_H

#include "core/Window.h"
#include "rendering/CoreRenderer.h"
#include <string>

class Engine {
public:
    Engine();
    ~Engine();

    void hello(const std::string& word);

    void Initialize();
    void Run();
    void Shutdown();

private:
    Window m_Window;
    CoreRenderer m_Renderer;
    bool m_Running;
    SDL_Event m_Event;

    void HandleEvents();
    void Update();
    void Render();
};

#endif // ENGINE_H
