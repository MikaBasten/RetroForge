#ifndef CAMERA2D_H
#define CAMERA2D_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera2D {
public:
    Camera2D();
    ~Camera2D();

    void SetPosition(const glm::vec2& position);
    void SetZoom(float zoom);

    glm::vec2 GetPosition() const;
    float GetZoom() const;

    glm::mat4 GetViewMatrix() const;

private:
    glm::vec2 m_position;
    float m_zoom;
    bool m_dirty;
    glm::mat4 m_viewMatrix;

    void UpdateViewMatrix();
};

#endif // CAMERA2D_H
