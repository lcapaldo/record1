#ifndef RECORD1_H
#define RECORD1_H
#include <inttypes.h>
#include <stdlib.h>

struct record1
{
  int16_t *aux;
  char *str;
  size_t len;
  size_t cap;
};

int32_t record1_get_codepoint(struct record1* s, size_t index);
void record1_set_codepoint(struct record1* s, size_t index, int32_t value);

void record1_init(struct record1 *s, size_t cap);
#endif
