#include "_getline.h"

/**
 * _getline - reads an entire line from stream
 * @fd: is the file descriptor to read from
 * Return: a null-terminated string, no new line character
 */
char *_getline(const int fd)
{
	static fd_t head;
	fd_t *file_buffer = NULL, *temp = NULL;
	char *lineptr = NULL;

	if (fd == -1)
	{
		if (head.buf == NULL)
			head.buf = (free(head.buf), NULL);
		file_buffer = head.next;
		while (file_buffer != NULL)
		{
			if (file_buffer->buf != NULL)
			{
				free(file_buffer->buf);
				file_buffer->buf = NULL;
			}
			temp = file_buffer;
			file_buffer = file_buffer->next;
			free(temp);
		}
		memset(&head, 0, sizeof(head));
		return (NULL);
	}

	file_buffer = fd_buffer(&head, fd);

	if (file_buffer)
	{
		lineptr = read_to_buffer(file_buffer);
	}

	if (lineptr && lineptr[0] == '\n' && !lineptr[1])
	{
		lineptr[0] = 0;
	}

	return (lineptr);
}

/**
 * read_to_buffer - reads and fills buffer
 * @fb: the file buffer bufer struct
 * Return: success = 0 or error = -1
 */
char *read_to_buffer(fd_t *fb)
{
	char buf[READ_SIZE + 1], *p, *lineptr;
	ssize_t r = 0;

	p = _strchr(fb->buf + fb->i, '\n', fb->len - fb->i);
	if (fb->len == 0 || fb->i >= fb->len || p == NULL)
	{
		while (1)
		{
			r = read(fb->fd, buf, READ_SIZE);
			if (r < 0 || (r == 0 && fb->len == 0))
				return (fb->buf ? (free(fb->buf), NULL) : NULL);
			if (r == 0)
			{
				p = fb->buf + fb->len;
				break;
			}
			fb->buf = _realloc(fb->buf, fb->len, fb->len + r + 1);
			if (fb->buf == NULL)
				return (NULL);
			memcpy(fb->buf + fb->len, buf, r), fb->len += r;
			p = _strchr(fb->buf + (fb->len - r), '\n', r);
			if (p)
			{
				fb->buf[fb->len] = 0;
				break;
			}
		}
	}
	*p = '\0';
	lineptr = malloc(1 + (p - (fb->buf + fb->i)));
	if (lineptr == NULL)
		return (NULL);
	memcpy(lineptr, fb->buf + fb->i, 1 + (p - (fb->buf + fb->i)));
	fb->i = (p - fb->buf) + 1;
	if (fb->i >= fb->len)
	{
		fb->i = fb->len = 0;
		fb->buf = (free(fb->buf), NULL);
	}
	return (lineptr);
}

/**
 * fd_buffer - gets the fd structs info into buffer for use
 * @head: a pointer to head of the linked list
 * @fd: file descriptor
 * Return: a pointer to the head of the fd struct
 */
fd_t *fd_buffer(fd_t *head, const int fd)
{
	fd_t *new_node;

	if (head->buf == NULL && head->fd == '\0'
	    && head->next == NULL)
	{
		head->fd = fd;
		return (head);
	}
	while (head->next && head->next->fd <= fd)
		head = head->next;
	if (head->fd == fd)
		return (head);
	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		return (NULL);
	if (fd < head->fd)
	{
		memcpy(new_node, head, sizeof(*head));
		memset(head, 0, sizeof(*head));
		head->fd = fd;
		head->next = new_node;
		return (head);
	}
	memset(new_node, 0, sizeof(*new_node));
	new_node->fd = fd;
	new_node->next = head->next;
	head->next = new_node;
	return (new_node);
}

/**
 ** _strchr - entry to compare character
 * Desc: _strchr function that locates a character in a string
 * @s: the string to be parsed
 * @c: the character to look for
 * @len: number of bytes to search
 * Return: pointer to memory
 */
char *_strchr(char *s, char c, size_t len)
{
	size_t i = 0;

	for (i = 0; i < len; i++)
	{
		if (s[i] == c)
			return (s + i);
	}
	return (NULL);
}

/**
 * _realloc - entry to reallocate
 * Desc: _realloc function that reallocates a block of memory
 * @ptr: pointer to buffer
 * @old_size: unisigned int type old size
 * @new_size: unsigned int type new size
 * Return: memory allocation, NULL if fails
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		new = malloc(new_size);
		if (new == NULL)
		{
			free(ptr);
			return (NULL);
		}
		free(ptr);
		return (new);
	}
	new = malloc(new_size);
	if (new == NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
		memcpy(new, ptr, old_size);
	free(ptr);
	return (new);
}
