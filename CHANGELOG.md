# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.0.0] - 2026-02-03

### Added

#### CL (Command-Line Launcher)
- Command-line argument parsing for options and commands
- Version information display (`-v`, `--version`)
- Help menu display (`-h`, `--help`)
- Tool execution capability (`exec hub`, `exec cxt`)
- Error handling for unknown options
- Windows system call integration for launching executables

#### HUB (Menu Interface)
- Interactive console menu system
- Numbered option selection (1: Go to CXT, 2: Exit)
- Console screen clearing between menu displays
- Error handling for invalid menu selections
- Integration with CXT tool launching

#### CXT (Text Analysis Tool)
- Text file analysis with multiple statistics:
  - Line count (`info -l`)
  - Word count (`info -w`)
  - Most common word identification (`info -m`)
  - Complete word frequency analysis (`info -f`)
  - All statistics display (`info -a`)
- Stop word filtering (common English words like "the", "a", "is")
- Text cleaning (punctuation removal, quote handling)
- Report saving functionality with timestamped filenames
- Report loading from saved analysis files
- Interactive command-line interface with help system
- File path input validation
- Memory management for dynamic word tracking
- Windows-specific console operations

#### Common Library
- Map data structure implementation:
  - Key-value storage using void pointers
  - FindKey() function for key index lookup
  - FindValue() function for value index lookup
  - ExistKey() function for key existence check
  - ExistValue() function for value existence check
- Screen management utilities:
  - clearConsole() for console screen clearing
  - Stop() for execution pause with user input
- Static library compilation for shared usage

#### Build System
- CMake-based build configuration (minimum version 3.10)
- Ninja build generator support
- C11 standard compliance
- GCC/MinGW compiler support on Windows
- Automatic header inclusion for common library
- Executable generation in build directory

#### Project Structure
- Modular project organization with common library
- Cross-project dependencies management
- Comprehensive documentation (README files for each component)
- Windows compatibility focus

### Technical Details
- Pure C implementation without external dependencies
- Standard C library usage only
- Windows API integration for console operations
- Dynamic memory allocation for data structures
- File I/O operations for text analysis and report management
- Command-line interface design
- Modular code architecture with separate header files

### Documentation
- Main project README with build and usage instructions
- Component-specific README files (CL, HUB, CXT, Common)
- Feature descriptions and API documentation
- Build system configuration details
- Dependency and compatibility information
- Comprehensive command reference (DOCUMENTATION.md)

### Author
- Developed by Nahum Naranjo as a C learning project