#include "main.h"

/**
* print_r - print a string in reverse.
*
* @args: args
* @nchar: no of characters to print on screen.
*
*/
void print_r(va_list args, int *nchar)
{
	int i = 0;
	char *s = va_arg(args, char *);
	char *o_s = malloc(_strlen(s) + 1);

	o_s = _strcpy(o_s, s);

	if (s == NULL)
		exit(0);

	o_s = rev_string(o_s);
	while (*(o_s + i))
	{
		_putchar(*(o_s + i));
		i++;
	}
	*nchar += i;
	free(o_s);
}
