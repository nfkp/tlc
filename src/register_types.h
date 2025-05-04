#ifndef GDEXAMPLE_REGISTER_TYPES_H
#define GDEXAMPLE_REGISTER_TYPES_H

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void initialize_sunvox_module(ModuleInitializationLevel p_level);
void uninitialize_sunvox_module(ModuleInitializationLevel p_level);
void initialize_bicycle_module(ModuleInitializationLevel p_level);
void uninitialize_bicycle_module(ModuleInitializationLevel p_level);
void initialize_types(ModuleInitializationLevel p_level);
void uninitialize_types(ModuleInitializationLevel p_level);

#endif // GDEXAMPLE_REGISTER_TYPES_H