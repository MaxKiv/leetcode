#include <stddef.h>
#include <string.h>
#include <stdio.h>

#define KEY "cacacaa"

typedef struct item {
  char* key;
  int value;
} item;

item* linear_search(item* items, size_t num_items, char* key) {
  for(size_t i = 0; i < num_items; ++i) {
    if(strcmp(items[i].key, key) == 0) {
      return &items[i];
    }
  }
  return NULL;
}

int main() {
  item items[] = {
      {"a", 10}, {"b", 12},  {"c", 16},  {"cacacaa", 18},
      {"d", 20}, {"e", 100}, {"f", 200},
  };
  size_t num_items = sizeof(items) / sizeof(items[0]);

  item *found = linear_search(items, num_items, KEY);
  if(!found) {
    printf("linear search found nothing for key %s", KEY);
    return 1;
  }
  printf("linear search returned value of %s is %d\n", KEY, found->value);
  
  return 0;
}
