extends Node2D

@onready var enhanced_sprite = $EnhancedSprite
@onready var player = $Player

func _ready():
    enhanced_sprite.sprite_clicked.connect(_on_enhanced_sprite_clicked)
    enhanced_sprite.orbit_completed.connect(_on_orbit_completed)
    
    player.player_action.connect(enhanced_sprite.on_player_action)

func _on_enhanced_sprite_clicked():
    print("EnhancedSprite clicked! Adding score.")

func _on_orbit_completed():
    print("Orbit completed! Animation finished.")
