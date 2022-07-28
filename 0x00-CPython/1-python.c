#include <Python.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_python_list - prints some basic info about Python lists
 * @p: a pointer to PyObject struct
 * Return: is void
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t sizeof_pylist;
	PyListObject *pylist;
	Py_ssize_t i;

	sizeof_pylist = Py_SIZE(p);
	pylist = (PyListObject *)p;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %ld\n", sizeof_pylist);
	printf("[*] Allocated = %ld\n", pylist->allocated);

	for (i = 0 ; i < sizeof_pylist ; i++)
	{
		printf("Element %ld: %s\n", i, Py_TYPE(pylist->ob_item[i])->tp_name);
	}
}
