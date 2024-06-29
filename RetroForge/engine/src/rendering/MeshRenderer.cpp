#include "rendering/MeshRenderer.h"

MeshRenderer::MeshRenderer()
    : VAO(0), VBO(0), EBO(0) {}

MeshRenderer::~MeshRenderer() {
    Shutdown();
}

void MeshRenderer::Initialize() {
    // Load and compile shaders
    shader = Shader("shaders/mesh/mesh_vertex.glsl", "shaders/mesh/mesh_fragment.glsl");

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
}

void MeshRenderer::Render(const Mesh& mesh) {
    shader.Use();
    SetupMesh(mesh);
    const auto& indices = mesh.GetIndices();
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void MeshRenderer::Shutdown() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    shader.Delete();
}

void MeshRenderer::SetupMesh(const Mesh& mesh) {
    glBindVertexArray(VAO);

    const auto& vertices = mesh.GetVertices();
    const auto& indices = mesh.GetIndices();

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    // Vertex positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));

    // Vertex normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));

    // Texture coordinates
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoords));

    glBindVertexArray(0);
}
