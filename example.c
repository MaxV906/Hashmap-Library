#include <stdio.h>
#include <stdlib.h>
#include "lib/hashtable.h"

int main() {

  HASHTABLE *t = hashtable_init(10);

  if (!hashtable_insert("hello", "Hello World!", t)) {

    fprintf(stderr, "Failed to insert new data\n");
    return 1;

  }

  printf("Data stored in key <hello> is: %s\n", hashtable_find("hello", t));

  free(t);

  return 0;

}  
