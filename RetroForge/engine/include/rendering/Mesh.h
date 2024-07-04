// Mesh.h
#ifndef MESH_H
#define MESH_H

#include <vector>
#include <glm/glm.hpp>
#include "Renderable.h"

struct Vertex {
    float position[3];
    float normal[3];
    float texCoords[2];
};

class Mesh : public IRenderable {
public:
    Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);
    ~Mesh();

    const std::vector<Vertex>& GetVertices() const;
    const std::vector<unsigned int>& GetIndices() const;

private:
    std::vector<Vertex> m_Vertices;
    std::vector<unsigned int> m_Indices;
    glm::mat4 m_ModelMatrix; // Add model matrix for transformation
};

#endif // MESH_H
