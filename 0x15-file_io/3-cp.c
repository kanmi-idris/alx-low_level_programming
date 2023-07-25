#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * open_files - opens the files to copy
 *
 * @file_from: the name of the file to copy from
 * @file_to: the name of the file to copy to
 * Return: an array of file structs, or NULL on failure
 */
file_t *open_files(char *file_from, char *file_to)
{
	file_t *fd;
	int fd_from = open(file_from, O_RDONLY);
	int fd_to = open(file_to, O_WRONLY | O_CREAT, 0664);

	fd = malloc(sizeof(file_t) * 2);
	if (fd == NULL)
		return (NULL);

	fd[0].fd = fd_from;
	fd[0].name = file_from;
	fd[1].fd = fd_to;
	fd[1].name = file_to;

	if (fd_from == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", file_from);
		free(fd);
		exit(98);
	}

	if (fd_to == -1)
	{
		dprintf(2, "Error: Can't write to %s\n", file_to);
		free(fd);
		exit(99);
	}

	return (fd);
}

/**
 * copy_content - copies the content of a file to another file
 *
 * @fd: an array of file structs
 */
void copy_content(file_t *fd)
{
	char buffer[1024];
	int bytes_read;
	int bytes_written;

	while ((bytes_read = read(fd[0].fd, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(fd[1].fd, buffer, bytes_read);
		if (bytes_written == -1)
		{
			dprintf(2, "Error: Can't write to %s\n", fd[1].name);
			free(fd);
			exit(99);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", fd[0].name);
		free(fd);
		exit(98);
	}
}

/**
 * close_files - closes the files
 *
 * @fd: an array of file structs
 */
void close_files(file_t *fd)
{
	int res;

	res = close(fd[0].fd);
	if (res == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd[0].fd);
		free(fd);
		exit(100);
	}

	res = close(fd[1].fd);
	if (res == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd[1].fd);
		free(fd);
		exit(100);
	}

	free(fd);
}

/**
 * main - copies the content of a file to another file
 *
 * @argc: the number of arguments
 * @argv: the arguments
 * Return: 0 on success and -1 on failure
 */
int main(int argc, char *argv[])
{
	file_t *fd;

	if (argc != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd = open_files(argv[1], argv[2]);
	copy_content(fd);
	close_files(fd);

	return (0);
}
