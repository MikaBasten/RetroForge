#ifndef RENDERABLEPTRWRAPPER_H
#define RENDERABLEPTRWRAPPER_H

#include "Renderable.h"
#include <memory>

// Wrapper class to handle shared pointers with specific types
class RenderablePtrWrapper {
public:
    RenderablePtrWrapper(std::shared_ptr<IRenderable> ptr) : ptr(ptr) {}

    template <typename T>
    bool IsType() const {
        return std::dynamic_pointer_cast<T>(ptr) != nullptr;
    }

    template <typename T>
    std::shared_ptr<T> As() const {
        return std::dynamic_pointer_cast<T>(ptr);
    }

    std::shared_ptr<IRenderable> Get() const {
        return ptr;
    }

private:
    std::shared_ptr<IRenderable> ptr;
};

#endif // RENDERABLEPTRWRAPPER_H
