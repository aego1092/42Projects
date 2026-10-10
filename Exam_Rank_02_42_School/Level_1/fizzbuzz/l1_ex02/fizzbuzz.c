#include<unistd.h>

void	putnumber(int n)
{
	char *decimal;

	decimal = "0123456789";
	if (n > 9)
	{
		putnumber(n / 10);
	}
	write(1, &decimal[n % 10], 1);
	return;
}



int main ()
{
	int	i;

	i = 1;
	while(i <= 100)
	{
		if (i % 15 == 0)
			write(1, &"fizzbuzz", 8);
		else if (i % 5 == 0)
			write(1, &"buzz", 4);
		else if (i % 3 == 0)
			write(1, &"fizz", 4);
		else
			putnumber(i);
		i++;
		write(1, &"\n", 1);
	}
	return (0);
}
