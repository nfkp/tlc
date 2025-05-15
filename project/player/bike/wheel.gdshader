shader_type spatial;

void vertex() {
	float l = length(VERTEX);
	const vec3 s = vec3(1.0, 3., 1.0) * 0.10;
	VERTEX *= 1. - l * step(l, 0.625) * s;
}

void fragment() {
	ALBEDO = vec3(0.07, 0.01, 0.01);
	ROUGHNESS = 0.5;
}
