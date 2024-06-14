
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

#endif
