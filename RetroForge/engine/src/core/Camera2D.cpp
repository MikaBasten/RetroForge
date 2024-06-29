#include "Core/Camera2D.h"

Camera2D::Camera2D()
    : m_position(0.0f, 0.0f), m_zoom(1.0f), m_dirty(true) {
}

Camera2D::~Camera2D() {
}

void Camera2D::SetPosition(const glm::vec2& position) {
    if (m_position != position) {
        m_position = position;
        m_dirty = true;
    }
}

void Camera2D::SetZoom(float zoom) {
    if (m_zoom != zoom) {
        m_zoom = zoom;
        m_dirty = true;
    }
}

glm::vec2 Camera2D::GetPosition() const {
    return m_position;
}

float Camera2D::GetZoom() const {
    return m_zoom;
}

glm::mat4 Camera2D::GetViewMatrix() const {
    if (m_dirty) {
        const_cast<Camera2D*>(this)->UpdateViewMatrix();
    }
    return m_viewMatrix;
}

void Camera2D::UpdateViewMatrix() {
    m_viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(-m_position, 0.0f));
    m_viewMatrix = glm::scale(m_viewMatrix, glm::vec3(m_zoom, m_zoom, 1.0f));
    m_dirty = false;
}
