#include "main.h"
/**
 * set_bit - bit of 0s and 1s
 * @n: pointer
 * @index: locator
 * Return: success
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = *n | (1 << index);
	return (1);
}
