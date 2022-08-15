#include <iostream>
#include "Window.h"

int main() {
    std::cout << "making window" << std::endl;
    Window window;
    std::cout << "Succesfully made window" << std::endl;


    while(!window.shouldClose()){
        window.handleInput();

        window.render();
    }
    return 0;
}
