#include "rendering/Mesh.h"
#include <iostream>

Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices)
    : m_Vertices(vertices), m_Indices(indices), m_ModelMatrix(1.0f) {
    // Calculate or initialize model matrix as needed
}

Mesh::~Mesh() {
    // Destructor implementation
}

const std::vector<Vertex>& Mesh::GetVertices() const {
    return m_Vertices;
}

const std::vector<unsigned int>& Mesh::GetIndices() const {
    return m_Indices;
}
