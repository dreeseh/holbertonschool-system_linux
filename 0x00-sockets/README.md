# 0x00. Sockets

## TASK 0:
### Write a program that opens an IPv4/TCP socket, and listens to traffic on port 12345 (Any address).<br>

Your program must hang indefinitely (It’ll eventually be killed by a signal during correction)<br>
You don’t have to accept entering connections<br>
Your program’s output won’t be checked, you can output any information you like<br>
In a terminal:<br>

alex@~/0x00-sockets$ gcc -Wall -Wextra -Werror -pedantic -o 0-server 0-server.c <br>
alex@~/0x00-sockets$ ./0-server <br>
Server listening on port 12345<br>
In a second terminal:<br>

alex@~/0x00-sockets$ lsof -i :12345<br>
COMMAND    PID    USER   FD   TYPE DEVICE SIZE/OFF NODE NAME<br>
0-server 24895 vagrant    3u  IPv4 251230      0t0  TCP *:12345 (LISTEN)<br>
alex@~/0x00-sockets$ killall 0-server<br>
alex@~/0x00-sockets$<br>