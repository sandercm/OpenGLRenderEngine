cmake_minimum_required(VERSION 3.23)
project(LearningOpenGL)

add_subdirectory(include/GLFW)
include_directories(include/GLFW/include include/linalg)

add_subdirectory(include/GLAD)

set(CMAKE_CXX_STANDARD 20)

add_executable(LearningOpenGL
        main.cpp
        Window.cpp
        Window.h
        Renderer.cpp
        Renderer.h
        include/linalg/linalg.h
        utils.h
        Shader.cpp
        Shader.h
        ShaderProgram.cpp
        ShaderProgram.h VertexArrayObject.cpp VertexArrayObject.h)

add_custom_target(copy_assets COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/shaders ${CMAKE_CURRENT_BINARY_DIR}/shaders)
add_dependencies(LearningOpenGL copy_assets)
target_link_libraries(LearningOpenGL glfw ${GLFW_LIBRARIES} glad)
