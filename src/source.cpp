#include "register_types.h"
#include "header.h"
#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/project_settings.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void initialize_example_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	GDREGISTER_RUNTIME_CLASS(SunVoxGD);
}

void uninitialize_example_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT example_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

	init_obj.register_initializer(initialize_example_module);
	init_obj.register_terminator(uninitialize_example_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}

void SunVoxGD::_bind_methods() {
	ClassDB::bind_method(D_METHOD("SV_load"), &SunVoxGD::SV_load);
	ClassDB::bind_method(D_METHOD("SV_volume"), &SunVoxGD::SV_volume);
	ClassDB::bind_method(D_METHOD("SV_play"), &SunVoxGD::SV_play);
	ClassDB::bind_method(D_METHOD("SV_stop"), &SunVoxGD::SV_stop);
}

void SunVoxGD::_notification(int p_what) {
	// Prevents this from running in the editor, only during game mode. In Godot 4.3+ use Runtime classes.
	if (Engine::get_singleton()->is_editor_hint()) {
		return;
	}

	switch (p_what) {
	case NOTIFICATION_EXIT_TREE: { // Thread must be disposed (or "joined"), for portability.
		end_function();
	} break;
	}
}

void SunVoxGD::SV_load(String path) {
	sv_load( 0, ProjectSettings::get_singleton()->globalize_path(path).utf8().get_data() );
}

void SunVoxGD::SV_volume(const int level) {
	sv_volume( 0, level );
}

void SunVoxGD::SV_play() {
	sv_play( 0 );
}

void SunVoxGD::SV_stop() {
	sv_stop( 0 );
}

void SunVoxGD::end_function() {	
	sv_close_slot( 0 );
	sv_deinit();
	sv_unload_dll();
}

SunVoxGD::SunVoxGD() {
	if( !sv_load_dll() ) {
		int ver = sv_init( 0, 44100, 2, 0 );
    	if( ver >= 0 ) {
			int major = ( ver >> 16 ) & 255;
			int minor1 = ( ver >> 8 ) & 255;
			int minor2 = ( ver ) & 255;
			
			sv_open_slot( 0 );
		}
	}
	m_volume = 255;
}

SunVoxGD::~SunVoxGD() {
	
}