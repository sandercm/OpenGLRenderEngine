cmake_minimum_required(VERSION 3.23)
project(LearningOpenGL)

add_subdirectory(include/GLFW)

include_directories(include/GLFW/include include/linalg include/glm)

add_subdirectory(include/GLAD)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(include/glm)

add_executable(LearningOpenGL
        src/main.cpp
        src/Window.cpp
        src/Window.h
        src/Renderer.cpp
        src/Renderer.h
        src/utils.h
        src/Shader.cpp
        src/Shader.h
        src/ShaderProgram.cpp
        src/ShaderProgram.h
        src/VertexArrayObject.cpp
        src/VertexArrayObject.h
        src/Texture.cpp
        src/Texture.h
        src/stb_image.cpp
        src/stb_image.h
        src/textures/wall.jpg src/Camera.cpp src/Camera.h)

add_custom_target(copy_assets COMMAND ${CMAKE_COMMAND} -E copy_directory ../src/shaders ${CMAKE_CURRENT_BINARY_DIR}/shaders)
add_dependencies(LearningOpenGL copy_assets)
add_custom_target(copy_textures COMMAND ${CMAKE_COMMAND} -E copy_directory ../src/textures ${CMAKE_CURRENT_BINARY_DIR}/textures)
add_dependencies(LearningOpenGL copy_textures)
target_link_libraries(LearningOpenGL glfw ${GLFW_LIBRARIES} glad glm)
