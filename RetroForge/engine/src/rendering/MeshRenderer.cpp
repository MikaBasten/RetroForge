#include "rendering/MeshRenderer.h"

MeshRenderer::MeshRenderer()
    : VAO(0), VBO(0), EBO(0) {}

MeshRenderer::~MeshRenderer() {
    Shutdown();
}


void MeshRenderer::Initialize() {
    // Load and compile shaders
    shader = Shader("../../engine/shaders/mesh/mesh_vertex.glsl", "../../engine/shaders/mesh/mesh_fragment.glsl");

    // Generate buffers and vertex arrays
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    std::cout << "Initialized MeshRenderer with VAO: " << VAO << std::endl;
}

void MeshRenderer::Render(const Mesh& mesh) {
    shader.Use();
    SetupMesh(mesh);
    const auto& indices = mesh.GetIndices();
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0); // Unbind VAO after rendering
}

void MeshRenderer::Shutdown() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    shader.Delete(); // Delete shader program
}

void MeshRenderer::SetupMesh(const Mesh& mesh) {
    glBindVertexArray(VAO);

    const auto& vertices = mesh.GetVertices();
    const auto& indices = mesh.GetIndices();

    // Bind VBO and buffer vertex data
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

    // Bind EBO and buffer index data
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    // Vertex positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, position)));

    // Vertex normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, normal)));

    // Texture coordinates
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, texCoords)));

    glBindVertexArray(0); // Unbind VAO after setup
}