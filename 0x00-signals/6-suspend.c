#include "signals.h"

/**
 * print_caught - prints caught with sig number
 * @sig_num: the signal number
 * Return: is void
 */
void print_caught(int sig_num)
{
	printf("Caught %d\n", sig_num);
	printf("Signal Received\n");
	fflush(stdout);
}

/**
 * main - entry to program
 * Return: always EXIT_SUCCESS
 */
int main(void)
{
	struct sigaction sig_action;

	sig_action.sa_handler = print_caught;
	sigaction(SIGINT, &sig_action, NULL);
	pause();
	return (EXIT_SUCCESS);
}
