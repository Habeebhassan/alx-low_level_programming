#include "main.h"
#include <stdio.h>
/**
 * get_bit - value of bit in an index
 * @n: number computed
 * @index: indexing each char
 * Return: bit values
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int num;

	if (index > 64)
		return (-1);

	num = n >> index;

	return (num & 1);
}
