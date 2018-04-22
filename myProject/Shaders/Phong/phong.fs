#version 430  
                                      
in vec3 fragPos;
in vec3 fragNormal;
in vec2 fragUV;

uniform sampler2D tex;
layout (location = 5) uniform vec3 camPos;   

layout (std140) uniform material
{ 
    vec4 Ka_Ns;
    vec4 Kd_d;
    vec4 Ks;
};

out vec4 fragmentColor;                
                                                    
void main()                                         
{  
    //diffuse
    float diffuse = max(dot(normalize(vec3(-10.0f, 6.0f, -10.0f) - fragPos), normalize(fragNormal)), 0.0);     
    float camDir = length(fragPos - camPos);
    vec3 ambient = vec3(1.0f, 0.2f, 0.2f);    
    vec3 albedo = texture(tex, fragUV).xyz;

    fragmentColor = vec4(Kd_d.rgb * diffuse, 1.0f);     
    //fragmentColor = vec4(albedo * ambient + albedo * diffuse, 1.0f);               
}                                                   