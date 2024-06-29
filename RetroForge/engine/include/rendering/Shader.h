#ifndef SHADER_H
#define SHADER_H

#include <glew/glew.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>

class Shader {
public:

    Shader();
    // Constructor reads and builds the shader
    Shader(const char* vertexPath, const char* fragmentPath);

    // Constructor for loading additional shaders
    Shader(const char* vertexPath, const char* fragmentPath, const char* fogPath);

    // Use the shader
    void Use() const;

    // Utility uniform functions
    void SetBool(const std::string& name, bool value) const;
    void SetInt(const std::string& name, int value) const;
    void SetFloat(const std::string& name, float value) const;
    void SetVec3(const std::string& name, const glm::vec3& value) const;
    void SetMat4(const std::string& name, const glm::mat4& value) const;

    // Delete the shader program
    void Delete();

private:
    GLuint programID;

    // Utility function for checking shader compilation/linking errors
    static void CheckCompileErrors(GLuint shader, std::string type);
};

#endif // SHADER_H
