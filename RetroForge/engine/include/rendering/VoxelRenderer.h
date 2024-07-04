#ifndef VOXELRENDERER_H
#define VOXELRENDERER_H

#include "rendering/Shader.h"
#include "rendering/VoxelGrid.h"
#include <glm/glm.hpp>

class VoxelRenderer {
public:
    VoxelRenderer();
    ~VoxelRenderer();

    void Initialize();
    void Render(const VoxelGrid& voxelGrid);
    void Shutdown();

private:
    Shader shader;
    GLuint VAO, VBO;

    void SetupMesh(const VoxelGrid& voxelGrid);
};

#endif // VOXELRENDERER_H
