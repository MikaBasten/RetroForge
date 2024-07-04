#include "rendering/CoreRenderer.h"
#include <iostream>


CoreRenderer::CoreRenderer()
    : meshRenderer(), voxelRenderer() {
    // Constructor initialization list
}

CoreRenderer::~CoreRenderer() {
    // Destructor implementation (if needed)
}

void CoreRenderer::Initialize() {
    // Implementation of Initialize method
    meshRenderer.Initialize();
    voxelRenderer.Initialize();
}

void CoreRenderer::Render() {
    // Implementation of Render method
    // Render logic for meshRenderer and voxelRenderer
}

void CoreRenderer::Shutdown() {
    // Implementation of Shutdown method
    meshRenderer.Shutdown();
    voxelRenderer.Shutdown();
}

void CoreRenderer::RenderObject(const IRenderable& renderableObject) {
    // Determine the type of renderableObject and dispatch it to the appropriate renderer
    if (const Mesh* meshObject = dynamic_cast<const Mesh*>(&renderableObject)) {
        meshRenderer.Render(*meshObject);
    }
    else if (const VoxelGrid* voxelObject = dynamic_cast<const VoxelGrid*>(&renderableObject)) {
        voxelRenderer.Render(*voxelObject);
    }
    else {
        std::cerr << "Error: Unsupported renderable object type." << std::endl;
    }
}