#include "array.h"

void push_arr(struct array* arr, uint32_t length, void* items)
{
  arr = realloc(arr, (arr->length + length) * sizeof(array));
  for (uint32_t i = arr->length; i < arr->length + length; i++)
    arr->items[i] = items[i - arr->length];
  arr->length+=length;
}
