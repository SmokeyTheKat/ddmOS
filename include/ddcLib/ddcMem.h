#ifndef __ddcLib_ddcMem_h__
#define __ddcLib_ddcMem_h__

#include "../ddcDef.h"

void ddMem_set(void* dest, int value, sizet length);
void ddMem_copy(void* dest, const void* src, sizet length);
void ddMem_copy_setp(void* dest, const void* src, sizet step, sizet length);
void ddMem_copy_offset(void* dest, const void* src, sizet destOffset, sizet srcOffset, sizet length);
void ddMem_copy_offset_step(void* dest, const void* src, sizet destOffset, sizet srcOffset, sizet step, sizet length);
void ddMem_copy_step_offset(void* dest, const void* src, sizet destOffset, sizet srcOffset, sizet step, sizet stepOffset, sizet length);

#endif
