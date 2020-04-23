/* I.M.F.S = "infinite memory file system" */

#ifndef IMFS_H
  #define IMFS_H

#include "../definitions.h"

enum IMFS_file_access {
  IMFS_FA_GLOBAL = 0x1,
  IMFS_FA_ROOT = 0x2,
  IMFS_FA_PRIVATE = 0x3
};

struct IMFS_file {
  const char* filepath;
  IMFS_file_access access;
  uint64_t length;
  void* ptr;
};

void IMFS_push_file(IMFS_file* file);
IMFS_file* IMFS_pull_file(const char* filepath);
void IMFS_erase_file(const char* filepath);

void IMFS_init();
void IMFS_terminate();

#endif
