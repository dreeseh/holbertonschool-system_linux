CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu90 -ggdb3

SRC0 = 4-request.c spinup_server.c
OBJ0 = $(SRC0:.c = o)
NAME0 = todo_api_0

todo_api_0: server_API.h $(OBJ0)
	$(CC) $(OBJ0) -o $(NAME0)