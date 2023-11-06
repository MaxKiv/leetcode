#include "ht.h"
#include <assert.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  char *s;
  char *t;
} input;

// check if s and t are anagrams by counting each letter using a hash table
bool isAnagram(char *s, char *t) {
  ht *table = ht_create(26);
  if (table == NULL) {
    printf("OOM\n");
    return false;
  }

  // Initialise table to ones
  for (size_t i = 0; i < 26; ++i) {
    // insert char
    char c[2] = {0};
    c[0] = 'a' + i;
    int *init_count = (int*) malloc(sizeof(int));
    *init_count = 1;
    ht_set(table, c, init_count);
  }

  // Count chars in string s
  for (const char *c = s; *c; ++c) {
    char key[2] = {0};
    key[0] = *c;

    int *val_ptr = (int *)ht_get(table, key);
    if (val_ptr == NULL) {
      printf("found NULL value for char %c, should never happen...\n", *c);
      assert(false);
    } else {
      (*val_ptr)++;
    }
  }

  // Subtract char count from string t
  for (const char *c = t; *c; ++c) {
    // Get this letters remaining count
    char key[2] = {0};
    key[0] = *c;

    int *val_ptr = (int *)ht_get(table, key);
    if (val_ptr == NULL) {
      printf("found NULL value for char %c, should never happen...\n", *c);
      assert(false);
    } else if (*val_ptr == 1) {
      // this char from string t was not in s, can't be an anagram
      return false;
    } else {
      (*val_ptr)--;
    }
  }

  // Check if count table is empty
  size_t count = 0;
  size_t capacity = ht_capacity(table);
  for (size_t i = 0; i < capacity; ++i) {
    char key[2] = {0};
    key[0] = 'a' + i;
    int *val_ptr = (int *)ht_get(table, key);
    if (val_ptr == NULL) {
      continue;
    } else {
      ++count;
    }
  }
  if(count == 26) {
    return true;
  }
  return false;
}

int main() {
  input inputs[] = {
      {"a", "a"},
      {"b", "a"},
      {"ab", "ab"},
      {"anagram", "nagaram"},
      {"cat", "tac"},
      {"cat", "rat"},
  };
  size_t num_inputs = sizeof(inputs) / sizeof(inputs[0]);

  for (size_t i = 0; i < num_inputs; ++i) {
    bool out = isAnagram(inputs[i].s, inputs[i].t);
    if (out) {
      printf("YES: %s and %s are an anagram\n", inputs[i].s, inputs[i].t);
    } else {
      printf("NO: %s and %s are no anagram\n", inputs[i].s, inputs[i].t);
    }
  }
}
