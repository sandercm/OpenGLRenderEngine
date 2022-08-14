//
// Created by sande on 14/08/2022.
//

#include <iostream>
#include <cassert>
#include "Shader.h"
#include "utils.h"

Shader::Shader(const std::string &&shaderFilePath, ShaderType type) {
    // create shader object on GPU
    _id = glCreateShader(static_cast<GLenum>(type));

    // load char data into shader
    std::string file = readFile(shaderFilePath);
    const char* shader = file.c_str();
    glShaderSource(_id, 1, &shader, nullptr);
    glCompileShader(_id);

    // check if compile was successful
    int success;
    char infoLog[512];
    glGetShaderiv(_id, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(_id, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

unsigned int Shader::getId() const {
    assert(_id != 0);
    return _id;
}

Shader::~Shader() {
    assert(_id != 0);
    glDeleteShader(getId());
}
