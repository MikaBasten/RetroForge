#ifndef VOXELRENDERER_H
#define VOXELRENDERER_H

#include "rendering/Shader.h"
#include <glm/glm.hpp>
#include <vector>

struct Voxel {
    glm::vec3 position;
    glm::vec3 color;
};

class VoxelRenderer {
public:
    VoxelRenderer();
    ~VoxelRenderer();

    void Initialize();
    void Render(const std::vector<Voxel>& voxels, const glm::mat4& projection, const glm::mat4& view);
    void Shutdown();

private:
    Shader shader;
    GLuint VAO, VBO;

    void SetupMesh();
};

#endif // VOXELRENDERER_H
