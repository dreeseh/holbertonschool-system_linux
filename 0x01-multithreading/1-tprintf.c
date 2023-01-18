#include "multithreading.h"

/**
* tprintf - uses the printf family to print out a given formatted string
* @format: string to print
* Return: 0 on success or 1 upon failure
*/
int tprintf(char const *format, ...)
{
	unsigned long int calling_thread_id;

	if (format != NULL)
	{
		calling_thread_id = pthread_self();
		printf("[%lu] %s", calling_thread_id, format);
	}

	return (EXIT_SUCCESS);
}
