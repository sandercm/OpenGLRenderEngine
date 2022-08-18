//
// Created by sande on 14/08/2022.
//

#ifndef LEARNINGOPENGL_WINDOW_H
#define LEARNINGOPENGL_WINDOW_H

#include <memory>
#include <vector>
#include <functional>
#include "Renderer.h"

class Window {
public:
    Window();
    Window(const Window&) = delete;
    Window(Window&&) = delete;
    ~Window();

    bool shouldClose();
    void handleInput();
    void render();
    void addFrameBufferCallBack(const GLFWframebuffersizefun& func);
    void addMouseCursorPosCallBack(const GLFWcursorposfun& func);
public:
    int width = 800;
    int height = 600;
    const std::string title = "LearnOpenGL";
private:
    GLFWwindow* glfwWindow = nullptr;
    Renderer renderer;

    void initWindow();
};

#endif //LEARNINGOPENGL_WINDOW_H
