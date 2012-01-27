#include "record1.h"

int32_t record1_get_codepoint(struct record1* s, size_t index)
{
  if( s->len < index ) {
    return -1;
  }
  int32_t val = s->str[index];
  if( (val & 0x7f) == val ) {
    return val;
  }

  int32_t r = ((val & 0x1f) << 16) | s->aux[index];
  return r;
}

void record1_set_codepoint(struct record1* s, size_t index, int32_t value)
{
  if( s->cap < index ) {
    return;
  }
  if( index > s->len )
  {
     s->len = index + 1;
  }
  if( (value & 0x7f) == value )
  {
    s->str[index] = (char)value;
    return;
  }

  int32_t lowbits = (value & 0xffff);
  int32_t hibits  = ((value >> 16) & 0xff) | 0x9f;
  if( !s->aux )
  {
    s->aux = malloc(s->cap);
  }
  s->str[index] = (char)hibits;
  s->aux[index] = lowbits;
}

void record1_init(struct record1 *s, size_t cap)
{
  char *i, *e;
  s->str = malloc(cap);
  i = s->str;
  e = i + cap;
  for(;i!=e;++i) *i = 0;
  s->aux = NULL;
  s->cap = cap;
  s->len = 0;
}
