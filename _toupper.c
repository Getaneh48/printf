#include "main.h"

/**
* _toupper - converts a string to uppercase.
*
* @str: string to be converted.
*
* Return: uppercase string.
*
*/
char *_toupper(char *str)
{
	int i = 0;

	while (*(str + i))
	{
		if ((*(str + i) >= 'a') && (*(str + i) <= 'z'))
			*(str + i) -= 32;
		i++;
	}

	return (str);
}
