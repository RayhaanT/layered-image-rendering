#version 400 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColour;
layout (location = 2) in vec2 aTexCoord;

out vec3 ourColour;
out vec2 texCoords;

void main()
{
    gl_Position = vec4(aPos, 1);
    ourColour = aColour;
    texCoords = aTexCoord;
}