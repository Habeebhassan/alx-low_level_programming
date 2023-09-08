#include "hash_tables.h"

/**
 * hash_table_delete - function that deletes a hash table.
 * @ht: pointer to hash table to be deleted.
 *
 * Return: No return.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *current = NULL;
	unsigned long int x = 0;

	if (ht == NULL)
		return;

	for (x = 0; x < ht->size; x++)
	{
		if (ht->array[x] != NULL)
		{
			while (ht->array[x])
			{
				current = ht->array[x];
				free(current->key);
				free(current->value);
				ht->array[x] = ht->array[x]->next;
				free(current);
			}
		}
	}
	free(ht->array);
	free(ht);
}
