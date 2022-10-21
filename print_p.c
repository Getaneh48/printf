#include "main.h"
#include <stdio.h>

int _print_pointer(void *ptr);

/**
* print_p - handle number conversion to an octal value.
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

int print_p(const char *fmt, int fsp_sindex,
		int fsp_eindex, int *nchar, va_list args)
{
	int pcounter = 0;
	char *numstr;
	void *ptr;

	ptr = va_arg(args, void *);

	if (fsp_eindex == fsp_sindex)
	{
		/* just print the entire string*/
		pcounter = _print_pointer(ptr);
		*nchar += pcounter;
		return (0);
	}
	else
	{
		numstr = _int_tostr((long int)ptr);
		/* process flags */
		process_format(fmt, 'p', fsp_sindex, fsp_eindex, _strlen(numstr), ptr);
		pcounter = _print_pointer(ptr);
	}

	*nchar += pcounter;
	free(numstr);

	return (0);
}

/**
* _print_pointer - prints an address.
*
* @ptr: address
*
* Return: no of char printed.
*
*/
int _print_pointer(void *ptr)
{
	int i = 0, pcounter = 0;
	char ch;
	char *numstr;

	if (ptr)
	{
		_putchar('0');
		_putchar('x');
		pcounter += 2;
		numstr = int_to_hex((long int)ptr);
		while ((ch = *(numstr + i)))
		{
			_putchar(ch);
			i++;
		}

		pcounter += i;
		free(numstr);
	}

	return (pcounter);
}
