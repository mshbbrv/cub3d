/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:30:02 by thjonell          #+#    #+#             */
/*   Updated: 2021/02/28 21:42:37 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void player_dir_init(t_all_data *all, char pl)
{
	all->ray_cast.pl_dir_x = 0;
	all->ray_cast.pl_dir_y = 0;
	all->ray_cast.plane_x = 0;
	all->ray_cast.plane_y = 0;
	if (pl == 'S')
	{
		all->ray_cast.pl_dir_y = 1;
		all->ray_cast.plane_x = -0.66;
	}
	if (pl == 'N')
	{
		all->ray_cast.pl_dir_y = -1;
		all->ray_cast.plane_x = 0.66;
	}
	if (pl == 'W')
	{
		all->ray_cast.pl_dir_x = -1;
		all->ray_cast.plane_y = -0.66;
	}
	if (pl == 'E')
	{
		all->ray_cast.pl_dir_x = 1;
		all->ray_cast.plane_y = 0.66;
	}
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
				player_dir_init(all, all->map_data.map[y][x]);
				all->map_data.x = x;
				all->map_data.y = y;
			}
			x++;
		}
		y++;
	}
}

void	ft_mlx_init(t_all_data *all)
{
	all->vars.mlx = mlx_init();
	all->vars.win = mlx_new_window(all->vars.mlx, all->world.x_res, all->world
			.y_res, "cub3d");
	all->img.img = mlx_new_image(all->vars.mlx, all->world.x_res, all->world
			.y_res);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel,
									  &all->img.line_length, &all->img.endian);
}

void	draw_walls(t_all_data *all)
{
	int	x;

	x = 0;
	while (x < all->world.x_res)
	{
		all->ray_cast.map_x = all->map_data.x;
		all->ray_cast.map_y = all->map_data.y;
		init_ray_dir(all, x);
		init_side_dist_step(all);
		check_hit_wall(all);
		//calc_dist(all);
		//wall_cast(all);
		//wall_line_draw(all, x);
		x++;
	}
}

void	start_mlx(t_map_data map_data, t_world world)
{
	t_all_data all;

	all.map_data = map_data;
	all.parse = world;
	player_init(&all);
	ft_mlx_init(&all);
	draw_walls(&all);
	//draw_map(&all);
	mlx_put_image_to_window(all.vars.mlx, all.vars.win, all.img.img, 0, 0);
	//mlx_hook(all.vars.win, 2, 1L<<0, &move_player, &all.vars);
	//mlx_loop_hook(all.vars.mlx, move_pl, all);
	mlx_loop(all.vars.mlx);
}