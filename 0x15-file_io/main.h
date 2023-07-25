#ifndef FILE_IO
#define FILE_IO
#include <stddef.h>
#include <sys/types.h>

/**
 * struct file - a struct that contains a file descriptor and a file name
 *
 * @fd: the file descriptor
 * @name: the file name
 */
typedef struct file
{
	int fd;
	char *name;
} file_t;

int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int main(int argc, char *argv[]);

#endif
