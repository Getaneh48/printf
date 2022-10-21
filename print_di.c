#include "main.h"
#include <stdio.h>

int _print_nums(int d);

/**
* print_di - prints decimal value.
*
* @fmt: format string.
* @fsp_sindex: format specifier start index.
* @fsp_eindex: format specifier end index.
* @nchar: no of characters to be printed on screen.
* @args: args.
*
* Return: integer
*
*/
int print_di(const char *fmt, int fsp_sindex,
		int fsp_eindex, int *nchar, va_list args)
{
	int d, *dptr, pcounter = 0;
	char *numstr;

	d = va_arg(args, int);
	dptr = &d;

	if (fsp_eindex == fsp_sindex)
	{
		/* just print the entire string*/
		pcounter = _print_nums(d);
		*nchar += pcounter;
		return (0);
	}
	else
	{
		numstr = _int_tostr(d);
		/* process flags */
		pcounter = process_format(fmt, 'd', fsp_sindex,
				fsp_eindex, _strlen(numstr), (void *) dptr);
		pcounter += _print_nums(d);
	}

	*nchar += pcounter;
	free(numstr);

	return (0);
}

/**
* _print_nums - print number
*
* @d: number
*
* Return: no of printed characters.
*
*/
int _print_nums(int d)
{
	char *numstr;
	int pcounter = 0, i = 0;

	if (d >= 0 && d < 10)
	{
		_putchar(d + '0');
		pcounter += 1;
		return (pcounter);
	}

	numstr = _int_tostr(d);
	if (d < 0)
	{
		_putchar('-');
		pcounter += 1;
	}

	while (*(numstr + i))
	{
		_putchar(*(numstr + i));
		i++;
	}
	pcounter += i;
	free(numstr);

	return (pcounter);
}
