#include "main.h"

/**
* print_b - convert a number to a binary value.
*
* @args: args.
* @nchar: no of charcter to be printed.
*
*/
void print_b(va_list args, int *nchar)
{
	int d, i = 0;
	char *numstr;

	d = va_arg(args, int);
	if (d < 0)
	{
		_putchar('-');
		*nchar += 1;
	}
	if (d >= -1 && d <= 1)
	{
		if (d < 0)
		{
			d = -d;
		}
		_putchar(d + 48);
		*nchar += 1;
	}
	else
	{
		numstr = int_to_binary(d);
		while (*(numstr + i))
		{
			_putchar(*(numstr + i));
			i++;
		}
		*nchar += i;
		free(numstr);
	}
}
