#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - entry point for program
 * @argc: the number of args
 * @argv: the arg vector
 * @env:  the environment variable
 * Return: -1 on fail, 0 upon success
 */
int main(int argc, char **argv, char **env)
{
	char *args[] = {"/usr/bin/readelf", "-W", "-s", "", NULL};

	(void)argc;
	args[3] = argv[1];

	if (execve("/usr/bin/readelf", args, env) == -1)
	{
		perror("execv");
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
