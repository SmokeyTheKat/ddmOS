#ifndef __ELF_H__
#define __ELF_H__

struct elf_header
{
	uint8t str_elf[3];
	uint8t arch_type;
	uint8t endian;
	uint8t elf_header_version;
	uint8t os_abi;
	uint64t upadding_1;
	uint16t file_type;
	uint16t instruction_set;
	uint32t elf_version;
	uint64t entry_point;
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
