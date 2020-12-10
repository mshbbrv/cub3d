/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:27:42 by thjonell          #+#    #+#             */
/*   Updated: 2020/12/03 20:59:26 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static void	ft_joinbuffer(char **tmp, char **buf)
{
	char	*tmppointer;

	tmppointer = ft_strjoin(*tmp, *buf);
	free(*tmp);
	*tmp = tmppointer;
}

static int	ft_newline(char **line, char **tmp, char **buf)
{
	char	*newlinepointer;
	char	*tmppointer;

	newlinepointer = ft_strchr(*tmp, '\n');
	*line = ft_cutstr(*tmp, '\n');
	tmppointer = ft_cutstr(++newlinepointer, '\0');
	free(*tmp);
	*tmp = tmppointer;
	free(*buf);
	return (1);
}

static int	ft_eof(char **line, char **tmp, char **buf)
{
	*line = ft_cutstr(*tmp, '\0');
	free(*buf);
	free(*tmp);
	*tmp = NULL;
	return (0);
}

int			get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*tmp[FOPEN_MAX];
	int			ret;

	if (fd >= 0 && BUFFER_SIZE > 0
		&& (buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
	{
		while ((ret = read(fd, buf, BUFFER_SIZE)) >= 0)
		{
			buf[ret] = '\0';
			if (!tmp[fd])
				tmp[fd] = ft_cutstr(buf, '\0');
			else
				ft_joinbuffer(&tmp[fd], &buf);
			if (ft_strchr(tmp[fd], '\n'))
				return (ft_newline(&*line, &tmp[fd], &buf));
			if (ret == 0)
				return (ft_eof(&*line, &tmp[fd], &buf));
		}
	}
	return (-1);
}
