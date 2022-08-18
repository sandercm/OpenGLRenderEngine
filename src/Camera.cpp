//
// Created by sande on 18/08/2022.
//

#include "Camera.h"
#include "geometric.hpp"
#include "ext/matrix_transform.hpp"

glm::vec3 Camera::getCameraDirection() const {
    return glm::normalize(cameraPosition - cameraTarget);
}

glm::vec3 Camera::getCameraRight() const {
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    return glm::normalize(glm::cross(up, getCameraDirection()));
}

glm::mat4 Camera::getViewAtMatrix() const {
    return glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp);
}

void Camera::moveForward() {
    cameraPosition += getCameraSpeed() * cameraFront;
}

void Camera::moveBackwards() {
    cameraPosition -= getCameraSpeed() * cameraFront;
}

void Camera::moveLeft() {
    cameraPosition -= glm::normalize(glm::cross(cameraFront, cameraUp)) * getCameraSpeed();
}

void Camera::moveRight() {
    cameraPosition += glm::normalize(glm::cross(cameraFront, cameraUp)) * getCameraSpeed();
}

float Camera::getCameraSpeed() {
    extern float deltaTime;
    return 4.5f * deltaTime;
}

void Camera::onMouseMovement(double xpos, double ypos) {
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw   += xoffset;
    pitch += yoffset;

    if(pitch > 89.0f)
        pitch = 89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(direction);
}
