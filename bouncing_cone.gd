extends Interactable

func _on_interact(_instigator):
	# Jump up
	var tween = create_tween()
	tween.tween_property($MeshInstance3D, "position:y", 1.0, 0.2).set_trans(Tween.TRANS_SINE)
	tween.tween_property($MeshInstance3D, "position:y", 0.0, 0.2).set_trans(Tween.TRANS_BOUNCE)
