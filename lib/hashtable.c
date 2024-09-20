#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {

  char *key;
  void *data;

} MAP_DATA;  

typedef struct {

  MAP_DATA *table;
  unsigned int size;

} HASHTABLE;

unsigned int hash(char *key, unsigned int size) {

  int hash_value = 0;

  for (int i = 0; i < strlen(key); i++) {

    hash_value += key[i];
    hash_value *= key[i];
    hash_value *= i + 1 + (i*i);

  }

  return hash_value % size;

}  

HASHTABLE *hashtable_init(unsigned int size) {

  HASHTABLE *t = malloc(sizeof(HASHTABLE));

  t->table = malloc(sizeof(MAP_DATA) * size);
  t->size = size;

  return t;

}

bool hashtable_insert(char *key, void *data, HASHTABLE *hashtable) {

  unsigned int hash_value = hash(key, hashtable->size);

  if (hashtable == NULL) return false;
  if (hashtable->table[hash_value].data) return false;

  hashtable->table[hash_value].key = key;
  hashtable->table[hash_value].data = data;

  return true;

}

bool hashtable_delete(char *key, HASHTABLE *hashtable) {

  unsigned int hash_value = hash(key, hashtable->size);

  if (hashtable == NULL) return false;

  hashtable->table[hash_value].key = NULL;
  hashtable->table[hash_value].data = NULL;

  return true;

}

void *hashtable_find(char *key, HASHTABLE *hashtable) {

  unsigned int hash_value = hash(key, hashtable->size);

  if (hashtable == NULL) return NULL;

  return hashtable->table[hash_value].data;

}
