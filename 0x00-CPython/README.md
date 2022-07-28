# 0x00. CPython

![Cartoon Image](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/277/3052.jpg)

## Requirements:

### General:

- Allowed editors: vi, vim, emacs.<br>
- All your files will be compiled on Ubuntu 14.04 LTS. <br>
- All your files should end with a new line. <br>
- A README.md file, at the root of the folder of the project is mandatory. <br>

### Big O Notation in Answer File

- O(1)
- O(n)
- O(n!)
- n square -> O(n^2)
- log(n) -> O(log(n))
- n * log(n) -> O(nlog(n))
- Please use the “short” notation (don’t use constants)
- All your answers files must have an empty line at the end

## Tasks

### 0. Lists big O

---

Write the big O notations for the following lists operations (one per line, in this exact order):

- L1 - Assigning. Example: holberton[98] = 402
- L2 - Appending. Example: holberton.append(98)
- L3 - Concatenating a list of n elements. Example: holberton + [98, 402]
- L4 - Inserting an item at a given position. Example: holberton.insert(98, 402)
- L5 - Removing an element. Example: holberton.remove(98)
- L6 - Removing and returning the last item in the list. Example: holberton.pop()
- L7 - Poping an element at a given position. Example: holberton.pop(98)
- L8 - Clearing a list. Example: holberton.clear()
- L9 - Counting the list. Example: holberton.count()
- L10 - Sorting the list. Example: holberton.sort()
- L11 - Reversing the list. Example: holberton.reverse()
- L12 - Deleting the list. Example: del holberton

---

### 1. CPython #0: Python lists

CPython is the reference implementation of the Python programming language. <br>
Written in C, CPython is the default and most widely used implementation of the language. <br>
Since we now know a bit of C, we can look at what is happening under the hood of Python. <br>
Let’s have fun with Python and C, and let’s look at what makes Python so easy to use. <br>

![aww yeah gif](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-higher-level_programming+/241/giphy-3.gif)

Create a C function that prints some basic info about Python lists.

- Prototype: void print_python_list(PyObject *p);
- Format: see example
- Python version: 3.4
- Your shared library will be compiled with this command line: <br>
gcc -Wall -Werror -Wextra -pedantic -std=c99 -shared -Wl,-soname,PyList -o libPyList.so -fPIC -I/usr/- include/python3.4 1-python.c
- OS: Ubuntu 14.04 LTS
- Start by reading: 
	- listobject.h
	- object.h
	- Common Object Structures
	- List Objects

### 2. CPython #1: PyBytesObject

---

Create two C functions that print some basic info about Python lists and Python bytes objects.

![Knights Who Say Ni](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-higher-level_programming+/243/giphy-4.gif)

Python lists:
- Prototype: void print_python_list(PyObject *p);
- Format: see example

Python bytes:
- Prototype: void print_python_bytes(PyObject *p);
- Format: see example
- Line “first X bytes”: print a maximum of 10 bytes
- If p is not a valid PyBytesObject, print an error message (see example)
- Read /usr/include/python3.4/bytesobject.h

About:

- Python version: 3.4
- Your shared library will be compiled with this command line: gcc -Wall -Werror -Wextra -pedantic -std=c99 -shared -Wl,-soname,libPython.so -o libPython.so -fPIC -I/usr/include/python3.4 2-python.c
- You are not allowed to use the following macros/functions:
	- Py_SIZE
	- Py_TYPE
	- PyList_GetItem
	- PyBytes_AS_STRING
	- PyBytes_GET_SIZE