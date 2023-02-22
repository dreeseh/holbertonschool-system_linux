#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>

/**
 * main - entry point to progran that connects
 * to a listening server on port 12345
 * @argc: cli argument count
 * @argv: cli argument vector
 * Return: 0 for seccess, 1 upon failure
 */
int main(int argc, char **argv)
{
	int fd_client;
	struct sockaddr_in server_address;
	struct hostent *host_network_addr;

	if (argc != 3)
	{
		printf("Usage: %s <host> <port>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	fd_client = socket(AF_INET, SOCK_STREAM, 0); /** create a socket */
	if (fd_client < 0)
	{
		perror("socket create error");
		exit(EXIT_FAILURE);
	}

	server_address.sin_family = AF_INET; /** connect to the server */
	server_address.sin_port = htons(atoi(argv[2]));
	host_network_addr = gethostbyname(argv[1]);
	inet_pton(AF_INET, inet_ntoa(*(struct in_addr *)host_network_addr->h_addr),
					&server_address.sin_addr);

	if (connect(fd_client, (struct sockaddr *)&server_address,
					sizeof(server_address)) == -1)
	{
		perror("client socket connect error");
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "Connected to %s:%s\n", argv[1], argv[2]);

	close(fd_client); /** close the socket */
	return (EXIT_SUCCESS);
}
