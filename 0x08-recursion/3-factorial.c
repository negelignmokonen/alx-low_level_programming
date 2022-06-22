#include "main.h"

/**
 * factorial - factorial of a given number: 5 - (5-1)
 * @n: number
 * Return: Always 0 (Success)
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0)
		return (1);
	else
		return (n * factorial(n - 1));
}

