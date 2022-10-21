#include "main.h"
#include <stdio.h>

/**
* process_format - handles formating.
*
* @fmt: format string
* @mdf: modifier
* @fsp_sindex: start index
* @fsp_eindex: end index
* @val_length: length
* @val: value
*
* Return: no of printed characters.
*
*/

int process_format(const char *fmt,
		char mdf, int fsp_sindex, int fsp_eindex, int val_length, void *val)
{
	int last_flag_index, printedchar = 0, width = 0, j;
	char *print;

	j = fsp_sindex;
	last_flag_index = _last_flag(fmt, fsp_sindex, fsp_eindex);
	if (last_flag_index > 0)
		width = _extract_number(fmt, last_flag_index + 1, fsp_eindex);
	else
		width = _extract_number(fmt, fsp_sindex, fsp_eindex);
	print = (char *)malloc(width + 2);
	if (last_flag_index > 0)
	{
		while (j <= last_flag_index)
		{
			dispatch_flag(fmt,
					j,
					*(fmt + j),
					mdf, print, &printedchar, val, width, val_length);
			j++;
		}
		move_char_onfirstindex(print, ' ');
		move_char_onfirstindex(print, '+');
		for (j = 0; j < _strlen(print); j++)
			_putchar(print[j]);
		free(print);
		return (printedchar);
	}
	else
		print_noflag(mdf, width, val_length, &printedchar);
	free(print);
	return (printedchar);
}

void dispatch_flag(const char *fmt, int j,
		char flag,
		char mdf, char *print, int *pchar, void *val, int width, int vl)
{
	switch (flag)
	{
		case '+':
			handle_plusF(mdf, print, pchar, val);
			break;
		case '-':
			handle_minusF(fmt, j, print);
			break;
		case '0':
			print = handle_zeroF(mdf, width,
			vl, pchar, print);
			break;
		case ' ':
			handle_spaceF(fmt, j, mdf, width, vl, pchar, print);
			break;
		case '#':
			handl_hashtagF(mdf, print, pchar);
			break;
		default:
			break;
	}

}

/**
* print_noflag - print the string.
*
* @mdf: modifier.
* @width: width specifier.
* @val_length: length of a value.
* @pchar: number of characters printed on the screen.
*
*/

void print_noflag(char mdf, int width, int val_length, int *pchar)
{

	int j, diff;
	/* if no flag found pad the output with empty space*/
	if (mdf == 'u' ||
		mdf == 'p' ||
		mdf == 'd' ||
		mdf == 'x' ||
		mdf == 'X' || mdf == 's' || mdf == 'c' || mdf == 'o')
	{
		if (width >= 0)
		{
			diff = width - (val_length + 1);
			for (j = 0; j <= diff; j++)
				_putchar(' ');
			*pchar += j;
		}
	}
}
