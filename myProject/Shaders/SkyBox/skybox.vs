#version 430                                       
                                                    
layout (location = 0) in vec3 vertexPosition;

out vec3 texCoord;

layout (location = 1) uniform mat4 viewMatrix;                           
layout (location = 2) uniform mat4 projMatrix;                                   

void main()   
{                
    texCoord = vertexPosition;
    gl_Position = projMatrix * viewMatrix * vec4(vertexPosition, 1.0f); 
}                                                   