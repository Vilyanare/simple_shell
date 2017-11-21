<a href="url"><img src="https://c.pxhere.com/photos/f3/90/peanuts_nuts_snack_nutrition_healthy_nibble_decoration_close-842313.jpg!d" align="middle" width="100" height="100"></a>  __simple_shell__

## Objectives
  * __Write a simple UNIX command interpreter__
  * Learn about the history of UNIX, shell versions, B language, Ken Thompson; How a shell works; What is a process, pid, and ppid; functions vs system calls; How to manipulate the environment of a process; How shell uses `PATH`; How to use `execve`; What is `EOF`

## Features
- [X] man page
- [ ] handles semi-columns, pipes, redirections
- [X] handles arguments
- [X] handles errors
- [X] handles end-of-file condition
- [X] handles the `PATH`
- [X] basic implementation of exit (no arguments)
- [X] handles `Ctrl+C`
- [X] implements `env` built-in
- [X] setenv and unsetenv builtins
- [ ] future features TBD

## System and Environment
  * Compiler: `gcc 4.8.4`
  * Tested on Ubuntu 14.04 LTS using Vagrant in VirtualBox

## Installation
  * Clone the repository: `git clone https://github.com/Vilyanare/simple_shell.git`
  * Change into the proper directory: `cd simple_shell`
  * Compile using: `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
  * Run in interactive mode: `./hsh`

## Usage Example
```
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ ./hsh
$ ls -la
total 92
drwxrwxr-x  4 vagrant vagrant  4096 Nov 20 07:34 .
drwxr-xr-x 11 vagrant vagrant  4096 Nov 20 01:16 ..
-rw-rw-r--  1 vagrant vagrant   144 Nov 20 07:29 AUTHORS
-rw-rw-r--  1 vagrant vagrant  1130 Nov 19 23:31 built_ins.c
-rw-rw-r--  1 vagrant vagrant  1675 Nov 19 23:31 envlistfunc.c
-rw-rw-r--  1 vagrant vagrant  3201 Nov 18 02:39 _eprintf.c
drwxrwxr-x  8 vagrant vagrant  4096 Nov 20 07:35 .git
-rw-rw-r--  1 vagrant vagrant    39 Nov 15 23:55 .gitignore
-rwxrwxr-x  1 vagrant vagrant 18692 Nov 20 03:21 hsh
-rw-rw-r--  1 vagrant vagrant  1484 Nov 20 07:24 man_1_simple_shell
-rw-rw-r--  1 vagrant vagrant  1195 Nov 19 23:31 path.c
-rw-rw-r--  1 vagrant vagrant  3183 Nov 15 22:19 _printf.c
-rw-rw-r--  1 vagrant vagrant  2364 Nov 20 07:34 README.md
-rw-rw-r--  1 vagrant vagrant  3189 Nov 19 23:31 shell.h
-rw-rw-r--  1 vagrant vagrant  1098 Nov 20 01:51 simple_shell.c
-rw-rw-r--  1 vagrant vagrant  1363 Nov 18 02:39 strings1.c
-rw-rw-r--  1 vagrant vagrant  3032 Nov 19 23:31 strings2.c
-rw-rw-r--  1 vagrant vagrant  1099 Nov 19 23:31 strings3.c
$ exit
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$
```

## File Descriptions
---
File | Description
--- | ---
`_eprintf.c` | a custom `printf()` that prints to standard error
`_printf.c` | a custom verson of `printf()` that handles `string` and `int`
`built_ins.c` | enables the shell to execute certain custom built-ins
`changeenv.c` | allows changes to be made to the environment
`envlistfunc.c` | contains functions for manipulating `env` as a linked list
`man_1_simple_shell` | a man page for `hsh`
`path.c` | enables the creation and searching of `PATH`
`shell.h` | contains directives, libraries, structures, and function prototypes
`simple_shell.c` | the `main` file that executes the shell
`strings1.c` | custom versions of `strcpy`, `strlen`, `puts`, `strchr`, `strdup`
`strings2.c` | custom versions of `strcat`, `realloc`, `strtok`, and tokenizer-related functions
`strings3.c` | custom versions of `strcmp` and `atoi`
 | Files not described: `.gitignore`, `AUTHORS`, `README.md`

## Constraints
  * No more than 5 functions per file
  * Program must have the exact same output as `sh` (`/bin/sh`)
  * `Betty` [styling](https://github.com/holbertonschool/Betty/wiki)
  * Only certain functions were allowed; many `STL` functions were recreated
  * Those functions allowed are: `access`, `chdir`, `close`, `closedir`, `execve`, `exit`, `fork`, `free`, `stat`, `lstat`, `fstat`, `getcwd`, `getline`, `kill`, `malloc`, `open`, `opendir`, `perror`, `read`, `readdir`, `signal`, `strtok`, `wait`, `waitpid`, `wait3`, `wait4`, `write`, `_exit`, `isatty`, `fflush`

## Authors
  * Thomas Dumont - github: `vilyanare`
  * Jacob Hartman - github: `JacobBHartman`
