#include <stdio.h>
#include <stdlib.h>
#include "lib/hashtable.h"

int main() {

  HASHTABLE *t = hashtable_init(40);

  hashtable_insert("hello", "Hello World", t);
  hashtable_insert("test", "Testing", t);
  hashtable_insert("number", (int *) 17, t);

  printf("Data stored in key <hello> is: %s\n", hashtable_find("hello", t));
  printf("Data stored in key <test> is: %s\n", hashtable_find("test", t));
  printf("Data stored in key <number> is: %d\n", hashtable_find("number", t));

  hashtable_delete("hello", t);
  hashtable_delete("test", t);
  hashtable_delete("number", t);

  hashtable_free(t);

  return 0;

}  
