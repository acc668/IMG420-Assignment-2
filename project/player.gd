extends CharacterBody2D

signal playerAction(actionName)

func _input(event):
    if event is InputEventKey and event.pressed:
        if event.keycode == KEY_SPACE:
            playerAction.emit("startOrbit")

        elif event.keycode == KEY_P:
            playerAction.emit("startPulse")

        elif event.keycode == KEY_S:
            playerAction.emit("stopAnimations")
