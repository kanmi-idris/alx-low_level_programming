#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - copies the content of a file to another file
 *
 * @argc: the number of arguments
 * @argv: the arguments
 * return: 0 on success and -1 on failure
 */
int main(int argc, char *argv[])
{
	char buffer[1024];
	int bytes_read;
	int fd_to = open(argv[2], O_WRONLY | O_CREAT, 0664);
	int fd_from = open(argv[1], O_RDONLY);

	if (argc != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}

	if (fd_from == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	if (fd_to == -1)
	{
		dprintf(2, "Error: Can't write to file %s\n", argv[2]);
		exit(99);
	}

	while ((bytes_read = read(fd_from, buffer, sizeof(buffer))) > 0)
		write(fd_to, buffer, bytes_read);

	close(fd_from);
	close(fd_to);

	return (0);
}
