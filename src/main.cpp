#include <iostream>
#include "Window.h"

float deltaTime = 0.0f;
float lastFrame = 0.0f;

int main() {
    std::cout << "making window" << std::endl;
    Window window;
    std::cout << "Succesfully made window" << std::endl;

    while(!window.shouldClose()){
        window.handleInput();

        window.render();

        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
    }
    return 0;
}
