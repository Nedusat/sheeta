#include "kernel.h"

#include "sys/imfs.h"

int kernel_init()
{
	IMFS_init();
	return 0;
}

int kernel_terminate()
{
	IMFS_terminate();
	return 0;
}
