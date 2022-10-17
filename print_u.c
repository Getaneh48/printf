#include "main.h"

int print_u(va_list args)
{
	unsigned int uInt;
	int pcounter = 0, i = 0;
	char *numstr;

	uInt = va_arg(args, unsigned int);
        if (uInt < 10)
        {
        	_putchar(uInt + '0');
        	pcounter += 1;
        	return (pcounter);
        }
                                
        numstr = intostr(uInt);
        numstr = rev_string(numstr);
        while (*(numstr + i))
        {
        	_putchar(*(numstr + i));
        	i++;
        }
	pcounter += i;
       	free(numstr);

	return (pcounter);
}
