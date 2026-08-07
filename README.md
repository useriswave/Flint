## Overview

**simple terminal based text editor written in C++ and ncurses.**

this project has only been tested in:  
- CachyOS
- Ubuntu

[<video src="https://github.com/user-attachments/assets/cb9d8f81-633b-4f94-b07d-de0055d53f70" width="200" controls></video>](https://github.com/user-attachments/assets/bcbc3674-11a2-47f9-a4d7-05fe772a0def)

## Requirements:
- CMake with version 3.20 or above
- C++20 capable compiler
- ncurses (already pre-installed on most linux distros)
## Usage (running with tests off)

In your terminal:
```
git clone https://github.com/useriswave/Flint.git
cd Flint
cmake -S . -B build -DBUILD_TESTING=OFF
cmake --build build/ -j
./build/src/Flint tests/files/empty.txt
```
## Note:  
I use command line arguments for this text editor. You must provide a valid path to a file as the second argument to be able to edit its content with this text editor. More flexibility will be implemented later.
## Example:
```
./build/src/Flint your/path/file.txt
```

## How to use:
#### Current Normal Mode Binds:
- h: Move left
- j: Move down
- k: Move up
- l: Move right
- 0: Move to the start of the line
- $: Move to the end of the line
- i: Insert before the cursor
- a: Insert after the cursor
- I: Insert at the start of the line before the first character
- A: Append at the end of the line
- u: Undo
- r: Redo (will be changed to CTRL+R soon)
- Ctrl + s: Save
- Ctrl + q: Quit

#### Current Insert Mode Binds:
- Backspace: Delete a character
- Enter: Add a new line
- Esc: Toggle Normal Mode

**NOTE: Pressing arrow keys to navigate in insert mode won't work because arrow keys are lame!**
