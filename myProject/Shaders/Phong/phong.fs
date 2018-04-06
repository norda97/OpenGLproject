#version 430  
                                      
in vec3 fragPos;
in vec3 fragNormal;
in vec2 fragUV;

uniform sampler2D tex;

out vec4 fragmentColor;                
                                                    
void main()                                         
{  
    //diffuse
    float diffuse = max(dot(vec3(0.0f, 0.0f, -1.0f), normalize(fragNormal)), 0.0);     
    
    vec3 ambient = vec3(0.2f, 0.2f, 0.2f);    
    vec3 albedo = texture(tex, fragUV).xyz;

    fragmentColor = vec4(albedo * ambient + albedo * diffuse, 1.0f);               
}                                                   