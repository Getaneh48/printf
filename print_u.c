#include "main.h"

int _print_uint(unsigned int uInt);

/**
* print_u - print a string.
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

int print_u(const char *fmt, int fsp_sindex,
		int fsp_eindex, int *nchar, va_list args)
{
	int pcounter = 0;
	char *numstr;
	unsigned int d, *dptr;

	d = va_arg(args, unsigned int);
	dptr = &d;
	if (fsp_eindex == fsp_sindex)
	{
		/* just print the entire string*/
		pcounter = _print_uint(d);
		*nchar += pcounter;
		return (0);
	}
	else
	{
		numstr = _int_tostr(d);
		/* process flags */
		process_format(fmt, 'u', fsp_sindex,
				fsp_eindex, _strlen(numstr), (void *) dptr);
		pcounter = _print_uint(d);
	}

	*nchar += pcounter;
	free(numstr);

	return (0);
}

/**
* _print_uint - handle unsigned int.
*
* @uInt: unsigned int
*
* Return: printed characters.
*
*/
int _print_uint(unsigned int uInt)
{
	int pcounter = 0, i = 0;
	char *numstr;

	if (uInt < 10)
	{
		_putchar(uInt + '0');
		pcounter += 1;
		return (pcounter);
	}

	numstr = _int_tostr(uInt);
	while (*(numstr + i))
	{
		_putchar(*(numstr + i));
		i++;
	}
	pcounter += i;
	free(numstr);

	return (pcounter);
}
