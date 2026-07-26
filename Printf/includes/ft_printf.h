/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:18:18 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/07/26 18:39:20 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//xxx
# include <stdio.h>
# include <limits.h>
//librerie necessarie
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

/*STRUCT*/
typedef int	(*t_ptr_funct)(va_list *);

/* CONVERSIONS */
int		ft_print_dispatcher(const char *stampa, size_t *i, va_list *args);
int		ft_print_char(va_list *args);
int		ft_print_str(va_list *args);
int		ft_print_nbr(va_list *args);
int		ft_print_unsigned(va_list *args);
int		ft_print_hex_low(va_list *args);
int		ft_print_hex_up(va_list *args);
int		ft_print_ptr(va_list *args);
int		ft_print_percent(va_list *args);

/* LIBFT */
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);

/* UTILS */
int		ft_putnbr_base(unsigned long nbr, const char *base);

int		ft_printf(const char *stampa, ...);
#endif