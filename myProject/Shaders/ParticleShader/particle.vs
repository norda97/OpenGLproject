#version 430      
layout (location = 0) in vec2 vertexPosition;


layout (location = 1) uniform mat4 worldMatrix;                           
layout (location = 2) uniform mat4  projViewMatrix;   
                                                             

void main()   
{                
    fragPos = (worldMatrix * vec4(vertexPosition, 1.0)).xyz;

    gl_Position = projViewMatrix * vec4(fragPos, 1.0); 
}     