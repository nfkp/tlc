#include "include/bicycle.h"

#include <godot_cpp/classes/engine.hpp>

using namespace godot;

void Bicycle::_bind_methods() {

}

void Bicycle::_notification(int p_what) {
	if (Engine::get_singleton()->is_editor_hint()) {
		return;
	}

	switch (p_what) {
	case NOTIFICATION_PROCESS: {
		time += delta;
		
	} break;
	}
}

void Bicycle::_process(double p_delta) {
	delta = p_delta;
}