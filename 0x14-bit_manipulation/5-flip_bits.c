#include "main.h"
/**
 * flip_bits - Counts the number of bits needed to be
 *             flipped to get from one number to another.
 * @n: The number.
 * @m: The number to flip n to.
 *
 * Return: The necessary number of bits to flip to get from n to m.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int num1 = n;
	unsigned long int num2 = m;
	unsigned long int xor = num1 ^ num2, digits = 0;

	while (xor > 0)
	{
		digits += (xor & 1);
		xor >>= 1;
	}

	return (digits);
}

