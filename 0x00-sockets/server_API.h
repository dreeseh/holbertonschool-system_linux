#ifndef _SERVER_API_H_
#define _SERVER_API_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>

#define PORT 8080

int spinup_server(void);
int accept_connection(int fd_server_socket, struct sockaddr_in server_address);
int break_print_request(int fd_new_socket);
int send_message(int fd_client_socket);

int break_print_request(int fd_new_socket);

#endif /* _SERVER_API_H_*/
