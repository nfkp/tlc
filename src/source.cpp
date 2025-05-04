#include "sokautil.h"
#include "sunvoxgd.h"
#include "bicycle.h"
#include "register_types.h"

#include <stdio.h>
#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/os.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/variant/builtin_types.hpp>

using namespace godot;


void VelocityLogic::increase_by(double value, double delta) {
	m_vel += value * delta;
	m_dist += m_vel * delta;
}

double VelocityLogic::get_velocity() {
	return m_vel;
}

double VelocityLogic::get_distance() {
	return m_dist;
}

Trigger::Trigger(double p_value, double precision = 0.01) {
	m_bool = false;
	value = p_value;
	m_precision = precision;
}
void Trigger::retrigger() {
	m_bool = true;
}

Trigger Trigger::operator+(double const& obj) {
	if (m_bool) [[unlikely]] {
		Trigger t(obj + value);
		m_bool = false;
		return t;
	}
	Trigger n(value);
	return n;
}
Trigger Trigger::operator-(double const& obj) {
	if (m_bool) [[unlikely]] {
		Trigger t(obj - value);
		m_bool = false;
		return t;
	}
	Trigger n(value);
	return n;
}
Trigger Trigger::operator*(double const& obj) {
	if (m_bool) [[unlikely]] {
		Trigger t(obj * value);
		m_bool = false;
		return t;
	}
	Trigger n(value);
	return n;
}
Trigger Trigger::operator/(double const& obj) {
	if (m_bool) [[unlikely]] {
		Trigger t(obj / value);
		m_bool = false;
		return t;
	}
	Trigger n(value);
	return n;
}


void initialize_sunvox_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	ClassDB::register_class<SunVoxGD>();
}

void uninitialize_sunvox_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

void initialize_bicycle_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	ClassDB::register_class<Bicycle>();
}
void uninitialize_bicycle_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

void initialize_types(ModuleInitializationLevel p_level) {
	initialize_sunvox_module(p_level);
	initialize_bicycle_module(p_level);
}

void uninitialize_types(ModuleInitializationLevel p_level) {
	uninitialize_sunvox_module(p_level);
	uninitialize_bicycle_module(p_level);
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT example_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

	init_obj.register_initializer(initialize_types);
	init_obj.register_terminator(uninitialize_types);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}

using namespace godot;

void SunVoxGD::_bind_methods() {
	ClassDB::bind_method(D_METHOD("sv_load"), &SunVoxGD::SV_load);
	ClassDB::bind_method(D_METHOD("sv_lock_slot"), &SunVoxGD::SV_lock_slot);
	ClassDB::bind_method(D_METHOD("sv_unlock_slot"), &SunVoxGD::SV_unlock_slot);
	ClassDB::bind_method(D_METHOD("sv_volume"), &SunVoxGD::SV_volume);
	ClassDB::bind_method(D_METHOD("sv_play"), &SunVoxGD::SV_play);
	ClassDB::bind_method(D_METHOD("sv_stop"), &SunVoxGD::SV_stop);
	ClassDB::bind_method(D_METHOD("sv_pattern_mute"), &SunVoxGD::SV_pattern_mute);
	ClassDB::bind_method(D_METHOD("sv_rewind"), &SunVoxGD::SV_rewind);
	ClassDB::bind_method(D_METHOD("sv_pause"), &SunVoxGD::SV_pause);
	ClassDB::bind_method(D_METHOD("sv_resume"), &SunVoxGD::SV_resume);
	ClassDB::bind_method(D_METHOD("sv_play_from_beginning"), &SunVoxGD::SV_play_from_beginning);
}

void SunVoxGD::_notification(int p_what) {
	if (Engine::get_singleton()->is_editor_hint()) {
		return;
	}

	switch (p_what) {
	case NOTIFICATION_EXIT_TREE: {
		end_function();
	} break;
	}
}

void SunVoxGD::SV_load(String path) { 
	String path_to = OS::get_singleton()->get_executable_path().get_base_dir() + "/music/" + path.get_file();
	const char* file_path = path_to.utf8().get_data();
	printf(file_path);
	sv_load( 0, file_path ); 
}
void SunVoxGD::SV_lock_slot() { sv_lock_slot( 0 ); }
void SunVoxGD::SV_unlock_slot() { sv_unlock_slot( 0 ); }
void SunVoxGD::SV_volume(const int level) { sv_volume( 0, level ); }
void SunVoxGD::SV_play() { sv_play( 0 ); }
void SunVoxGD::SV_stop() { sv_stop( 0 ); }
void SunVoxGD::SV_pattern_mute(String name, int mute) { sv_pattern_mute( 0, sv_find_pattern( 0, name.utf8().get_data() ), mute ); }
void SunVoxGD::SV_rewind(const int line_num) { sv_rewind( 0, line_num ); }
void SunVoxGD::SV_pause() { sv_pause( 0 ); }
void SunVoxGD::SV_resume() { sv_resume( 0 ); }
void SunVoxGD::SV_play_from_beginning() { sv_play_from_beginning( 0 ); }


void SunVoxGD::end_function() {	
	sv_close_slot( 0 );
	sv_deinit();
	sv_unload_dll();
}

SunVoxGD::SunVoxGD() {
	if( !sv_load_dll() ) {
		int ver = sv_init( 0, 44100, 2, 0 );
    	if( ver >= 0 ) {
			//int major = ( ver >> 16 ) & 255;
			//int minor1 = ( ver >> 8 ) & 255;
			//int minor2 = ( ver ) & 255;
			
			sv_open_slot( 0 );
		}
	}
}

//bicycle

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