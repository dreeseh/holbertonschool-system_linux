#include "syscalls.h"

/**
 * exe_trace - a program that executes and traces a given command.
 * @child_pid: the child process
 * Return: 0 on success, 1 upon failure
 */
int exe_trace(pid_t child_pid)
{
	int status, syscall_return = 1, first_syscall = 1;
	struct user_regs_struct regs;

	while (1)
	{
		if (wait(&status) == -1)
		{
			return (1);
		}

		if (WIFEXITED(status))
		{
			printf(" = ?\n");
			break;
		}

		if (ptrace(PTRACE_GETREGS, child_pid, NULL, &regs) == -1)
		{
			return (EXIT_FAILURE);
		}

		if (!syscall_return || first_syscall)
		{
			printf("%s", syscalls_64_g[regs.orig_rax].name);
			fflush(stdout);
			first_syscall = 0;
		}

		if (syscall_return)
		{
			printf(" = %#lx\n", (unsigned long)regs.rax);
		}

		if (ptrace(PTRACE_SYSCALL, child_pid, NULL, NULL) == -1)
		{
			return (1);
		}
		syscall_return = syscall_return ? 0 : 1;
	}
	return (0);
}



/**
 * main - main file for strace project
 * @argc: argument count
 * @argv: argument array
 * @envp: environment variable
 * Return: 0 on success, 1 upon failur
 */
int main(int argc, char **argv, char **envp)
{
	pid_t pid;
	int retval;

	if (argc < 2 || !argv)
	{
		printf("Usage: %s command [args...]\n", argv[0]);
		return (EXIT_FAILURE);
	}

	pid = fork();
	if (pid == -1)
	{
		printf("fork failed");
		return (EXIT_FAILURE);
	}

	if (pid == 0)
	{
		if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1)
		{
			return (EXIT_FAILURE);
		}

		if (execve(argv[1], argv + 1, envp) == -1)
		{
			return (EXIT_FAILURE);
		}
	}

	retval = exe_trace(pid);

	return (retval);
}
