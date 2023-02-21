#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 12345

/**
 * main - entry point for socket listener
 * Return: 0 on success, 1 upon failure
 */
int main(void)
{
	int fd_server, new_socket, opt = 1, fd_client_sock;
	struct sockaddr_in address;
	int addrlen = sizeof(address), num_bytes;
	char buffer[1024] = {0};

	fd_server = socket(AF_INET, SOCK_STREAM, 0); /** Create socket */
	if (fd_server == 0)
		exit(EXIT_FAILURE);
	/** Set socket options to reuse address and port */
	if (setsockopt(fd_server, SOL_SOCKET, SO_REUSEADDR |
			SO_REUSEPORT, &opt, sizeof(opt)))
		exit(EXIT_FAILURE);
	address.sin_family = AF_INET; /** Bind socket to the specified port */
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);
	if (bind(fd_server, (struct sockaddr *)&address, sizeof(address)) < 0)
		exit(EXIT_FAILURE);

	if (listen(fd_server, 3) < 0) /** Listen for incoming connections */
	{
		perror("listen failed");
		exit(EXIT_FAILURE);
	}
	printf("Server listening on port %d\n", PORT);
	while (1) /** Accept incoming connections and print client IP address */
	{
		new_socket = accept(fd_server, (struct sockaddr *)&address,
					(socklen_t *)&addrlen);
		if (new_socket < 0)
		{
			perror("accept failed");
			exit(EXIT_FAILURE);
		}
		printf("Client connected: %s\n", inet_ntoa(address.sin_addr));

		/** Receive data from the client */
		fd_client_sock = new_socket;
		if ((num_bytes = read(fd_client_sock, buffer, 1024)) < 0)
		{
			perror("read failed");
			exit(EXIT_FAILURE);
		}

		/** Print the received message */
		printf("Message recieved: \"%s\"\n", buffer);

		close(new_socket); /** Close the connection */
		close(fd_client_sock);
		exit(EXIT_SUCCESS);
	}
}
