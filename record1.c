#include "record1.h"

int32_t record1_get_codepoint(struct record1* s, size_t index)
{
  return 0;
}

void record1_set_codepoint(struct record1* s, size_t index, int32_t value)
{
   
}

void record1_init(struct record1 *s, size_t cap)
{
  s->str = malloc(cap);
  s->aux = NULL;
  s->cap = cap;
  s->len = 0;
}
