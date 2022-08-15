//
// Created by sande on 14/08/2022.
//

#ifndef LEARNINGOPENGL_RENDERER_H
#define LEARNINGOPENGL_RENDERER_H


#include <string>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "ShaderProgram.h"
#include "VertexArrayObject.h"

class Renderer {
public:
    Renderer();
    void setWindowContext(GLFWwindow* w) {
        window = w;
    }

    void render();
    void loadModels();
private:
    GLFWwindow* window = nullptr;
    std::string exeLocation;

    std::vector<ShaderProgram> shaderPrograms;
    std::vector<VertexArrayObject> vaos;
};


#endif //LEARNINGOPENGL_RENDERER_H
