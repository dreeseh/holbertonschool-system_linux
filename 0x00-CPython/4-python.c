#include <Python.h>
#include <bytesobject.h>

void print_python_string(PyObject *p)
{

	printf("[.] string object info\n");
	if (!p || !PyUnicode_Check(p))
	{
		printf("  [ERROR] Invalid String Object\n");
		return;
	}
	
	if (((PyASCIIObject *)p)->state.ascii)
	{
		printf("  type: compact ascii\n");
		printf("  length: %ld\n", ((PyASCIIObject *)p)->length);
	}
	else{
		printf("  type: compact unicode object\n");
		printf("  length: %ld\n", ((PyASCIIObject *)p)->length);
		printf("  value: %ls\n", PyUnicode_AS_UNICODE(p));
	}

}