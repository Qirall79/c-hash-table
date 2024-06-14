
#include "hash_table.h"

int main(void)
{
	ht_hash_table *ht = create_ht();
	delete_hash_table(ht);
}