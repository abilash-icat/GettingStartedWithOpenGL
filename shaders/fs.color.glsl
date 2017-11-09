#version 330 core
in vec3 vsColor;

out vec4 out_Color;

void main()
{
	out_Color=vec4(vsColor, 1.0f);
}