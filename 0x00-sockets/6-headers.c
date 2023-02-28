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
	// char *DELIMITER = " \t\r\n";
	char *line, *header, *save1, *save2, *key, *value;

	read(fd_client_socket, buffer, 1024);
	printf("Raw request: \"%s", buffer);

	line = strtok_r(buffer, "\r\n", &save1);
        header = strtok_r(NULL, "\r\n", &save1);
	
	printf("\"\n");
	while(header)
	{
		key = strtok_r(header, ":", &save2);
		value = strtok_r(NULL, "\r\n", &save2);
		value++;
		printf("Header: \"%s\" -> \"%s\"\n", key, value);
		header = strtok_r(NULL, "\r\n", &save1);
	}

	return(send_message(fd_client_socket));
}