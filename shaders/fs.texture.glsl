#version 330 core

in vec2 passTextureCoord;

out vec4 outColor;

uniform sampler2D textureSampler;

void main(void) {
	outColor = texture (textureSampler, passTextureCoord);
}