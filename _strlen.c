#include "main.h"

/**
* _strlen -  returns the length of a string.
*
* @s: character pointer
*
* Return: integer length of a string.
*
*/
int _strlen(char *s)
{
	int i;

	i = 0;
	while (*s)
	{
		i++;
		s += 1;
	}

	return (i);
}
