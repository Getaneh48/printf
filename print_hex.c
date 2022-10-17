#include "main.h"
#include <stdio.h>

int print_hex(va_list args, char format)
{
	int i = 0, pcounter = 0;
	long int lp;
	char *numstr = malloc(sizeof(char*) + 16);

	lp = va_arg(args, unsigned int);
	if (lp < 0)
	{
		_putchar('-');
		pcounter += 1;
	}

	if (lp >= -9 && lp <= 9)
	{
		if (lp < 0)
			lp = -lp;
		_putchar(lp + '0');
		pcounter += 1;
		return (pcounter);
	}

	numstr = int_to_hex(lp);
	if (format == 'X')
		numstr = _toupper(numstr);
	
	while (*(numstr + i))
	{
		_putchar(*(numstr + i));
		i++;
	}
	free(numstr);

	pcounter += i;

	return (pcounter);
}
