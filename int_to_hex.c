#include "main.h"

void hex_alpha(char *numstr, int val);

/**
* int_to_hex - converts a number to a hexadecimal value.
*
* @num: number.
*
* Return: character array of a hex number.
*
*/
char *int_to_hex(long int num)
{
	char *numstr = malloc(sizeof(char) * 16);
	long int i, div, mod;

	i = 0;
	if (num < 0)
		num = -num;

	if (num >= 16)
	{
		do {
			div = num / 16;
			mod = num % 16;
			num = div;
			hex_alpha(numstr + i, mod);
			i++;
		} while (div >= 16);
		hex_alpha(numstr + i, div);
	}
	else
		hex_alpha(numstr + i, num);

	numstr = rev_string(numstr);

	return (numstr);
}

/**
* hex_alpha - represents 10 - 15 value using alphabet.
*
* @numstr: array of converted number to hex.
*
* @val: value to be converted to alphabet.
*
*/

void hex_alpha(char *numstr, int val)
{
	switch (val)
	{
		case 10:
			*numstr = 'a';
			break;
		case 11:
			*numstr = 'b';
			break;
		case 12:
			*numstr = 'c';
			break;
		case 13:
			*numstr = 'd';
			break;
		case 14:
			*numstr = 'e';
			break;
		case 15:
			*numstr = 'f';
			break;
		default:
			*numstr = val + '0';
			break;
	}
}
