
#include "hash_table.h"

int main(void)
{
	ht_hash_table *ht = create_ht();

	if (!ht || !ht->items)
		return 0;

	insert(ht, "Name", "Walid");
	// insert(ht, "Age", "23");
	// insert(ht, "School", "1337");

	delete_hash_table(ht);
}