extends Node2D

@onready var enhancedSprite = $EnhancedSprite
@onready var player = $Player

func _ready():
    enhancedSprite.spriteClicked.connect(_onEnhancedSpriteClicked)
    enhancedSprite.orbitCompleted.connect(_onOrbitCompleted)
    
    player.playerAction.connect(enhancedSprite.onPlayerAction)

func _onEnhancedSpriteClicked():
    print("EnhancedSprite clicked! Adding score.")

func _onOrbitCompleted():
    print("Orbit completed! Animation finished.")
