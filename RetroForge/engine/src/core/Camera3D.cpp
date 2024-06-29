#include "Core/Camera3D.h"

Camera3D::Camera3D(float fov, float aspectRatio, float nearPlane, float farPlane)
    : fov(fov), aspectRatio(aspectRatio), nearPlane(nearPlane), farPlane(farPlane) {
    UpdateViewMatrix();
    projectionMatrix = glm::perspective(glm::radians(fov), aspectRatio, nearPlane, farPlane);
}

void Camera3D::SetPosition(const glm::vec3& position) {
    this->position = position;
    UpdateViewMatrix();
}

void Camera3D::SetRotation(const glm::vec3& rotation) {
    this->rotation = rotation;
    UpdateViewMatrix();
}

void Camera3D::Move(const glm::vec3& offset) {
    position += offset;
    UpdateViewMatrix();
}

void Camera3D::Rotate(const glm::vec3& offset) {
    rotation += offset;
    UpdateViewMatrix();
}

glm::mat4 Camera3D::GetViewMatrix() const {
    return viewMatrix;
}

glm::mat4 Camera3D::GetProjectionMatrix() const {
    return projectionMatrix;
}

void Camera3D::UpdateViewMatrix() {
    glm::mat4 transform = glm::mat4(1.0f);
    transform = glm::rotate(transform, glm::radians(rotation.x), glm::vec3(1, 0, 0));
    transform = glm::rotate(transform, glm::radians(rotation.y), glm::vec3(0, 1, 0));
    transform = glm::rotate(transform, glm::radians(rotation.z), glm::vec3(0, 0, 1));
    transform = glm::translate(transform, -position);
    viewMatrix = transform;
}
