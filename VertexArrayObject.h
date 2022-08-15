//
// Created by sande on 15/08/2022.
//

#ifndef LEARNINGOPENGL_VERTEXARRAYOBJECT_H
#define LEARNINGOPENGL_VERTEXARRAYOBJECT_H
#include <vector>
#include "linalg.h"

using namespace linalg::aliases;

class VertexArrayObject {
public:
    VertexArrayObject(std::vector<float3> &&vertex_array_buffer, std::vector<unsigned int> &&element_array_buffer);
    VertexArrayObject(const VertexArrayObject& other) = delete; // don't allow copy
    VertexArrayObject(VertexArrayObject&& other)  noexcept :
        VAO(other.VAO),
        VBO(other.VBO),
        EBO(other.EBO)
    {
        other.VAO = 0;
        other.VBO = 0; // not strictly necessary
        other.EBO = 0; // not strictly necessary
    }
    VertexArrayObject& operator=(VertexArrayObject&& other) noexcept {
        if (&other != this){
            VAO = other.VAO;
            VBO = other.VBO;
            EBO = other.EBO;

            other.VAO = 0;
            other.VBO = 0;
            other.EBO = 0;
        }
        return *this;
    }
    ~VertexArrayObject();
    void bind();
private:
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
};


#endif //LEARNINGOPENGL_VERTEXARRAYOBJECT_H
