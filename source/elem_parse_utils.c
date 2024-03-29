/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_parse_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 12:55:37 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/17 21:16:36 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	invalid_color_check(int tmp, char *line, int i, int j)
{
	if (tmp > 255 || tmp < 0 || (*(line + i) != ',' && j < 2) ||
		(*(line + i) != '\0' && j == 2))
	{
		free(line);
		error_handler("Invalid color set");
	}
}

void	empty_line_check(char *line, int j)
{
	int	i;

	if (j == 0 && *line == '\0')
	{
		free(line);
		error_handler("Invalid first line");
	}
	i = 0;
	if (*(line + i) == ' ' || *(line + i) == '\t')
	{
		while (*(line + i) == ' ' || *(line + i) == '\t')
			i++;
		if (*(line + i) == '\0')
		{
			free(line);
			error_handler("Spaces in an empty line");
		}
	}
}

void	digit_check(char *line, int i)
{
	if (!ft_isdigit(*(line + i)))
	{
		free(line);
		error_handler("Invalid color set");
	}
}

void	space_check(char *line, int i, char *str)
{
	if (*(line + i) != ' ')
	{
		free(line);
		error_handler(str);
	}
}
