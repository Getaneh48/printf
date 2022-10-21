#include "main.h"

/**
* move_char_onfirstindex - moves a flag on the first index of
* a string.
*
* @print: string to be printed on screen.
* @flag: the flag that will be moved on first index.
*
* Return: the index.
*
*/

int move_char_onfirstindex(char *print, char flag)
{
	int len, i, index;
	char temp, temp2;

	len = _strlen(print);
	index = 0;
	/* find index of + */
	for (i = 0; i < len; i++)
	{
		if (print[i] == flag)
		{
			index = i;
			break;
		}
	}
	/* check if + is between strings */
	if (index > 0)
	{
		temp = print[index];
		for (i = index; i > 0; i--)
		{
			temp2 = print[i - 1];
			print[i] = temp2;
		}
		print[0] = temp;
	}
	return (index);
}
