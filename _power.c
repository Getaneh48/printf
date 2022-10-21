/**
* _power - calculates the power of a number.
*
* @base: base of the number.
* @exp: exponent of the base.
*
* Return: the result of a number powered to its exponent.
*
*/

int _power(int base, int exp)
{
	int p;

	p = base;
	if (exp > 0)
	{
		while (exp > 1)
		{
			p = p * base;
			exp--;
		}
	}
	else
	{
		p = 1;
	}

	return (p);
}
