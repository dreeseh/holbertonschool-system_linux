#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/**
 * main - program entry point
 * Return: 0 on success, 1 upon failure
 */
int main(void)
{
	unsigned int len;
	int fd_socket, fd_connect, n;
	struct sockaddr_in servaddr, cliaddr;
	char buffer[1024];

	/** create the socket**/
	fd_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (!fd_socket)
	{
		printf("create socket failed");
		exit(0);
	}

	/** set server address */
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(12345);

	/** bind socket to server address **/
	if ((bind(fd_socket, (struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
	{
		printf("Socket bind failed.\n");
		exit(0);
	}

	/** listen for incoming connections **/
	if ((listen(fd_socket, 5)) != 0)
	{
		printf("listen is failing");
		exit(0);
	}
	else
	{
		printf("Server listening on port 12345");
	}

	/** accept incoming connections **/
	len = sizeof(cliaddr);
	fd_connect = accept(fd_socket, (struct sockaddr *)&cliaddr, &len);
	if (fd_connect < 0)
	{
		printf("Server accept failed.\n");
		exit(0);
	}

	/** read data from client **/
	while (1)
	{
		memset(buffer, 0, sizeof(buffer));
		n = read(fd_connect, buffer, sizeof(buffer));
		if (n < 0)
		{
			printf("Read error.\n");
			exit(0);
		}

		printf("Received data: %s\n", buffer);
	}

	/** close tge socket **/
	close(fd_socket);

	return (0);
}
