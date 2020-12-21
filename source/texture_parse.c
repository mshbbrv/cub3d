/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:23:38 by thjonell          #+#    #+#             */
/*   Updated: 2020/12/21 19:17:43 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	color_parse(char ***line, int *color, int i)
{
	int j;

	while (*(**line + i) == ' ')
		i++;
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
			error_handler("Invalid color set");
		}
		j++;
		i++;
	}
	free(**line);
	return (PARSE_SUCCESS);
}

int	texture_parse(char ***line, char **str, int i)
{
	int fd;

	while (*(**line + i) == ' ')
		i++;
	*str = **line + i;
	if ((fd = open(*str, O_RDONLY)) < 0)
	//	error_handler("Сan not open texture file");
		;
	close(fd);
	return (PARSE_SUCCESS);
}

int	r_parse(char ***line, t_world ***world, int i)
{
	while (*(**line + i) == ' ')
		i++;
	if (ft_isdigit(*(**line + i)))
	{
		while (ft_isdigit(*(**line + i)))
		{
			(**world)->x_res = (**world)->x_res * 10 + (*(**line + i) - 48);
			i++;
		}
		if (*(**line + i) == ' ')
			i++;
		while (ft_isdigit(*(**line + i)))
		{
			(**world)->y_res = (**world)->y_res * 10 + (*(**line + i) - 48);
			i++;
		}
		if ((!ft_isdigit(*(**line + i)) && *(**line + i) != '\0'))
		{
			free(**line);
			error_handler("Invalid screen resolution");
		}
		free(**line);
	}
	else
		error_handler("Invalid screen resolution");
	return (PARSE_SUCCESS);
}