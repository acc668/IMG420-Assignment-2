extends Node2D

@onready var enhanced_sprite = $EnhancedSprite
@onready var player = $Player
@onready var orbit_target = $OrbitTarget

func _ready():
    enhanced_sprite.sprite_clicked.connect(_on_enhanced_sprite_clicked)
    enhanced_sprite.orbit_completed.connect(_on_orbit_completed)
    enhanced_sprite.animation_completed.connect(_on_animation_completed)
    
    enhanced_sprite.orbit_target = orbit_target
    
    enhanced_sprite.start_pulsing()

func _on_enhanced_sprite_clicked():
    print("EnhancedSprite was clicked!")
    enhanced_sprite.start_orbiting()

func _on_orbit_completed():
    print("Orbit completed! Score +100")

func _on_animation_completed():
    print("Animation completed")

func _input(event):
    if event is InputEventMouseButton and event.pressed:
        enhanced_sprite._on_player_interaction(event.position)
