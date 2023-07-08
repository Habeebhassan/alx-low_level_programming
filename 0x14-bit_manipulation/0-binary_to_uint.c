#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - convert a binary number to int
 * @b: binary value
 *
 * Return: unsigned int.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;

	if (b == NULL)
		return (0);
	while (*b != '\0')
	{
		num = num << 1;
		if (*b != '1' && *b != '0')
			return (0);
		else if (*b == '1')
			num = num | 1;
		b++;
	}
	return (num);
}
