#include "main.h"

int print_b(va_list args)
{
	int d, pcounter = 0, i = 0;
	char *numstr;

	d = va_arg(args, int);
        if (d < 0)
        {
        	_putchar('-');
        	pcounter += 1;
        }

        if (d >= -1 && d <= 1)
        {
        	if (d < 0)
        	{
        		d = -d;
        	}
        	_putchar(d + 48);
        	pcounter += 1;
        	return (pcounter);
        }

        numstr = int_to_binary(d);
        while (*(numstr + i))
        {
 	       _putchar(*(numstr + i));
        	i++;
        }
	pcounter += i;
        free(numstr);
	return (pcounter);
}

