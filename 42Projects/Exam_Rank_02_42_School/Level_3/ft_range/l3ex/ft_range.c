#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{
	int	*int_ptr;
	int	n;
	int	i;
	int	cd;

	cd = 1;

	if (end >= start)
		n = (end - start) + 1;
	else
	{
		n = (- 1) * (end - start) + 1;
		cd = -1;
	}
	int_ptr = (int *)malloc((n)*(sizeof(int)));
	if (int_ptr == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		int_ptr[i] = start + i*cd;
		printf("%d\n", int_ptr[i]);
		i++;
	}
	return(int_ptr);
}

int main()
{
	int a = -1;
	int b = 2;
	// printf("%p", ft_range(a, b));
	return (0);
}

