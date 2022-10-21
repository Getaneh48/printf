#include "main.h"

/**
* check_flag_exist - check if a flag exists on the format string.
*
* @fmt: format string.
* @s_index: start index to search.
* @e_index: end index to end search.
* @flag: the flag to be searched.
*
* Return: true or false.
*
*/

int check_flag_exist(const char *fmt, int s_index, int e_index, char flag)
{
	int i, found = 0;

	for (i = s_index; i <= e_index; i++)
	{
		if (fmt[i] == flag)
		{
			found = 1;
			break;
		}
	}
	return (found);
}
