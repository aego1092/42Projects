# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpuscedd <gpuscedd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/31 15:23:39 by gpuscedd          #+#    #+#              #
#    Updated: 2026/05/31 15:23:42 by gpuscedd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome dell'eseguibile
NAME		= fixed

# Compilatore e flag obbligatori per il C++98
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

# I file sorgenti del progetto
SRCS		= main.cpp \
			  Fixed.cpp

# Generazione automatica dei file oggetto (.o)
OBJS		= $(SRCS:.cpp=.o)

# Regola principale
all: $(NAME)

# Regola per creare l'eseguibile unendo i file oggetto
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Regola per pulire i file intermedi (.o)
clean:
	rm -f $(OBJS)

# Regola per pulire tutto (file intermedi + eseguibile)
fclean: clean
	rm -f $(NAME)

# Regola per ricompilare tutto da zero
re: fclean all

# Dichiarazione delle regole fittizie per evitare conflitti con file omonimi
.PHONY: all clean fclean re