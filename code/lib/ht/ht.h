#include <stddef.h>

// Hash table structure, create with ht_create, free wit ht_destroy
typedef struct ht ht;

// Create a hash table and return a pointer to it, returns NULL if OOM
ht* ht_create(size_t initial_capacity);

// Free memory allocated to a hash table, also frees allocated keys
void ht_destroy(ht* table);

// Set item with given key (NULL terminated) to value (cannot be NULL)
// If key is not yet present, it is copied, new adress is returned
const char* ht_set(ht* table, const char* key, void* value);

// Get item with given key from hash table. Returns NULL if key was not found
void* ht_get(const ht* const table, const char* key);

// Returns number of items in hash table
size_t ht_length(const ht* const table);

// Returns total capacity of the hash table
size_t ht_capacity(const ht *const table);

