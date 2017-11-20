<a href="url"><img src="https://c.pxhere.com/photos/f3/90/peanuts_nuts_snack_nutrition_healthy_nibble_decoration_close-842313.jpg!d" align="middle" width="100" height="100"></a>  __simple_shell__

## Objectives
  * __Write a simple UNIX command interpreter__
  * Learn about the history of UNIX, shell versions, B language, Ken Thompson; How a shell works; What is a process, pid, and ppid; functions vs system calls; How to manipulate the environment of a process; How shell uses `PATH`; How to use `execve`; What is `EOF`

## System and Environment
  * Compiler: `gcc 4.8.4`
  * Tested on Ubuntu 14.04 LTS using Vagrant in VirtualBox

## Installation
  * Clone the repository: `git clone https://github.com/Vilyanare/simple_shell.git`
  * Change into the proper directory: `cd simple_shell`
  * Compile using: `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
  * Run in interactive mode: `./hsh`

## Usage Example

## File Descriptions
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

## Constraints
  * No more than 5 functions per file
  * Program must have the exact same output as `sh` (`/bin/sh`)
  * `Betty` [styling](https://github.com/holbertonschool/Betty/wiki)
  * Only certain functions were allowed; many `STL` functions were recreated
  * Those functions allowed are: `access`, `chdir`, `close`, `closedir`, `execve`, `exit`, `fork`, `free`, `stat`, `lstat`, `fstat`, `getcwd`, `getline`, `kill`, `malloc`, `open`, `opendir`, `perror`, `read`, `readdir`, `signal`, `strtok`, `wait`, `waitpid`, `wait3`, `wait4`, `write`, `_exit`, `isatty`, `fflush`

## Authors
  * Thomas Dumont - github: `vilyanare`
  * Jacob Hartman - github: `JacobBHartman`
