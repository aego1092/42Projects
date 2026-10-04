/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvucc <fsalvucc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 00:09:29 by fsalvucc          #+#    #+#             */
/*   Updated: 2026/06/01 17:56:49 by fsalvucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int	i;

	if (!s)
		return ;
	i = ft_strlen(s);
	write(fd, s, i);
	write(fd, "\n", 1);
}
