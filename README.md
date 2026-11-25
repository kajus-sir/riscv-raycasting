# RISC-V Raycasting

A simple raycasting renderer for the DTEK-V board, written in C.
Inspired by early 3D games like Wolfenstein 3D.

Mini project in IS1500 (Computer Hardware Engineering) at KTH.

## Authors
- Kajus Sirvinskas
- Hugo Lundberg

## File structure

```
riscv-raycasting/
├── Makefile             # Build rules: compiles everything into main.bin
├── boot.S               # Startup code (from the course), runs before main()
├── dtekv-lib.c/.h       # Helper functions from the course (print, etc.)
├── dtekv-script.lds     # Linker script: where code and data go in memory
├── softfloat.a          # Library for float math (the CPU has no float unit)
├── docs/
│   └── testspec.md      # How we test the program
└── src/
    ├── main.c           # Program start and main loop
    ├── config.h         # Shared settings, like colors
    ├── platform.h       # Hardware interface (screen size, draw pixel)
    ├── platform_dtek.c  # Hardware code for the DTEK-V board (VGA)
    ├── map.c/.h         # The map as a 2D array (0 = empty, 1+ = wall)
    ├── player.c/.h      # Player position, direction and movement
    ├── raycast.c/.h     # Raycasting: finds the distance to walls
    └── render.c/.h      # Draws the 3D view and the top-down map
```

## Status
Work in progress.
