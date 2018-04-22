#version 430                                       
                                                    
layout (location = 0) in vec3 vertexPosition;
layout (location = 1) in vec3 vertexNormal;
layout (location = 2) in vec2 vertexUV;

out vec3 fragPos;
out vec3 fragNormal;
out vec2 fragUV;

layout (location = 3) uniform mat4 worldMatrix;                           
layout (location = 4) uniform mat4  projViewMatrix;   
                                                             

void main()   
{                
    fragPos = (worldMatrix * vec4(vertexPosition, 1.0)).xyz;
    fragNormal = (worldMatrix * vec4(vertexNormal, 1.0)).xyz;
    fragUV = vertexUV;
    gl_Position = projViewMatrix * vec4(fragPos, 1.0); 
}                                                   