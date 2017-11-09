#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 textureCoord;

out vec2 passTextureCoord;

uniform mat4 translate;

void main(void){
	gl_Position = translate * vec4 (position, 1.0f);
	passTextureCoord = textureCoord;
}