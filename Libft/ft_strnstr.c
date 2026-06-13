/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 18:09:37 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/13 20:57:32 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s);

char 	*ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t  res_len;
    int     i;
    int     j;

    i = 0;
    j = 0;
    
    while (len <= ft_strlen (big) - i - ft_strlen(little))
    {
        if (big[i] == little[j])
        {
            j = 0;
            while (j <= ft_strlen(little))
            {
                if (big[i + j] == little[j])
                {
                    j++;
                    if (j == ft_strlen(little))
                        return (big[i + j]);
                }
            }
        }
        i++;
    }
    return (NULL);
}
