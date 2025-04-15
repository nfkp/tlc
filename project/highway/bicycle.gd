extends RigidBody3D

func _process(delta: float) -> void:
	apply_central_force(Vector3(20., 0., 0.))
