#ifndef CORERENDERER_H
#define CORERENDERER_H

#include "rendering/MeshRenderer.h"
#include "rendering/VoxelRenderer.h"
#include "Renderable.h"

class CoreRenderer {
public:
    CoreRenderer();
    ~CoreRenderer();

    void Initialize();
    void Render();
    void Shutdown();


    void RenderObject(const IRenderable& renderableObject);

private:
    MeshRenderer meshRenderer;
    VoxelRenderer voxelRenderer;
};

#endif // CORERENDERER_H
