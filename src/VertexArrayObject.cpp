//
// Created by sande on 15/08/2022.
//

#include "VertexArrayObject.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <cassert>
#include "utils.h"
#include "glm.hpp"
#include "vec3.hpp"

unsigned int createVAO(int amountOfBuffers = 1)
{
    unsigned int VAO;
    glGenVertexArrays(amountOfBuffers, &VAO);
    glBindVertexArray(VAO);
    return VAO;
}

template<typename T>
unsigned int bindVertexData(std::vector<T>& array_buffer)
{
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vectorSizeOf(array_buffer), &array_buffer[0], GL_STATIC_DRAW);
    return VBO;
}

unsigned int bindElementArrayBuffer(std::vector<unsigned int>& element_array_buffer)
{
    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, vectorSizeOf(element_array_buffer), &element_array_buffer[0], GL_STATIC_DRAW);
    return EBO;
}

// use this constructor if no color data is present
VertexArrayObject::VertexArrayObject(
        std::vector<vec3>&& array_buffer,
        std::vector<unsigned int>&& element_array_buffer
        ) :
    VAO{0},
    VBO{0},
    EBO{0}
{
    // create VAO object
    VAO = createVAO();
    // create and bind vertex position data (the 3D coordinates)
    VBO = bindVertexData(array_buffer);
    // create and bind the index array to draw these coordinates
    EBO = bindElementArrayBuffer(element_array_buffer);

    // set the in params of the shaders
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vec3), nullptr);
    glEnableVertexAttribArray(0);
}

VertexArrayObject::VertexArrayObject(std::vector<vertexTextureData> &&vertex_array_buffer) {
    // create VAO object
    VAO = createVAO();
    // create and bind vertex position data (the 3D coordinates)
    VBO = bindVertexData(vertex_array_buffer);

    // set the in params of the shaders
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertexTextureData), nullptr);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertexTextureData), (void*)(sizeof(vec3)));
    glEnableVertexAttribArray(1);
}

// use this constructor if using color data in array
VertexArrayObject::VertexArrayObject(std::vector<vertexColorData> &&vertex_array_buffer,
                                     std::vector<unsigned int> &&element_array_buffer) :
        VAO{0},
        VBO{0},
        EBO{0}
{
    // create VAO object
    VAO = createVAO();
    // create and bind vertex position data (the 3D coordinates)
    VBO = bindVertexData(vertex_array_buffer);
    // create and bind the index array to draw these coordinates
    EBO = bindElementArrayBuffer(element_array_buffer);

    // set the in params of the shaders
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertexColorData), nullptr);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertexColorData), (void*)(sizeof(vec3)));
    glEnableVertexAttribArray(1);
}

VertexArrayObject::VertexArrayObject(std::vector<vertexColorTextureData> &&vertex_array_buffer,
                                     std::vector<unsigned int> &&element_array_buffer) :
        VAO{0},
        VBO{0},
        EBO{0}
{
    // create VAO object
    VAO = createVAO();
    // create and bind vertex position data (the 3D coordinates)
    VBO = bindVertexData(vertex_array_buffer);
    // create and bind the index array to draw these coordinates
    EBO = bindElementArrayBuffer(element_array_buffer);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertexColorTextureData), nullptr);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertexColorTextureData), (void*)(sizeof(vec3)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(vertexColorTextureData), (void*)(sizeof(vec3) * 2));
    glEnableVertexAttribArray(2);
}

void VertexArrayObject::bind() {
    assert(VAO != 0);
    glBindVertexArray(VAO);
}

VertexArrayObject::~VertexArrayObject() {
    if (VAO != 0)
    {
        unsigned int buffers[2];
        buffers[0] = VBO;
        buffers[1] = EBO;
        glDeleteBuffers(1, buffers);
        unsigned int vaos[1];
        vaos[0] = VAO;
        glDeleteVertexArrays(1, vaos);
    }
}
