/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_id_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 11:39:02 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/17 19:53:43 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	double_color_check(char *line, t_all_data *all)
{
	if (*line == 'C')
	{
		if (all->parse_data.c_color_flag == 1)
			error_handler("Double ceil color set");
		all->parse_data.c_color_flag = 1;
	}
	if (*line == 'F')
	{
		if (all->parse_data.f_color_flag == 1)
			error_handler("Double floor color set");
		all->parse_data.f_color_flag = 1;
	}
}

void	double_tex_check2(char *line, t_all_data *all)
{
	if (*line == 'W' && *(line + 1) == 'E')
	{
		if (all->parse_data.we_flag == 1)
			error_handler("Double west texture set");
		all->parse_data.we_flag = 1;
	}
	else if (*line == 'E' && *(line + 1) == 'A')
	{
		if (all->parse_data.ea_flag == 1)
			error_handler("Double east texture set");
		all->parse_data.ea_flag = 1;
	}
	else if (*line == 'S')
	{
		if (all->parse_data.s_flag == 1)
			error_handler("Double sprite texture set");
		all->parse_data.s_flag = 1;
	}
}

void	double_tex_check(char *line, t_all_data *all)
{
	if (*line == 'N' && *(line + 1) == 'O')
	{
		if (all->parse_data.no_flag == 1)
			error_handler("Double north texture set");
		all->parse_data.no_flag = 1;
	}
	else if (*line == 'S' && *(line + 1) == 'O')
	{
		if (all->parse_data.so_flag == 1)
			error_handler("Double south texture set");
		all->parse_data.so_flag = 1;
	}
	else
		double_tex_check2(line, all);
}

void	double_res_check(char *line, t_all_data *all)
{
	if (*line == 'R')
	{
		if (all->parse_data.res_flag == 1)
			error_handler("Double resolution set");
		all->parse_data.res_flag = 1;
	}
}

void	elem_check(t_all_data *all)
{
	if (all->parse_data.res_flag == 0)
		error_handler("Screen resolution not set");
	if (all->parse_data.c_color_flag == 0)
		error_handler("Ceil color not set");
	if (all->parse_data.f_color_flag == 0)
		error_handler("Floor color not set");
	if (all->parse_data.we_flag == 0)
		error_handler("West texture not set");
	if (all->parse_data.no_flag == 0)
		error_handler("North texture not set");
	if (all->parse_data.so_flag == 0)
		error_handler("South texture not set");
	if (all->parse_data.ea_flag == 0)
		error_handler("East texture not set");
	if (all->parse_data.s_flag == 0)
		error_handler("Sprite texture not set");
}
