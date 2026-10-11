#include<stdio.h>

int ft_strlen(char *str)
{
	int i;
	i = 0;

	if (!str[i])
		return(i);
	while (str[i])
		i++;
	return(i);
}

int main()
{
	char a[] ="MaremmaAgmagnacca";
	printf("%d",ft_strlen(a));
	return(0);
}
