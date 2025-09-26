# IMG420-Assignment-2

## Design Overview

This project extends Godot's Sprite2D class via GDExtension to create an EnhancedSprite with custom behaviors.

### Features Implemented

**Feature 1: Orbital Rotation**
- Sprite orbits around a target node with configurable radius and speed
- Editor-accessible parameters: `orbitRadius`, `orbitSpeed`, `orbitTarget`

**Feature 2: Pulsating Scale** 
- Sprite scales up and down smoothly with sine wave interpolation
- Editor-accessible parameters: `pulseSpeed`, `pulseMinScale`, `pulseMaxScale`

### Signaling System

**Signal Emitted by EnhancedSprite**: `spriteClicked()`
- Triggers methods in existing nodes when the sprite is interacted with

**Method in EnhancedSprite**: `onPlayerAction(actionName)`
- Triggered by signals emitted from existing nodes (like Player)
- Controls animation behaviors based on player input

### Extra Credit: Animation Control
- `playAnimation()`, `pauseAnimation()`, `stopAnimation()` methods
- Custom animation system without using built-in Godot animation tools

## Building Instructions

1. Place this project next to a `godot-cpp` binding library
2. Build with: `cd src && scons platform=<your_platform>`
3. Open the project in Godot 4.2+

## Demonstration

The demo shows:
- EnhancedSprite with orbital and pulsating animations
- Signal connections between GDExtension nodes and GDScript nodes
- Editor-accessible parameters for both features
- Extra credit animation controls
