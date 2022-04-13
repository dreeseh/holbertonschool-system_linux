#include "signals.h"

/**
 * main - program entry
 * @argc: args count
 * @argv: args vector
 * Return: EXIT_SUCCESS | EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	int pid_number = 0;

	if (argc != 2)
	{
		printf("Usage: %s <pid>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	pid_number = atoi(argv[1]);
	if (kill(pid_number, SIGINT) == 0)
		return (EXIT_SUCCESS);

	return (EXIT_FAILURE);

}
