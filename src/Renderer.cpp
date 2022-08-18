//
// Created by sande on 14/08/2022.
//

#include <cassert>
#include "Renderer.h"
#include "Shader.h"
#include "Texture.h"
#include "ext/matrix_transform.hpp"

#define VertexShader(name) (exeLocation + "/shaders/vertex/" + (name) + ".glsl")
#define FragmentShader(name) (exeLocation + "/shaders/fragment/" + (name) + ".glsl")

void Renderer::render() {
    assert(this->window != nullptr);
    assert(!shaderPrograms.empty());

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::mat4 viewMatrix = camera.getViewAtMatrix();

    int width, height;
    glfwGetWindowSize(window, &width, &height);

    glm::mat4 perspectiveProjs = glm::perspective(
            glm::radians(45.0f),
            float(width)/float(height),
            0.1f,
            100.f);

    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    shaderPrograms[0].bind();
    vaos[0].bind();

    std::vector<glm::vec3> cubes{
            glm::vec3( 0.0f,  0.0f,  0.0f),
            glm::vec3( 2.0f,  5.0f, -15.0f),
            glm::vec3(-1.5f, -2.2f, -2.5f),
            glm::vec3(-3.8f, -2.0f, -12.3f),
            glm::vec3( 2.4f, -0.4f, -3.5f),
            glm::vec3(-1.7f,  3.0f, -7.5f),
            glm::vec3( 1.3f, -2.0f, -2.5f),
            glm::vec3( 1.5f,  2.0f, -2.5f),
            glm::vec3( 1.5f,  0.2f, -1.5f),
            glm::vec3(-1.3f,  1.0f, -1.5f)
    };

    for (auto const & location: cubes)
    {
        glm::mat4 modelMatrix = glm::mat4(1.0f);
        modelMatrix = glm::translate(modelMatrix, location);
        modelMatrix = glm::rotate(modelMatrix, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));

        shaderPrograms[0].setUniform("modelMatrix", modelMatrix);
        shaderPrograms[0].setUniform("viewMatrix", viewMatrix);
        shaderPrograms[0].setUniform("perspectiveProjection", perspectiveProjs);
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }

    glfwPollEvents();
    glfwSwapBuffers(window);
}

void Renderer::loadModels() {
    // Load Shader Program
    ShaderProgram shader(VertexShader("basicVertexShader"), FragmentShader("basicFragmentShader"));
    shader.setTextureN(0, "container","textures/container.jpg");
    shader.setTextureN(1, "wall","textures/wall.jpg");

    shaderPrograms.push_back(std::move(shader));

    // Setup Triangle

    std::vector<vertexTextureData> squareLeft{
            {{-0.5f, -0.5f, -0.5f},  {0.0f, 0.0f}},
            {{ 0.5f, -0.5f, -0.5f},  {1.0f, 0.0f}},
            {{ 0.5f,  0.5f, -0.5f},  {1.0f, 1.0f}},
            {{ 0.5f,  0.5f, -0.5f},  {1.0f, 1.0f}},
            {{-0.5f,  0.5f, -0.5f},  {0.0f, 1.0f}},
            {{-0.5f, -0.5f, -0.5f},  {0.0f, 0.0f}},

            {{-0.5f, -0.5f,  0.5f},  {0.0f, 0.0f}},
            {{ 0.5f, -0.5f,  0.5f},  {1.0f, 0.0f}},
            {{ 0.5f,  0.5f,  0.5f},  {1.0f, 1.0f}},
            {{ 0.5f,  0.5f,  0.5f},  {1.0f, 1.0f}},
            {{-0.5f,  0.5f,  0.5f},  {0.0f, 1.0f}},
            {{-0.5f, -0.5f,  0.5f},  {0.0f, 0.0f}},

            {{-0.5f,  0.5f,  0.5f},  {1.0f, 0.0f}},
            {{-0.5f,  0.5f, -0.5f},  {1.0f, 1.0f}},
            {{-0.5f, -0.5f, -0.5f},  {0.0f, 1.0f}},
            {{-0.5f, -0.5f, -0.5f},  {0.0f, 1.0f}},
            {{-0.5f, -0.5f,  0.5f},  {0.0f, 0.0f}},
            {{-0.5f,  0.5f,  0.5f},  {1.0f, 0.0f}},

            {{ 0.5f,  0.5f,  0.5f},  {1.0f, 0.0f}},
            {{ 0.5f,  0.5f, -0.5f},  {1.0f, 1.0f}},
            {{ 0.5f, -0.5f, -0.5f},  {0.0f, 1.0f}},
            {{ 0.5f, -0.5f, -0.5f},  {0.0f, 1.0f}},
            {{ 0.5f, -0.5f,  0.5f},  {0.0f, 0.0f}},
            {{ 0.5f,  0.5f,  0.5f},  {1.0f, 0.0f}},

            {{-0.5f, -0.5f, -0.5f},  {0.0f, 1.0f}},
            {{ 0.5f, -0.5f, -0.5f},  {1.0f, 1.0f}},
            {{ 0.5f, -0.5f,  0.5f},  {1.0f, 0.0f}},
            {{ 0.5f, -0.5f,  0.5f},  {1.0f, 0.0f}},
            {{-0.5f, -0.5f,  0.5f},  {0.0f, 0.0f}},
            {{-0.5f, -0.5f, -0.5f},  {0.0f, 1.0f}},

            {{-0.5f,  0.5f, -0.5f},  {0.0f, 1.0f}},
            {{ 0.5f,  0.5f, -0.5f},  {1.0f, 1.0f}},
            {{ 0.5f,  0.5f,  0.5f},  {1.0f, 0.0f}},
            {{ 0.5f,  0.5f,  0.5f},  {1.0f, 1.0f}},
            {{-0.5f,  0.5f,  0.5f},  {0.0f, 1.0f}},
            {{-0.5f,  0.5f, -0.5f},  {1.0f, 0.0f}}
    };

    VertexArrayObject VAOLeft{std::move(squareLeft)};


    // create VAO at pos 1
    vaos.push_back(std::move(VAOLeft));
}

Renderer::Renderer() :
    exeLocation(std::filesystem::current_path().string())
{}
