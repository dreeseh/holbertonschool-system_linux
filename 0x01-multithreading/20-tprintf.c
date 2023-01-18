#include "multithreading.h"

static pthread_mutex_t mutex_print;
void mutex_constructor(void) __attribute__((constructor));
void mutex_destructor(void) __attribute__((destructor));

/**
 * mutex_constructor - initializes the mutex
 * Return: is void
 */
void mutex_constructor(void)
{
	if (pthread_mutex_init(&mutex_print, NULL) != 0)
	{
		printf("mutex initialization fail\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * mutex_destructor - destroys the mutex
 * Return: is void
 */
void mutex_destructor(void)
{
	if (pthread_mutex_destroy(&mutex_print) != 0)
	{
		printf("mutex destroy fail\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * tprintf - uses the printf family to print out a given formatted string
 * @format: format string for printed output, followed by vargs
 * Return: 0 on success, 1 upon failure
 */
int tprintf(char const *format, ...)
{
	va_list arguments;
	pthread_t thread_number;

	va_start(arguments, format);

	if (!format)
	{
		printf("format string error");
		exit (EXIT_FAILURE);
	}

	if (pthread_mutex_lock(&mutex_print) != 0)
	{
		printf("Mutex lock has failed\n");
		exit (EXIT_FAILURE);
	}

	thread_number = pthread_self();
	printf("[%lu] ", thread_number);
	vprintf(format, arguments);
	
	if (pthread_mutex_unlock(&mutex_print) != 0)
	{
		printf("mutex unlock failed");
		exit(EXIT_FAILURE);
	}

	va_end(arguments);

	return (EXIT_SUCCESS);
}
