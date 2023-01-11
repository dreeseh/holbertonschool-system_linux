#include "syscalls.h"


/**
 * main - a program that executes and traces a given command
 * @argc: the commandline argument count
 * @argv: the commandline argument vector
 * @envp: the current environment
 * Return: 0 on success | 1 on failure (not enough arguments)
 **/
int main(int argc, char **argv, char **envp)
{
	int status;
	struct user_regs_struct regs;
	pid_t pid;
	int syscall_return = 1;
	int first_syscall = 1;

	/* Validate command-line args here, EXIT_FAILURE if no child command given */
	if (argc < 2)
	{
		printf("Usage: %s command [args...]\n", argv[0]);
		return (EXIT_FAILURE);
	}

	pid = fork();
	if (pid == -1)
	{
		printf(stderr, "Fork failed\n");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		ptrace(PTRACE_TRACEME, 0, NULL, NULL);

		if (execve(argv[1], argv + 1, envp) == -1)
		{
			dprintf(STDERR_FILENO, "Exec failed: %d\n", errno);
			exit(EXIT_FAILURE);
		}
	}

	else if (pid > 0)
	{
		while (1)
		{
			if (wait(&status) == -1)
				return (1);
			if (WIFEXITED(status))
				break;

			if (!syscall_return || first_syscall)
			{
				if (ptrace(PTRACE_GETREGS, pid, NULL, &regs) == -1)
					return (1);

				printf("%lu\n", (unsigned long)regs.orig_rax);
				first_syscall = 0;
			}
			

		if (ptrace(PTRACE_SYSCALL, pid, NULL, NULL) == -1)
			return (1);
		fflush(stdout);

		/* wait will return after every syscall entry and exit */
		syscall_return = syscall_return ? 0 : 1;
		}
	}
	else
	{
		/* Fork failed, EXIT_FAILURE here */
		perror("fork failed");
		exit(EXIT_FAILURE);
	}

	return (0);
}