extends Node2D

@onready var enhancedSprite = $EnhancedSprite
@onready var player = $Player

func _ready():
    enhancedSprite.spriteClicked.connect(_on_enhancedSprite_clicked)
    enhancedSprite.orbitCompleted.connect(_on_orbitCompleted)
    
    player.playerAction.connect(enhancedSprite.on_playerAction)

func _on_enhancedSprite_clicked():
    print("EnhancedSprite clicked! Adding score.")

func _on_orbitCompleted():
    print("Orbit completed! Animation finished.")
