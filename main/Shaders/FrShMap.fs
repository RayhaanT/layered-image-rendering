#version 400 core

out vec4 FragColour;

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
};

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 Normal;
in vec3 FragPos;
in vec3 LightPos;
in vec2 TexCoords;

uniform vec3 lightColor;
uniform Material material;
uniform Light light;

void main()
{
    //Ambient
    vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));

    //Diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(LightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));

    //Specular
    vec3 viewPos = vec3(0.0, 0.0, 0.0);
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));

    FragColour = vec4(ambient + diffuse + specular, 1);
}