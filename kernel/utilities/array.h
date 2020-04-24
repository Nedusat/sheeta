#ifndef ARRAY_H
  #define ARRAY_H

#include "../definitions.h"

struct array {
  uint32_t length;
  void* items;
};

void push_arr(struct array* arr, uint32_t length, void* items);

#endif
