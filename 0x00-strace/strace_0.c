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
	int status, in_syscall = 0;
	struct user_regs_struct regs;
	pid_t pid;
	unsigned long syscall_nb;

	/* Validate command-line args here, EXIT_FAILURE if no child command given */
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s <full_path> [path_args]\n", argv[0]);
		return (1);
	}

	pid = fork();

	if (pid == 0)
	{
		ptrace(PTRACE_TRACEME, 0, NULL, NULL);
		execve(argv[1], argv + 1, envp);
		return (1);
	}

	else if (pid > 0)
	{
		/* In parent process, intercept child's syscalls */
		/* Wait for execve to finish */
		wait(&status);

		/* Child-process status has 16 significant bits
		 * Upper 8 bits indicate the signal (we want SIGTRAP)
		 * Lower 8 indicate child is stopped if equal to 0177 (octal)
		 * Alternatively, you could just use `while(status == 1407)` but that's even more opaque
		 */
		while ((status >> 8) == SIGTRAP && (status & 0xFF) == 0177)
		{
			if (!in_syscall)
			{
				/* Stopped after the syscall, get register data here */
				/* Get register values */
				ptrace(PTRACE_GETREGS, pid, NULL, &regs);

				/* Syscall number in orig_rax */
				syscall_nb = (unsigned long)regs.orig_rax;

				/* Print syscall number*/
				printf("%lu\n", syscall_nb);
				in_syscall = 1;

				/* For parts 1-8...
				 * You'll use the syscall number to find data in syscalls_64_g array
				 */
			}else
			{
				/* Stopped during the syscall, get data on next interation */
				in_syscall = 0;
			}

			ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
			wait(&status);
		}	
	}
	else {
		/* Fork failed, EXIT_FAILURE here */
		perror("fork failed");
		exit(EXIT_FAILURE);
	}

	return (0);
}