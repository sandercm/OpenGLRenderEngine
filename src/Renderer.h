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
#include "Camera.h"

class Renderer {
public:
    Renderer();
    void setWindowContext(GLFWwindow* w, int width, int height) {
        window = w;
        camera.lastX = width / 2;
        camera.lastY = height / 2;
    }

    void render();
    void loadModels();

    Camera camera;
private:
    GLFWwindow* window = nullptr;
    std::string exeLocation;

    std::vector<ShaderProgram> shaderPrograms;
    std::vector<VertexArrayObject> vaos;
};


#endif //LEARNINGOPENGL_RENDERER_H
