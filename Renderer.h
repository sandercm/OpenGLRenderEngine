//
// Created by sande on 14/08/2022.
//

#ifndef LEARNINGOPENGL_RENDERER_H
#define LEARNINGOPENGL_RENDERER_H


#include <string>
#include "GLFW/glfw3.h"

class Renderer {
public:
    Renderer();
    void setWindowContext(GLFWwindow* w) {
        window = w;
    }

    void render();
    void loadShaders();
private:
    GLFWwindow* window = nullptr;
    std::string exeLocation;
};


#endif //LEARNINGOPENGL_RENDERER_H
