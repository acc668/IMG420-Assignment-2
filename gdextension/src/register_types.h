#ifndef MY_EXTENSION_REGISTER_TYPES_H
#define MY_EXTENSION_REGISTER_TYPES_H

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void initialize_my_extension_module(ModuleInitializationLevel p_level);
void uninitialize_my_extension_module(ModuleInitializationLevel p_level);

#endif