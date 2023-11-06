#include "ht.h"
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 16

// Hash table entry
typedef struct ht_entry {
  const char *key; // NULL if slot is empty
  void *value;
} ht_entry;

// Hash table structure
struct ht {
  ht_entry *entries; // Hash slots
  size_t capacity;   // Max number of items in hash table
  size_t length;     // Number of items currently in hash table
};

// Create a hash table and return a pointer to it, returns NULL if OOM
ht *ht_create(size_t initial_capacity) {
  // Allocate
  ht *table = (ht *)malloc(sizeof(ht));
  if (table == NULL) {
    return NULL;
  }
  // Init members
  table->length = 0;
  table->capacity = initial_capacity ? initial_capacity : INITIAL_CAPACITY;

  table->entries = (ht_entry *)calloc(table->capacity, sizeof(ht_entry));
  if (table->entries == NULL) {
    free(table);
    return NULL;
  }

  return table;
}

// Free memory allocated to a hash table, also frees allocated keys
void ht_destroy(ht *table) {
  // Free allocated keys
  for (size_t i = 0; i < table->capacity; ++i) {
    free((void *)table->entries[i].key);
  }
  // Free entries array
  free(table->entries);
  free(table);
}

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

// Return 64-bit FNV-1a hash for key (NUL-terminated). See description:
// https://en.wikipedia.org/wiki/Fowler–Noll–Vo_hash_function
static uint64_t hash_key(const char *key) {
  uint64_t hash = FNV_OFFSET;
  for (const char *p = key; *p; ++p) {
    hash ^= (uint64_t)(unsigned char)(*p);
    hash *= FNV_PRIME;
  }
  return hash;
}

// Set a hash table entry (without expanding the table)
static const char *ht_set_entry(ht_entry *entries, size_t capacity,
                                const char *key, void *value,
                                size_t *prev_length) {
  // AND hash with capacity-1 to ensure it's within entries array.
  uint64_t hash = hash_key(key);
  size_t index = (size_t)(hash & (uint64_t)(capacity - 1));

  while (entries[index].key != NULL) {
    if (strcmp(entries[index].key, key) == 0) {
      // Found key, update value
      entries[index].value = value;
      return entries[index].key;
    }

    // Linear probe to next available slot
    ++index;
    if (index >= capacity) {
      index = 0;
    }
  }

  // Key is not in hash table, duplicate key if table is not empty and insert it
  if (prev_length != NULL) {
    char* new_key = strdup(key);
    if (new_key == NULL) {
      return NULL;
    }
    (*prev_length)++;
    entries[index].key = new_key;
  } else {
    entries[index].key = key;
  }

  entries[index].value = value;
  return key;
}

// Expand given hash table to twice its size, returns false on failure
static bool ht_expand(ht *table) {
  // Calculate new capacity of entries array
  size_t new_capacity = table->capacity * 2;
  if (new_capacity < table->capacity) {
    return false; // overflow (capacity would be too big)
  }

  // Allocate space for expanded entries array
  ht_entry *new_entries = (ht_entry *)calloc(new_capacity, sizeof(ht_entry));
  if (new_entries == NULL) {
    return false;
  }

  // Move non-empty items over
  for (size_t i = 0; i < table->capacity; ++i) {
    ht_entry entry = table->entries[i];
    if (entry.key != NULL) {
      ht_set_entry(new_entries, new_capacity, entry.key, entry.value, NULL);
    }
  }

  // Free old entries array
  free(table->entries);
  // Update table details
  table->entries = new_entries;
  table->capacity = new_capacity;
  return true;
}

// Set item with given key (NULL terminated) to value (cannot be NULL)
// If key is not yet present, it is copied, new adress is returned
const char *ht_set(ht *table, const char *key, void *value) {
  // Make sure given value is not NULL
  assert(value != NULL);
  if (value == NULL) {
    return NULL;
  }

  // Expand hash table if length exceeds half of capacity
  if (table->length >= table->capacity / 2) {
    if (!ht_expand(table)) {
      return NULL;
    }
  }

  // Set entry and update length
  return ht_set_entry(table->entries, table->capacity, key, value,
                      &table->length);
}

// Get item with given key from hash table. Returns NULL if key was not found
void *ht_get(const ht *const table, const char *key) {
  // AND hash with capacity-1 to ensure it's within entries array.
  uint64_t hash = hash_key(key);
  size_t index = (size_t)(hash & (uint64_t)table->capacity - 1);

  while (table->entries[index].key != NULL) {
    if (strcmp(table->entries[index].key, key) == 0) {
      return table->entries[index].value;
    }
    // Key wasn't in this slot, Linear probe to find it
    ++index;
    // Wrap around at end of hash table
    if (index >= table->capacity) {
      index = 0;
    }
  }

  // Key was not found
  return NULL;
}

// Returns number of items in hash table
size_t ht_length(const ht *const table) { return table->length; }

// Returns number of items in hash table
size_t ht_capacity(const ht *const table) { return table->capacity; }
