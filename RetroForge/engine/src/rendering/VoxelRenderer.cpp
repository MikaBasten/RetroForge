#include "rendering/VoxelRenderer.h"
#include <iostream>

VoxelRenderer::VoxelRenderer()
    : shader("shaders/voxel/voxel_vertex.glsl", "shaders/voxel/voxel_fragment.glsl"), VAO(0), VBO(0) {}

VoxelRenderer::~VoxelRenderer() {
    Shutdown();
}

void VoxelRenderer::Initialize() {
    // Initialize shader and buffers
    shader.Use();
    SetupMesh();
}

void VoxelRenderer::Render(const std::vector<Voxel>& voxels, const glm::mat4& projection, const glm::mat4& view) {
    shader.Use();

    // Set uniforms
    shader.SetMat4("projection", projection);
    shader.SetMat4("view", view);

    // Bind VAO and render
    glBindVertexArray(VAO);
    glDrawArrays(GL_POINTS, 0, static_cast<GLsizei>(voxels.size()));
    glBindVertexArray(0);
}

void VoxelRenderer::Shutdown() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void VoxelRenderer::SetupMesh() {
    // Create VAO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Create VBO
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Set VBO data (empty for now, since we use glVertexAttribPointers)
    glBufferData(GL_ARRAY_BUFFER, 0, nullptr, GL_STATIC_DRAW);

    // Specify vertex attributes
    // Position attribute (vec3)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Voxel), reinterpret_cast<void*>(offsetof(Voxel, position)));
    glEnableVertexAttribArray(0);
    // Color attribute (vec3)
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Voxel), reinterpret_cast<void*>(offsetof(Voxel, color)));
    glEnableVertexAttribArray(1);

    // Unbind VAO
    glBindVertexArray(0);
}
