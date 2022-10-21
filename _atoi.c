#include "main.h"

/*
* _atoi - converts string to integer.
*
* @num: string to be converted.
*
* Return: integer representation of a string.
*
*/

int _atoi(char *num)
{
	int i = 0, len = 0, n = 0, p = 0;

	if (num == NULL || _strlen(num) <= 0)
		return (-1);

	len = _strlen(num);
	p = len - 1;

	for (i = 0; i < len; i++)
	{
		n += ((int)num[i] - 48) * _power(10, p - i);
	}

	return (n);
}
