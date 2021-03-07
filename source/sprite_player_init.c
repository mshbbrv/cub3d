/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_player_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:05:54 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/07 19:59:57 by thjonell         ###   ########.fr       */
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

int		num_sprites(t_all_data *all)
{
	int	x;
	int y;
	int count;

	count = 0;
	y = 0;
	while (all->map_data.map[y])
	{
		x = 0;
		while (all->map_data.map[y][x])
		{
			if (all->map_data.map[y][x] == '2')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	sprite_init(t_all_data *all)
{
	int	x;
	int y;
	int count;

	all->sprite_data.num_sprites = num_sprites(all);
	if (!(all->sprite_data.sprite = (t_sprite *)malloc(all->sprite_data
	.num_sprites * sizeof(t_sprite))))
		error_handler("Can not allocate memory");
	count = 0;
	y = 0;
	while (all->map_data.map[y])
	{
		x = 0;
		while (all->map_data.map[y][x])
		{
			if(all->map_data.map[y][x] == '2')
			{
				all->sprite_data.sprite[count].x = x + 0.5;
				all->sprite_data.sprite[count].y = y + 0.5;
				count++;
			}
			x++;
		}
		y++;
	}
	if (!(all->sprite_data.z_buffer = (double *)malloc(all->parse_data
															   .x_res * sizeof(double))))
		error_handler("Can not allocate memory");
	if (!(all->sprite_data.dist = (double *)malloc(all->sprite_data
														   .num_sprites * sizeof(double))))
		error_handler("Can not allocate memory");
	if (!(all->sprite_data.order = (int *)malloc(all->sprite_data
														   .num_sprites *
														   sizeof(int))))
		error_handler("Can not allocate memory");
}

void	sprite_player_init(t_all_data *all)
{
	player_init(all);
	sprite_init(all);
}
