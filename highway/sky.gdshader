shader_type sky;

#define RANDOM_SINLESS
#define RANDOM_SCALE vec4(.1031, .1030, .0973, .1099)

float random(in vec3 pos) {
#ifdef RANDOM_SINLESS
    pos  = fract(pos * RANDOM_SCALE.xyz);
    pos += dot(pos, pos.zyx + 31.32);
    return fract((pos.x + pos.y) * pos.z);
#else
    return fract(sin(dot(pos.xyz, vec3(70.9898, 78.233, 32.4355))) * 43758.5453123);
#endif
}

void sky() {
	vec3 e = EYEDIR.xyz;
	float r = step(random(e), 0.0001) * 0.3;
	r = r * clamp(random(e), 0.6, 1.);
	COLOR = vec3(r);
}
