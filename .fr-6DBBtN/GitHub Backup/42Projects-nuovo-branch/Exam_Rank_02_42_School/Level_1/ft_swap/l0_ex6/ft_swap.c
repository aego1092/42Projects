#include<stdio.h>

void	swap(int *a, int *b)
{
	int *tmp;

	tmp = a;
	a = b;
	b = tmp;
	printf("%d", *(a));
	printf("%d", *(b));
	return;
}


int main(void)
{
	int a;
	int b;

	a = 11;
	b = 22;

	swap(&a, &b);
	return(0);
}
