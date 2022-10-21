#include "main.h"
#include <stdio.h>

void print_num(long int n, char *nstr, int i);

/**
* _int_tostr - converts integer to array of characters.
*
* @num: number to be converted.
*
* Return: array of number characters.
*
*/

char *_int_tostr(long int num)
{
	char *nstr;

	nstr = (char *) malloc(20);
	print_num(num, nstr, 0);
	nstr = rev_string(nstr);
	return (nstr);
}

/**
* print_num - performs number conversion to characters.
*
* @n: number to be converted.
* @nstr: memory location to store the characters.
* @i: index.
*
*/

void print_num(long int n, char *nstr, int i)
{
	if (n < 0)
	{
		n = -n;
	}

	if (n / 10)
	{
		print_num(n / 10, nstr, i + 1);
	}

	*(nstr + i) = n % 10 + '0';
}
