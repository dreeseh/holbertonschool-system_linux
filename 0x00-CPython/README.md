# 0x00. CPython

![Cartoon Image](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/277/3052.jpg)

## Requirements:

### General:

- Allowed editors: <font color="red">vi, vim, emacs.</font> <br>
- All your files will be compiled on Ubuntu 14.04 LTS. <br>
- All your files should end with a new line. <br>
- A <font color="red">README.md</font> file, at the root of the folder of the project is mandatory. <br>

### Big O Notation in Answer File

- <font color="red">O(1)</font>
- <font color="red">O(n)</font>
- <font color="red">O(n!)</font>
- n square -> <font color="red">O(n^2)</font>
- log(n) -> <font color="red">O(log(n))</font>
- n * log(n) -> <font color="red">O(nlog(n))</font>
- Please use the “short” notation (don’t use constants)
- All your answers files must have an empty line at the end

## Tasks

### 0. Lists big O

---

Write the big O notations for the following lists operations (one per line, in this exact order):

- L1 - Assigning. Example: <font color="red">holberton[98] = 402</font>
- L2 - Appending. Example: <font color="red">holberton.append(98)</font>
- L3 - Concatenating a list of n elements. Example: <font color="red">holberton + [98, 402]</font>
- L4 - Inserting an item at a given position. Example: <font color="red">holberton.insert(98, 402)</font>
- L5 - Removing an element. Example: <font color="red">holberton.remove(98)</font>
- L6 - Removing and returning the last item in the list. Example: <font color="red">holberton.pop()</font>
- L7 - Poping an element at a given position. Example: <font color="red">holberton.pop(98)</font>
- L8 - Clearing a list. Example: <font color="red">holberton.clear()</font>
- L9 - Counting the list. Example: <font color="red">holberton.count()</font>
- L10 - Sorting the list. Example: <font color="red">holberton.sort()</font>
- L11 - Reversing the list. Example: <font color="red">holberton.reverse()</font>
- L12 - Deleting the list. Example: del <font color="red">holberton</font>

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