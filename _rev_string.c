#include "main.h"

/**
* rev_string -  a function that prints a string,
* in reverse, followed by a new line
*
* @s: first argument, character pointer
*
* Return: the reversed string.
*/

char *rev_string(char *s)
{
	char *str, *o_s, temp;
	int len;

	len = _strlen(s) - 1;
	str = &s[len];
	o_s = s;
	while (str > s)
	{
		temp = *s;
		*s = *str;
		*str = temp;
		str -= 1;
		s += 1;
	}

	return (o_s);
}
