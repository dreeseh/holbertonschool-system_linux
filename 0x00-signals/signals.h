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

/*	task 10		*/
int pid_exist(pid_t pid);

/*	task 12		*/
void all_in_one(void);

/*	task 13		*/
int sigset_init(sigset_t *set, int *signals);

/*	task 14		*/
int signals_block(int *signals);

/*	task 15		*/
int signals_unblock(int *signals);
int _signals_block(int *signals);

#endif /** _SIGNALS_H_ **/
