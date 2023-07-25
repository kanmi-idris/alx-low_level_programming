#include <elf.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(1);
	}

	FILE *fp = fopen(argv[1], "rb");
	if (fp == NULL)
	{
		fprintf(stderr, "Could not open file '%s'\n", argv[1]);
		exit(1);
	}

	Elf64_Ehdr ehdr;
	if (fread(&ehdr, sizeof(ehdr), 1, fp) != 1)
	{
		fprintf(stderr, "Could not read ELF header from file '%s'\n", argv[1]);
		exit(1);
	}

	if (ehdr.e_ident[EI_MAG0] != ELFMAG0 || ehdr.e_ident[EI_MAG1] != ELFMAG1 ||
		ehdr.e_ident[EI_MAG2] != ELFMAG2 || ehdr.e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "File '%s' is not an ELF file\n", argv[1]);
		exit(98);
	}

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", ehdr.e_ident[i]);
	}
	printf("\n");

	printf("Class:");
	switch (ehdr.e_class)
	{
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	default:
		printf("Unknown\n");
		break;
	}

	printf("Data:");
	switch (ehdr.e_data)
	{
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("Unknown\n");
		break;
	}

	printf("  Version:%d (current)\n", ehdr.e_version);
	printf("  OS/ABI:%d\n", ehdr.e_osabi);
	printf("  ABI Version:%d\n", ehdr.e_abiversion);
	printf("  Type:");
	switch (ehdr.e_type)
	{
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	default:
		printf("Unknown\n");
		break;
	}

	printf("  Entry point address:               %#x\n", ehdr.e_entry);

	fclose(fp);

	return (0);
}
