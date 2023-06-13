#!/bin/bash
# This line is a shebang that tells the operating system to use bash as the interpreter for this script

gcc -c *.c
# This line uses the gcc command to compile all the .c files in the current directory into object files with the -c flag

ar -rc liball.a *.c
# This line uses the ar command to create a static library called liball.a from all the .c files in the current directory with the -rc flags
