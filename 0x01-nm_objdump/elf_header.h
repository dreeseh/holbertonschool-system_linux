#ifndef _elf_header_
#define _elf_header_

#include <elf.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/**
 * struct Elf - stores proper data: 32/64 bits
 * @eh64: elf 64bit struct
 * @eh32: elf 32bit struct
 * @sh64: section header 64bit struct
 * @sh32: section header 32bit struct
 * @ph64: program array 64bit struct
 * @ph32: program array 32bit struct
 * @sym64: symbol array 64bit struct
 * @sym32: symbol array 32bit struct
 */
typedef struct Elf
{
	Elf64_Ehdr eh64;
	Elf32_Ehdr eh32;
	Elf64_Shdr *sh64;
	Elf32_Shdr *sh32;
	Elf64_Phdr *ph64;
	Elf32_Phdr *ph32;
	Elf64_Sym *sym64;
	Elf32_Sym *sym32;
} elf_t;

#endif /* end _elf_header_ */