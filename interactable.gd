class_name Interactable
extends StaticBody3D

func interact(instigator: Node3D):
	print("Interacted with ", name)
	_on_interact(instigator)

func focus():
	print("Focused: ", name)
	# Simple highlight effect: Create a tween to pulse scale
	var tween = create_tween()
	tween.tween_property($MeshInstance3D, "scale", Vector3(1.2, 1.2, 1.2), 0.1)

func unfocus():
	print("Unfocused: ", name)
	var tween = create_tween()
	tween.tween_property($MeshInstance3D, "scale", Vector3(1.0, 1.0, 1.0), 0.1)

func _on_interact(_instigator):
	# Override this
	pass
