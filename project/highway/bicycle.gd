extends Node3D

var w : float = 0
var ad : float = 0
@onready var handle = get_node("meshes/handle")
@onready var meshes = get_node("meshes")

var x : float = 0
var time : float = 0
var s : float = 0
var g : float = 0
var b : float = 0
var p : Array[float] = [-0.013, 2.3, 0.22]

func _process(delta: float) -> void:
	time += delta
	w = Input.is_action_pressed("w") as float
	ad = (Input.is_action_pressed("a") as float) - (Input.is_action_pressed("d") as float)
	ad *= 0.25
	x += (ad-x) * delta
	x = clampf(x, -0.25, 0.25)
	g -= w * delta
	g -= g * delta * 0.3
	translate(Vector3(0, 0, g * delta))
	#x += g * p[2] * sign(x) * delta
	meshes.translate_object_local(Vector3(0,0,0.599))
	meshes.rotate_object_local(Vector3(1,0,0), p[0] * abs(x) - meshes.get_rotation().x)
	meshes.translate_object_local(Vector3(0,0,-0.599))
	rotate_y(x* delta * -g * p[1])
	
	meshes.rotate_object_local(Vector3(0, 0, 1), x - meshes.get_rotation().z)
	handle.rotate_object_local(Vector3(0, 1, 0), x * 0.5 - handle.get_rotation().y)


func _on_h_slider_value_changed(value: float) -> void:
	p[1] = value
	print(p[1])
