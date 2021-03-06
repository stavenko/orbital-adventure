#version 330 core

layout(location=0)in vec3 position;
layout(location=1)in vec3 normal;
layout(location=2)in vec2 uvAttr;


uniform mat4 modelViewProjection;
uniform mat4 northPoleToCameraRotation;


out vec2 uv;
out vec2 attrUV;
out vec4 pos;


float PI = 3.1415926;
void main(void){
    attrUV = uvAttr;

    pos = northPoleToCameraRotation * vec4(position, 1.0);
     
    float ang = mod(asin(pos.z) / PI + 1.5, 1.0);
    float lonAngle = atan(pos.y, pos.x);
    float lon = mod(atan(pos.y, pos.x) / (2*PI) + 1.0, 1.0);

    uv = vec2( lon, ang);


    gl_Position = modelViewProjection * pos;

    
}
