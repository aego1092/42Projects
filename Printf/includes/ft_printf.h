/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:18:18 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/07/25 18:22:24 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//xxx
#include <stdio.h>

//librerie necessarie
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>

/* CONVERSIONS */
void	ft_print(const char *stampa, int j);

/* LIBFT */
size_t	ft_strlen(const char *s);

/* UTILS */


#endif