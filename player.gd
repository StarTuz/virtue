extends CharacterBody3D

const SPEED = 5.0

@onready var camera = $Camera3D
@onready var mesh = $MeshInstance3D # Reference to the visual mesh

var focused_object: Interactable = null

func _physics_process(_delta):
	# 1. Movement
	var input_dir = Input.get_vector("move_left", "move_right", "move_forward", "move_backward")
	
	# Isometric correction: Align with Camera View
	var cam_basis = camera.global_transform.basis
	var direction = (cam_basis * Vector3(input_dir.x, 0, input_dir.y)).normalized()
	direction.y = 0 # Flatten to ground plane
	direction = direction.normalized()

	if direction:
		velocity.x = direction.x * SPEED
		velocity.z = direction.z * SPEED
		
		# Rotate ONLY the Mesh to look at movement direction
		# We add position to direction because look_at takes a global target point
		var target_look = global_position + direction
		mesh.look_at(target_look, Vector3.UP)
	else:
		velocity.x = move_toward(velocity.x, 0, SPEED)
		velocity.z = move_toward(velocity.z, 0, SPEED)

	move_and_slide()
	
	# 2. Interaction Raycast
	_handle_interaction_raycast()

func _input(event):
	if event.is_action_pressed("interact"):
		if focused_object:
			focused_object.interact(self)

func _handle_interaction_raycast():
	var mouse_pos = get_viewport().get_mouse_position()
	var from = camera.project_ray_origin(mouse_pos)
	var to = from + camera.project_ray_normal(mouse_pos) * 1000.0
	
	var space_state = get_world_3d().direct_space_state
	var query = PhysicsRayQueryParameters3D.create(from, to)
	query.collision_mask = 4 # Interactables layer
	
	var result = space_state.intersect_ray(query)
	
	if result:
		var collider = result.collider
		if collider is Interactable:
			if focused_object != collider:
				if focused_object:
					focused_object.unfocus()
				focused_object = collider
				focused_object.focus()
	else:
		if focused_object:
			focused_object.unfocus()
			focused_object = null
