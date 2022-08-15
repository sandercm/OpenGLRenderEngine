//
// Created by sande on 14/08/2022.
//

#include <cassert>
#include "Renderer.h"
#include "Shader.h"
#include "linalg.h"

using namespace linalg::aliases;

#define VertexShader(name) (exeLocation + "/shaders/vertex/" + (name) + ".glsl")
#define FragmentShader(name) (exeLocation + "/shaders/fragment/" + (name) + ".glsl")

void Renderer::render() {
    assert(this->window != nullptr);
    assert(!shaderPrograms.empty());

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    shaderPrograms[0].bind();
    vaos[0].bind();
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

    shaderPrograms[1].bind();
    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    shaderPrograms[1].setUniform("color2",{r, 1.0f, 1.0f});
    vaos[1].bind();
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

    glfwPollEvents();
    glfwSwapBuffers(window);
}

void Renderer::loadModels() {
    // Load Shader Program
    shaderPrograms.emplace_back(VertexShader("basicVertexShader"), FragmentShader("basicFragmentShader"));
    shaderPrograms.emplace_back(VertexShader("basicVertexShader"), FragmentShader("basicFragmentShader2"));

    // Setup Triangle

    std::vector<float3> squareLeft{
            {0.5f, -0.5f, 0.0f},
            {-0.5f, -0.5f, 0.0f},
            {-0.5f, 0.5f, 0.0f}
    };

    std::vector<float3> squareRight{
            {0.5f, 0.5f, 0.0f},
            {0.5f, -0.5f, 0.0f},
            {-0.5f, 0.5f, 0.0f}
    };

    VertexArrayObject VAOLeft{std::move(squareLeft), {0, 1, 2}};
    VertexArrayObject VAORight{std::move(squareRight), {0, 1, 2}};
    // create VAO at pos 1
    vaos.push_back(std::move(VAOLeft));
    vaos.push_back(std::move(VAORight));
}

Renderer::Renderer() :
    exeLocation(std::filesystem::current_path().string())
{}
