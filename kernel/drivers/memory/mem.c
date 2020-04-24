#include "mem.h"

void memory_copy(uint8_t* src, uint8_t* dest, int nbytes)
{
	int i;
	for(i = 0; i < nbytes; i++)
	{
		*(dest + i) = *(src + i);
	}
}

void memory_set(uint8_t* dest, uint8_t val, uint32_t len)
{
	uint8_t* temp = (uint8_t*) dest;
	for( ; len != 0; len--) *temp++ = val;
}

uint32_t free_mem_addr = 0x10000;

uint32_t malloc(uint32_t size, int align, uint32_t* phys_addr)
{
	if(align == 1 && (free_mem_addr & 0xFFFFF000))
	{
		free_mem_addr &= 0xFFFFF000;
		free_mem_addr += 0x1000;
	}

	if(phys_addr) *phys_addr = free_mem_addr;

	uint16_t ret = free_mem_addr;
	free_mem_addr += size;
	return ret;
}