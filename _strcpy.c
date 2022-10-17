#include "main.h"

/**
* _strcpy - copies the string pointed to by src,
* including the terminating null byte (\0),
* to the buffer pointed to by dest
*
* @dest: character pointer for the destination
* @src: character pointer of source to be copied.
*
* Return: pointer of the destination
*
*/

char *_strcpy(char *dest, char *src)
{
	char *s, *d;

	s = src;
	d = dest;
	while (*s)
	{
		*d = *s;
		s += 1;
		d += 1;
	}
	*d = '\0';

	return (dest);
}
