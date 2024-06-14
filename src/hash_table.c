
#include "hash_table.h"

static ht_item HT_DELETED_ITEM = {NULL, NULL};

int hash(const char *str, int a, int size)
{
	long index;
	int str_size;

	if (!str)
		return (0);
	index = 0;
	str_size = strlen(str);
	for (int i = 0; i < str_size; i++)
		index += (long) pow(a, (str_size - (i + 1))) * (int) str[i];
	index = index % size;
	return (index);
}

static int get_hash(const char *str, const int size, const int attempts)
{
	int hash_a = hash(str, HT_PRIME_1, size);
	int hash_b = hash(str, HT_PRIME_2, size);
	return (hash_a + (attempts * (hash_b + 1)) % size);
}

static ht_item *create_ht_item(const char *k, const char *v)
{
	ht_item *new;

	new = (ht_item *) malloc(sizeof(ht_item));
	if (!new)
		return (NULL);
	new->key = strdup(k);
	new->value = strdup(v);

	return (new);
}

ht_hash_table *create_ht(void)
{
	ht_hash_table *new = (ht_hash_table *) malloc(sizeof(ht_hash_table));

	if (!new)
		return (NULL);
	new->size = 53;
	new->count = 0;
	new->items = calloc((size_t)new->size, sizeof(ht_item *));
	return (new);
}

static void delete_ht(ht_item *item)
{
	if (!item)
		return ;
	free(item->key);
	free(item->value);
	free(item);
}

void delete_hash_table(ht_hash_table *ht)
{
	for (int i = 0; i < ht->size; i++)
		delete_ht(ht->items[i]);
	free(ht->items);
	free(ht);
}

void insert(ht_hash_table *ht, const char *key, const char *value)
{
	ht_item *item;
	int index;
	int i;

	item = create_ht_item(key, value);
	index = get_hash(key, ht->size, 0);
	i = 1;
	while (ht->items[index] && ht->items[index] != &HT_DELETED_ITEM)
	{
		index = get_hash(key, ht->size, i);
		i++;
	}
	ht->items[index] = item;
	ht->count++;
}

void update(ht_hash_table *ht, const char *key, const char *new_value)
{
	int index;
	int i;

	index = get_hash(key, ht->size, 0);
	i = 1;
	while (ht->items[index])
	{
		if (ht->items[index] != &HT_DELETED_ITEM
		&& !strcmp(ht->items[index]->key, key))
		{
			free(ht->items[index]->value);
			ht->items[index]->value = strdup(new_value);
			return ;
		}
		index = get_hash(key, ht->size, i);
		i++;
	}
}

char *search(ht_hash_table *ht, const char *key)
{
	int index;
	int i;

	index = get_hash(key, ht->size, 0);
	i = 1;
	while (ht->items[index])
	{
		if (ht->items[index] != &HT_DELETED_ITEM
		&& !strcmp(ht->items[index]->key, key))
			return (ht->items[index]->value);
		index = get_hash(key, ht->size, i);
		i++;
	}
	return (NULL);
}

void delete(ht_hash_table *ht, const char *key)
{
	int index;
	int i;

	index = get_hash(key, ht->size, 0);
	i = 1;
	while (ht->items[index])
	{
		if (ht->items[index] != &HT_DELETED_ITEM
		&& !strcmp(ht->items[index]->key, key))
		{
			delete_ht(ht->items[index]);
			ht->items[index] = &HT_DELETED_ITEM;
			ht->count--;
			break ;
		}
		index = get_hash(key, ht->size, i);
		i++;
	}
}


