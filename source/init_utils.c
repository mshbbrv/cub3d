/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:18:50 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/11 18:01:55 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_dir_init(t_all_data *all, char player)
{
	all->rc.pl_dir_x = 0;
	all->rc.pl_dir_y = 0;
	all->rc.cam_plane_x = 0;
	all->rc.cam_plane_y = 0;
	if (player == 'S')
	{
		all->rc.pl_dir_y = 1;
		all->rc.cam_plane_x = -0.66;
	}
	if (player == 'N')
	{
		all->rc.pl_dir_y = -1;
		all->rc.cam_plane_x = 0.66;
	}
	if (player == 'W')
	{
		all->rc.pl_dir_x = -1;
		all->rc.cam_plane_y = -0.66;
	}
	if (player == 'E')
	{
		all->rc.pl_dir_x = 1;
		all->rc.cam_plane_y = 0.66;
	}
}

void	player_init(t_all_data *all)
{
	int	x;
	int y;

	y = 0;
	while (all->map_data.map[y])
	{
		x = 0;
		while (all->map_data.map[y][x])
		{
			if (pl_validate(all->map_data.map[y][x]))
			{
				all->map_data.pl_x = x + 0.5;
				all->map_data.pl_y = y + 0.5;
				player_dir_init(all, all->map_data.map[y][x]);
			}
			x++;
		}
		y++;
	}
}

void	screen_size_init(t_all_data *all)
{
	int	height;
	int	width;

	height = 1600;
	width = 2560;
	if (all->parse_data.x_res > width)
		all->parse_data.x_res = width;
	if (all->parse_data.y_res > height)
		all->parse_data.y_res = height;
}
