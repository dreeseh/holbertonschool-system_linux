# 0x00. Sockets

## TASK 0:
### Write a program that opens an IPv4/TCP socket, and listens to traffic on port 12345 (Any address).<br>

Your program must hang indefinitely (It’ll eventually be killed by a signal during correction)<br>
You don’t have to accept entering connections<br>
Your program’s output won’t be checked, you can output any information you like<br>
In a terminal:<br>

	reese@~/0x00-sockets$ gcc -Wall -Wextra -Werror -pedantic -o 0-server 0-server.c 
	reese@~/0x00-sockets$ ./0-server
	Server listening on port 12345
In a second terminal:<br>

	reese@~/0x00-sockets$ lsof -i :12345
	COMMAND    PID    USER   FD   TYPE DEVICE SIZE/OFF NODE NAME
	0-server 24895 vagrant    3u  IPv4 251230      0t0  TCP *:12345 (LISTEN)
	reese@~/0x00-sockets$ killall 0-server
	reese@~/0x00-sockets$

## TASK 1:
### Write a program that opens an IPv4/TCP socket, and listens to traffic on port 12345 (Any address).<br>
### Your program must accept an entering connection, print the IP address of the connected client, and close the connection right after<br>

In a terminal:

	reese@~/0x00-sockets$ gcc -Wall -Wextra -Werror -pedantic -o 1-server 1-server.c 
	reese@~/0x00-sockets$ ./1-server 
	Server listening on port 12345
	Client connected: 127.0.0.1
	reese@~/0x00-sockets$
In a second terminal:

	reese@~/0x00-sockets$ ./1-client localhost 12345
	Connected to localhost:12345
	reese@~/0x00-sockets$

## TASK 2:
### Write a program that connects to a listening server<br>
Usage: 2-client <host> <port><br>
Where port is an unsigned short<br>
If the number of command-line arguments is not sufficient, your program must display:<br>
Usage: %s <host> <port> (where %s must be replaced by the name of the program), followed by a new line and exit with EXIT_FAILURE<br>
You can assume that <port> will be a positive integer<br>
Once your client established a connection with the server, it must print a message, and exit successfully<br>
In a terminal:

	reese@~/0x00-sockets$ ./2-server 
	Server listening on port 12345
	Client connected: 127.0.0.1
In a second terminal:

	reese@~/0x00-sockets$ gcc -Wall -Wextra -Werror -pedantic -o 2-client 2-client.c 
	reese@~/0x00-sockets$ ./2-client localhost 12345
	Connected to localhost:12345
	reese@~/0x00-sockets$

## TASK 3:
### Write a program that opens an IPv4/TCP socket, and listens to traffic on port 12345 (Any address).<br>
Your program must:<br>
Accept an entering connection<br>
Print the IP address of the connected client<br>
Wait for an incoming message from the connected client<br>
Print the received message<br>
Close the connection with the client<br>
Exit<br>
In a terminal:

	reese@~/0x00-sockets$ gcc -Wall -Wextra -Werror -pedantic -o 3-server 3-server.c 
	reese@~/0x00-sockets$ ./3-server 
	Server listening on port 12345
	Client connected: 127.0.0.1
	Message received: "Holberton School !!!"
	reese@~/0x00-sockets$
In a second terminal:

	reese@~/0x00-sockets$ ./3-client localhost 12345 'Holberton School !!!'
	Connected to localhost:12345
	Sending the message: "Holberton School !!!"
	Sent
	reese@~/0x00-sockets$

## TASK 4:
### Write a program that opens an IPv4/TCP socket, and listens to traffic on port 8080 (Any address).

Your program must:<br>
Accept an entering connection<br>
Print the IP address of the connected client<br>
Wait for an incoming message from the connected client<br>
Print the full received HTTP request<br>
Print the break-down of the first line of the received HTTP request (See example)<br>
Send back a response to the connected client (HTTP 200 OK)<br>
Close the connection with the client<br>
Wait for the next connection<br>

In a terminal:

	reese@~/0x00-sockets$ make todo_api_0
	[...]
	reese@~/0x00-sockets$ ./todo_api_0 
	Server listening on port 8080
	Client connected: 127.0.0.1
	Raw request: "GET /test HTTP/1.1
	User-Agent: curl/7.35.0
	Host: localhost:8080
	Accept: */*

	"
	Method: GET
	Path: /test
	Version: HTTP/1.1
	Client connected: 127.0.0.1
	Raw request: "POST /holberton HTTP/1.1
	User-Agent: curl/7.35.0
	Host: localhost:8080
	Accept: */*

	"
	Method: POST
	Path: /holberton
	Version: HTTP/1.1
	^C
	reese@~/0x00-sockets$
In a second terminal:

	reese@~/0x00-sockets$ curl -D - 'http://localhost:8080/test' 2> /dev/null | cat -e
	HTTP/1.1 200 OK^M$
	^M$
	reese@~/0x00-sockets$ curl -D - -X POST 'http://localhost:8080/holberton' 2> /dev/null | cat -e
	HTTP/1.1 200 OK^M$
	^M$
	reese@~/0x00-sockets$