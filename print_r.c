#include "main.h"

int print_r(va_list args)
{
	int pcounter = 0, i = 0;
	char *s = va_arg(args, char *);
	char *o_s = malloc(_strlen(s) + 1);
	o_s = _strcpy(o_s, s);

	if (s == NULL)
		return (0);

	o_s = rev_string(o_s);
	while(*(o_s + i))
	{
		_putchar(*(o_s + i));
		i++;
	}
	pcounter += i;
	free(o_s);

	return (pcounter);
}
