#ifndef _MEM_H_
#define _MEM_H_

#include <def.h>

void memory_copy(uint8_t* src, uint8_t* dest, int nbytes);
void memory_set(uint8_t* dest, uint8_t val, uint32_t len);

uint32_t malloc(uint32_t size, int align, uint32_t* phys_addr);

#endif
