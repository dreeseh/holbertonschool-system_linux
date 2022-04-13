#include "signals.h"

/**
 * current_handler_signal - handles signal
 * Return: is void
 */
void (*current_handler_signal(void))(int)
{
	void (*handler)(int) = signal(SIGINT, SIG_DFL);

	if (signal(SIGINT, handler) == SIG_ERR)
		return (NULL);

	return (handler);
}
