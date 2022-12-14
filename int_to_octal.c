#include "main.h"

/**
* int_to_octal - converts a number to an octal value.
*
* @num: number to be converted.
*
* Return: string representaion of the octal values.
*
*/
char *int_to_octal(long int num)
{
	char *numstr = malloc(sizeof(char) * 16);
	int i, div, mod;

	i = 0;
	if (num < 0)
		num = -num;
	do {
		div = num / 8;
		mod = num % 8;
		num = div;
		*(numstr + i) = mod + '0';
		i++;
	} while (div >= 8);
	*(numstr + i) = div + '0';

	numstr = rev_string(numstr);

	return (numstr);
}
