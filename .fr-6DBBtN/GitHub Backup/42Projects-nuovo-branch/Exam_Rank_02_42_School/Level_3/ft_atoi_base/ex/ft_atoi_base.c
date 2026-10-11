#include <stdio.h>

int	get_digit(char	c, int	base)
{
	int	val;

	if (c >= '0' && c <= '9')
		val = c - '0';
	else if (c >= 'a' && c <= 'f')
		val = c - 'a' + 10;
	else if (c >= 'A' && c <= 'F')
		val = c - 'A' + 10;	
	else
		return (-1);

	if (val < base)
		return (val);
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	res;
	int	sign;
	int	digit;
	int	i;

	if (str_base < 2 || str_base > 16)
		return(0);
	
	i=0;
	sign = 1;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	res = 0;
	while (str[i])
	{
		digit = get_digit(str[i], str_base);

		if (digit == -1)
			break;
		res = res * str_base + digit;
		i++;
	}
	return(sign * res);
}

int	main()
{
	printf("%d",ft_atoi_base("12FDB3", 16));

	return(0);
}