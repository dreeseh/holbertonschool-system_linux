#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - entry-point for program
 * @argc: number of args
 * @argv: arg vector
 * @env:  environment variable
 * Return: -1 on fail, 1 upon success
 */
int main(int argc, char **argv, char **env)
{
	char *args[] = {"/usr/bin/readelf", "-W", "-S", "", NULL};

	(void)argc;
	args[3] = argv[1];

	if (execve("/usr/bin/readelf", args, env) == -1)
	{
		perror("execv");
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
