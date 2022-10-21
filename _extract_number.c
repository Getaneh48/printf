#include "main.h"
#include <stdio.h>

/**
* _extract_number - extract a number from astring.
*
* @str: string.
* @s_index: start index.
* @e_index: end index
*
* Return: integer.
*/

int _extract_number(const char *str, int s_index, int e_index)
{
	int num, i, j = 0;
	char *ptr;

	if (str == NULL || _strlen(str) <= 0 || e_index < s_index)
		return (-1);

	/*len = _strlen(str);*/
	ptr = (char *)malloc((e_index - s_index) + 1);
	i = s_index;
	while (i <= e_index)
	{
		if ((int)str[i] >= 48 && (int)str[i] <= 57)
		{
			*(ptr + j) = str[i];
			j++;
		}
		i++;
	}
	ptr[j] = '\0';
	num = _atoi(ptr);

	free(ptr);

	return (num);
}
