#version 450 core
in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

out vec4 FragColor;

uniform sampler2D texture_diffuse;

void main() {
    vec3 lightColor = vec3(1.0);
    vec3 lightPos = vec3(0.0, 0.0, 10.0);
    vec3 viewPos = vec3(0.0, 0.0, 5.0);

    vec3 ambient = 0.1 * lightColor;
    
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    vec3 result = (ambient + diffuse) * texture(texture_diffuse, TexCoords).rgb;
    FragColor = vec4(result, 1.0);
}
