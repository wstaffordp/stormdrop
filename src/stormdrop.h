#ifndef STORMDROP_H
#define STORMDROP_H

#include <stdint.h>

struct stormdrop64_s {
  uint64_t elements[512];
  uint64_t a;
  uint64_t b;
};

struct stormdrop32_s {
  uint32_t elements[1024];
  uint32_t a;
  uint32_t b;
};

uint64_t stormdrop64(struct stormdrop64_s *s);

uint32_t stormdrop32(struct stormdrop32_s *s);

#endif
