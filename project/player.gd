extends CharacterBody2D

signal player_action(action_name)

func _input(event):
    if event is InputEventKey and event.pressed:
        if event.keycode == KEY_SPACE:
            player_action.emit("start_orbit")

        elif event.keycode == KEY_P:
            player_action.emit("start_pulse")

        elif event.keycode == KEY_S:
            player_action.emit("stop_animations")
