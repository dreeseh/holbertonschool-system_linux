#ifndef _SIGNALS_H_
#define _SIGNALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

/** prototypes**/
int handle_signal(void);
void signal_handler(int sig_num);

void (*current_handler_signal(void))(int);

int handle_sigaction(void);

void (*current_handler_sigaction(void))(int);

int trace_signal_sender(void);



#endif /** _SIGNALS_H_ **/