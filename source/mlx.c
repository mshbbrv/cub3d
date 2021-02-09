/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:30:02 by thjonell          #+#    #+#             */
/*   Updated: 2021/02/09 19:14:19 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x *
			(data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_big_pixel(int i, int j, t_data img, int color)
{
	int y;
	int x;
	int size;

	size = 10;
	y = 0;
	while (y++ < size)
	{
		x = 0;
		while (x++ < size)
			my_mlx_pixel_put(&img, i * size + y, j * size + x, color);
	}
}

void	draw_map(t_all_data *all)
{
	int	x;
	int y;

	x = all->map_data.x;
	y = all->map_data.y;
	//all->map_data.map[player_y][player_x] = all->map_data.player;
	draw_big_pixel(x, y, all->img, 0x00FF0000);
	y = 0;
	while (all->map_data.map[y])
	{
		x = 0;
		while (all->map_data.map[y][x])
		{
			if (all->map_data.map[y][x] == '1')
				draw_big_pixel(x, y, all->img, 0x00FFFFFF);
			//if (pl_validate(all->map_data.map[y][x]))
			//	draw_big_pixel(x, y, all->img, 0x00FF0000);
			if (all->map_data.map[y][x] == '2')
				draw_big_pixel(x, y, all->img, 0x000000FF);
			x++;
		}
		y++;
	}
}

int move_player(int keycode, t_all_data *all)
{
	mlx_clear_window(all->vars.mlx, all->vars.win);
	if (keycode == 13)
	{
		if (all->map_data.map[all->map_data.y - 1][all->map_data.x] == '0')
			all->map_data.y -= 1;
	}
	if (keycode == 1)
	{
		if (all->map_data.map[all->map_data.y + 1][all->map_data.x] == '0')
			all->map_data.y += 1;
	}
	if (keycode == 2)
	{
		if (all->map_data.map[all->map_data.y][all->map_data.x + 1] == '0')
			all->map_data.x += 1;
	}
	if (keycode == 0)
	{
		if (all->map_data.map[all->map_data.y][all->map_data.x - 1] == '0')
			all->map_data.x -= 1;
	}
	if (keycode == 53)
		exit(0);
	all->img.img = mlx_new_image(all->vars.mlx, 640, 480);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel,
									 &all->img.line_length, &all->img.endian);
	draw_map(all);
	mlx_put_image_to_window(all->vars.mlx, all->vars.win, all->img.img, 0, 0);
	return (0);
}

void	player_init(t_all_data *all)
{
	int x;
	int y;

	y = 0;
	while (all->map_data.map[y])
	{
		x = 0;
		while (all->map_data.map[y][x])
		{
			if (pl_validate(all->map_data.map[y][x]))
			{
				//all->map_data.player = all->map_data.map[y][x];
				all->map_data.x = x;
				all->map_data.y = y;
			}
			x++;
		}
		y++;
	}
}

void	put_map(t_map_data map_data)
{
	t_all_data all;

	all.map_data = map_data;
	player_init(&all);
	all.vars.mlx = mlx_init();
	all.vars.win = mlx_new_window(all.vars.mlx, 640, 480, "cub3d");
	all.img.img = mlx_new_image(all.vars.mlx, 640, 480);
	all.img.addr = mlx_get_data_addr(all.img.img, &all.img.bits_per_pixel,
							  &all.img.line_length, &all.img.endian);
	draw_map(&all);
	mlx_put_image_to_window(all.vars.mlx, all.vars.win, all.img.img, 0, 0);
	mlx_hook(all.vars. win, 2, 1L<<0, &move_player, &all);
	mlx_loop(all.vars.mlx);
}