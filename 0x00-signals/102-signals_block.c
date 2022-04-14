#include "signals.h"
#include "101-sigset_init.c"

int sigset_init(sigset_t *set, int *signals);

/**
 * signals_block - blocks a given set of signals
 * @signals: a 0-terminated array of int
 * Return: 0 on success, or -1 on error
 */
int signals_block(int *signals)
{
	sigset_t set;

	if (sigset_init(&set, signals))
		return (-1);

	return (sigprocmask(SIG_BLOCK, &set, NULL));
}
