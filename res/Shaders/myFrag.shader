#version 400 core
out vec4 FragColor;

in vec2 TextureCoordinates;

uniform sampler2D tex0;

void main()
{
	FragColor = texture(tex0, TextureCoordinates);
}