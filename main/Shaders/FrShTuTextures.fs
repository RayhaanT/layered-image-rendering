#version 400 core
out vec4 FragColour;

in vec3 ourColour;
in vec2 texCoords;

uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;

void main()
{
    FragColour = mix(texture(ourTexture1, texCoords), texture(ourTexture2, texCoords), 0.2) * vec4(ourColour, 1.0f);
}