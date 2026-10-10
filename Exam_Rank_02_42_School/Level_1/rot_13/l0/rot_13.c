#include<unistd.h>
#include<stdio.h>
void ft_rot13(char * str)
{
	int i;

	i = 0;

	if (!str[i])
		return;
	while(str[i])
	{
		if((str[i] >= 'a') && (str[i] <= 'l'))
		{
			str[i] = ((str[i] - 'a'+ 13)) + 'a';
		}
		else if((str[i] >= 'm') && (str[i] <= 'z'))
		{
			str[i] = ((str[i] - 'm' - 13)) + 'm' ;
		}
		else if((str[i] >= 'A') && (str[i] <= 'L'))
		{
			str[i] = ((str[i] - 'A'+ 13)) + 'A';
		}
		else if((str[i] >= 'M') && (str[i] <= 'Z'))
		{
			str[i] = ((str[i] - 'M' -13)) + 'M';
		}
		else
	write(1, &str[i], 1);
	i++;
	}
	return;
}

int main(int argc, char **argv)
{
	if (argc == 2)
		ft_rot13(argv[1]);
	write(1, &"\n", 1);
	return(0);
}
