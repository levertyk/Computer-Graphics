#version 410
layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 texCoord;

out vec2 TexCoord;
uniform mat4 mvp;
uniform vec2 offset;
uniform float scale;
 
void main()
{
	TexCoord = texCoord * vec2(scale) + offset; // Optimized texture mapping
    gl_Position = mvp * vec4(pos, 1.0);
}