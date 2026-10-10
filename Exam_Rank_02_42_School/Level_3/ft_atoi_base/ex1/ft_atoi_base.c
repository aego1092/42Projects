#include <stdio.h>


int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return(1);
	else
		return(0);
}

int	ft_isspace(char	c)
{
	if ((c >= 9 && c <=13) || c == 32)
	{
		return(1);
	}
	else
		return(0);
}


int value(char c, char *set){
	int i = 0;
while(set[i])
{
if(set[i] == c)
	return i;
i++;
}
return -1;
}

int	ft_atoi_base(const char	*str, int str_base)
{
	int	res;
	int	i;
	int	sign;
	
	char	s[16] = "0123456789abcdef";
	int x;

	res = 0;
	i = 0;
	sign = 1;
	x = 0;

	while (str[i])
	{
		if (ft_isspace(str[i]))
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
			{
				sign = -sign;
			}
			i++;
		}
		x = value(str[i], s);
		int num = (str[i] >= 48 && str[i]<= 57) ? str[i]-48 : str[i]-87; 
		res =( res * str_base) + num;
		i++;
	}
	return (sign * res);
}

int	 main ()
{
	printf("%d", ft_atoi_base("ff", 16));
}
