#include <Python.h>

#define abs(x) (((x) < 0) ? -(x) : (x))

void print_python_int(PyObject *p)
{
	PyLongObject *_base, *_dig;
	Py_ssize_t s, i, j;
	digit *_p, u, *count;
	twodigits z;
	int dig;

	if (!p || !PyLong_Check(p))
	{
		printf("Invalid Int Object\n");
		return;
	}
	_dig = (PyLongObject *)p;
	dig = (33 * _PyLong_DECIMAL_SHIFT) /
		(10 * PyLong_SHIFT - 33 * _PyLong_DECIMAL_SHIFT);
	s = 1 + abs(Py_SIZE(_dig)) + abs(Py_SIZE(_dig)) / dig;
	_base = _PyLong_New(s);
	if (_base == NULL)
		return;
	_p = _dig->ob_digit, count = _base->ob_digit,  s = 0;
	for (i = abs(Py_SIZE(_dig)); --i >= 0; )
	{
		u = _p[i];
		for (j = 0; j < s; j++)
		{
			z = (twodigits)count[j] << PyLong_SHIFT | u;
			u = (digit)(z / _PyLong_DECIMAL_BASE);
			count[j] = (digit)(z - (twodigits)u * _PyLong_DECIMAL_BASE);
		}
		while (u)
			count[s++] = u % _PyLong_DECIMAL_BASE, u /= _PyLong_DECIMAL_BASE;
	}
	s == 0 ? count[s++] = 0 : 0, Py_SIZE(_dig) < 0 ? putchar('-') : 0;
	for (i = s; --i >= 0;)
		i == s - 1 ? printf("%u", count[i]) : printf("%09u", count[i]);
	printf("\n");
}