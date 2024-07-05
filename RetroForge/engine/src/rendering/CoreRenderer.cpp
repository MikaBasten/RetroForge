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
    for (const auto& renderableWrapper : renderables) {
        if (renderableWrapper.IsType<Mesh>()) {
            meshRenderer.Render(*renderableWrapper.As<Mesh>());
        }
        else if (renderableWrapper.IsType<VoxelGrid>()) {
            voxelRenderer.Render(*renderableWrapper.As<VoxelGrid>());
        }
        else {
            std::cerr << "Error: Unsupported renderable object type." << std::endl;
        }
    }
}

void CoreRenderer::Shutdown() {
    // Implementation of Shutdown method
    meshRenderer.Shutdown();
    voxelRenderer.Shutdown();
}

void CoreRenderer::AddRenderable(const std::shared_ptr<IRenderable>& renderableObject) {
    renderables.emplace_back(renderableObject);
}
