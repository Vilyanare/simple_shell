# a simple shell project
![alt text](https://c.pxhere.com/photos/f3/90/peanuts_nuts_snack_nutrition_healthy_nibble_decoration_close-842313.jpg!d "delicious" =100x100)

### Authors
  * Thomas Dumont - github: `vilyanare`
  * Jacob Hartman - github: `JacobBHartman`

### Learning Objectives
  * __Write a simple UNIX command interpreter__
  * History of UNIX, shell versions, B language, Ken Thompson; How a shell works; What is a process, pid, and ppid; functions vs system calls; How to manipulate the environment of a process; How shell uses `PATH`; How to use `execve`; What is `EOF`

### System and Compilation
  * Compiler: `gcc 4.8.4`
  * Compile using: `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
  * Tested on Ubuntu 14.04 LTS using Vagrant in VirtualBox
  * Install by using `git clone https://github.com/Vilyanare/simple_shell.git`

### Constraints
  * No more than 5 functions per file
  * Program must have the exact same output as `sh` (`/bin/sh`)
  * `Betty` [styling](https://github.com/holbertonschool/Betty/wiki)
  * Only certain functions were allowed; many `STL` functions were recreated
  * those functions allowed are: 
### Prototype

### Tasks

### Functions

### File Descriptions
---
File | Description
--- | ---
`_eprintf.c` | a custom `printf()` that prints to standard error
`_printf.c` | a custom verson of `printf()` that handles `string` and `int`
`built_ins.c` | enables the shell to execute certain custom built-ins
`envlistfunc.c` | contains functions for manipulating `env` as a linked list
`path.c` | enables the creation and searching of `PATH`
`shell.h` | contains directives, libraries, structures, and function prototypes
`simple_shell.c` | the `main` file that executes the shell
`strings1.c` | custom versions of `strcpy`, `strlen`, `puts`, `strchr`, `strdup`
`strings2.c` | custom versions of `strcat`, `realloc`, `strtok`, and tokenizer-related functions
`strings3.c` | custom versions of `strcmp` and `atoi`

### Comment(s) by Jacob
Focus should obviously be placed on completing the mandatory. That being said,
when I go through to clean-up for Betty, I would like to do the following.
1. variable and function names
  * make sure all variable names are relatively short (7 chars?)
  * make sure all variable names are descriptive
  * variable names for indices may be 1 letter
2. comment the code
  * long description in the function header
3. make as portable as possible
  * replaces all 1's that are passed as the first parameter in write() with
    the proper constants
  * do the same thing for sizeof()
4. other things to make it better
  * separate blocks of code with a single empty line to easily identify potential
    functions
  * turn ints into unsigned ints if we can. do this for other variable types as well.
  * instead of passing a string literal to strtok lie ":", define a variable and
    assign it the value of ":". do this for functions other than strtok as well.
5. make sure we are not using any of the functions we're not allowed to use

