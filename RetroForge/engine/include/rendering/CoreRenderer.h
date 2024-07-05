#ifndef CORERENDERER_H
#define CORERENDERER_H

#include "rendering/MeshRenderer.h"
#include "rendering/VoxelRenderer.h"
#include "RenderablePtrWrapper.h"
#include <vector>

class CoreRenderer {
public:
    CoreRenderer();
    ~CoreRenderer();

    void Initialize();
    void Render();
    void Shutdown();

    void AddRenderable(const std::shared_ptr<IRenderable>& renderableObject);

private:
    MeshRenderer meshRenderer;
    VoxelRenderer voxelRenderer;
    std::vector<RenderablePtrWrapper> renderables;
};

#endif // CORERENDERER_H