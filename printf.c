#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <stdlib.h>

int _printf(const char *format, ...)
{
    va_list args;
    int d,nchar;
    char *str;

    nchar = 0;
    va_start(args, format);
 
    while (*format != '\0')
    {
        if (*format == '%')
	{
		switch(*(format + 1))
		{
			case 'i':
			case 'd':
				nchar += print_di(args);
				break;
			case 'u':
				nchar += print_u(args);
				break;
			case 'c':
				d = va_arg(args, int);
				if(d >= 0 && d <= 9)
					_putchar(d + 48);
				else
					_putchar(d);
				nchar += 1;
				break;
			case 'o':
				nchar += print_o(args);
				break;
			case 'X':
			case 'x':

				if (*(format + 1) == 'X')
					nchar += print_hex(args,'X');
				else
					nchar += print_hex(args,'x');
				
				break;
			case 'p':
				nchar += print_p(args);
				break;
			case 'r':
				nchar += print_r(args);
				break;
			case 'R':
				nchar += print_R(args);
				break;
			case 'b':
				nchar += print_b(args);
				break;
			case 's':
				str = va_arg(args, char*);
				while(*str)
				{
					_putchar(*str);
					str++;
					nchar += 1;
				}
				break;
			case 'S':
				str = va_arg(args, char*);
				_handleS(str, &nchar);
				break;
			case '%':
				_putchar('%');
				nchar += 1;
				format += 2;
				_putchar(*format);
				nchar += 1;
				break;
			
			default:
				break;
		}
	}
	else if(*format == '\\')
	{
		switch(*(format + 1))
		{
			case 'n':
				_putchar('\n');
				nchar += 1;
				break;
			case 't':
				if(_putchar('\t'))
					nchar += 1;
				break;
			default:
				break;
		}
	}
	else
	{
		if ((*format != 'd' && *(format - 1) != '%') || (*format != 'c' && *(format - 1) != '%'))
			if(_putchar(*format))
				nchar += 1;
	}

	++format;
    }
    
    va_end(args);
    
    return (nchar);
}

void _handleS(char *str, int *nchar)
{
	int i = 0, j = 0;
	char ch, c, *numstr;

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
				while((c = *(numstr + j)))
				{
					if (c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F')
					{
						_putchar(0 + '0');
						_putchar(c);
						*nchar += 2;
					}
					else
					{
						_putchar(c);
						*nchar += 1;
					}
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

char *intostr(long int num)
{
	char *numstr = malloc(sizeof(char) * 20);

	_int_to_str(num, numstr, 0);

	return (numstr);
}

void _int_to_str(long int num, char *buf, int counter)
{
	if (num < 0)
	{
		num = -num;
	}

	if (num / 10)
	{
		_int_to_str(num / 10, buf, (counter + 1));
	}

	*(buf + counter) = num % 10 + '0';
}
