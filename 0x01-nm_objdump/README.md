# 0x01. C - ELF: nm/objdump
## Learning Objectives
<li>What is the ELF format</li>
<li>What are the commands nm and objdump</li>
<li>How to use them properly</li>
<li>How to parse the content of an ELF file</li>
<li>What information can be extracted from an ELF file</li>
<li>What are the differences between nm and objdump</li>

#
## Requirements
<li>Allowed editors: vi, vim, emacs</li>
<li>All your files will be compiled on Ubuntu 14.04 LTS</li>
<li>Your C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic</li>
<li>All your files should end with a new line</li>
<li>A README.md file, at the root of the folder of the project, is mandatory</li>
<li>Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl</li>
<li>You are not allowed to have more than 5 functions per file</li>
<li>All your header files should be include guarded</li>

#
## Allowed Functions and System Calls
<li>Unless specified otherwise, you are allowed to use the C standard library</li>
<li>You’re not allowed to use system(3)</li>
<li>You’re not allowed to use exec*(2 and 3)</li>

#
## Compilation
<li>You have to provide a Makefile in order to compile each task</li>
<li>Make sure each task compiles on Ubuntu 14.04 LTS, with gcc 4.8.4</li>
<li>You must compile each task using the flags -Wall -Werror -Wextra and -pedantic</li>

#
## Tests
<li>Your program must be able to handle both 32-bit and 64-bit ELF files</li>
<li>Your program must be able to handle both little and big endian ELF files</li>
<li>Your program must be able to handle all types of ELF files</li>

#
# Tasks
## 0. nm
Write a program that reproduces the GNU nm command
<li>Usage: hnm [objfile ...]</li>
<li>The output should be the exact same as nm -p</li>
<li>Your sources must be compiled and linked using a Makefile</li>
Your makefile must define the rule hnm and compile the needed sources to form the executable hnm

#
## 1. objdump -sf
Write a program that reproduces the GNU objdump command
<li>Usage: hobjdump [objfile ...]</li>
<li>The output should be the exact same as objdump -sf</li>
<li>Your sources must be compiled and linked using a Makefile</li>
Your makefile must define the rule hobjdump and compile the needed sources to form the executable hobjdump