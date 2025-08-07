### Here's the Knight's Tour Problem visualized with SFML & coded in C++ ###

An interactive visualization of the Knight’s Tour problem in chess — built with C++ and SFML.

Click any square to start  
The knight visits every square **exactly once** using backtracking  
Each move is animated step-by-step  
A blue path connects each move  
A knight PNG sprite replaces boring red dots

---


## Features

Mouse-click starting square
Guaranteed solution using backtracking
Animated knight movement
Knight image + path lines

---

## How to Run

### Requirements:
- [MSYS2](https://www.msys2.org/)
- `g++`, `SFML` installed via:
  bash:
  ```
  cd /c/Users/(whatever your user's name is)/Downloads/knightstour
  pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-sfml
  ./knight-tour
    ```
