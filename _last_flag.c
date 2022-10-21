#include "main.h"
#include <stdio.h>

/**
* _last_flag - finds the index of the last flag in the format string.
*
* @fmt: format string.
* @s_index: start index.
* @e_index: end index.
*
* Return: the index of the last flag.
*
*/

int _last_flag(const char *fmt, int s_index, int e_index)
{
	char flags[] = {'-', '+', '0', ' ', '#', '\0'};
	int j = 0, i = 0;
	int match = 0;
	int lf_index = -1;

	for (i = s_index; i <= e_index; i++)
	{
		match = 0;
		for (j = 0; j < _strlen(flags); j++)
		{
			if (fmt[i] == flags[j])
			{
				match = 1;
				lf_index = i;
				break;
			}
		}
		if (match == 0)
			break;
	}

	return (lf_index);
}
