#include <stdlib.h>

char *ft_strjoin(char *s1, char *s2)
{
	int	i1;
	int	i2;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	
	str= (char*)malloc((ft_strlen(s1)+ft_strlen(s2)+1)*sizeof(char));
	if (!str)
		return (NULL);
	
	i1 = 0;
	if (s1)
	{
		while (s1[i1])
		{
			str[i1] = s1[i1];
			i1++;
		}
	}
	i2 = 0;
	if (s2)
	{
		while (s2[i2])
		{
			str[i1 + i2] = s2[i2];
			i2++;
		}
	}
	str[i1 + i2] = '\0';
	return(str);
}