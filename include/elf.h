#ifndef __ELF_H__
#define __ELF_H__

#include <ddcLib/ddcDef.h>

struct elf_header
{
	uint8t idenity[16];
	uint16t type;
	uint16t machine;
	uint32t elf_version;
	uint64t entry;
	uint64t program_header_position;
	uint64t section_header_position;
	uint32t flags;
	uint16t header_size;
	uint16t program_header_size;
	uint16t program_header_entry_count;
	uint16t section_header_size;
	uint16t section_header_entry_count;
	uint16t index_of_section_names;
}__attribute__((__packed__));

#endif
