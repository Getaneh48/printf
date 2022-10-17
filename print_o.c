#include "main.h"

int print_o(va_list args)
{
	long int octal;
	char *numstr;
	int i = 0;
	int pcounter = 0;

	octal = va_arg(args, long int);
        if (octal < 0)
        {
        	_putchar('-');
        	pcounter += 1;
	}

        if (octal >= -7 && octal <= 7)
        {
        	if (octal < 0)
        		octal = -octal;
        	_putchar(octal + '0');
        	pcounter += 1;
       		return (pcounter);
        }
        numstr = int_to_octal(octal);
        while (*(numstr + i))
        {
        	_putchar(*(numstr + i));
        	i++;
        }
	pcounter += i;
	free(numstr);

	return (pcounter);
}
