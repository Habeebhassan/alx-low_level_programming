#include "main.h"
/**
 * clear_bit - representing index of 0
 * @n: pointer
 * @index: index
 * Return: success
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = *n & ~(1 << index);
	return (1);
}
