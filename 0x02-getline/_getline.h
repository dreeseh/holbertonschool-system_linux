#ifndef _GETLINE_H_
#define _GETLINE_H_

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

/* defines the number of bytes in read(fd, buffer, READ_SIZE) is called*/
#define READ_SIZE 1020

/* struct for fd (singly linked list) */
/**
 * struct file_descriptor - singly linked fd list
 * @fd: int file descriptor
 * @buf: pointer to char buffer
 * @i: size_t int type
 * @len: size_t int type
 * @next: pointer to next node
 */
typedef struct file_descriptor
{
	int fd;
	char *buf;
	size_t i;
	size_t len;
	struct file_descriptor *next;
} fd_t;

/* prototypes*/
char *_getline(const int fd);
char *read_to_buffer(fd_t *fb);
fd_t *fd_buffer(fd_t *head, const int fd);
char *_strchr(char *s, char c, size_t size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif /* _GETLINE_H_ */
