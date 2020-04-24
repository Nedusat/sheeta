#ifndef KERNEL_H
  #define KERNEL_H

#include "general.h"
#include <def.h>

u16* VGA_BUFFER;
u16 VGA_INDEX;

struct command_exec_s;
struct command_inst_s;
struct command_buffer_s;

typedef struct command_exec_s command_exec;
typedef struct command_inst_s command_inst;
typedef struct command_buffer_s command_buffer;

struct command_exec_s {

};

struct command_inst_s {

  command_exec* execute;

};

struct command_buffer_s {

  uint32_t length;
  command_inst* buffer;

};

typedef struct command_exec_s command_exec;
typedef struct command_inst_s command_inst;
typedef struct command_buffer_s command_buffer;

int kernel_init();
int kernel_terminate();

#endif
