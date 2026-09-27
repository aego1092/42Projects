/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 15:25:41 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/08/22 15:41:15 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	max(int	*tab, unsigned int	len)
{
	int	max_no;
	int	i;
	
	if (len == 0 || tab == NULL)
		return (0);
	i = 0;
	max_no = tab[i];
	i++;
	while (i < len)
	{
		if (tab[i] > max_no)
			max_no = tab[i];
		i++;
	}
	return (0);		
}
