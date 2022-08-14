//
// Created by sande on 14/08/2022.
//

#include <iostream>
#include <cassert>
#include "glad/glad.h"
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

    glUseProgram(_id);

    glDeleteShader(vertexShader.getId());
    glDeleteShader(fragmentShader.getId());
}

inline unsigned int ShaderProgram::getId() {
    assert(_id != 0);
    return _id;
}
