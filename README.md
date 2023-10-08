<div align="center">
  <h1>Godot Rapier2D</h1> 

  <a href="https://github.com/godotengine/godot/releases/tag/4.1-stable"><img src="https://img.shields.io/badge/Godot-v4.1-%23478cbf?logo=godot-engine&logoColor=white"/></a>
  <a href="https://github.com/dimforge/rapier/releases/tag/v0.17.2"><img src="https://img.shields.io/badge/Rapier2D-v0.17.2-%23478cbf?logoColor=white"/></a>
  <a href="https://github.com/fabriceci/godot-rapier2d/actions/workflows/runner.yml?branch=main">![🔗 Build Status](https://github.com/fabriceci/godot-rapier2d/actions/workflows/runner.yml/badge.svg?branch=main)</a>
</div>

<img src="https://github.com/fabriceci/godot-rapier2d/blob/main/logo.jpg?raw=true"/> 

A [rapier](https://github.com/dimforge/rapier) physics server for [Godot Engine](https://github.com/godotengine/godot), implemented as a GDExtension.

# [Limitations/Known Issues](https://github.com/fabriceci/godot-rapier2d/issues/8)

- One way direction not implemented
- WIP (still needs to be updated with what else needs to be done)

# Installation

- Automatic (WIP)

- Manual: Download the github release and move only the `addons` folder into your project `addons` folder.

After installing, go to `Advanced Settings` -> `Physics` -> `2D`. Change `Physics Engine` to `Rapier2D`.

## Build the Rapier 2D Extension

### Build godot-cpp

Official C++ bindings for Godot API (https://github.com/godotengine/godot-cpp)

Steps to build godot-cpp:
- Open a command line prompt in `godot-cpp/` folder
- Run `scons target=[TARGET] platform=[PLATFORM] debug_symbols=[DEBUG] dev_build=[DEBUG] -j[CORES]` with:
`[TARGET]`: `template_debug` for godot debug export and `template_release` for godot release export
`[PLATFORM]`: (optional) target platform if different from the current patform
`[DEBUG]`: (optional) `yes` to generate symbols and disable optimization for a debug build (useful only for debugging the extension)
`[CORES]`: (optional) number of cores to use in order to accelerate the build

Example:

```
cd godot-cpp
scons target=template_debug generate_bindings=yes
```

See [Building the C++ bindings](https://docs.godotengine.org/en/stable/tutorials/scripting/gdextension/gdextension_cpp_example.html#building-the-c-bindings) from the official documentation for more details about building the bindings.

### Build the Rapier 2D wrapper

Prerequisites:
- Install `cargo` for Rust support
Generate the C bindings header file (in `src/rapier2d-wrapper/includes/`)

Go to `src/rapier2d-wrapper` folder and run `cbindgen`

```
cd src/rapier2d-wrapper
cargo install --force cbindgen
cbindgen --config cbindgen.toml --crate rapier2d-wrapper --output includes/rapier2d_wrapper.h
```

Compile the rust release Rapier2D library:

```
cargo build --release
```

### Compile the Rapier 2D extension

This step will build the final Godot Rapier extension library.

Steps to compile the extension:
- Open a command line prompt in the root folder
- Run `scons target=[TARGET] platform=[PLATFORM] debug_symbols=[DEBUG] dev_build=[DEBUG] -j[CORES]` with:
`[TARGET]`: `template_debug` for godot debug export and `template_release` for godot release export
`[PLATFORM]`: (optional) target platform if different from the current patform
`[DEBUG]`: (optional) `yes` to generate symbols and disable optimization for a debug build (useful only for debugging the extension)
`[CORES]`: (optional) number of cores to use in order to accelerate the build

```
scons target=template_debug generate_bindings=no
```

The library files will be found in `bin/addons/` folder.

## Use the Rapier 2D extension

Copy the `addons/` folder to your project root.

If you need to use a debug version with debug symbols, open `physics_server_rapier2D.gdextension` and rename all `template_debug` to `template_debug.dev`.
This is useful only if you wish to debug the Rapier extension itself.

# Roadmap

- Cross Platform Determinism
- Add more types of joints
- Pass all Godot Physics Tests.

# [Discord](https://discord.gg/56dMud8HYn)

A vibrant community for discussion, user support and showcases.

# License

All code in this repository is provided under the MIT license. See `LICENSE` for more details and `THIRDPARTY.txt` for third-party licenses.
