#include "register_types.h"
#include "enhanced_sprite.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_enhanced_sprite_module(ModuleInitializationLevel p_level)
{
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
    {
        return;
    }
    
    ClassDB::register_class<EnhancedSprite>();
}


void uninitialize_enhanced_sprite_module(ModuleInitializationLevel p_level)
{
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
    {
        return;
    }
}


extern "C"
{
  GDExtensionBool GDE_EXPORT enhanced_sprite_library_init(
      GDExtensionInterfaceGetProcAddress p_get_proc_address,
      GDExtensionClassLibraryPtr p_library,
      GDExtensionInitialization *r_initialization)
  {
      
      godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);
      
      init_obj.register_initializer(initialize_enhanced_sprite_module);
      init_obj.register_terminator(uninitialize_enhanced_sprite_module);
      init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);
      
      return init_obj.init();
  }
}
