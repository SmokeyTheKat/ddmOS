#include <kernel/ata.h>
#include <kernel/system.h>

#define STATUS_BSY 0x80
#define STATUS_RDY 0x40
#define STATUS_DRQ 0x08
#define STATUS_DF 0x20
#define STATUS_ERR 0x01

static void ata_wait_bsy(void)
{
	while (system_inb(0x1F7)&STATUS_BSY);
}
static void ata_wait_drq(void)
{
	while (!(system_inb(0x1F7)&STATUS_RDY));
}
void ata_read_sectors(void* target_address, uint32t lba, uint8t sector_count)
{
	ata_wait_bsy();
	system_outb(0x1F6,0xB0);
	system_outb(0x1F6,0xE0 | ((lba >>24) & 0xF));
	system_outb(0x1F2,sector_count);
	system_outb(0x1F3, (uint8t) lba);
	system_outb(0x1F4, (uint8t)(lba >> 8));
	system_outb(0x1F5, (uint8t)(lba >> 16)); 
	system_outb(0x1F7,0x20);

	uint16t* target = (uint16t*)target_address;

	for (int j = 0; j < sector_count; j++)
	{
		ata_wait_bsy();
		ata_wait_drq();
		for(int i = 0; i < 256; i++)
			target[i] = system_inw(0x1F0);
		target += 256;
	}
}

void ata_write_sectors(uint32t lba, uint8t sector_count, void* vbytes)
{
	ata_wait_bsy();
	system_outb(0x1F6, 0xE0 | ((lba >> 24) & 0xF));
	system_outb(0x1F2, sector_count);
	system_outb(0x1F3, (uint8t)lba);
	system_outb(0x1F4, (uint8t)(lba >> 8));
	system_outb(0x1F5, (uint8t)(lba >> 16)); 
	system_outb(0x1F7, 0x30);

	uint32t* bytes = (uint32t*)vbytes;

	for (int j = 0; j < sector_count; j++)
	{
		ata_wait_bsy();
		ata_wait_drq();
		for (int i = 0; i < 256; i++)
			system_outl(0x1F0, bytes[i]);
	}
}

