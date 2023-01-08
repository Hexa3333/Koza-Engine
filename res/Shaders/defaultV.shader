#version 400 core
layout (location = 0) in vec3 mPos;
layout (location = 1) in vec2 mTex;

out vec2 TextureCoordinates;

uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;


void main()
{
   gl_Position = projection * view * model * vec4(mPos, 1.0);
   TextureCoordinates = mTex;
}