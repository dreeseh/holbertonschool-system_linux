#include "multithreading.h"

/**
 * thread_entry - function that serves as the entry point to a new thread
 * @arg: holds the address of a string that must be printed
 * Return: is void*
 */

void *thread_entry(void *arg)
{
	if (arg == NULL)
	{
		pthread_exit(NULL);
	}
	else
	{
		printf("%s\n", (char *)arg);
	}

	pthread_exit(NULL);
}
