#include <sys/types.h>
#include <signal.h>

int pid_exist(pid_t pid);

/**
 * pid_exist - tests if a process exists, given its PID
 * @pid: the PID we care checking
 * Return: the PID or 0 on fail
 */
int pid_exist(pid_t pid)
{
	return (!kill(pid, 0));
}
