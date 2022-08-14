#include "Window.h"

int main() {
    Window window;

    while(!window.shouldClose()){
        window.handleInput();

        window.render();
    }
    return 0;
}
