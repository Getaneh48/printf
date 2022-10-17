#include "main.h"

int print_di(va_list args)
{
	int d, i = 0, pcounter = 0;
	char *numstr;

	d = va_arg(args, int);
	if (d >= 0 && d < 10)
	{
		_putchar(d + '0');
		pcounter += 1;
		return (pcounter);
	}

	numstr = intostr(d);
	numstr = rev_string(numstr);
	
	if (d < 0)
	{
		_putchar('-');
		pcounter += 1;
	}

	while(*(numstr + i))
	{
		_putchar(*(numstr + i));
		i++;
	}
	pcounter += 1;
	free(numstr);

	return (pcounter);
}
