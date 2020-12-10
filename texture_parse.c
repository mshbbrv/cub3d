/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elemParse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:23:38 by thjonell          #+#    #+#             */
/*   Updated: 2020/12/10 20:38:15 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	color_parse(char ***line, int *color)
{
	int	i;
	int j;

	i = 2;
	j = 0;
	while (j < 3)
	{
		color[j] = 0;
		while (ft_isdigit(*(**line + i)))
		{
			color[j] = color[j] * 10 + (*(**line + i) - 48);
			i++;
		}
		if (color[j] > 255 || color[j] < 0)
		{
			free(**line);
			return (-1);
		}
		j++;
		i++;
	}
	free(**line);
	return (0);
}

int	texture_parse(char ***line, char **str, int i)
{
	int fd;

	while (*(**line + i) == ' ')
		i++;
	*str = **line + i;
	if ((fd = open(*str, O_RDONLY)) < 0)
		return (-1);
	close(fd);
	return (0);
}

int	r_parse(char ***line, t_world ***world)
{
	int	i;

	i = 2;
	while (ft_isdigit(*(**line + i)))
	{
		(**world)->x_res = (**world)->x_res * 10 + (*(**line + i) - 48);
		i++;
	}
	i++;
	while (ft_isdigit(*(**line + i)))
	{
		(**world)->y_res = (**world)->y_res * 10 + (*(**line + i) - 48);
		i++;
	}
	if ((**world)->y_res < 0 || (**world)->x_res < 0)
	{
		free(**line);
		return (-1);
	}
	free(**line);
	return (0);
}
