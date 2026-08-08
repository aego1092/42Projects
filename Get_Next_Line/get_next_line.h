/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 13:32:20 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/08/08 15:32:21 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//A
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//B
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//C
#  ifndef OPEN_MAX
#   define OPEN_MAX 1024
#  endif


//xxx
//# include <fcntl.h>  // Contiene open() ma al massimo la uso nel main
# include <string.h> //da verificare

//Libraries needeed
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
// <unistd.h>  Contiene read() e close()



char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
int		main(void);

//
//ssize_t	read(int fildes, void *buf, size_t nbyte);
//ssize_t	read(fd, buffer, BUFFER_SIZE);

#endif

