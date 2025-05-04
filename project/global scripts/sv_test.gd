extends SunVoxGD

func _ready() -> void:
	sv_load("res://music/SV_01.sunvox")
	sv_volume(127)
	sv_play()
	
