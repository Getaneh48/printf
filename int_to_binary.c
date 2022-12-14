#include "main.h"

/**
* int_to_binary - converts a number to a binary value.
*
* @num: number.
*
* Return: array of binary representation of a number.
*
*/
char *int_to_binary(int num)
{
	char *numstr = malloc(sizeof(char) * 16);
	int i, div, mod;

	i = 0;
	if (num < 0)
		num = -num;
	do {
		div = num / 2;
		mod = num % 2;
		num = div;
		*(numstr + i) = mod + '0';
		i++;
	} while (div >= 2);
	*(numstr + i) = div + '0';

	numstr = rev_string(numstr);

	return (numstr);
}
