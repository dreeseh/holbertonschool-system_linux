#include "server_API.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	return (spinup_server());
}

int break_print_request(int fd_client_socket)
{
	char buffer[1024] = {0};
	char *method, *path, *http_version;

	read(fd_client_socket, buffer, 1024);
	printf("Raw request: \"%s", buffer);

	method = strtok(buffer, " ");
        path = strtok(NULL, " ");
        http_version = strtok(NULL, "\r\n");

	printf("\"\n");
	printf("Method: %s\n", method);
        printf("Path: %s\n", path);
        printf("Version: %s\n", http_version);

	return(send_message(fd_client_socket));
}