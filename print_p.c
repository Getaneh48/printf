#include "main.h"
#include <stdio.h>

int print_p(va_list args)
{
	void *ptr;
	int i = 0, pcounter = 0;
	char ch;
	char *numstr; 

	ptr = va_arg(args, void *);
	if(ptr)
	{
		_putchar('0');
		_putchar('x');
		pcounter += 2;
		numstr = int_to_hex((long int)ptr);	
		while((ch = *(numstr + i)))
		{
			_putchar(ch);
			i++;
		}

		pcounter += i;
		free(numstr);
	}
	
	return (pcounter);
}
