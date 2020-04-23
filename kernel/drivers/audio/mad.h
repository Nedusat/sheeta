/* M.A.D = "Mega Audio Driver" */

#ifndef MAD_H
  #define MAD_H

#include "../../definitions.h"

struct MAD_audio_device {
  const char* identifier;
};

struct MAD_audio_buffer {
  uint32_t length;
  uint8_t* buffer;
};

#endif
