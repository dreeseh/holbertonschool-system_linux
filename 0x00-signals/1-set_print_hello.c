#include "signals.h"

/**
 * print_hello - receives signal
 * @sig_num: the signal number received
 */
void print_hello(int sig_num)
{
	(void)(sig_num);
	puts("Hello :)");
}

/**
 * set_print_hello - signal handler helper
 * Return: 0 on success else -1 on error
 */
void set_print_hello(void)
{
	signal(SIGINT, print_hello);
}
