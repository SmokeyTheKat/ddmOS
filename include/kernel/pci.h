#ifndef __DDMOS_PCI_H__
#define __DDMOS_PCI_H__

#include <ddcLib/ddcDef.h>

struct pci_device;

void init_pci(void);
void pci_probe(void);
uint16t pci_read_word(uint16t bus, uint16t slot, uint16t func, uint16t offset);
uint16t getVendorID(uint16t bus, uint16t device, uint16t function);
uint16t getDeviceID(uint16t bus, uint16t device, uint16t function);

struct pci_device
{
	uint32t vendor;
	uint32t device;
	uint32t function;
};

#endif
