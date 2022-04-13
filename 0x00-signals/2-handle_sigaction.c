#include "signals.h"

/**
 * print_gotcha - prints gotcha and the signal number
 * @sig_num: the signal number
 * Return: is void
 */
void print_gotcha(int sig_num)
{
	printf("Gotcha! [%d]\n", sig_num);
	fflush(stdout);
}

/**
 * handle_sigaction - the sigaction handler
 * Return: 0 on success, or -1 on error
 */
int handle_sigaction(void)
{
	struct sigaction sig_action;

	sig_action.sa_handler = print_gotcha;

	return (sigaction(SIGINT, &sig_action, NULL));
}
