extends Node3D
var fullscreen : bool = false

func _ready() -> void:
	var screen_refresh_rate = DisplayServer.screen_get_refresh_rate() as int
	
	var fps : int = screen_refresh_rate
	Engine.max_fps = clamp(fps, 1, screen_refresh_rate)

func _unhandled_key_input(event: InputEvent) -> void:
	if event is InputEventKey:
		if event.pressed:
			match event.keycode:
				KEY_ESCAPE:
					get_tree().quit()
				KEY_F4:
					if fullscreen:
						DisplayServer.window_set_mode(DisplayServer.WINDOW_MODE_WINDOWED)
						fullscreen = false
					else:
						DisplayServer.window_set_mode(DisplayServer.WINDOW_MODE_EXCLUSIVE_FULLSCREEN)
						fullscreen = true
