CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu90 -ggdb3

SRC0 = 4-request.c spinup_server.c
OBJ0 = $(SRC0:.c = o)
NAME0 = todo_api_0

SRC1 = 5-queries.c spinup_server.c
OBJ1 = $(SRC1:.c = o)
NAME1 = todo_api_1

SRC2 = 6-headers.c spinup_server.c
OBJ2 = $(SRC2:.c = o)
NAME2 = todo_api_2

todo_api_0: server_API.h $(OBJ0)
	$(CC) $(OBJ0) -o $(NAME0)

todo_api_1: server_API.h $(OBJ1)
	$(CC) $(OBJ1) -o $(NAME1)

todo_api_2: server_API.h $(OBJ2)
	$(CC) $(OBJ2) -o $(NAME2)
