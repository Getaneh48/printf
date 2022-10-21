#include "main.h"
#include <stdio.h>

int _print_string(char *);

/**
* print_s - print a string.
*
* @fmt: format string.
* @fsp_sindex: format specifier start index.
* @fsp_eindex: format specifier end index.
* @nchar: number of character to be printed on screen.
* @args: args.
*
* Return: status.
*
*/

int print_s(const char *fmt, int fsp_sindex,
		int fsp_eindex, int *nchar, va_list args)
{
	char *str;
	int pcount = 0;
	int status = 0;

	str = va_arg(args, char *);
	if (fsp_eindex == fsp_sindex)
	{
		/* just print the entire string*/
		if (str != NULL)
		{
			pcount = _print_string(str);
		}
		else
			status = -1;
	}
	else
	{
		/* process flags */
		pcount = process_format(fmt, 's', fsp_sindex,
				fsp_eindex, _strlen(str), str);
		pcount += _print_string(str);
	}

	*nchar += pcount;

	return (status);
}

/**
* _print_string - print string.
*
* @str: string to be printed.
*
* Return: no of char printed on screen.
*
*/
int _print_string(char *str)
{
	int pcount = 0;

	while (*str)
	{
		_putchar(*str);
		str++;
		pcount += 1;
	}

	return (pcount);
}
