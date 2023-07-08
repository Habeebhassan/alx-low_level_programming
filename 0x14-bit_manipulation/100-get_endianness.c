#include <stdio.h>

/**
 * get_endianness - checker
 * Prototype: int
 * Return: 1
 */
int get_endianness(void)
{
	unsigned int x = 1;
	char *c = (char *) &x;

	return ((int)*c);
}
