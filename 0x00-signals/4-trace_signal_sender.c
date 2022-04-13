#include "signals.h"

/**
 * sig_quit_handler - handles the SIGQUIT signal
 * @sig: signal numnber that caused invocation
 * @info: a pointer to siginfo_t
 * @ucontext: pointer to ucintext struct cast to void
 * Return: is void
 */
void sig_quit_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void) sig;
	(void) ucontext;

	printf("SIGQUIT sent by %i\n", info->si_pid);
	fflush(stdout);
}

/**
 * trace_signal_sender - shows the sender of the signal
 * Return: 0 on success, or -1 on error
 */
int trace_signal_sender(void)
{
	struct sigaction sig_action;

	sig_action.sa_flags = SA_SIGINFO;
	sig_action.sa_sigaction = sig_quit_handler;

	return (sigaction(SIGQUIT, &sig_action, NULL));
}
