//
// Created by sande on 14/08/2022.
//

#ifndef LEARNINGOPENGL_SHADERPROGRAM_H
#define LEARNINGOPENGL_SHADERPROGRAM_H


#include <string>
#include "Shader.h"

class ShaderProgram {
public:
    ShaderProgram() = delete;
    ShaderProgram(const std::string&& vertexShader, const std:: string&& fragmentShader);

    inline unsigned int getId();
private:
    unsigned int _id = 0;
};


#endif //LEARNINGOPENGL_SHADERPROGRAM_H
