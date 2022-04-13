#include "signals.h"

/**
 * main - entry point for function
 * @argc: number of args
 * @argv: args vector
 * Return: EXIT_SUCCESS upon success EXIT_FAILURE upon failure
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <signum>\n", *argv);
		return (EXIT_FAILURE);
	}

	printf("%s: %s\n", argv[1], strsignal(atoi(argv[1])));
	return (EXIT_SUCCESS);
}
