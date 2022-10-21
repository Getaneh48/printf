#include "main.h"
#include <stdio.h>

/**
* printf - prints a formated output.
*
* @fmt: format.
*
* Return: number of characters printed on screen.
*
*/

int _printf(const char *fmt, ...)
{
	int i = 0;
	int nchar = 0;
	char ch;
	int fsp_last_index = 0;
	int fsp_found = 0;
	va_list args;

	va_start(args, fmt);
	while ((ch = *(fmt + i)))
	{
		if (ch == '%')
		{
			fsp_last_index = format_handler(fmt, i + 1, &nchar, args);
			fsp_found = 1;
			i = fsp_last_index;
		}
		else
		{
			_putchar(ch);
			nchar += 1;
		}
		i++;
	}

	if (fsp_found == 0)
	{
		i = 0;
		while ((ch = *(fmt + i)))
		{
			_putchar(ch);
			nchar += 1;
			i++;
		}
	}
	va_end(args);

	return (nchar);
}
