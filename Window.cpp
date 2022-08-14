//
// Created by sande on 14/08/2022.
//

#include <iostream>
#include "glad/glad.h"
#include "Window.h"

Window::Window() : renderer(Renderer{}) {
    initWindow();

    // register callback resize function
    addCallBack([](GLFWwindow* window, int _height, int _width){
        glViewport(0, 0, _height, _width);
    });

    // setup render
    renderer.setWindowContext(glfwWindow);
    renderer.loadShaders();
}

void Window::initWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    if (glfwWindow == nullptr)
    {
        std::cout << "Failed to create Window instance" << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(glfwWindow);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
}


Window::~Window() {
    glfwDestroyWindow(glfwWindow);
    glfwTerminate();
}

bool Window::shouldClose() {
    return glfwWindowShouldClose(glfwWindow);
}

void Window::handleInput() {
    if (glfwGetKey(glfwWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(glfwWindow, true);
    }
}

void Window::addCallBack(const GLFWframebuffersizefun &func) {
    glfwSetFramebufferSizeCallback(glfwWindow, func);
}

void Window::render() {
    renderer.render();
}
