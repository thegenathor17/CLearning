# Common - Shared Library for CLEARNING

Common is a static library written in pure C that provides shared utilities used by multiple projects within the CLEARNING ecosystem.

## Features

- **Map Structure**: Simple key-value map implementation for data storage.
- **Screen Management**: Functions to clear console and pause execution.
- **Static Library**: Compiled as static library for linking with other projects.

## Components

### Map (map.h / map.c)
Provides a simple data structure for maps:

- `Map`: Structure containing key and value (void pointers).
- `FindKey()`: Searches for the index of a key in the map.
- `FindValue()`: Searches for the index of a value in the map.
- `ExistKey()`: Checks if a key exists.
- `ExistValue()`: Checks if a value exists.

### Screen Management (screenManagment.h / screenManagment.c)
Functions for console handling:

- `clearConsole()`: Clears the console screen.
- `Stop()`: Pauses execution waiting for user input.

## Usage in Other Projects

To use the common library in a project:

1. **Include in CMakeLists.txt**:
   ```cmake
   target_link_libraries(your_project common)
   ```

2. **Include headers in code**:
   ```c
   #include "map.h"
   #include "screenManagment.h"
   ```

## Building

The library is built automatically as part of the main CLEARNING project. See the [main README](../README.md) for build instructions.

## Dependencies

- **Standard C Libraries**: Uses only the standard library (stdbool.h, stddef.h, stdio.h).

## File Structure

- `CMakeLists.txt`: Library build configuration.
- `map.c` and `map.h`: Map structure implementation.
- `screenManagment.c` and `screenManagment.h`: Screen management functions.

## Notes

- Designed to be lightweight and reusable.
- Uses void pointers for data type flexibility.
- Compatible with C11 standard.

## Version

Common v1.0.0 - Part of CLEARNING</content>
<parameter name="filePath">d:\Programacion\CLearning\common\README.md