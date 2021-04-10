#include <kernel/pci.h>
#include <kernel/system.h>
#include <kernel/mbank.h>
#include <ddcLib/ddcPrint.h>

struct pci_device** pci_devices = 0;
uint32t pci_device_count = 0;

void pci_add_device(struct pci_device* dev)
{
	pci_devices[pci_device_count++] = dev;
	return;
}

uint16t pci_read_word(uint16t bus, uint16t slot, uint16t func, uint16t offset)
{
	uint64t lbus = (uint64t)bus;
	uint64t lslot = (uint64t)slot;
	uint64t lfunc = (uint64t)func;
	uint64t address = (uint64t)((lbus << 16) | (lslot << 11) |
				(lfunc << 8) | (offset & 0xfc) | ((uint32t)0x80000000));
	system_outl (0xCF8, address);
	return (((system_inl (0xCFC) >> ((offset & 2) * 8)) & 0xffffffff));
}

uint16t pci_get_vendor_id(uint16t bus, uint16t device, uint16t function)
{
	return pci_read_word(bus,device,function,0);
}

uint16t pci_get_device_id(uint16t bus, uint16t device, uint16t function)
{
	return pci_read_word(bus,device,function,2);
}

void pci_probe(void)
{
	for (uint32t bus = 0; bus < 256; bus++)
	{
		for (uint32t slot = 0; slot < 32; slot++)
		{
			for (uint32t function = 0; function < 8; function++)
			{
				uint16t vendor = pci_get_vendor_id(bus, slot, function);
				if (vendor == (uint16t)0xffff) continue;
				uint16t device = pci_get_device_id(bus, slot, function);
				ddPrints("vendor: ");
				ddPrint_int(vendor);
				ddPrints(" device: ");
				ddPrint_int(device);
				ddPrints("\n");
				struct pci_device* dev = malloc(sizeof(struct pci_device));
				dev->vendor = vendor;
				dev->device = device;
				dev->function = function;
				pci_add_device(dev);
			}
		}
	}
}

void init_pci(void)
{
	pci_devices = malloc(sizeof(struct pci_device)*32);
	pci_probe();
}
