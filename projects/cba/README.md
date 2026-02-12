# CBA - A build assistant for lost developers

CBA is a simple command-line build assist tool written in C. It allows users to automatically write CMake files and build. It only supports C code built with CMake Ninja but more options will be added as the project continues its development.

**Part of the CLEARNING project** - A collection of C learning projects. See the [main README](../../README.md) for more information about the overall project.

## Features (More coming soon)

- **Automatic CMake handler**: It automatically writes your cmakelists.txt and builds yout project :D

## Usage

1. Run the program: `./cba.exe`
2. Run either `build` or `prepare`, depending if you already have a cba.build file.
3. Enjoy

## Building

Run the CL installer, this dependencie does not have a separate repository yet.

## Dependencies

- **CMake 3.10**: It's the standard build scripting tool.
- **Ninja 1.10.0**: It's the default build system.

## File Structure

- `main.c`: Main program loop.
- `ui.c`: User interface functions (menus, input handling).
- `cba.c`: contains the program itself, all the functions live here.

## Notes

- It is recommended to read the documentation, it has the supported project structures and all commands

## Version

CBA - Build helper v1.0.0