#include "main.h"

int print_R(va_list args)
{
	char *o_s;
	char *s = va_arg(args, char*);
	int i = 0;
	int pcounter = 0;
	
	if (s == NULL)
		return (0);

	o_s = malloc(_strlen(s) + 1);
	o_s = _strcpy(o_s, s);
	o_s = rot13(o_s);

	while(*(o_s + i))
	{
		_putchar(*(o_s + i));
		i++;
	}
	pcounter += i;
	free(o_s);
	return (pcounter);
}
