# Virtue: Implementation Plan & Status

This document tracks the technical implementation steps for the three prototyping phases of **Virtue**.

## Phase 1: Prototype A - "The Tactician" (Top-Down)
**Goal**: Establish the core RPG loop, moral system foundation, and world interactivity in a classic isometric view.

### 1.1 Core Setup [COMPLETED]
- [x] **Project Initialization**: Godot Project initialized.
- [x] **Virtue System**: `VirtueSystemComponent` created (Tracks 8 Virtues).
- [x] **Character Basics**: `VirtueCharacter` created with Top-Down Camera.
- [x] **Movement**: WASD Movement implemented and verified.
- [x] **Visuals**: Basic geometric placeholder (White Cube) for the Paragon.

### 1.2 Interactivity (Godot Migration Complete)
- [x] **Interaction System**: Create `interactable.gd` base script.
- [x] **Player Raycast**: Implement `_handle_interaction_raycast` in `player.gd`.
- [x] **Input Handling**: Setup Input Map (`move_`, `interact`) in Project Settings.
- [x] **Visual Feedback**: Simple tween-based scaling on Focus.
- [x] **Test Actor**: Created `cone.tscn` with bounce logic.

### 1.3 The "Living World" Mechanics
- [ ] **Drag & Drop / Physics**:
    *   Implement `RigidBody3D` picking.
    *   Create a "Hold" node on the Player to snap objects to.
- [ ] **Inventory System**: 
    *   Create `Inventory` Resource (ScriptableObject equivalent).
    *   UI: Simple GridContainer for items.

### 1.4 NPC & Dialogue
- [ ] **NPC Base Class**: Character class with `VirtueSystemComponent`.
- [ ] **Schedule System**: Time-of-day tracking and NPC waypoints (Sleep -> Work -> Tavern).
- [ ] **Dialogue System**: Integration with a dialogue parser (maybe external JSON or DataTables).

---

## Phase 2: Prototype B - "The Explorer" (Immersive First-Person)
**Goal**: leverage Godot's Forward+ Renderer for high-fidelity visuals and immersive physics.

- [ ] **Camera Switching**: Toggle between Top-Down and First/Third-Person.
- [ ] **Enhanced Visuals**: Replace "White Cube" with a skeletal mesh (Helga).
- [ ] **Physics Interaction**: First-person grabbing/throwing mechanics.
- [ ] **Environment**: Build "The Virtue Swirl" bakery test map.

---

## Phase 3: Prototype C - "The Virtue" (Unified Experience)
**Goal**: seamlessly blend the tactical and immersive views.

- [ ] **Dynamic Zoom**: Smooth transition from Iso to FPS.
- [ ] **Contextual Controls**: Controls adapt based on zoom level (Click-to-move in Iso vs WASD in FPS).
- [ ] **Final Polish**: UI, Audio, VFX.
