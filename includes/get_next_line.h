/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:28:48 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/13 19:26:57 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		get_next_line(int fd, char **line);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_cutstr(char const *s, int c);
size_t	ft_strlen(const char *str);
#endif
