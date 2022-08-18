//
// Created by sande on 14/08/2022.
//

#include <iostream>
#include <cassert>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(const std::string&& _vertexShader, const std::string&& _fragmentShader)
{
    Shader vertexShader{_vertexShader.c_str(), ShaderType::VertexShader};
    Shader fragmentShader{_fragmentShader.c_str(), ShaderType::FragmentShader};

    //    unsigned int shaderProgram;
    _id = glCreateProgram();

    assert(_id != 0);

    glAttachShader(_id, vertexShader.getId());
    glAttachShader(_id, fragmentShader.getId());
    glLinkProgram(_id);

    int success;
    char infoLog[512];
    glGetProgramiv(_id, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(_id, 512, nullptr, infoLog);
    }

    glDeleteShader(vertexShader.getId());
    glDeleteShader(fragmentShader.getId());
}

unsigned int ShaderProgram::getId() const {
    return _id;
}

void ShaderProgram::bind() const {
    assert(_id != 0);
    glUseProgram(_id);
}

ShaderProgram::~ShaderProgram() {
    if (_id != 0) {
        glDeleteProgram(getId());
    }
}

void ShaderProgram::setTextureN(int textureSlot, const std::string& textureName, const std::string& fileName) {
    if (textureSlot < 0 || textureSlot > 16)
    {
        std::cout << "trying to set texture out of range index: " << textureSlot << std::endl;
    } else
    {
        bind();

        std::cout << "setting texture for " << GL_TEXTURE0 + textureSlot << std::endl;
        glActiveTexture(GL_TEXTURE0 + textureSlot);
        textures[textureSlot] = Texture{fileName};
        setUniform(textureName, textureSlot);
    }
}
