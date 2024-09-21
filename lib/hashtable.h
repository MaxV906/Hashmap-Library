#ifndef hashtable_h__
#define hashtable_h__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct map_data {

  char *key;
  void *data;
  struct map_data *next;

} MAP_DATA;  

typedef struct {

  MAP_DATA *table;
  unsigned int size;

} HASHTABLE;  

unsigned int hash(char* key, unsigned int size);
HASHTABLE *hashtable_init(unsigned int size);
bool hashtable_insert(char *key, void *data, HASHTABLE *hashtable);
bool hashtable_delete(char *key, HASHTABLE *hashtable);
void *hashtable_find(char *key, HASHTABLE *hashtable);
void hashtable_free(HASHTABLE *hashtable);

#endif
