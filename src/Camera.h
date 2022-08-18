//
// Created by sande on 18/08/2022.
//

#ifndef LEARNINGOPENGL_CAMERA_H
#define LEARNINGOPENGL_CAMERA_H


#include "vec3.hpp"
#include "mat4x4.hpp"

class Camera {
public:
    Camera() = default;

    void moveForward();
    void moveLeft();
    void moveRight();
    void moveBackwards();
    void onMouseMovement(double xpos, double ypos);

    [[nodiscard]] static float getCameraSpeed() ;

    [[nodiscard]] glm::vec3 getCameraDirection() const;
    [[nodiscard]] glm::vec3 getCameraRight() const;
    [[nodiscard]] glm::mat4 getViewAtMatrix() const;
    glm::vec3 cameraPosition = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    float yaw = -90.0f;
    float pitch = 0.0f;
    bool firstMouse = true;
    float lastX{0};
    float lastY{0};
};


#endif //LEARNINGOPENGL_CAMERA_H
