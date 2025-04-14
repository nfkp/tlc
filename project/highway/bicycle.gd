extends VehicleBody3D

var time : float = 0;
@onready var center : Vector3 = get_center_of_mass()

func _process(delta: float) -> void:
	time += delta
	set_center_of_mass(center + Vector3(sin(time * 2.) * 0.1, 0., 0.))
