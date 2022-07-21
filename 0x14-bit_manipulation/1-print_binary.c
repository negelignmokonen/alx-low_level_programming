#include "main.h"
/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be printed in binary.
 */
void print_binary(unsigned long int n)
{
	unsigned long int tt = n;
	if (tt > 1)
		print_binary(tt >> 1);

	_putchar((tt & 1) + '0');
}

