#version 400 core
layout (location = 0) in vec3 mPos;
layout (location = 1) in vec2 mTex;

out vec2 TextureCoordinates;

uniform mat4 model;

void main()
{
   gl_Position = model * vec4(mPos, 1.0);
   TextureCoordinates = mTex;
}