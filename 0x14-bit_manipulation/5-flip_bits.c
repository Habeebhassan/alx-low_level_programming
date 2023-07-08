#include "main.h"

/**
 * flip_bits - counter
 * @n: start numbers
 * @m: later numbers
 *
 * Return: number of bits to transform
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int count,  num = 0;

	for (count = 63; count >= 0; count--)
	{
		if (((n ^ m) >> count) & 1)
			num++;
	}

	return (num);
}
