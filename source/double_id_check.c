/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_id_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 11:39:02 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/14 15:40:04 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	double_color_check(char *line, unsigned int *color)
{
	if (*color != 0)
	{
		free(line);
		error_handler("Double color set");
	}
}

void	double_tex_check(char *str)
{
	if (str != NULL)
		error_handler("Double texture set");
}

void	double_res_check(char *line, t_all_data *all)
{
	if (all->parse_data.x_res != 0 || all->parse_data.y_res != 0)
	{
		free(line);
		error_handler("Double resolution set");
	}
}
