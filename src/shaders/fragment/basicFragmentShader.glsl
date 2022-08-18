#version 430
out vec4 FragColor;

in vec2 texCor;

uniform sampler2D container;
uniform sampler2D wall;

void main() {
    const float borderWidth = 0.02f;

    if (texCor.x <= 1.0f && texCor.x >= 1.0f - borderWidth ||
            texCor.y <= 1.0f && texCor.y >=1.0f - borderWidth ||
            texCor.x >= 0.0f && texCor.x <= borderWidth ||
            texCor.y >= 0.0f && texCor.y <= borderWidth)
    {
        FragColor = vec4(0.0f, 0.0f, 1.0f, 1.0f);
    } else {
        FragColor = mix(texture(container, texCor), texture(wall, texCor), 0.5);
    }
}
