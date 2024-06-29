#ifndef MESHRENDERER_H
#define MESHRENDERER_H

#include "rendering/Mesh.h"
#include "rendering/Shader.h"

class MeshRenderer {
public:
    MeshRenderer();
    ~MeshRenderer();

    void Initialize();
    void Render(const Mesh& mesh);
    void Shutdown();

private:
    Shader shader;
    GLuint VAO, VBO, EBO;

    void SetupMesh(const Mesh& mesh);
};

#endif // MESHRENDERER_H
