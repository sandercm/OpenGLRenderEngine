//
// Created by sande on 15/08/2022.
//

#ifndef LEARNINGOPENGL_VERTEXARRAYOBJECT_H
#define LEARNINGOPENGL_VERTEXARRAYOBJECT_H
#include <vector>
#include "glm.hpp"
#include "vec3.hpp"
#include "vec2.hpp"

using namespace glm;

struct vertexColorData {
    vec3 location;
    vec3 color;
};

struct vertexTextureData {
    vec3 location;
    vec2 textureCor;
};

struct vertexColorTextureData {
    vec3 location;
    vec3 color;
    vec2 textureCor;
};

class VertexArrayObject {
public:
    VertexArrayObject(std::vector<vec3> &&vertex_array_buffer, std::vector<unsigned int> &&element_array_buffer);
    VertexArrayObject(std::vector<vertexColorData> &&vertex_array_buffer, std::vector<unsigned int> &&element_array_buffer);
    VertexArrayObject(std::vector<vertexTextureData> &&vertex_array_buffer);
    VertexArrayObject(std::vector<vertexColorTextureData> &&vertex_array_buffer, std::vector<unsigned int> &&element_array_buffer);
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
