#include "record1.h"

int main()
{
  struct record1 s;
  record1_init(&s, 5u);
  record1_set_codepoint(&s, 0u, 'a');
  record1_set_codepoint(&s, 1u, 0x1cd);
  int32_t c = record1_get_codepoint(&s, 0u);
  if( c != 'a')
    return 1;
  c = record1_get_codepoint(&s, 1u);
  if( c != 0x1cd )
    return 2;
  
  return 0;
}
