extends Button

@onready var sprite = get_node("../MyEnhancedSprite")
var is_pulsing = true  # Pulse starts enabled by default

func _on_pressed():
	if is_pulsing:
		sprite.stop_pulse()
		text = "Start Pulse"
		is_pulsing = false
	else:
		sprite.start_pulse()
		text = "Stop Pulse"
		is_pulsing = true
