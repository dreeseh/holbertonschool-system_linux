index of:
0x00. C - ELF: readelf

Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

General:
What is the ELF format
What kind of files are in the ELF format
What are the different parts that constitute an ELF file
What information are present in the file header
What information are present in the sections header table
What information are present in the program header table
How to parse an ELF file using C structures

Requirements

General:
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 14.04 LTS
Your C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
All your files should end with a new line
A README.md file, at the root of the folder of the project, is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
You are not allowed to have more than 5 functions per file
All your header files should be include guarded

Betty Compliance:
All the C source files in your directory and subdirectories must be Betty-compliant
Allowed Functions and System Calls
Unless specified otherwise, you are allowed to use the C standard library
You’re not allowed to use system(3)
You’re not allowed to use exec*(2 and 3)

Compilation:
You have to provide a Makefile in order to compile each task
Make sure each task compiles on Ubuntu 14.04 LTS, with gcc 4.8.4
You must compile each task using the flags -Wall -Werror -Wextra and -pedantic

Tests:
Your program must be able to handle both 32-bit and 64-bit ELF files
Your program must be able to handle both little and big endian ELF files
Your program must be able to handle all types of ELF files