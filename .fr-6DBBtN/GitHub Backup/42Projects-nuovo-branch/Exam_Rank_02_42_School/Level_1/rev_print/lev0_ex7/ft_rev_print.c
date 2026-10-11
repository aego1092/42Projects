#include<unistd.h>
#include<stdio.h>

void ft_reverse_print(char *str)
{
	if (!str)
		return;
	int i;

	i = 0;

	while (str[i])
		i++;
	i--;
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
	return;
}


int	main(int argc, char **argv)
{
	ft_reverse_print(argv[1]);
	write(1, &"\n", 1);
	return(0);
}
