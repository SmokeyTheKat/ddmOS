#ifndef __DDMOS_KERNEL_H__
#define __DDMOS_KERNEL_H__

#include <ddcLib/ddcDef.h>
#include <boot/multiboot.h>

extern struct multiboot_info* multiboot_ptr;
extern uint64t multiboot_magic;

#endif
