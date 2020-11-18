#ifndef __ddmos_pio_h__
#define __ddmos_pio_h__

#include "../../ddcDef.h"

enum
{
	ATA_DEVICE_UNKNOWN=0,
	ATA_DEVICE_PATAPI,
	ATA_DEVICE_SATAPI,
	ATA_DEVICE_PATA,
	ATA_DEVICE_SATA
};

struct ataDevice
{
	uint16t base;
	uint16t deviceCtrl;
};

void ata_soft_reset(uint16t device);
int ata_detect_device_type(int slavebit, struct ataDevice* ctrl);

#endif
