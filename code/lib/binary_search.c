#include <stddef.h>
#include <string.h>
#include <stdio.h>

typedef struct item {
  char* key;
  int value;
} item;

item* binary_search(item* items, size_t num_items, char* key) {
  size_t low = 0;
  size_t high = num_items;
  while(low < high) {
    // Calculate new mid
    size_t mid = low + ((high-low)/2);
    // Check mid index
    int c = strcmp(items[mid].key, key);
    if(c == 0) {
      // Found key, return it
      return &items[mid];
    } else if(c < 0) {
      // eliminate low half of the array
      low = mid + 1;
    } else {
      // eliminate high half of the array
      high = mid;
    }
  }

  // Key not found
  return NULL;
}

int main() {
  item items[] = {
      {"a", 10}, {"b", 12},  {"c", 16},  {"cacacaa", 18},
      {"d", 20}, {"e", 100}, {"f", 200},
  };
  size_t num_items = sizeof(items) / sizeof(items[0]);

  char* keys[] = {
    "a", "b", "f", "z"
  };
  size_t num_keys = sizeof(keys)/sizeof(keys[0]);

  for(size_t i = 0; i < num_keys; ++i) {
    item *found = binary_search(items, num_items, keys[i]);
    if (!found) {
      printf("binary search found nothing for key %s\n", keys[i]);
      return 1;
    }
    printf("binary search returned value of %s is %d\n", keys[i], found->value);
  }
    
  return 0;
}
