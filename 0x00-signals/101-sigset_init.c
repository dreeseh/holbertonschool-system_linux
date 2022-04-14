#include "signals.h"

/**
 * sigset_init - a function that initializes a sigset
 * @set: a pointer to the signal set to initialize
 * @signals: a 0-terminated array of int
 * Return: 0 on success, or -1 on error
 */
int sigset_init(sigset_t *set, int *signals)
{
	for (sigemptyset(set); *signals != 0; signals++)
	{
		if (sigaddset(set, *signals))
			return (-1);
	}
	return (0);
}
