//
// Created by sande on 14/08/2022.
//

#ifndef LEARNINGOPENGL_UTILS_H
#define LEARNINGOPENGL_UTILS_H
#pragma once
#include <filesystem>
#include <fstream>
#include <string>

namespace fs = std::filesystem;

inline std::string readFile(const fs::path& path)
{
    // Open the stream to 'lock' the file.
    std::ifstream f(path, std::ios::in | std::ios::binary);

    // Obtain the size of the file.
    const auto sz = fs::file_size(path);

    // Create a buffer.
    std::string result(sz, '\0');

    // Read the whole file into the buffer.
    f.read(result.data(), sz);

    return result;
}

template<typename T>
size_t vectorSizeOf(const typename std::vector<T>& vec)
{
    return sizeof(T) * vec.size();
}
#endif //LEARNINGOPENGL_UTILS_H
