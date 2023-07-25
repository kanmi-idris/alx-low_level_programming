#include <elf.h>
#include <fcntl.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ELF_MAGIC_SIZE 16

void print_error(const char *message)
{
	fprintf(stderr, "Error: %s\n", message);
	exit(98);
}

void print_elf_header(const Elf64_Ehdr *header)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:");
	for (i = 0; i < ELF_MAGIC_SIZE; ++i)
	{
		printf(" %02x", header->e_ident[i]);
	}
	printf("\n");

	printf("  Class:                             ");
	switch (header->e_ident[EI_CLASS])
	{
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %02x>\n", header->e_ident[EI_CLASS]);
		break;
	}

	printf("  Data:                              ");
	switch (header->e_ident[EI_DATA])
	{
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %02x>\n", header->e_ident[EI_DATA]);
		break;
	}

	printf("  Version:                           %u (current)\n",
		   header->e_ident[EI_VERSION]);

	printf("  OS/ABI:                            ");
	switch (header->e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	default:
		printf("<unknown: %02x>\n", header->e_ident[EI_OSABI]);
		break;
	}

	printf("  ABI Version:                       %u\n",
		   header->e_ident[EI_ABIVERSION]);

	printf("  Type:                              ");
	switch (header->e_type)
	{
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	default:
		printf("<unknown: %04x>\n", header->e_type);
		break;
	}

	printf("  Entry point address:               0x%" PRIx64 "\n",
		   header->e_entry);
}

int main(int argc, char *argv[])
{
	const char *filename;
	int fd;
	union
	{
		Elf32_Ehdr ehdr32;
		Elf64_Ehdr ehdr64;
	} header;

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

	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		close(fd);
		print_error("Failed to read ELF header");
	}

	/* Verify the ELF magic number */
	if (memcmp(header.ehdr64.e_ident, elf_magic, ELF_MAGIC_SIZE) != 0)
	{
		close(fd);
		print_error("Not an ELF file");
	}

	/* Print the ELF header depending on the class */
	if (header.ehdr64.e_ident[EI_CLASS] == ELFCLASS32)
	{
		print_elf_header((Elf64_Ehdr *)&header.ehdr32);
	}
	else if (header.ehdr64.e_ident[EI_CLASS] == ELFCLASS64)
	{
		print_elf_header(&header.ehdr64);
	}
	else
	{
		close(fd);
		print_error("Unknown ELF class");
	}

	close(fd);
	return (0);
}
