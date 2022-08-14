//
// Created by sande on 14/08/2022.
//

#include <cassert>
#include "glad/glad.h"
#include "Renderer.h"
#include "Shader.h"
#include "linalg.h"
#include "ShaderProgram.h"

// using namespace linalg::aliases;

#define VertexShader(name) (exeLocation + "/shaders/vertex/" + (name) + ".glsl")
#define FragmentShader(name) (exeLocation + "/shaders/fragment/" + (name) + ".glsl")

void Renderer::render() {
    assert(this->window != nullptr);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

//    std::vector<float3> triangle{
//            {-0.5f, -0.5f, 0.0f},
//            {0.5f, -0.5f, 0.0f},
//            {0.0f, 0.5f, 0.0f}
//    };

    float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
    };

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), &triangle, GL_STATIC_DRAW);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // load and compile vertexShader with given path
    ShaderProgram shaderProgram1{VertexShader("basicVertexShader"), FragmentShader("basicFragmentShader")};
    // TODO: Create a program class

    glfwPollEvents();
    glfwSwapBuffers(window);
}

void Renderer::loadShaders() {
}

Renderer::Renderer() : exeLocation(std::filesystem::current_path().string())
{}
