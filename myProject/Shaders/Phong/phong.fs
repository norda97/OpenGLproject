#version 430  
                                      
in vec3 fragPos;
in vec3 fragNormal;
in vec2 fragUV;

uniform sampler2D tex;
layout (location = 5) uniform vec3 camPos;   
layout (location = 6) uniform vec3 lightPos; 

layout (std140) uniform material
{ 
    vec4 Ka_Ns;
    vec4 Kd_d;
    vec4 Ks;
};

out vec4 fragmentColor;                
                                                    
void main()                                         
{  
    vec3 albedo = texture(tex, fragUV).xyz;

    //Ambient
    vec3 ambient = Ka_Ns.rgb * albedo;

    //diffuse
    vec3 lightDir = normalize(lightPos - fragPos);
    vec3 normal = normalize(fragNormal);
    float diff = max(dot(lightDir, normal), 0.0);     
    vec3 diffuse = Kd_d.rgb * albedo * diff;

    //specular
    vec3 viewDir = normalize(camPos - fragPos);
    vec3 reflectDir = reflect(-viewDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), Ka_Ns.w);
    vec3 specular = spec * Ks.rgb * diff;

    fragmentColor = vec4(diffuse + ambient + specular, 1.0f);                 
}                                                   