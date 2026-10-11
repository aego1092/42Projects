# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarino <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/01 11:34:04 by cmarino           #+#    #+#              #
#    Updated: 2026/07/01 11:42:14 by cmarino          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC	= cc
FLAGS	= -Wall -Wextra -Werror -g

SRC = main.c \
	stack.c \
	parsing.c \
	utils.c \
	printf_fd.c \
	printf_fd_utils.c \
	printf_fd_putfloat.c \
	operations_swap.c \
	operations_push.c \
	operations_rotate.c \
	operations_rev_rotate.c \
	compute_disorder.c \
	normalize.c \
	benchmark.c \
	sort_simple.c \
	sort_medium.c \
	sort_complex.c \
	sort_adaptive.c \
	sort_tiny.c \
	parsing_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	   $(CC) $(FLAGS) $(OBJ) -o $(NAME) -lm

%.o: %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
