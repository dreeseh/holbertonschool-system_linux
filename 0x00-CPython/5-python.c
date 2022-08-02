#include <Python.h>

#define abs(x) (((x) < 0) ? -(x) : (x))

void print_python_int(PyObject *p)
{
	unsigned long number = 0;
	Py_ssize_t size, i;
	digit *object_digit;
	
	if (!PyLong_Check(p))
	{
		printf("Invalid Int Object\n");
		return;
	}

	size = ((PyVarObject *)(p))->ob_size;
	object_digit = ((PyLongObject *)(p))->ob_digit;
	
	if (abs(size) > 3 || (abs(size) == 3 && object_digit[2] > 15))
	{
		printf("C unsigned long int overflow\n");
		return;
	}
	
	for (i = 0; i < abs(size); i++)
		number += object_digit[i] * (1L << (i * PyLong_SHIFT));
	
	if (size < 0)	
		putchar('-');

	printf("%lu\n", number);
}