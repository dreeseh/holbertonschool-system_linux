#include "signals.h"

/**
 * all_in_one_sigHandler - signal handler for the below function
 * @sig: number of the signal that caused invocation
 * @info: pointer to a siginfo_t
 * @ucontext: a pointer to a ucontext_t structure, cast to void
 * Return: is void
 */
void all_in_one_sigHandler(int sig, siginfo_t *info, void *ucontext)
{
	(void) sig;
	(void) ucontext;

	psiginfo(info, "Caught");
}

/**
 * all_in_one - sets up a single handler for all the signals
 * Return: is void
 */
void all_in_one(void)
{
	int sig = 0;
	struct sigaction sig_action;

	sig_action.sa_flags = SA_SIGINFO;
	sig_action.sa_sigaction = all_in_one_sigHandler;
	for ( ; sig <= SIGRTMAX ; sig++)
		sigaction(sig, &sig_action, NULL);
}
