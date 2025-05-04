extends MeshInstance3D

@onready var mat = ShaderMaterial.new()

func _ready() -> void:
	mat.set_shader(preload("res://highway/meshes/road.gdshader"))
