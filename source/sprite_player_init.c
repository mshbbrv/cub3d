/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_player_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:05:54 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/12 13:42:35 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	allocate_mem(t_all_data *all)
{
	if (!(all->sprite_data.sprite = (t_sprite *)
			malloc(all->sprite_data.num_sprites * sizeof(t_sprite))))
		error_handler("Can not allocate memory");
	if (!(all->sprite_data.z_buffer = (double *)
			malloc(all->parse_data.x_res * sizeof(double))))
		error_handler("Can not allocate memory");
	if (!(all->sprite_data.dist = (double *)
			malloc(all->sprite_data.num_sprites * sizeof(double))))
		error_handler("Can not allocate memory");
	if (!(all->sprite_data.order = (int *)
			malloc(all->sprite_data.num_sprites * sizeof(int))))
		error_handler("Can not allocate memory");
}

void	sprite_init(t_all_data *all)
{
	int	x;
	int y;
	int count;

	all->sprite_data.num_sprites = num_sprites(all);
	allocate_mem(all);
	count = 0;
	y = 0;
	while (all->map_data.map[y])
	{
		x = 0;
		while (all->map_data.map[y][x])
		{
			if (all->map_data.map[y][x] == '2')
			{
				all->sprite_data.sprite[count].x = x + 0.5;
				all->sprite_data.sprite[count].y = y + 0.5;
				count++;
			}
			x++;
		}
		y++;
	}
}

void	sprite_player_init(t_all_data *all)
{
	player_init(all);
	sprite_init(all);
	screen_size_init(all);
}
