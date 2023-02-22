#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>

/**
 * main - entry point to progran that connects
 * to a listening server on port 12345
 * @argc: cli argument count
 * @argv: cli argument vector
 * Return: 0 for seccess, 1 upon failure
 */
int main(int argc, char **argv)
{
	int client_socket;
	struct sockaddr_in server_address;

	if (argc != 3)
	{
		printf("Usage: %s <host> <port>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	/** create a socket */
	client_socket = socket(PF_INET, SOCK_STREAM, 0);
	if (client_socket < 0)
	{
		perror("socket create error");
		exit(EXIT_FAILURE);
	}
	/** connect to the server */
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(atoi(argv[2]));
	if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) > 0)
	{
		perror("inet_pton error");
		exit(EXIT_FAILURE);
	}
	if (connect(client_socket, (struct sockaddr *)&server_address,
					sizeof(server_address)) < 0)
	{
		perror("client socket connect error");
		exit(EXIT_FAILURE);
	}

	printf("Connected to %s:%s\n", argv[1], argv[2]);

	/** close the socket */
	close(client_socket);
	return (EXIT_SUCCESS);
}
