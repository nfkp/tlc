shader_type spatial;

void vertex() {
	// Called for every vertex the material is visible on.
}

void fragment() {
	ALBEDO = vec3(step(1. - UV.y, 0.51));
}

//void light() {
//	// Called for every pixel for every light affecting the material.
//	// Uncomment to replace the default light processing function with this one.
//}
