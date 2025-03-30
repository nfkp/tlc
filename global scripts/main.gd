extends Node3D
var fullscreen : bool = false

func _ready() -> void:
	Engine.max_fps = DisplayServer.screen_get_refresh_rate() as int

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
