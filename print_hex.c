#include "main.h"

int _print_hex(long int, char);

/**
* print_x - print hex value.
*
* @fmt: format string.
* @f: flag.
* @fsp_sindex: start index.
* @fsp_eindex: format specifier end index.
* @nchar: no of character to be printed.
* @args: args.
*
* Return: true or false.
*
*/

int print_x(const char *fmt, char f, int fsp_sindex,
		int fsp_eindex, int *nchar, va_list args)
{
	long int d, *dptr;
	int pcounter = 0;
	char *numstr;

	d = va_arg(args, long int);
	dptr = &d;
	if (fsp_eindex == fsp_sindex)
	{
		/* just print the entire string*/
		pcounter = _print_hex(d, f);
		*nchar += pcounter;
		return (0);
	}
	else
	{
		numstr = _int_tostr(d);
		/* process flags */
		pcounter = process_format(fmt, 'x', fsp_sindex,
					fsp_eindex, _strlen(numstr), (void *) dptr);
		pcounter += _print_hex(d, f);
	}

	*nchar += pcounter;
	free(numstr);
	return (0);
}

/**
* _print_hex - process hex value conversion.
*
* @lp: number.
* @format: format
*
* Return: number of characters printed on screen.
*
*/

int _print_hex(long int lp, char format)
{
	int i = 0, pcounter = 0;
	char *numstr = malloc(sizeof(char *) + 16);

	if (lp < 0)
	{
		_putchar('-');
		pcounter += 1;
	}

	if (lp >= -9 && lp <= 9)
	{
		if (lp < 0)
			lp = -lp;
		_putchar(lp + '0');
		pcounter += 1;
		return (pcounter);
	}

	numstr = int_to_hex(lp);
	if (format == 'X')
		numstr = _toupper(numstr);

	while (*(numstr + i))
	{
		_putchar(*(numstr + i));
		i++;
	}
	free(numstr);

	pcounter += i;

	return (pcounter);
}
