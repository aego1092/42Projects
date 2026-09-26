/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matozzi- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:50:54 by matozzi-          #+#    #+#             */
/*   Updated: 2026/07/18 18:50:57 by matozzi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);

char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strchr_gnl(char *s, char c);
char	*extract_line(char *stash);
char	*update_stash(char *stash);
int		ft_strlen_gnl(char *s);

#endif
