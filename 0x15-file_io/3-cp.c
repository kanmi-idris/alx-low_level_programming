#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFSIZE 1024
#define USAGE "Usage: cp file_from file_to\n"
#define READ_ERROR "Error: Can't read from file %s\n"
#define WRITE_ERROR "Error: Can't write to %s\n"
#define CLOSE_ERROR "Error: Can't close fd %d\n"

/**
 * open_files - opens the source and destination files
 * @file_from: name of the source file
 * @file_to: name of the destination file
 * Return: an array of file descriptors, or NULL on failure
 */
int *open_files(char *file_from, char *file_to)
{
	int *fds;
	mode_t mode;

	fds = malloc(sizeof(int) * 2);
	if (fds == NULL)
		return (NULL);
	fds[0] = open(file_from, O_RDONLY);
	if (fds[0] == -1)
	{
		dprintf(STDERR_FILENO, READ_ERROR, file_from);
		free(fds);
		exit(98);
	}
	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	fds[1] = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (fds[1] == -1)
	{
		dprintf(STDERR_FILENO, WRITE_ERROR, file_to);
		close(fds[0]);
		free(fds);
		exit(99);
	}
	return (fds);
}

/**
 * close_files - closes the source and destination files
 * @fds: array of file descriptors
 */
void close_files(int *fds)
{
	if (close(fds[0]) == -1)
	{
		dprintf(STDERR_FILENO, CLOSE_ERROR, fds[0]);
		close(fds[1]);
		free(fds);
		exit(100);
	}
	if (close(fds[1]) == -1)
	{
		dprintf(STDERR_FILENO, CLOSE_ERROR, fds[1]);
		free(fds);
		exit(100);
	}
	free(fds);
}

/**
 * copy_content - copies the content of a file to another file
 * @fds: array of file descriptors
 */
void copy_content(int *fds)
{
	int rcount, wcount;
	char buffer[BUFSIZE];

	while ((rcount = read(fds[0], buffer, BUFSIZE)) > 0)
	{
		wcount = write(fds[1], buffer, rcount);
		if (wcount != rcount)
		{
			dprintf(STDERR_FILENO, WRITE_ERROR, argv[2]);
			close_files(fds);
			exit(99);
		}
	}
	if (rcount == -1)
	{
		dprintf(STDERR_FILENO, READ_ERROR, argv[1]);
		close_files(fds);
		exit(98);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, exit with code on failure
 */
int main(int argc, char *argv[])
{
	int *fds;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, USAGE);
		exit(97);
	}
	fds = open_files(argv[1], argv[2]);
	copy_content(fds);
	close_files(fds);
	return (0);
}
