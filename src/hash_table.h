
#ifndef HASH_TABLE_H

# define HASH_TABLE_H

# define HT_PRIME_1 151
# define HT_PRIME_2 163

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

typedef struct {
	char *key;
	char *value;
} ht_item;

typedef struct {
	int size;
	int count;
	ht_item **items;
} ht_hash_table;

ht_hash_table *create_ht(void);
void delete_hash_table(ht_hash_table *ht);

// operations
void insert(ht_hash_table *ht, const char *key, const char *value);
void update(ht_hash_table *ht, const char *key, const char *new_value);
char *search(ht_hash_table *ht, const char *key);
void delete(ht_hash_table *ht, const char *key);
void resize(ht_hash_table *ht);
void print_ht(ht_hash_table *ht);

#endif
