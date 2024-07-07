#ifndef ENGINE_H
#define ENGINE_H

#include "core/Window.h"
#include "core/ISystem.h"
#include "rendering/CoreRenderer.h"
#include "rendering/Renderable.h"
#include <string>

class Engine {
public:
    Engine();
    ~Engine();

    void hello(const std::string& word);

    void Initialize();
    void Run();
    void Shutdown();

    void AddSystem(std::shared_ptr<ISystem> system);

    // Method to render any Renderable object
    template <typename T>
    void RenderObject(const std::shared_ptr<T>& renderableObject) {
        m_Renderer.AddRenderable(renderableObject);
    }

private:
    Window m_Window;
    CoreRenderer m_Renderer;
    bool m_Running;
    SDL_Event m_Event;

    std::vector<std::shared_ptr<ISystem>> m_Systems;

    void HandleEvents();
    void Update();
    void Render();
};

#endif // ENGINE_H