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
  
  MAP_DATA *curr = &hashtable->table[hash_value];

  while (true) {

    if (!curr->next) curr->next = malloc(sizeof(MAP_DATA));

    if (!curr->key && !curr->data) {

      curr->key = key;
      curr->data = data;

      return true;

    }

    curr = curr->next;
  }

  return false;

}

bool hashtable_delete(char *key, HASHTABLE *hashtable) {

  unsigned int hash_value = hash(key, hashtable->size);

  if (hashtable == NULL) return false;

  MAP_DATA *curr = &hashtable->table[hash_value];
  
  while (curr) {

    if (curr->key) {

      if (!strcmp(key, curr->key)) {

        curr->data = NULL;
        curr->key = NULL;

        return true;

      }

    }

    curr = curr->next;

  }

  return false;

}

void *hashtable_find(char *key, HASHTABLE *hashtable) {

  unsigned int hash_value = hash(key, hashtable->size);

  if (hashtable == NULL) return NULL;

  MAP_DATA *curr = &hashtable->table[hash_value];

  while (curr) {

    if (!strcmp(key, curr->key)) return curr->data;
    curr = curr->next;

  }

  return NULL;

}

void hashtable_free(HASHTABLE *hashtable) {

  if (!hashtable) return;

  for (int i = 0; i < hashtable->size; i++) {

    MAP_DATA *curr = hashtable->table[i].next;
    MAP_DATA *next = NULL;

    while (curr) {

      next = curr->next;

      free(curr);
      curr = next;

    }

  }

  free(hashtable->table);
  free(hashtable);

}
