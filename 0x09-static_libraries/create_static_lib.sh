#!/bin/bash
# A shebang that tells the OS to use bash as the interpreter for this script

gcc -c *.c
# Compile all .c files in current dir into object files with gcc -c

ar -rc liball.a *.c
# Create liball.a static library from all .c files in current dir with ar -rc
