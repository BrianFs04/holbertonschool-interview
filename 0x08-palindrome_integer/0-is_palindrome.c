#include "palindrome.h"
/**
 * is_palindrome - function that checks whether or not a
 * given unsigned integer is a palindrome
 * @n: number to be checked
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long x = n, rev = 0, rem;

	while (x != 0)
	{
		rem = x % 10;
		rev = rev * 10 + rem;
		x /= 10;
	}
	return ((n == rev) ? 1 : 0);
}
