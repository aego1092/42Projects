/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pushswap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 15:04:40 by cmarino           #+#    #+#             */
/*   Updated: 2026/07/03 16:54:40 by cmarino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/*
** ═══════════════════════════════════════════
**              STRUCTURES
** ═══════════════════════════════════════════
*/

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node		*top;
	int			size;
}	t_stack;

/*
** ═══════════════════════════════════════════
**         PRINTF_FD (PERSONA B)
** ═══════════════════════════════════════════
*/

int				ft_putchar_fd(char c, int fd);
int				ft_putstr_fd(char *s, int fd);
int				ft_putnbr_base_fd(long n, int fd);
int				ft_putunbr_fd(unsigned long n, int fd);
int				ft_printf_fd(int fd, const char *format, ...);
unsigned long	ft_get_scale(int precision);
unsigned long	ft_round(double *frac, long *int_part, unsigned long scale);
int				ft_print_frac(unsigned long frac, unsigned long scale, int fd);
int				ft_putfloat_fd(double nb, int precision, int fd);

/*
** ═══════════════════════════════════════════
**         BENCHMARK (Persona A)
** ═══════════════════════════════════════════
*/

typedef struct s_bench
{
	int			total_ops;
	int			sa;
	int			sb;
	int			ss;
	int			pa;
	int			pb;
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
	double		disorder;
	char		*strategy;
}				t_bench;

t_bench			*bench_init(void);
void			bench_print(t_bench *b);

/*
** ═══════════════════════════════════════════
**         OPERAZIONI STACK (Persona A)
** ═══════════════════════════════════════════
*/

/* swap */
void			sa(t_stack *a, t_bench *bench);
void			sb(t_stack *b, t_bench *bench);
void			ss(t_stack *a, t_stack *b, t_bench *bench);

/* push */
void			pa(t_stack *a, t_stack *b, t_bench *bench);
void			pb(t_stack *a, t_stack *b, t_bench *bench);

/* rotate */
void			ra(t_stack *a, t_bench *bench);
void			rb(t_stack *b, t_bench *bench);
void			rr(t_stack *a, t_stack *b, t_bench *bench);

/* reverse rotate */
void			rra(t_stack *a, t_bench *bench);
void			rrb(t_stack *b, t_bench *bench);
void			rrr(t_stack *a, t_stack *b, t_bench *bench);

/*
** ═══════════════════════════════════════════
**         UTILS STACK (Persona A)
** ═══════════════════════════════════════════
*/

t_stack			*stack_init(void);
void			stack_push(t_stack *s, int value);
int				stack_pop(t_stack *s);
int				is_sorted(t_stack *a);
void			stack_free(t_stack *s);

/*
** ═══════════════════════════════════════════
**         UTILS (Persona A)
** ═══════════════════════════════════════════
*/

int				ft_atoi_check(const char *str, int *result);
int				has_duplicate(int *arr, int size);

/*
** ═══════════════════════════════════════════
**         PARSING (Persona A)
** ═══════════════════════════════════════════
*/

t_stack			*parse_args(int argc, char **argv, int *flag);
int				get_flag(char *str);
int				is_flag(char *str);
int				count_tokens_str(const char *str);
int				count_total_numbers(char **argv, int start, int argc);
int				extract_token(const char *str, int *pos, char *buf);
int				ps_strncmp(const char *s1, const char *s2, size_t n);
int				get_start(int argc, char **argv, int *flag);
void			error_exit(void);

/*
** ═══════════════════════════════════════════
**         DISORDER (Persona A)
** ═══════════════════════════════════════════
*/

double			compute_disorder(t_stack *a);

/*
** ═══════════════════════════════════════════
**         NORMALIZZAZIONE (Persona B — TUA)
** ═══════════════════════════════════════════
*/

void			normalize(t_stack *a);

/*
** ═══════════════════════════════════════════
**         ALGORITMI (Persona B — TUOI)
** ═══════════════════════════════════════════
*/

/* O(n²) */
void			sort_simple(t_stack *a, t_stack *b, t_bench *bench);

/* O(n√n) */
void			sort_medium(t_stack *a, t_stack *b, t_bench *bench);

/* O(n log n) */
void			sort_complex(t_stack *a, t_stack *b, t_bench *bench);

/* adattivo */
void			sort_adaptive(t_stack *a, t_stack *b, t_bench *bench);

/* sort utils */
int				find_min_pos(t_stack *a);
void			bring_to_top(t_stack *a, int pos, t_bench *bench);
void			sort_tiny(t_stack *a, t_stack *b, t_bench *bench);

#endif