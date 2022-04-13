#ifndef _SIGNALS_H_
#define _SIGNALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

/**---------------------**/
/**	prototypes	**/
/**---------------------**/
/**	task 0		**/
int handle_signal(void);
void signal_handler(int sig_num);

/*	task 1		*/
void (*current_handler_signal(void))(int);

/*	task 2		*/
int handle_sigaction(void);

/*	task 3		*/
void (*current_handler_sigaction(void))(int);

/*	task 4		*/
int trace_signal_sender(void);

#endif /** _SIGNALS_H_ **/
