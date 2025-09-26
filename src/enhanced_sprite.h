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
        float orbitRadius;
        float orbitSpeed;
        Node2D* orbitTarget;
        bool orbiting;
        float orbitAngle;
        float pulseSpeed;
        float pulseMinScale;
        float pulseMaxScale;
        bool pulsing;
        float pulseTimer;
        bool isAnimating;
    
    protected:
        static void _bind_methods();
    
    public:
        EnhancedSprite();
        ~EnhancedSprite();

        // declare necessary functions
        void _process(double delta) override;
        void setOrbitRadius(float p_radius);
        float getOrbitRadius() const;
        void setOrbitSpeed(float p_speed);
        float getOrbitSpeed() const;
        void setOrbitTarget(Node2D* p_target);
        Node2D* getOrbitTarget() const;
        void startOrbiting();
        void stopOrbiting();
        void setPulseSpeed(float p_speed);
        float getPulseSpeed() const;
        void setPulseMinScale(float p_minScale);
        float getPulseMinScale() const;
        void setPulseMaxScale(float p_maxScale);
        float getPulseMaxScale() const;
        void startPulsing();
        void stopPulsing();
        void playAnimation();
        void pauseAnimation();
        void stopAnimation();
        void spriteClicked();
        void onPlayerAction(const String& actionName);
        void animationCompleted();
        void orbitCompleted();
    
    private:
        void updateOrbitPosition(double delta);
        void updatePulseAnimation(double delta);
  };

}

#endif
