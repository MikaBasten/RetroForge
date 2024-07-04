#include "rendering/VoxelRenderer.h"
#include <iostream>

// Constructor
VoxelRenderer::VoxelRenderer()
    : shader("../../engine/shaders/voxel/voxel_vertex.glsl", "../../engine/shaders/voxel/voxel_fragment.glsl"), VAO(0), VBO(0) {}

// Destructor
VoxelRenderer::~VoxelRenderer() {
    Shutdown();
}

// Initialize the renderer
void VoxelRenderer::Initialize() {
    shader.Use();
}

// Render method for VoxelGrid
void VoxelRenderer::Render(const VoxelGrid& voxelGrid) {
    shader.Use();
    SetupMesh(voxelGrid); // Setup the mesh for the given VoxelGrid

    // Render voxels as points
    glBindVertexArray(VAO);
    glDrawArrays(GL_POINTS, 0, static_cast<GLsizei>(voxelGrid.GetVoxels().size()));
    glBindVertexArray(0);
}

// Shutdown method
void VoxelRenderer::Shutdown() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    shader.Delete(); // Delete shader program
}

// Setup mesh method
void VoxelRenderer::SetupMesh(const VoxelGrid& voxelGrid) {
    glBindVertexArray(VAO);

    // Bind VBO and buffer voxel data
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, voxelGrid.GetVoxels().size() * sizeof(Voxel), voxelGrid.GetVoxels().data(), GL_DYNAMIC_DRAW);

    // Specify vertex attributes
    // Position attribute (vec3)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Voxel), reinterpret_cast<void*>(offsetof(Voxel, position)));
    glEnableVertexAttribArray(0);
    // Color attribute (vec3)
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Voxel), reinterpret_cast<void*>(offsetof(Voxel, color)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0); // Unbind VAO after setup
}
