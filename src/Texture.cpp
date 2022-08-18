//
// Created by sande on 16/08/2022.
//

#include <cassert>
#include "Texture.h"
#include "stb_image.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <vector>

Texture::Texture(const std::string& filename) {
    int width, height, nrChannels;
    unsigned char* rawData = stbi_load(filename.c_str(), &width, &height, &nrChannels, 0);
    std::vector<unsigned char> data(rawData, rawData + width*height*nrChannels);

    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    if (!data.empty())
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, &data[0]);
        glGenerateMipmap(GL_TEXTURE_2D);
        _id = texture;
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
}

unsigned int Texture::getID() const {
    assert(_id != 0);
    return _id;
}

void Texture::freeMemory() const {
    if(_id != 0)
    {
        unsigned int id[1];
        id[0] = _id;
        glDeleteTextures(1, id);
    } else
    {
        std::cout << "trying to delete texture with _id 0" << std::endl;
    }
}
