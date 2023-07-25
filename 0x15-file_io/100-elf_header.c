#include <elf.h>
#include <fcntl.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ELF_MAGIC_SIZE 16
#define UNKNOWN "<unknown: %02x>\n"

void print_error(const char *message)
{
	perror(message);
	exit(98);
}

void print_magic(const unsigned char *e_ident)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:");
	for (i = 0; i < ELF_MAGIC_SIZE; ++i)
	{
		printf(" %02x", e_ident[i]);
	}
	printf("\n");
}

void print_class(const unsigned char *e_ident)
{
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
	{
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf(UNKNOWN, e_ident[EI_CLASS]);
		break;
	}
}

void print_data(const unsigned char *e_ident)
{
	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
	{
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf(UNKNOWN, e_ident[EI_DATA]);
		break;
	}
}

void print_version(const unsigned char *e_ident)
{
	printf("  Version:                           %u (current)\n",
		   e_ident[EI_VERSION]);
}

void print_osabi(const unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
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
		printf(UNKNOWN, e_ident[EI_OSABI]);
		break;
	}
}

void print_abiversion(const unsigned char *e_ident)
{
	printf("  ABI Version:                       %u\n", e_ident[EI_ABIVERSION]);
}

void print_type(uint16_t e_type)
{
	printf("  Type:                              ");
	switch (e_type)
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
		printf("<unknown: %04x>\n", e_type);
		break;
	}
}

void print_entry(uint64_t e_entry)
{
	printf("  Entry point address:               0x%" PRIx64 "\n", e_entry);
}

void print_elf_header(const Elf64_Ehdr *header)
{
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abiversion(header->e_ident);
	print_type(header->e_type);
	print_entry(header->e_entry);
}

int main(int argc, char *argv[])
{
	const char *filename;
	int fd;
	unsigned char elf_magic[] = {0x7F, 'E', 'L', 'F'};
	union
	{
		unsigned char buffer[sizeof(Elf64_Ehdr)];
		Elf32_Ehdr *ehdr32;
		Elf64_Ehdr *ehdr64;
	} header;

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

	close(fd);

	/* Verify the ELF magic number */
	if (memcmp(header.buffer, elf_magic, ELF_MAGIC_SIZE) != 0)
	{
		print_error("Not an ELF file");
	}

	/* Print the ELF header depending on the class */
	if (header.buffer[EI_CLASS] == ELFCLASS32)
	{
		print_elf_header((Elf64_Ehdr *)header.ehdr32);
	}
	else if (header.buffer[EI_CLASS] == ELFCLASS64)
	{
		print_elf_header(header.ehdr64);
	}
	else
	{
		print_error("Unknown ELF class");
	}

	return (0);
}
