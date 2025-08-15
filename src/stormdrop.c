#include "stormdrop.h"

uint64_t stormdrop64(struct stormdrop64_s *s) {
  uint64_t mix = (s->elements[s->b & 511] ^ s->a) + s->b;

  s->a = ((s->a << 35) | (s->a >> 29)) ^ s->b;
  s->b += 111111111111111111ULL;
  s->elements[s->b & 511] += (mix << 23) | (mix >> 41);
  return mix;
}

uint32_t stormdrop32(struct stormdrop32_s *s) {
  uint32_t mix = (s->elements[s->b & 1023] ^ s->a) + s->b;

  s->a = ((s->a << 17) | (s->a >> 15)) ^ s->b;
  s->b += 1111111111;
  s->elements[s->b & 1023] += (mix << 13) | (mix >> 19);
  return mix;
}
