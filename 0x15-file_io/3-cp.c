#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char buffer[1024];
	size_t bytes_read;
	FILE *file_to;
	FILE *file_from;

	if (argc != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = fopen(argv[1], "r");
	if (file_from == NULL)
	{
		dprintf(2, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	file_to = fopen(argv[2], "w");
	if (file_to == NULL)
	{
		dprintf(2, "Error: Can't write to file %s\n", argv[2]);
		exit(99);
	}


	while ((bytes_read = fread(buffer, 1, sizeof(buffer), file_from)) > 0)
	{
		fwrite(buffer, 1, bytes_read, file_to);
	}

	fclose(file_from);
	fclose(file_to);

	return 0;
}
