#ifndef ENHANCED_SPRITE2D_H
#define ENHANCED_SPRITE2D_H

#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {

class EnhancedSprite2D : public Sprite2D {
    GDCLASS(EnhancedSprite2D, Sprite2D)

private:
    // Feature 1: Auto-rotation
    float rotation_speed;
    bool is_rotating;
    
    // Feature 2: Pulsing scale
    float pulse_intensity;
    bool is_pulsing;
    float pulse_timer;
    
    // Internal tracking
    float total_rotation;

protected:
    static void _bind_methods();

public:
    EnhancedSprite2D();
    ~EnhancedSprite2D();

    void _process(double delta) override;

    // Getters and setters for editor properties
    void set_rotation_speed(float p_speed);
    float get_rotation_speed() const;
    
    void set_pulse_intensity(float p_intensity);
    float get_pulse_intensity() const;
    
    // Method that can be called from signals
    void on_external_trigger();
    
    // Methods to control features
    void start_rotation();
    void stop_rotation();
    void start_pulse();
    void stop_pulse();
};

}

#endif