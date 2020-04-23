#ifndef KERNEL_H
  #define KERNEL_H

#include "general.h"

u16* VGA_BUFFER;
u16 VGA_INDEX;

struct command_exec {

};

struct command_inst {

  command_exec* execute;

};

struct command_pool {

  

};

int kernel_init();

#endif
