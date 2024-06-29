#ifndef MESH_H
#define MESH_H

#include <vector>

struct Vertex {
    float position[3];
    float normal[3];
    float texCoords[2];
};

class Mesh {
public:
    Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);
    ~Mesh();

    const std::vector<Vertex>& GetVertices() const;
    const std::vector<unsigned int>& GetIndices() const;

private:
    std::vector<Vertex> m_Vertices;
    std::vector<unsigned int> m_Indices;
};

#endif // MESH_H
