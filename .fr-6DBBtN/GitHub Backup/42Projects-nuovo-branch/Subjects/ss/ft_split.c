#include <stdlib.h>
#include <stdio.h>

int	count_word(char *s)
{
	int	i = 0;
	int	c_char = 0;
	int 	c_word = 0;

	while (s[i])
	{
		if(s[i] != ' ')
			c_char++;
		if (c_char > 0 && (s[i] == ' ' || s[i + 1] == '\0'))
		{
			c_char = 0;
			c_word++;
		}
		i++;
	}
	return (c_word);
}

void	allocate_mtrx(char **mtrx, char *s)
{
	int	i = 0;
	int	k = 0;
	int	c_char = 0;

	while (s[i])
	{
		if(s[i] != ' ')
			c_char++;
		if (c_char > 0 && (s[i] == ' ' || s[i + 1] == '\0'))
		{
			mtrx[k] = (char *) malloc (sizeof(char) * (c_char + 1));
			c_char = 0;
			k++;
		}
		i++;
	}
	mtrx = NULL;
}

void	insert_mtrx(char **mtrx, char *s)
{
	int	i = 0;
	int	k = 0;
	int	j = 0;
	int	c_char = 0;
 	
	while (s[i])
	{
		if(s[i] != ' ')
		{
			mtrx[j][k] = s[i];
			c_char++;
			k++;
		}	
		if (c_char > 0 && (s[i] == ' ' || s[i + 1] == '\0'))
		{
			mtrx[j][k] = '\0';
			k = 0;
			j++;
			c_char = 0;
		}
		i++;
	}
}


char    **ft_split(char *str)
{
	int count = count_word(str);
	char **mtrx = (char **) malloc(sizeof(char *)*(count + 1));
	allocate_mtrx(mtrx, str);
	insert_mtrx(mtrx, str);
	return (mtrx);	
}


int main()
{
	char **mtrx = ft_split("");
	int i = 0;
	while(mtrx[i])
	{
		printf("%s\n", mtrx[i]);
		i++;
	}	
}
