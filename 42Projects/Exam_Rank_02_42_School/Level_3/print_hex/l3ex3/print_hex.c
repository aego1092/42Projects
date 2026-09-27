#include <unistd.h>
get_digit(char c, int str_base)
{
int val;
if (c >= '0' && c <= '9')
	val = c - '0';
if (c >= 'a' && c <= 'z')
	val = c - 'a' + 10;
if (c >= 'A' && c <= 'Z')
	val = c - 'A' +10;
else
	return(-1);

if (val < str_base)
	return (val);
return(-1);
}


int	atoi_base(char *str, int str_base)
{
	int res;
	int sign;
	int digit;
	int i;

	if (str_base != 10)
		return (0);

	i=0;
	sign = 1;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i])
	{
		digit = get_digit(str[i], str_base);

		if (digit == -1)
			return(0);
		res = res * str_base + digit;
		i++;

	}
}

void	print_hex(char *n)
{
	return ;
}

int main(int argc, char **argv)
{
	int	intb10;

	if (argc == 2)
	{
		intb10 = atoi_base(argv[1], 10);
		
	}
	write(1,"\n",1);
	return(0);
} 