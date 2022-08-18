//
// Created by sande on 16/08/2022.
//

#ifndef LEARNINGOPENGL_TEXTURE_H
#define LEARNINGOPENGL_TEXTURE_H


#include <string>

class Texture {
public:
    Texture() = default;
    explicit Texture(const std::string& textureName);
public:
    [[nodiscard]] unsigned int getID() const;
    void freeMemory() const;
private:
    unsigned int _id{0};
};


#endif //LEARNINGOPENGL_TEXTURE_H
