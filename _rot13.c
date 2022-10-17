#include "main.h"

/**
* rot13 - encodes a string using rot13.
*
* @s: string to be encoded/decoded
*
* Return: the encoded / decoded string
*
*/

char *rot13(char *s)
{
	int c;
	char *o_s = s;
	int aschii_tbl[128];

	aschii_tr_table(aschii_tbl, 0, 64, 0);
	aschii_tr_table(aschii_tbl, 65, 90, 13);
	aschii_tr_table(aschii_tbl, 91, 96, 0);
	aschii_tr_table(aschii_tbl, 97, 122, 13);

	while (*s != '\0')
	{
		c = (int) *s;
		*s = (char) aschii_tbl[c];
		s += 1;
	}

	return (o_s);
}

/**
* aschii_tr_table - rot13 encoded aschii table.
*
* @atbl: an array to hold the encoded aschii table.
*
* @min: starting index to start the encoding.
* @max: the ending index to end encoding.
* @shift: the number to use for encoding.
*
*/

void aschii_tr_table(int *atbl, int min, int max, int shift)
{
	int i;
	int c;

	for (i = min; i <= max; i++)
	{
		c = i + shift;
		if (c > max)
		{
			c = min + c % max - 1;
		}

		atbl[i] = c;
	}

}
