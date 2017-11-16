# simple_shell

### file and folder descriptions
  * hartman_exercises
  * .gitignore
  * README.md
##### code files
  * _printf.c
  * shell.h
  * simple_shell.c
  * strings1.c

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
