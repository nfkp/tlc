extends SunVoxGD

var time : float = 0.0
var ok : bool = false

func _ready() -> void:
	SV_load("res://music/test.sunvox")
	SV_play()

func _process(delta: float) -> void:
	time += delta
	if time >= 5. && ok == false:
		SV_stop()
		ok = true
