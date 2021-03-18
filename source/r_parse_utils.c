/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_parse_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:37:31 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/18 15:11:25 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wind_digits(char *line, int *i)
{
	while (ft_isdigit(*(line + *i)))
		(*i)++;
}

void	res_error_check(char *line, int i, t_all_data *all)
{
	if ((!ft_isdigit(*(line + i)) && *(line + i) != '\0') ||
		all->parse_data.x_res <= 0 || all->parse_data.y_res <= 0)
	{
		free(line);
		error_handler("Invalid screen resolution");
	}
}

int		check_text_ext(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '.')
		i++;
	if (str[i] != 'x' && str[i + 1] != 'p' && str[i] != 'm')
		return (-1);
	return (0);
}
