extends MeshInstance3D

@onready var tex := preload("res://highway/meshes/highway_second_highway_tex.png")
@onready var mat := ShaderMaterial.new()

func _ready() -> void:
	mat.set_shader(preload("res://highway/meshes/road.gdshader"))
	mat.set_shader_parameter("tex", tex)
	mesh.surface_set_material(0, mat)
