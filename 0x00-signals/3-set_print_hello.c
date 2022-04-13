#include "signals.h"

/**
 * print_hello - prints hello
 * @sig_num: int variable set to void so we can print
 * Return: is void
 */
void print_hello(int sig_num)
{
	(void) sig_num;
	puts("Hello :)");
}

/**
 * set_print_hello - sets print hello's handler
 * Return: is void
 */
void set_print_hello(void)
{
	signal(SIGINT, print_hello);
}
