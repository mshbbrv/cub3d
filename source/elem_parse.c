/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:23:38 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/17 21:26:15 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_color(int *tmp, char *line, int *i)
{
	while (ft_isdigit(*(line + *i)))
	{
		if (*tmp <= 255)
			*tmp = *tmp * 10 + (*(line + *i) - 48);
		else
			break ;
		(*i)++;
	}
}

int		color_parse(char *line, unsigned int *color, int i, t_all_data *all)
{
	int j;
	int	tmp[3];

	double_color_check(line, all);
	space_check(line, i, "Invalid color set");
	while (*(line + i) == ' ')
		i++;
	j = 0;
	while (j < 3)
	{
		tmp[j] = 0;
		digit_check(line, i);
		read_color(&tmp[j], line, &i);
		invalid_color_check(tmp[j], line, i, j);
		if (*(line + i) == ',')
			i++;
		j++;
	}
	*color = (tmp[0] << 16 | tmp[1] << 8 | tmp[2]);
	return (PARSE_SUCCESS);
}

int		texture_parse(char *line, char **str, int i, t_all_data *all)
{
	int fd;

	double_tex_check(line, all);
	space_check(line, i, "Invalid texture set");
	while (*(line + i) == ' ')
		i++;
	*str = ft_strdup(line + i);
	if ((fd = open(*str, O_RDONLY)) < 0 && check_text_ext(*str) == -1)
	{
		close(fd);
		error_handler("Сan not open texture file");
	}
	close(fd);
	return (PARSE_SUCCESS);
}

void	r_parse_2(char *line, int i, t_all_data *all)
{
	while (ft_isdigit(*(line + i)))
	{
		if (all->parse_data.x_res < 214748364)
			all->parse_data.x_res = all->parse_data.x_res * 10 + (line[i] - 48);
		else
		{
			wind_digits(line, &i);
			break ;
		}
		i++;
	}
	if (*(line + i) == ' ')
		i++;
	while (ft_isdigit((*(line + i))))
	{
		if (all->parse_data.y_res < 214748364)
			all->parse_data.y_res = all->parse_data.y_res * 10 + (line[i] - 48);
		else
		{
			wind_digits(line, &i);
			break ;
		}
		i++;
	}
	res_error_check(line, i, all);
}

int		r_parse(char *line, t_all_data *all, int i)
{
	double_res_check(line, all);
	space_check(line, i, "Invalid resolution set");
	while (*(line + i) == ' ')
		i++;
	if (ft_isdigit(*(line + i)))
		r_parse_2(line, i, all);
	else
	{
		free(line);
		error_handler("Invalid screen resolution");
	}
	screen_size_init(all);
	return (PARSE_SUCCESS);
}
