#include <stdlib.h>
#include <string.h>
#include <uthash.h>

typedef struct Hash {
  int            key;
  char*          val;
  UT_hash_handle hh;
} Hash;

void add_to_hash(Hash* hashTable, int key, char* val)
{
  Hash* hash= (Hash*)malloc(sizeof(Hash));
  hash->key = key;
  hash->val = (char*)malloc(sizeof(val));
  hash->val = strdup(val);
  HASH_ADD_INT(hashTable, key, hash);
}
void hash_init(Hash* hashTable, char** entries, int entriesLen)
{
  for(int i= 0; i < entriesLen; i++) {
    add_to_hash(hashTable, i, entries[i]);
  }
}
char* get_from_hash(Hash* hashTable, int key)
{
  Hash* hash;
  HASH_FIND_INT(hashTable, &key, hash);
  return hash ? hash->val : NULL;
}
void free_hash(Hash* hashTable)
{
  Hash *hash, *tmp;
  HASH_ITER(hh, hashTable, hash, tmp)
  {
    HASH_DEL(hashTable, hash);
    free(hash->val);
    free(hash);
  }
}
