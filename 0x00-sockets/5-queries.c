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
	char *DELIMITER = " \t\r\n";
	char *path, *query, *save1, *save2, *key, *value;

	read(fd_client_socket, buffer, 1024);
	printf("Raw request: \"%s", buffer);

	strtok(buffer, DELIMITER);
        path = strtok(NULL, DELIMITER);
	path = strtok_r(path, "?", &save1);
	printf("\"\nPath: %s\n", path);

	query = strtok_r(NULL, "&", &save1);
	while(query)
	{
		key = strtok_r(query, "=", &save2);
		value = strtok_r(NULL, "=", &save2);
		printf("Query: \"%s\" -> \"%s\"\n", key, value);
		query = strtok_r(NULL, "&", &save1);
	}

	return(send_message(fd_client_socket));
}