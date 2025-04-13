extends SunVoxGD

var time : float = 0.0
var ok : bool = false

func _ready() -> void:
	sv_load("res://music/SV_01.sunvox")
	sv_lock_slot()
	sv_pattern_mute("M_01", 0)
	sv_pattern_mute("M_02", 0)
	sv_unlock_slot()
	sv_play()

func _process(delta: float) -> void:
	time += delta
	if time >= 10. && ok == false:
		sv_stop()
		ok = true
