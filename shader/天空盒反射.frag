#version 330 core
in vec3 Normal;
in vec3 Position;
out vec4 color;

uniform vec3 cameraPos;
uniform samplerCube skybox;

void main()
{
    float ratio = 1.0/1.52;
    vec3 I = normalize(Position - cameraPos);
    if((gl_FragCoord.x < 650&&gl_FragCoord.y<450)||(gl_FragCoord.x > 650&&gl_FragCoord.y > 450)){
    	vec3 R = reflect(I, normalize(Normal));
    	color = texture(skybox, R);
    	}

    else if((gl_FragCoord.x < 650&&gl_FragCoord.y>450)||(gl_FragCoord.x > 650&&gl_FragCoord.y < 450)){
    	vec3 R = refract(I, normalize(Normal) ,ratio);
   	    color = texture(skybox, R);
   	    }
}