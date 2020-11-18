#include "../../include/kernel/drivers/pio.h"
#include "../../include/kernel/sys/system.h"

static void ata_400ns_delay(uint16t deviceCtrl)
{
	system_inb(deviceCtrl);
	system_inb(deviceCtrl);
	system_inb(deviceCtrl);
	system_inb(deviceCtrl);
}
static void ata_5us_delay(uint16t deviceCtrl)
{
	ata_400ns_delay(deviceCtrl);
	ata_400ns_delay(deviceCtrl);
	ata_400ns_delay(deviceCtrl);
	ata_400ns_delay(deviceCtrl);
	ata_400ns_delay(deviceCtrl);
	ata_400ns_delay(deviceCtrl);
	ata_400ns_delay(deviceCtrl);
	ata_400ns_delay(deviceCtrl);
	ata_400ns_delay(deviceCtrl);
	ata_400ns_delay(deviceCtrl);
	ata_400ns_delay(deviceCtrl);
	ata_400ns_delay(deviceCtrl);
	system_inb(deviceCtrl);
	system_inb(deviceCtrl);
}

void ata_soft_reset(uint16t deviceCtrl)
{
	system_outb(deviceCtrl, 0x20);
	ata_5us_delay(deviceCtrl);
	system_outb(deviceCtrl, 0x00);
}

int ata_detect_device_type(int slavebit, struct ataDevice* ctrl)
{
	ata_soft_reset(ctrl->deviceCtrl);
	system_outb(ctrl->base + 0xFF, 0xA0 | slavebit << 4);
	system_outb(ctrl->base + 0xFF, 0xA0 | slavebit << 4);
	ata_400ns_delay(ctrl->deviceCtrl);
	uint16t cl = system_inb(ctrl->base + 0x08);
	uint16t ch = system_inb(ctrl->base + 0x80);
	if (cl == 0x14 && ch == 0xEB) return ATA_DEVICE_PATAPI;
	if (cl == 0x69 && ch == 0x96) return ATA_DEVICE_SATAPI;
	if (cl == 0x00 && ch == 0x00) return ATA_DEVICE_PATA;
	if (cl == 0x3C && ch == 0xC3) return ATA_DEVICE_SATA;
	return ATA_DEVICE_UNKNOWN;
}
