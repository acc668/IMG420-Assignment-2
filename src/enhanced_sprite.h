#ifndef ENHANCED_SPRITE_H
#define ENHANCED_SPRITE_H

#include <godot_cpp/classes/sprite2d.hpp>
#include <godot_cpp/core/class_db.hpp>

namespace godot
{

  class EnhancedSprite : public Sprite2D
  {
      GDCLASS(EnhancedSprite, Sprite2D)
  
    private:
        // declare variable(s)
        float orbit_radius;
        float orbit_speed;
        Node2D* orbit_target;
        bool orbiting;
        float orbit_angle;
        float pulse_speed;
        float pulse_min_scale;
        float pulse_max_scale;
        bool pulsing;
        float pulse_timer;
        bool is_animating;
    
    protected:
        static void _bind_methods();
    
    public:
        EnhancedSprite();
        ~EnhancedSprite();

        // declare necessary functions
        void _process(double delta) override;
        void set_orbit_radius(float p_radius);
        float get_orbit_radius() const;
        void set_orbit_speed(float p_speed);
        float get_orbit_speed() const;
        void set_orbit_target(Node2D* p_target);
        Node2D* get_orbit_target() const;
        void start_orbiting();
        void stop_orbiting();
        void set_pulse_speed(float p_speed);
        float get_pulse_speed() const;
        void set_pulse_min_scale(float p_min_scale);
        float get_pulse_min_scale() const;
        void set_pulse_max_scale(float p_max_scale);
        float get_pulse_max_scale() const;
        void start_pulsing();
        void stop_pulsing();
        void play_animation();
        void pause_animation();
        void stop_animation();
        void sprite_clicked();
        void on_player_action(const String& action_name);
        void animation_completed();
        void orbit_completed();
    
    private:
        void update_orbit_position(double delta);
        void update_pulse_animation(double delta);
  };

}

#endif
