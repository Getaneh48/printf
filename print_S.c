#include "main.h"

/**
* print_S - switchs non printable character to their
* ascii value on a string.
*
* @args: args
* @nchar: number of characters to be printed on screen.
*
*/
void print_S(va_list args, int *nchar)
{
	int i = 0, j = 0;
	char ch, c, *numstr, *str;

	str = va_arg(args, char *);
	while ((ch = *(str + i)))
	{
		if ((ch >= 0 && ch <= 32) || ch >= 127)
		{
			_putchar('\\');
			_putchar('x');
			*nchar += 2;
			if ((int)ch <= 9)
			{
				_putchar((int)ch + '0');
				*nchar += 1;
			}
			else
			{
				numstr = int_to_hex((int)ch);
				numstr = _toupper(numstr);
				j = 0;
				while ((c = *(numstr + j)))
				{
					if (c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F')
					{
						_putchar(0 + '0');
						*nchar += 2;
					}
					else
						*nchar += 1;
					_putchar(c);
					j++;
				}
				free(numstr);
			}
		}
		else
		{
			_putchar(ch);
			*nchar += 1;
		}
		i++;
	}
}
