#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void fprime(int	n)
{
	int i;


	if (n == 1)
	{
		printf("1");
		return;
	}

	i = 2;
	while (i <= n)
	{
		if (n % i == 0 && i != n)
		{
			printf("%d", i);
			printf("*");
			n = n / i;
		}
		else if (n % i == 0 && i == n)
		{
			printf("%d", i);
			n = n / i;
		}
		else
			i++;
	}

return ;
}

int main(int argc, char **argv)
{
	if (argc ==2)
	{
		if(atoi(argv[1]) > 0)
		{
			fprime(atoi(argv[1]));
		}
	}
	write(1,"\n",1);	
	return(0);
}