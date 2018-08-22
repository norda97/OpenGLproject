#version 430      

layout (location = 1) uniform vec3 color;

out vec4 fragmentColor; 


void main()                                         
{   
    fragmentColor = vec4(color, 1.0f);                 
}    