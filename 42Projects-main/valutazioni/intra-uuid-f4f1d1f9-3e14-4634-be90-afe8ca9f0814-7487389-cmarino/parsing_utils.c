/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 10:40:25 by cmarino           #+#    #+#             */
/*   Updated: 2026/08/02 10:40:28 by cmarino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_flag(char *str)
{
	if (ps_strncmp(str, "--simple", 8) == 0 || ps_strncmp(str, "--medium",
			8) == 0 || ps_strncmp(str, "--complex", 8) == 0 || ps_strncmp(str,
			"--adaptive", 10) == 0)
		return (1);
	else
		return (0);
}

int	get_flag(char *str)
{
	if (ps_strncmp(str, "--simple", 8) == 0)
		return (1);
	else if (ps_strncmp(str, "--medium", 8) == 0)
		return (2);
	else if (ps_strncmp(str, "--complex", 8) == 0)
		return (3);
	else if (ps_strncmp(str, "--adaptive", 10) == 0)
		return (4);
	else
		return (0);
}

int	count_tokens_str(const char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] && str[i] != ' ')
		{
			count++;
			while (str[i] && str[i] != ' ')
				i++;
		}
	}
	return (count);
}

int	count_total_numbers(char **argv, int start, int argc)
{
	int	total;
	int	i;

	total = 0;
	i = start;
	while (i < argc)
	{
		total += count_tokens_str(argv[i]);
		i++;
	}
	return (total);
}

int	extract_token(const char *str, int *pos, char *buf)
{
	int	j;

	while (str[*pos] == ' ')
		(*pos)++;
	j = 0;
	while (str[*pos] && str[*pos] != ' ' && j < 31)
		buf[j++] = str[(*pos)++];
	buf[j] = '\0';
	return (j > 0);
}
