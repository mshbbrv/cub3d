/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_parse_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:37:31 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/17 22:12:44 by thjonell         ###   ########.fr       */
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
