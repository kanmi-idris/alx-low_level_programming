#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ELF_MAGIC_SIZE 16

typedef struct
{
	unsigned char magic[ELF_MAGIC_SIZE];
	unsigned char class;
	unsigned char data;
	unsigned char version;
	unsigned char os_abi;
	unsigned char abi_version;
	unsigned char pad[7];
	unsigned short type;
	unsigned short machine;
	unsigned int version2;
	unsigned int entry_point_high;
	unsigned int entry_point_low;
	unsigned int ph_offset;
	unsigned int sh_offset;
	unsigned int flags;
	unsigned short eh_size;
	unsigned short ph_entry_size;
	unsigned short ph_num;
	unsigned short sh_entry_size;
	unsigned short sh_num;
	unsigned short sh_str_index;
} ElfHeader;

void print_error(const char *message)
{
	fprintf(stderr, "Error: %s\n", message);
	exit(98);
}

void print_elf_header(const ElfHeader *header)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:");
	for (i = 0; i < ELF_MAGIC_SIZE; ++i)
	{
		printf(" %02x", header->magic[i]);
	}
	printf("\n");

	printf("  Class:                             ");
	switch (header->class)
	{
	case 1:
		printf("ELF32\n");
		break;
	case 2:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %02x>\n", header->class);
		break;
	}

	printf("  Data:                              ");
	switch (header->data)
	{
	case 1:
		printf("2's complement, little endian\n");
		break;
	case 2:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %02x>\n", header->data);
		break;
	}

	printf("  Version:                           %u (current)\n",
		   header->version);

	printf("  OS/ABI:                            ");
	switch (header->os_abi)
	{
	case 0:
		printf("UNIX - System V\n");
		break;
	case 3:
		printf("UNIX - NetBSD\n");
		break;
	case 6:
		printf("UNIX - Solaris\n");
		break;
	default:
		printf("<unknown: %02x>\n", header->os_abi);
		break;
	}

	printf("  ABI Version:                       %u\n", header->abi_version);

	printf("  Type:                              ");
	switch (header->type)
	{
	case 1:
		printf("REL (Relocatable file)\n");
		break;
	case 2:
		printf("EXEC (Executable file)\n");
		break;
	case 3:
		printf("DYN (Shared object file)\n");
		break;
	default:
		printf("<unknown: %04x>\n", header->type);
		break;
	}

	printf("  Entry point address:               0x%08x%08x\n",
		   header->entry_point_high, header->entry_point_low);
}

int main(int argc, char *argv[])
{
	const char *filename;
	int fd;
	ElfHeader header;
	unsigned char elf_magic[] = {0x7F, 'E', 'L', 'F'};

	if (argc != 2)
	{
		print_error("Usage: elf_header elf_filename");
	}

	filename = argv[1];
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		print_error("Failed to open the file");
	}

	if (read(fd, &header, sizeof(ElfHeader)) != sizeof(ElfHeader))
	{
		close(fd);
		print_error("Failed to read ELF header");
	}

	/* Verify the ELF magic number */
	if (memcmp(header.magic, elf_magic, ELF_MAGIC_SIZE) != 0)
	{
		close(fd);
		print_error("Not an ELF file");
	}

	print_elf_header(&header);

	close(fd);
	return 0;
}
