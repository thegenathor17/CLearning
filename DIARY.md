# Dev Diary :D  
## Introduction
Here, I'll narrate every single problem/curious thing that happened during the development of this project, just so I can read it and laugh at myself in the future (I hope near future D:).  
## 1.0.0 realease  
I actually never really worked with all these new tools before (Inno setup, C itself, cmake, etc...) but i really enjoyed the experience, it was very challenging to learn a new coding language (And specially if it is C) with a project instead of a class but it was rewarding. One of the biggest challenges I had during the development of this project (specially cxt) was learning about pointers and strings with c, it might be one of the hardest things to dominate out there, if it wasn't because of google this project might be dead, I can't imagine how people used to code without the beauty of learning through a search engine.  

## 1.1.0 realease
Hello there! it's the first time I write it from the beginning of the period of time I'm supposed to be doing it, so, let's start with the first few things I would like to present you the only thing I wanna add in this realease.  
- **Build Assistant**: I know its hard to do but I would like to code an automatic cmake file generator to just code and code without worrying for the cmake :D. I guess I'll just have a basic template for its first version and then add a bunch more of them. I'm thinking of some commands like:  
```bash
    # This one would make the cbaFile.cl so the user can just do build or cl -ba build to update
    [buildSystem] -[assembler] # This would go in cba.c
    cl -ba cmake -ninja # This one would use CL PATH command as a short cut
    # ↑ uses cmake and ninja as examples

    build # On cba.c would update the CMake files and  build the .exe
    reset # Deletes all cbaFiles.cl so you can change configurations
    config # configuration menu
```
Anyways, I'll put them in the documentation once I finish it. For the moment, those are the only ones I have planned so far.  

### 1.0.1 update :D
For this update (which I have about half an hour to code) I'll try to set the base for this new tool in the stack, wish me luck!

For the first files I made, I must say, I really should work on ui.c, it reapeats in every new project that needs it, I know it's hard to make an universal one. Was thinking about C#'s override feature but discarded it after noticing it'd be the same, I'd override it literally ALL the times I wanna make a personalized UI so I'll keep doing it the way I'm doing so until I come up with a better plan.

As I kept working I found out the past bash commands were not good enough, this is the idea now:  
```bash
    build # Will look for cba.build, with all the info it needs to run
    prepare # If it doesn't find said file, you should run this one
    config # Pretty much self-explanatory
```
If build is run without a cba.build file it'll ask the user for permission to make another one, assuming its the root directory of the project and writing with the options saved in cba directory in C:/InCGames/CL/configs