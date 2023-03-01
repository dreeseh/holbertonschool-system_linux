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
	char *body, *path_start, *path_end, *key_start, *key_end, *value_start, *value_end;
	char *save1;

	read(fd_client_socket, buffer, 1024);
	printf("Raw request: \"%s", buffer);
	printf("\"\n");

	body = strstr(buffer, "\r\n\r\n") + 4;
	key_start = body;

	path_start = strstr(buffer, "POST ") + 5;
        path_end = strstr(path_start, " ");
        *path_end = '\0';
        printf("Path: %s\n", path_start);

        while (key_start)
	{
		key_end = strchr(key_start, '=');
		if (!key_end)
			break;
		*key_end = '\0';
		key_end++;

		value_start = key_end;
		value_end = strchr(value_start, '&');
		if (value_end)
			*value_end = '\0';
		
		printf("Body param: \"%s\" -> ", key_start);
		value_end++;
		key_start = value_end;
		printf("\"%s\"\n", value_start);
		
		
	}
	
	return(send_message(fd_client_socket));
}