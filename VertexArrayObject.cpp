//
// Created by sande on 15/08/2022.
//

#include "VertexArrayObject.h"
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <cassert>
#include "utils.h"

VertexArrayObject::VertexArrayObject(
        std::vector<float3>&& array_buffer,
        std::vector<unsigned int>&& element_array_buffer
        ) :
    VAO{0},
    VBO{0},
    EBO{0}
{
    // create VAO object
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // create and bind vertex position data (the 3D coordinates)
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vectorSizeOf(array_buffer), &array_buffer[0], GL_STATIC_DRAW);

    // create and bind the index array to draw these coordinates
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, vectorSizeOf(element_array_buffer), &element_array_buffer[0], GL_STATIC_DRAW);

    // set the in params of the shaders
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float3), nullptr);
    glEnableVertexAttribArray(0);
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
