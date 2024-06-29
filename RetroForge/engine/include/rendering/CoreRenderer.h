
#ifndef CORERENDERER_H
#define CORERENDERER_H

#include "rendering/VoxelRenderer.h"
#include "rendering/MeshRenderer.h"


class CoreRenderer {
public:
    CoreRenderer();
    ~CoreRenderer();

    void Initialize();
    void Render();
    void Shutdown();

private:
    VoxelRenderer voxelRenderer;
    MeshRenderer meshRenderer;
};
#endif