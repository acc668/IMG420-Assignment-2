#include "enhanced_sprite2d.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void EnhancedSprite2D::_bind_methods() {
    // Bind properties (editor parameters)
    ClassDB::bind_method(D_METHOD("set_rotation_speed", "speed"), &EnhancedSprite2D::set_rotation_speed);
    ClassDB::bind_method(D_METHOD("get_rotation_speed"), &EnhancedSprite2D::get_rotation_speed);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "rotation_speed"), "set_rotation_speed", "get_rotation_speed");
    
    ClassDB::bind_method(D_METHOD("set_pulse_intensity", "intensity"), &EnhancedSprite2D::set_pulse_intensity);
    ClassDB::bind_method(D_METHOD("get_pulse_intensity"), &EnhancedSprite2D::get_pulse_intensity);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "pulse_intensity"), "set_pulse_intensity", "get_pulse_intensity");
    
    // Bind methods that can be called from GDScript/signals
    ClassDB::bind_method(D_METHOD("on_external_trigger"), &EnhancedSprite2D::on_external_trigger);
    ClassDB::bind_method(D_METHOD("start_rotation"), &EnhancedSprite2D::start_rotation);
    ClassDB::bind_method(D_METHOD("stop_rotation"), &EnhancedSprite2D::stop_rotation);
    ClassDB::bind_method(D_METHOD("start_pulse"), &EnhancedSprite2D::start_pulse);
    ClassDB::bind_method(D_METHOD("stop_pulse"), &EnhancedSprite2D::stop_pulse);
    
    // Register signal that will be emitted
    ADD_SIGNAL(MethodInfo("rotation_completed"));
}

EnhancedSprite2D::EnhancedSprite2D() {
    rotation_speed = 1.0f;
    is_rotating = true;
    pulse_intensity = 0.2f;
    is_pulsing = true;
    pulse_timer = 0.0f;
    total_rotation = 0.0f;
    
    UtilityFunctions::print("EnhancedSprite2D created!");
}

EnhancedSprite2D::~EnhancedSprite2D() {
}

void EnhancedSprite2D::_process(double delta) {
    // Feature 1: Auto-rotation
    if (is_rotating) {
        float rotation_delta = rotation_speed * delta;
        set_rotation(get_rotation() + rotation_delta);
        
        total_rotation += rotation_delta;
        
        // Emit signal when completing a full rotation (2π radians)
        if (total_rotation >= 6.28318f) {  // 2 * PI
            emit_signal("rotation_completed");
            total_rotation = 0.0f;
            UtilityFunctions::print("Rotation completed!");
        }
    }
    
    // Feature 2: Pulsing scale
    if (is_pulsing) {
        pulse_timer += delta;
        
        // Use sine wave for smooth pulsing effect
        float scale_factor = 1.0f + (Math::sin(pulse_timer * 3.0f) * pulse_intensity);
        set_scale(Vector2(scale_factor, scale_factor));
    }
}

// Property getters/setters
void EnhancedSprite2D::set_rotation_speed(float p_speed) {
    rotation_speed = p_speed;
}

float EnhancedSprite2D::get_rotation_speed() const {
    return rotation_speed;
}

void EnhancedSprite2D::set_pulse_intensity(float p_intensity) {
    pulse_intensity = p_intensity;
}

float EnhancedSprite2D::get_pulse_intensity() const {
    return pulse_intensity;
}

// Method triggered by external signal (Requirement 4)
void EnhancedSprite2D::on_external_trigger() {
    UtilityFunctions::print("EnhancedSprite2D received external trigger!");
    
    // Toggle rotation when triggered
    is_rotating = !is_rotating;
    
    if (is_rotating) {
        UtilityFunctions::print("Rotation started!");
    } else {
        UtilityFunctions::print("Rotation stopped!");
    }
}

// Control methods
void EnhancedSprite2D::start_rotation() {
    is_rotating = true;
}

void EnhancedSprite2D::stop_rotation() {
    is_rotating = false;
}

void EnhancedSprite2D::start_pulse() {
    is_pulsing = true;
}

void EnhancedSprite2D::stop_pulse() {
    is_pulsing = false;
}