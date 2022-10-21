#include "main.h"

/**
* print_R - handles reverse of a string
*
* @args: arguments.
*
* @nchar: number of characters to be printed on screen.
*
*/
void print_R(va_list args, int *nchar)
{
	char *o_s;
	char *s = va_arg(args, char*);
	int i = 0;

	if (s == NULL)
		exit(0);

	o_s = malloc(_strlen(s) + 1);
	o_s = _strcpy(o_s, s);
	o_s = rot13(o_s);

	while (*(o_s + i))
	{
		_putchar(*(o_s + i));
		i++;
	}
	*nchar += i;
	free(o_s);
}
