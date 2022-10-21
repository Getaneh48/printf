#include "main.h"
#include <stdio.h>

void excute_fh(char ch, const char *fmt, int i,
		int mi, int *nc, va_list args);

/**
* format_handler - process the format strings.
*
* @fmt: format string.
* @index: index.
* @nchar: number of characters printed on screen.
* @args: args.
*
* Return: the index of a modifier.
*
*/

int format_handler(const char *fmt, int index, int *nchar, va_list args)
{
	int modf_index;
	char ch;

	modf_index = get_modifier(fmt, index);
	if (modf_index == -1)
		return (-1);

	ch = *(fmt + modf_index);

	excute_fh(ch, fmt, index, modf_index, nchar, args);

	return (modf_index);
}

/**
* excute_fh - process the format strings.
*
* @ch: format modifier.
* @fmt: format string.
* @i: index.
* @mi: modifier index.
* @nc: number of characters printed on screen.
* @args: args.
*
*/

void excute_fh(char ch, const char *fmt, int i, int mi, int *nc, va_list args)
{
	switch (ch)
	{
		case 's':
			print_s(fmt, i, mi, nc, args);
			break;
		case 'c':
			print_c(fmt, i, mi, nc, args);
			break;
		case '%':
			print_percent(nc);
			break;
		case 'o':
			print_o(fmt, i, mi, nc, args);
			break;
		case 'u':
			print_u(fmt, i, mi, nc, args);
			break;
		case 'b':
			print_b(args, nc);
			break;
		case 'p':
			print_p(fmt, i, mi, nc, args);
			break;
		case 'x':
			print_x(fmt, 'x', i, mi, nc, args);
			break;
		case 'X':
			print_x(fmt, 'X', i, mi, nc, args);
			break;
		case 'S':
			print_S(args, nc);
			break;
		case 'r':
			print_r(args, nc);
			break;
		case 'R':
			print_R(args, nc);
			break;
		case 'd':
		case 'i':
			print_di(fmt, i, mi, nc, args);
	}
}

/**
* get_modifier - gets a modifier.
*
* @fmt: format string.
* @index: index to start searching.
*
* Return: index of a modifier.
*
*/

int get_modifier(const char *fmt, int index)
{
	char modf[17] = {'s',
		'c',
		'%',
		'b',
		'u',
		'd',
		'l',
		'o',
		'h', 'p', 'x', 'X', 'S', 'R', 'r', 'i', '\0'};
	int found = 0;
	int j = 0;
	char ch;

	while ((ch = *(fmt + index)))
	{
		for (j = 0; j < _strlen(modf); j++)
		{
			if (modf[j] == ch)
			{
				found = 1;
				break;
			}
		}
		if (found)
			break;
		index++;
	}

	if (found)
		return (index);

	return (-1);
}
