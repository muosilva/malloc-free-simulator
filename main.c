#include <stdio.h>
#include "linked_list.h"
#include "memory.h"

int main() {
  list* l = new_list();

  insert(l, 1);
  show(l);

  insert(l, 2);
  show(l);

  insert(l, 3);
  show(l);

  clear_value(l, 20);
  show(l);

  clear_value(l, 1);
  show(l);

  clear(l);
  return 0;
}