#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - copies the content of a file to another file
 * @argc: the number of arguments
 * @argv: the arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	int ret;
	char c;

	if (argc != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT, 0644);
	if (fd_to == -1)
	{
		dprintf(2, "Error: Can't write to file %s\n", argv[2]);
		exit(99);
	}

	while ((ret = read(fd_from, &c, 1)) != 0)
	{
		if (ret == -1)
		{
			dprintf(2, "Error: Can't read from file %s\n", argv[1]);
			exit(100);
		}

		if (c == '\0')
		{
			break;
		}

		ret = write(fd_to, &c, 1);
		if (ret == -1)
		{
			dprintf(2, "Error: Can't write to file %s\n", argv[2]);
			exit(101);
		}
	}

	close(fd_from);
	close(fd_to);
	if (close(fd_from) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd_from);
		exit(102);
	}

	if (close(fd_to) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd_to);
		exit(103);
	}
	if (access(argv[2], W_OK) == -1)
	{
		dprintf(2, "Error: Can't write to file %s\n", argv[2]);
		exit(99);
	}

	return (0);
}
