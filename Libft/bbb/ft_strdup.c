/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giupalum <giupalum@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:36:45 by giupalum          #+#    #+#             */
/*   Updated: 2026/06/15 17:36:46 by giupalum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len_s1;
	char	*res;

	len_s1 = ft_strlen(s1);
	res = malloc(len_s1 + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, len_s1 + 1);
	return (res);
}
