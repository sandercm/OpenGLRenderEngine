//
// Created by sande on 14/08/2022.
//

#ifndef LEARNINGOPENGL_SHADER_H
#define LEARNINGOPENGL_SHADER_H


#include <string>
#include <filesystem>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

enum class ShaderType {
    FragmentShader = GL_FRAGMENT_SHADER,
    VertexShader = GL_VERTEX_SHADER
};

class Shader {
public:
    Shader() = default;
    Shader(const Shader&) = delete;
    Shader(Shader&& other)  noexcept :
        _id(other._id)
    {
        // Set id of other object to -1 so the OpenGL destructor won't be called when object is moved
        other._id = 0;
    }
    Shader& operator=(Shader&& other)  noexcept {
        if (this != &other)
        {
            _id = other.getId();
            other._id = 0;
        }
        return *this;
    }
    ~Shader();
    explicit Shader(const std::string&& shaderFilePath, ShaderType);
    [[nodiscard]] unsigned int getId() const;
private:
    unsigned int _id = 0;
};


#endif //LEARNINGOPENGL_SHADER_H
