/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:56:55 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/13 19:15:01 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_big_pixel(t_all_data *all, double i, double j, unsigned int color)
{
	double	x;
	double	y;
	double	size;

	size = 10;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			my_mlx_pixel_put(&all->img_data, x + i * size,
					y + j * size, color);
			x++;
		}
		y++;
	}
}

void	render_minimap(t_all_data *all)
{
	double	x;
	double	y;

	y = 0;
	while (all->map_data.map[(int)y])
	{
		x = 0;
		while (all->map_data.map[(int)y][(int)x])
		{
			if (all->map_data.map[(int)y][(int)x] == '0')
				put_big_pixel(all, x, y, 0x809933);
			if (all->map_data.map[(int)y][(int)x] == '1')
				put_big_pixel(all, x, y, 0xFFFFFF);
			if (all->map_data.map[(int)y][(int)x] == '2')
				put_big_pixel(all, x, y, 0x0000FF);
			put_big_pixel(all, all->map_data.pl_x - 0.5,
			all->map_data.pl_y - 0.5, 0xFF0000);
			x++;
		}
		y++;
	}
}
