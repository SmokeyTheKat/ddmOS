#ifndef __DDMOS_ATA_H__
#define __DDMOS_ATA_H__

#include <ddcLib/ddcDef.h>

void ata_read_sectors(void* target_address, uint32t lba, uint8t sector_count);
void ata_write_sectors(uint32t lba, uint8t sector_count, void* bytes);

#endif
