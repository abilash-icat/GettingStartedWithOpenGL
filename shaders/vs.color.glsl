#version 330 core
layout (location=0) in vec3 position;

out vec3 vsColor;
uniform float elapsedTime;

void main()
{
	gl_Position = vec4(position, 1.0f);
	vsColor = vec3(position.x * 2, (position.x + position.y) * sin( elapsedTime), tan(elapsedTime));
	//vsColor = vec3(1.0, 0.0, 0.0);
}