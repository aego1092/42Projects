NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

LIBFT_DIR   = src/libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRCDIR		= src
INCDIR		= includes

SRCS		= 	ft_printf.c \
				$(SRCDIR)/conversions/ft_print_char_str.c \
				$(SRCDIR)/conversions/ft_print_dispatcher.c \
				$(SRCDIR)/conversions/ft_print_hex.c \
				$(SRCDIR)/conversions/ft_print_nbr.c \
				$(SRCDIR)/conversions/ft_print_percent.c \
				$(SRCDIR)/conversions/ft_print_ptr.c \
				$(SRCDIR)/utils/ft_utils.c 

OBJS		= $(SRCS:.c=.o)

INCLUDES    = -I. -I$(LIBFT_DIR) -I$(INCDIR)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re