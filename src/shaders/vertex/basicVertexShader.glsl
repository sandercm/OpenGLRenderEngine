#version 430 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 textureCor;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 perspectiveProjection;

out vec3 vertexColor;
out vec2 texCor;

void main()
{
    gl_Position = perspectiveProjection * viewMatrix * modelMatrix * vec4(aPos, 1.0);
    texCor = textureCor;
}