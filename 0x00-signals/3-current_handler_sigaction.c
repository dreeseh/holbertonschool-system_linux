#include "signals.h"

/**
 * current_handler_sigaction - retrieves the handler of the signal SIGINT
 * Return: is void
 */
void (*current_handler_sigaction(void))(int)
{
	struct sigaction sig_action;

	if (sigaction(SIGINT, NULL, &sig_action) == -1)
		return (NULL);

	return (sig_action.sa_handler);
}
