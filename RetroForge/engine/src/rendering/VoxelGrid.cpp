#include "rendering/VoxelGrid.h"
#include <iostream> // For debugging

VoxelGrid::VoxelGrid(int width, int height, int depth)
    : m_Width(width), m_Height(height), m_Depth(depth) {
    
    m_Voxels.resize(width * height * depth);
}

VoxelGrid::~VoxelGrid() {
    
}

void VoxelGrid::SetVoxel(int x, int y, int z, const glm::vec3& color) {
    if (x >= 0 && x < m_Width && y >= 0 && y < m_Height && z >= 0 && z < m_Depth) {
        int index = x + y * m_Width + z * m_Width * m_Height;
        m_Voxels[index].position = glm::vec3(x, y, z); // Adjust position based on voxel size if needed
        m_Voxels[index].color = color;
    }
    else {
        std::cerr << "Error: Voxel coordinates out of bounds." << std::endl;
    }
}

const std::vector<Voxel>& VoxelGrid::GetVoxels() const {
    return m_Voxels;
}

