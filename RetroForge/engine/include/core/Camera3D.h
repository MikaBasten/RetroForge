#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera3D {
public:
    Camera3D(float fov, float aspectRatio, float nearPlane, float farPlane);

    void SetPosition(const glm::vec3& position);
    void SetRotation(const glm::vec3& rotation);
    void Move(const glm::vec3& offset);
    void Rotate(const glm::vec3& offset);

    glm::mat4 GetViewMatrix() const;
    glm::mat4 GetProjectionMatrix() const;

private:
    glm::vec3 position;
    glm::vec3 rotation;
    float fov;
    float aspectRatio;
    float nearPlane;
    float farPlane;
    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;

    void UpdateViewMatrix();
};
