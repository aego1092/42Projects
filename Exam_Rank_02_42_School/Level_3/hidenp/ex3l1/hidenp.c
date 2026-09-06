#include <unistd.h>

void	hidenp(char	*p, char *s)
{
	int i;
	int j;
	int imax;
	int jmax;
	int match;
	i = 0;
	j = 0;
	imax = 0;
	jmax = 0;
	match = 0;
	while (p[i])
		imax = i++;

	while (s[j])
		jmax = j++;

	i = 0;
	j = 0;

	if (p[i] == '\0')
	{
		write(1, "0\n", 2);
		return;
	}
	while (p[i] && s[j])
		{
			if (p[i] == s[j])
				i++;
			j++;
		}
		
	
	
	if (imax + 1 == match)
		write(1, "1\n", 2);
}

int main(int argc, char **argv)
{
	if (argc == 3)
		hidenp(argv[1], argv[2]);
	write(1,"\n",1);
	return(0);
}