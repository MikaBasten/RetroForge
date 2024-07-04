#ifndef VOXELGRID_H
#define VOXELGRID_H

#include "Renderable.h"
#include <vector>
#include <glm/glm.hpp>

struct Voxel {
    glm::vec3 position;
    glm::vec3 color;
};

class VoxelGrid : public IRenderable {
public:
    VoxelGrid(int width, int height, int depth);
    ~VoxelGrid();

    void SetVoxel(int x, int y, int z, const glm::vec3& color);
    const std::vector<Voxel>& GetVoxels() const;

    // Implementing IRenderable interface

private:
    int m_Width;
    int m_Height;
    int m_Depth;
    std::vector<Voxel> m_Voxels;
};

#endif // VOXELGRID_H