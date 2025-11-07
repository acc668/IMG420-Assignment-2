# IMG420-Assignment-2

A demonstration of extending Godot's Sprite2D node using GDExtension (C++ bindings) to add custom features and behaviors.

## Features

This project adds two new features to Sprite2D:

1. **Auto-Rotation** - Sprite rotates continuously at a configurable speed
2. **Pulse Effect** - Sprite scales up and down in a pulsing animation

Both features have editor-adjustable parameters and can be controlled at runtime through signals and methods.

## Requirements

- **Godot Engine 4.5.1** (or compatible 4.x version)
- **Visual Studio 2019 or later** with C++ development tools
- **Python 3.6+**
- **SCons** build system (`pip install scons`)
- **Git**

## Project Structure
```
assignment-2-fixed/
├── project/              # Godot project files
│   ├── project.godot
│   ├── bin/              # Compiled DLL files
│   └── my_extension.gdextension
├── gdextension/          # C++ extension source code
│   ├── src/
│   │   ├── enhanced_sprite2d.h
│   │   ├── enhanced_sprite2d.cpp
│   │   ├── register_types.h
│   │   └── register_types.cpp
│   └── SConstruct
└── godot-cpp/            # Godot C++ bindings
```

## Building the Extension

### 1. Clone godot-cpp (first time only)
```bash
cd assignment-2-fixed
git clone https://github.com/godotengine/godot-cpp --recursive
cd godot-cpp
git checkout godot-4.5-stable
```

### 2. Build godot-cpp (first time only)
```bash
scons platform=windows target=template_debug
```

This takes 5-10 minutes on first build.

### 3. Build the extension
```bash
cd ..\gdextension
scons platform=windows target=template_debug
```

### 4. Rebuild after code changes
```bash
cd gdextension
scons platform=windows target=template_debug
```

Then restart Godot.

## Usage in Godot

1. Open the project in Godot Engine
2. Create a new 2D scene
3. Add **EnhancedSprite2D** node (instead of regular Sprite2D)
4. Add a texture to the sprite
5. Adjust parameters in the Inspector:
   - **Rotation Speed** - Controls rotation speed
   - **Pulse Intensity** - Controls pulsing effect strength

## Demo Features

The demo scene includes:

- **EnhancedSprite2D** with custom rotation and pulsing
- **Toggle Rotation Button** - Toggles auto-rotation on/off
- **Toggle Pulse Button** - Toggles pulse effect on/off
- **Status Label** - Updates when sprite completes a full rotation

### Signals

- `rotation_completed` - Emitted when sprite completes a full 360° rotation

### Methods

- `on_external_trigger()` - Toggles rotation (can be called from other nodes)
- `start_rotation()` - Starts auto-rotation
- `stop_rotation()` - Stops auto-rotation
- `start_pulse()` - Starts pulse effect
- `stop_pulse()` - Stops pulse effect
