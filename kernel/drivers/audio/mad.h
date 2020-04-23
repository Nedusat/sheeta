/* M.A.D = "Mega Audio Driver" */

#ifndef MAD_H
  #define MAD_H

#include "../../definitions.h"

enum MAD_audio_format : unsigned char {
  MAD_AUD_FORMAT_S8BIT = 0x1,
  MAD_AUD_FORMAT_S16BIT = 0x2,
  MAD_AUD_FORMAT_S24BIT = 0x3,
  MAD_AUD_FORMAT_S32BIT = 0x4,

  MAD_AUD_FORMAT_U8BIT = 0x5,

  MAD_AUD_FORMAT_FLOAT32 = 0x6,
  MAD_AUD_FORMAT_FLOAT64 = 0x7
};

struct MAD_audio_stream {
  MAD_audio_format format;
  double sample_rate;
  uint8_t channels;

  uint32_t length;
  uint8_t* buffer;
};

struct MAD_audio_device {
  const char* identifier;
};

void MAD_init();
void MAD_terminate();

#endif
