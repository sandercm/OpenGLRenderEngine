//
// Created by sande on 14/08/2022.
//

#ifndef LEARNINGOPENGL_SHADERPROGRAM_H
#define LEARNINGOPENGL_SHADERPROGRAM_H


#include <string>
#include "Shader.h"
#include <iostream>
#include "linalg.h"

using namespace linalg::aliases;

class ShaderProgram {
public:
    ShaderProgram() = delete;
    ShaderProgram(const std::string&& vertexShader, const std:: string&& fragmentShader);
    ShaderProgram(const ShaderProgram&) = delete;
    ShaderProgram& operator=(const ShaderProgram&) = delete;
    ShaderProgram(ShaderProgram&& other) noexcept :
        _id(other._id)
    {
        // Set id of other object to -1 so the OpenGL destructor won't be called when object is moved
        other._id = 0;
    }
    ShaderProgram& operator=(ShaderProgram&& other) noexcept {
        if (this != &other)
        {
            _id = other.getId();
            other._id = 0;
        }
        return *this;
    }
    ~ShaderProgram();

    [[nodiscard]] unsigned int getId() const;
    void bind() const;

    /*
     * Calling this function requires
     * the selected program to be bound.
     * */
    void setUniform(const std::string&& uniformName, float1 value) const
    {
        int uniformLocation = glGetUniformLocation(getId(), uniformName.c_str());
        glUniform4f(uniformLocation, value.x, 1.0f, 1.0f, 1.0f);
    }

    void setUniform(const std::string&& uniformName, float2 value) const
    {
        int uniformLocation = glGetUniformLocation(getId(), uniformName.c_str());
        glUniform4f(uniformLocation, value.x, value.y, 1.0f, 1.0f);
    }

    void setUniform(const std::string&& uniformName, float3 value) const
    {
        int uniformLocation = glGetUniformLocation(getId(), uniformName.c_str());
        glUniform4f(uniformLocation, value.x, value.y, value.z, 1.0f);
    }

    void setUniform(const std::string&& uniformName, float4 value) const
    {
        int uniformLocation = glGetUniformLocation(getId(), uniformName.c_str());
        glUniform4f(uniformLocation, value.x, value.y, value.z, value.w);
    }
private:
    unsigned int _id = 0;
};


#endif //LEARNINGOPENGL_SHADERPROGRAM_H
