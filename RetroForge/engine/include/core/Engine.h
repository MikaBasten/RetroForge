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

    void initialize();
    void run();
    void shutdown();

private:
    Window m_Window;
    CoreRenderer m_Renderer;
};

#endif // ENGINE_H
