extends MeshInstance3D

func _ready() -> void:
	var mat : ShaderMaterial = mesh.surface_get_material(0)
	mat.set_shader(preload("res://highway/boat.gdshader"))
	var tex := preload("res://boat_boat1.png")
	mat.set_shader_parameter("tex", tex)
