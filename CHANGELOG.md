# CLEARNING Project Roadmap

For future releases I'm planning to add:

## 1. CL Package Manager
It's kinda hard to do and I know it (have no idea) but I think I'll be alright. Basically, I want to add the typical "cl install [package]" so you can install CL and then just add a specific library to your project root instead of doing it by hand. For example, CMap would work really well with this, I had headaches trying to add it to chocolatey (gave up about five minutes later when I decided to do one on my own).

**Goals:**
- `cl install [package]` command
- Automatic library integration into projects
- Local package repository
- Version management
- Dependency resolution

## 2. CMNGR (C Configuration Manager)
Basically, another CL DLC to configure all the project's libraries in one central configuration. I'm thinking of having configuration files, something like "cxt.config" or so, it won't be that necessary but it'll be fun to code.

**Goals:**
- Centralized configuration system
- Project-specific `.config` files
- Tool integration (CBA, CXT, etc.)
- Configuration validation
- Migration tools between versions

## 3. CUTEST (C Unit Test)
Basically, just another tool for doing tests just like CUnit or Check. I don't really know what will I do here but (I hope) it'll be fun though. Honestly, the name was so good I couldn't help but consider it.

**Goals:**
- Simple test declaration syntax
- Assertion library
- Test discovery and execution
- Code coverage reporting
- Integration with CBA build system

## 4. CFM (C File Manager)
Another DLC for cl.c (I think it's my favorite part of the project), this one will be just as good as Windows built-in file manager (just joking, obviously better). I'm planning to do it for maybe the 2.0.0 or so, it's a bigger project than it seems.

**Goals:**
- Project structure analysis
- Dependency visualization
- Smart file operations (rename with reference updates)
- Refactoring tools
- Integration with version control

## 5. CDOCGEN (C Document Generator)
Just a garbage file generator, maybe you wanna make a 3 GB file worth of pure chaos, just like a very long keyboard smash.

**Goals:**
- Chaos file generation (keyboard smash style)
- Test data generation (CSV, JSON, etc.)
- Code documentation generation
- Pattern-based file creation
- Performance testing utilities

---

## Development Timeline

### Short-term (Next 2-3 Months)
1. **CBA Improvements & Bug Fixes**
   - Refactor folder checking and CMake generation
   - Add .config file support
   - Improve error handling and user feedback

2. **CL Overhaul**
   - Enhance command parsing and execution
   - Add more built-in commands
   - Improve help system and documentation

### Medium-term (3-6 Months)
1. **CBA Out of Beta**
   - Full integration with HUB
   - Enhanced configuration options
   - Cross-platform compatibility improvements

2. **CL Package Manager Foundation**
   - Basic package installation system
   - Local package management
   - Integration with existing tools

### Long-term (6+ Months)
1. **CUTEST Development**
   - Test framework implementation
   - Integration with CBA
   - Documentation and examples

2. **Configuration Manager**
   - Unified configuration system
   - Tool integration
   - Migration utilities

3. **File Manager & Document Generator**
   - Advanced file operations
   - Project analysis tools
   - Various document generation capabilities

---

## Current Focus Areas

### Immediate Tasks (v1.2.x)
- **CBA Refactoring:** Fix folder checking issues and improve CMake generation
- **Documentation:** Update all README files and changelogs
- **Installer Updates:** Ensure installer includes all necessary files
- **Bug Fixes:** Address issues in lookForRootFiles.c and cba.c

### Next Release (v1.3.0)
- Enhanced CBA functionality with .config file support
- Improved CL command structure
- Better error handling and user feedback
- More comprehensive documentation

---

## Notes
- **Weekly Development Goal:** Add a new tool or major update each week
- **Cross-Platform:** Focus on Windows compatibility with eventual Linux/Mac support
- **Community Input:** Features may change based on user feedback and needs
- **Learning Focus:** The project serves as a learning experience in C development

---

## Success Metrics
- Reduce project setup time for C developers
- Provide useful tools that integrate well together
- Maintain clean, readable, and maintainable code
- Support both novice and experienced C developers

---

*Last updated: 2026-02-09*  
*Author: Nahum Naranjo*  
*Project Status: Active Development*