#include "main.h"

/**
* handl_hashtagF - handles the hashtag flag.
*
* @mdf: modifier.
* @print: string to be printed on the screen.
* @pchar: number of characters printed on the screen.
*
*/

void handl_hashtagF(char mdf, char *print, int *pchar)
{
	if (mdf == 'o' || mdf == 'x' || mdf == 'X')
	{
		if (mdf == 'o')
		{
			print = _strcat(print, "0");
			*pchar += 1;
		}
		else
		{
			print = _strcat(print, "0x");
			*pchar += 2;
		}
	}
}

/**
* handle_spaceF - handles the space flag.
*
* @fmt: format string.
* @j: index of a loop.
* @mdf: modifier.
* @w: width specifier.
* @vl: length of a value.
* @pchar: number of characters printed on the screen.
* @print: string to be printed on the screen.
*
*/

void handle_spaceF(const char *fmt,
		int j,
		char mdf, int w, int vl, int *pchar, char *print)
{
	int diff = 0, pad_len = 0, k = 0;

	if (mdf == 'd' || mdf == 'i' || mdf == 's' || mdf == 'c')
	{
		diff = w - (vl + *pchar);
		pad_len = diff;

		if (*(fmt + j - 1) == '0' || *(fmt + j + 1) == '0')
		{
		}
		else
		{
			k = 0;
			while (k < pad_len)
			{
				print = _strcat(print, " ");
				k++;
			}
			*pchar += k;
		}
	}
}

/**
* handle_zeroF - handles the zero flag.
*
* @mdf: modifier.
* @width: width specifier.
* @val_length: length of a value.
* @printedchar: number of characters printed on the screen.
* @print: string to be printed on the screen.
*
* Return: printed characters.
*/

char *handle_zeroF(char mdf,
		int width, int val_length, int *printedchar, char *print)
{

	int k = 0, pad_len, diff;

	if (mdf == 'd' ||
			mdf == 'i' ||
			mdf == 'o' || mdf == 'u' || mdf == 'x' || mdf == 'X')
	{
		if (val_length < width)
		{
			diff = width - (val_length + *printedchar);
			pad_len = diff;

			k = 0;
			while (k < pad_len)
			{
				print = _strcat(print, "0");
				k++;
			}
			*printedchar += k;
		}
	}

	return (print);
}

/**
* handle_minusF - handles the minus flag.
*
* @fmt: format string.
* @j: loop index.
* @print: string to be printed on the screen.
*
*/

void handle_minusF(const char *fmt, int j, char *print)
{
	char pchar, nchar;

	pchar = *(fmt + j - 1);
	nchar = *(fmt + j + 1);

	if (pchar == '0' || nchar == '0' || pchar == '#' || nchar == '#')
	{
	}
	else
	{
		print[0] = '\0';
	}
}


/**
* handle_plusF - handles the plus flag.
*
* @mdf: modifier.
* @print: the string to be printed on the screen.
* @val: length of a value.
* @printedchar: number of characters printed on the screen.
*
*/

void handle_plusF(char mdf, char *print, int *printedchar, void *val)
{
	int *dval;

	if (mdf == 'd' || mdf == 'i')
	{
		dval = (int *) val;
		if (*dval > 0)
		{
			print = _strcat(print, "+");
			*printedchar += 1;
		}
	}
}
