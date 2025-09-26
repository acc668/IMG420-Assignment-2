#include "enhanced_sprite.h"
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/input_event_mouse_button.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void EnhancedSprite::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_orbit_radius", "radius"), &EnhancedSprite::set_orbit_radius);
    ClassDB::bind_method(D_METHOD("get_orbit_radius"), &EnhancedSprite::get_orbit_radius);
    ClassDB::add_property("EnhancedSprite", 
        PropertyInfo(Variant::FLOAT, "orbit_radius", PROPERTY_HINT_RANGE, "0,500,1"), 
        "set_orbit_radius", "get_orbit_radius");
    
    ClassDB::bind_method(D_METHOD("set_orbit_speed", "speed"), &EnhancedSprite::set_orbit_speed);
    ClassDB::bind_method(D_METHOD("get_orbit_speed"), &EnhancedSprite::get_orbit_speed);
    ClassDB::add_property("EnhancedSprite", 
        PropertyInfo(Variant::FLOAT, "orbit_speed", PROPERTY_HINT_RANGE, "0,10,0.1"), 
        "set_orbit_speed", "get_orbit_speed");
    
    ClassDB::bind_method(D_METHOD("set_orbit_target", "target"), &EnhancedSprite::set_orbit_target);
    ClassDB::bind_method(D_METHOD("get_orbit_target"), &EnhancedSprite::get_orbit_target);
    ClassDB::add_property("EnhancedSprite", 
        PropertyInfo(Variant::OBJECT, "orbit_target", PROPERTY_HINT_NODE_TYPE, "Node2D"), 
        "set_orbit_target", "get_orbit_target");
    
    ClassDB::bind_method(D_METHOD("set_pulse_speed", "speed"), &EnhancedSprite::set_pulse_speed);
    ClassDB::bind_method(D_METHOD("get_pulse_speed"), &EnhancedSprite::get_pulse_speed);
    ClassDB::add_property("EnhancedSprite", 
        PropertyInfo(Variant::FLOAT, "pulse_speed", PROPERTY_HINT_RANGE, "0,5,0.1"), 
        "set_pulse_speed", "get_pulse_speed");
    
    ClassDB::bind_method(D_METHOD("set_pulse_min_scale", "min_scale"), &EnhancedSprite::set_pulse_min_scale);
    ClassDB::bind_method(D_METHOD("get_pulse_min_scale"), &EnhancedSprite::get_pulse_min_scale);
    ClassDB::add_property("EnhancedSprite", 
        PropertyInfo(Variant::FLOAT, "pulse_min_scale", PROPERTY_HINT_RANGE, "0.1,2,0.1"), 
        "set_pulse_min_scale", "get_pulse_min_scale");
    
    ClassDB::bind_method(D_METHOD("set_pulse_max_scale", "max_scale"), &EnhancedSprite::set_pulse_max_scale);
    ClassDB::bind_method(D_METHOD("get_pulse_max_scale"), &EnhancedSprite::get_pulse_max_scale);
    ClassDB::add_property("EnhancedSprite", 
        PropertyInfo(Variant::FLOAT, "pulse_max_scale", PROPERTY_HINT_RANGE, "0.1,3,0.1"), 
        "set_pulse_max_scale", "get_pulse_max_scale");
    

    ClassDB::bind_method(D_METHOD("start_orbiting"), &EnhancedSprite::start_orbiting);
    ClassDB::bind_method(D_METHOD("stop_orbiting"), &EnhancedSprite::stop_orbiting);
    ClassDB::bind_method(D_METHOD("start_pulsing"), &EnhancedSprite::start_pulsing);
    ClassDB::bind_method(D_METHOD("stop_pulsing"), &EnhancedSprite::stop_pulsing);
    

    ClassDB::bind_method(D_METHOD("play_animation"), &EnhancedSprite::play_animation);
    ClassDB::bind_method(D_METHOD("pause_animation"), &EnhancedSprite::pause_animation);
    ClassDB::bind_method(D_METHOD("stop_animation"), &EnhancedSprite::stop_animation);
    

    ClassDB::bind_method(D_METHOD("_on_game_event_triggered", "event_name"), &EnhancedSprite::_on_game_event_triggered);
    ClassDB::bind_method(D_METHOD("_on_player_interaction", "position"), &EnhancedSprite::_on_player_interaction);
    

    ADD_SIGNAL(MethodInfo("sprite_clicked"));
    ADD_SIGNAL(MethodInfo("animation_completed"));
    ADD_SIGNAL(MethodInfo("orbit_completed"));
}

EnhancedSprite::EnhancedSprite()
{
    orbit_radius = 100.0f;
    orbit_speed = 1.0f;
    orbit_target = nullptr;
    orbiting = false;
    orbit_angle = 0.0f;
    pulse_speed = 1.0f;
    pulse_min_scale = 0.8f;
    pulse_max_scale = 1.2f;
    pulsing = false;
    pulse_timer = 0.0f;
    is_animating = false;
}

EnhancedSprite::~EnhancedSprite()
{

}

void EnhancedSprite::_ready()
{

}

void EnhancedSprite::_process(double delta)
{
    if (Engine::get_singleton()->is_editor_hint())
    {
        return;
    }
    
    if (orbiting && orbit_target != nullptr)
    {
        update_orbit_position(delta);
    }
    
    if (pulsing && is_animating)
    {
        update_pulse_animation(delta);
    }
}


void EnhancedSprite::set_orbit_radius(float p_radius)
{
    orbit_radius = p_radius;
}

float EnhancedSprite::get_orbit_radius() const
{
    return orbit_radius;
}

void EnhancedSprite::set_orbit_speed(float p_speed)
{
    orbit_speed = p_speed;
}

float EnhancedSprite::get_orbit_speed() const
{
    return orbit_speed;
}

void EnhancedSprite::set_orbit_target(Node2D* p_target)
{
    orbit_target = p_target;
}

Node2D* EnhancedSprite::get_orbit_target() const
{
    return orbit_target;
}

void EnhancedSprite::start_orbiting()
{
    orbiting = true;
    is_animating = true;
    orbit_angle = 0.0f;
}

void EnhancedSprite::stop_orbiting()
{
    orbiting = false;
}

void EnhancedSprite::update_orbit_position(double delta)
{
    orbit_angle += orbit_speed * delta;
    
    Vector2 orbit_position = Vector2(
        cos(orbit_angle) * orbit_radius,
        sin(orbit_angle) * orbit_radius);
    
    if (orbit_target != nullptr)
    {
        set_global_position(orbit_target->get_global_position() + orbit_position);
    }
    

    if (orbit_angle >= 2 * Math_PI)
    {
        orbit_angle = 0.0f;
        emit_signal("orbit_completed");
    }
}


void EnhancedSprite::set_pulse_speed(float p_speed)
{
    pulse_speed = p_speed;
}

float EnhancedSprite::get_pulse_speed() const
{
    return pulse_speed;
}

void EnhancedSprite::set_pulse_min_scale(float p_min_scale)
{
    pulse_min_scale = p_min_scale;
}

float EnhancedSprite::get_pulse_min_scale() const
{
    return pulse_min_scale;
}

void EnhancedSprite::set_pulse_max_scale(float p_max_scale)
{
    pulse_max_scale = p_max_scale;
}

float EnhancedSprite::get_pulse_max_scale() const
{
    return pulse_max_scale;
}

void EnhancedSprite::start_pulsing()
{
    pulsing = true;
    is_animating = true;
    pulse_timer = 0.0f;
}

void EnhancedSprite::stop_pulsing()
{
    pulsing = false;
    set_scale(Vector2(1.0f, 1.0f));
}

void EnhancedSprite::update_pulse_animation(double delta)
{
    pulse_timer += delta * pulse_speed;
    
    float scale_factor = pulse_min_scale + 
        (pulse_max_scale - pulse_min_scale) * 
        (sin(pulse_timer * 2 * Math_PI) + 1.0f) / 2.0f;
    
    set_scale(Vector2(scale_factor, scale_factor));
 }


void EnhancedSprite::play_animation()
{
    is_animating = true;
    if (!pulsing && !orbiting)
    {
        start_pulsing();
    }
}

void EnhancedSprite::pause_animation() {
    is_animating = false;
}

void EnhancedSprite::stop_animation()
{
    is_animating = false;
    pulsing = false;
    orbiting = false;
    set_scale(Vector2(1.0f, 1.0f));
}


void EnhancedSprite::_on_game_event_triggered(const String& event_name)
{
    if (event_name == "start_orbiting")
    {
        start_orbiting();
    }
    
    else if (event_name == "start_pulsing")
    {
        start_pulsing();
    }
    
    else if (event_name == "stop_animations")
    {
        stop_animation();
    }
}


void EnhancedSprite::_on_player_interaction(const Vector2& position)
{
    float distance = get_global_position().distance_to(position);
  
    if (distance < 50.0f)
    {
        emit_signal("sprite_clicked");
        start_pulsing();
    }
}
