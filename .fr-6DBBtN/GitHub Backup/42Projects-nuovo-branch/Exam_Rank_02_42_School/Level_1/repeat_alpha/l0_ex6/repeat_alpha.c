#include<unistd.h>
#include<stdio.h>

void	ft_repeat_alpha(char *argv)
{
	int i;
	int c;

	i = 0;
	while (argv[i] >= 'a' && argv[i] <= 'z' && argv[i])
	{
		c = argv[i] - 'a' + 1;
		while(c > 0)
		{
			write(1, &argv[i], 1);
			c--;
		}
		i++;
	}
	return;
}


int main(int argc, char **argv)
{
	if (argc == 2)
		ft_repeat_alpha(argv[1]);
	write(1, &"\n", 1);
	return(0);
}
