#include "signals.h"

/**
 * signal_handler - handles SIGINT signal
 * Return: is void
 */
void signal_handler(int sig_num)
{
	printf("Gotcha! [%d]\n", sig_num);
	fflush(stdout);
}

/**
 * handle_signal - signal handler
 * Return: 0 on success, or -1 on error
 */
int handle_signal(void)
{
	if (signal(SIGINT, signal_handler) == SIG_ERR)
		return (-1);
	
	return (0);
}