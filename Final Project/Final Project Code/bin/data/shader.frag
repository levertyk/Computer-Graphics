#version 410
out vec4 outColor;
in vec2 TexCoord;
in vec2 fragUV;

uniform sampler2D tex; // color ramp
uniform int iter; // max iterations
// uniform vec2 offset
// uniform float scale

void main()
{
	vec2 z, c;
	c.x = 1.3333 * (TexCoord.x - 0.5); // * scale + offset.x			Unoptimized
	c.y = (TexCoord.y - 0.5); // * scale + offset.y						Unoptimized

	int i; // iteration
	z = c; // orignal location
	for (i=0; i < iter; i++) {
		float x = (z.x * z.x - z.y * z.y) + c.x;
		float y = (z.y * z.x + z.x * z.y) + c.y;

		if((x * x + y * y) > 4.0) break;
		z.x = x;
		z.y = y;
	}

	outColor = texture(tex, vec2((i == iter ? 0.0 : float(i)) / 100.0), 1); 

}