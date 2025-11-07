extends Label

func _on_my_enhanced_sprite_rotation_completed():
	text = "Rotation Completed at: " + str(Time.get_ticks_msec())
	print("Label received rotation_completed signal!")
