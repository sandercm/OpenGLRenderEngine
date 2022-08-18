//
// Created by sande on 14/08/2022.
//

#ifndef LEARNINGOPENGL_SHADERPROGRAM_H
#define LEARNINGOPENGL_SHADERPROGRAM_H


#include <string>
#include "Shader.h"
#include <iostream>
#include "Texture.h"
#include "vec2.hpp"
#include "vec3.hpp"
#include "vec4.hpp"
#include "mat4x4.hpp"
#include "gtc/type_ptr.hpp"

using namespace glm;

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

public:
    [[nodiscard]] unsigned int getId() const;
    void bind() const;

    void setTextureN(int textureSlot, const std::string& textureName, const std::string& fileName);

    /*
     * Calling this function requires
     * the selected program to be bound.
     * */
    void setUniform(const std::string& uniformName, float value) const
    {
        int uniformLocation = glGetUniformLocation(getId(), uniformName.c_str());
        glUniform1f(uniformLocation, value);
    }

    void setUniform(const std::string& uniformName, vec2 value) const
    {
        int uniformLocation = glGetUniformLocation(getId(), uniformName.c_str());
        glUniform4f(uniformLocation, value.x, value.y, 1.0f, 1.0f);
    }

    void setUniform(const std::string& uniformName, vec3 value) const
    {
        int uniformLocation = glGetUniformLocation(getId(), uniformName.c_str());
        glUniform4f(uniformLocation, value.x, value.y, value.z, 1.0f);
    }

    void setUniform(const std::string& uniformName, vec4 value) const
    {
        int uniformLocation = glGetUniformLocation(getId(), uniformName.c_str());
        glUniform4f(uniformLocation, value.x, value.y, value.z, value.w);
    }

    void setUniform(const std::string& uniformName, bool value) const
    {
        int uniformLocation = glGetUniformLocation(getId(), uniformName.c_str());
        glUniform1i(uniformLocation, value);
    }

    void setUniform(const std::string& uniformName, int value) const
    {
        int uniformLocation = glGetUniformLocation(getId(), uniformName.c_str());
        glUniform1i(uniformLocation, value);
    }

    void setUniform(const std::string& uniformName, glm::mat4 value) const
    {
        int uniformLocation = glGetUniformLocation(getId(), uniformName.c_str());
        glUniformMatrix4fv(uniformLocation, 1, false, glm::value_ptr(value));
    }
private:
    unsigned int _id = 0;
    std::vector<Texture> textures{16};
};


#endif //LEARNINGOPENGL_SHADERPROGRAM_H
