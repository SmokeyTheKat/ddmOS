#ifndef __DDMOS_ATA_H__
#define __DDMOS_ATA_H__

#include <ddcLib/ddcDef.h>

void write_sectors_ata_pio(uint32t lba, uint8t sector_count, void* bytes);
void read_sectors_ata_pio(void* target_address, uint32t lba, uint8t sector_count);

#endif
