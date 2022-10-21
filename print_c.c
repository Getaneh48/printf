#include "main.h"

/**
* print_c - print a character.
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
int print_c(const char *fmt, int fsp_sindex,
		int fsp_eindex, int *nchar, va_list args)
{
	int c, *cptr;
	int pcount = 0;
	int status = 0;

	c = va_arg(args, int);
	cptr = &c;

	if (fsp_eindex == fsp_sindex)
	{
		/* just print the entire string*/
			_putchar(c);
			pcount += 1;
	}
	else
	{
		/* process flags */
		process_format(fmt, 'c', fsp_sindex, fsp_eindex, 1, cptr);
		_putchar(c);
		pcount += 1;
	}

	*nchar += pcount;

	return (status);
}
