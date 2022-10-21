#include "main.h"
#include <stdio.h>

int _print_octal(long int d);

/**
* print_o - handle number conversion to an octal value.
*
* @fmt: format string.
* @fsp_sindex: start index.
* @fsp_eindex: end index.
* @nchar: number of characters to be printed.
* @args: args.
*
* Return: true or false
*
*/
int print_o(const char *fmt, int fsp_sindex,
		int fsp_eindex, int *nchar, va_list args)
{
	int  pcounter = 0;
	char *numstr;
	long int d, *dptr;

	d = va_arg(args, long int);
	dptr = &d;
	if (fsp_eindex == fsp_sindex)
	{
		/* just print the entire string*/
		pcounter = _print_octal(d);
		*nchar += pcounter;
		return (0);
	}
	else
	{
		numstr = _int_tostr(d);
		/* process flags */
		pcounter = process_format(fmt, 'o', fsp_sindex,
				fsp_eindex, _strlen(numstr), (void *) dptr);
		pcounter += _print_octal(d);
	}
	*nchar += pcounter;
	free(numstr);

	return (0);
}

/**
* _print_octal - process octal value conversion
*
* @d: number to be converted.
*
* Return: number of character printed on screen.
*/
int _print_octal(long int d)
{
	char *numstr;
	int i = 0;
	int pcounter = 0;

	if (d < 0)
	{
		_putchar('-');
		pcounter += 1;
	}

	if (d >= -7 && d <= 7)
	{
		if (d < 0)
			d = -d;
		_putchar(d + '0');
		pcounter += 1;
		return (pcounter);
	}
	numstr = int_to_octal(d);
	while (*(numstr + i))
	{
		_putchar(*(numstr + i));
		i++;
	}
	pcounter += i;
	free(numstr);

	return (pcounter);
}
