#include "kernel.h"

#include "sys/imfs.h"

#include "drivers/ports/ports.h"
#include "drivers/memory/mem.h" // Should probably be copied to kernel/include/

int kernel_init()
{
	port_byte_out(0x3d4, 14);
	int position = port_byte_in(0x3d5);
	position = position << 8;

	port_byte_out(0x3d4, 15);
	position += port_byte_in(0x3d5);

	int offset_from_vga = position * 2;

	char* vga = 0xb8000;


	vga[offset_from_vga] = 'X';
	vga[offset_from_vga+1] = 0x0f;
	
	IMFS_init();
	return 0;
}

int kernel_terminate()
{
	IMFS_terminate();
	return 0;
}
