/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:30:02 by thjonell          #+#    #+#             */
/*   Updated: 2021/02/28 21:20:40 by thjonell         ###   ########.fr       */
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
	int	y;

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
	{
		mlx_destroy_window(all->vars.mlx, all->vars.win);
		exit(0);
	}
	all->img.img = mlx_new_image(all->vars.mlx, all->world.x_res, all->world
			.y_res);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel,
									  &all->img.line_length, &all->img.endian);
	draw_map(all);
	mlx_put_image_to_window(all->vars.mlx, all->vars.win, all->img.img, 0, 0);
	return (0);
}

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
				player_dir_init(&(*all), all->map_data.map[y][x]);
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
	.y_res, "cub3D");
	all->img.img = mlx_new_image(all->vars.mlx, all->world.x_res, all->world
	.y_res);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel,
									 &all->img.line_length, &all->img.endian);
}

void	init_ray_dir(t_all_data *all, int x)
{
	all->ray_cast.camera_y = 2 * x / (double)all->world.x_res - 1;
	all->ray_cast.ray_dir_x = all->ray_cast.pl_dir_x + all->ray_cast.plane_x
			* all->ray_cast.camera_y;
	all->ray_cast.ray_dir_y = all->ray_cast.pl_dir_y + all->ray_cast.plane_y
			* all->ray_cast.camera_y;
	all->ray_cast.delta_x = fabs(1 / all->ray_cast.ray_dir_x);
	all->ray_cast.delta_y = fabs(1 / all->ray_cast.ray_dir_y);

	printf("%f\n", all->ray_cast.camera_y);
	printf("%f\n", all->ray_cast.ray_dir_x);
	printf("%f\n", all->ray_cast.ray_dir_y);
	printf("%f\n", all->ray_cast.delta_x);
	printf("%f\n", all->ray_cast.delta_y);
}

/*void	ray_dir_and_delta(t_head *h, int x)
{
	h->ray.cam_y = 2 * x / (double)h->resol.w - 1;
	h->ray.raydir_x = h->player.dir_x + h->ray.plane_x * h->ray.cam_y;
	h->ray.raydir_y = h->player.dir_y + h->ray.plane_y * h->ray.cam_y;
	h->ray.delta_x = fabs(1 / h->ray.raydir_x);
	h->ray.delta_y = fabs(1 / h->ray.raydir_y);
}*/

void	init_side_dist_step(t_all_data *all)
{
	if (all->ray_cast.ray_dir_x < 0)
	{
		all->ray_cast.step_x = -1;
		all->ray_cast.side_dist_x = (all->map_data.x - all->ray_cast.map_x) * all->ray_cast.delta_x;
	}
	else
	{
		all->ray_cast.step_x = 1;
		all->ray_cast.side_dist_x = (all->ray_cast.map_x + 1.0 - all->map_data
				.x) * all->ray_cast.delta_x;
	}
	if (all->ray_cast.ray_dir_y < 0)
	{
		all->ray_cast.step_y = -1;
		all->ray_cast.side_dist_y = (all->map_data.y - all->ray_cast.map_y) *
				all->ray_cast.delta_y;
	}
	else
	{
		all->ray_cast.step_y = 1;
		all->ray_cast.side_dist_y = (all->ray_cast.map_y + 1.0 - all->map_data.y) * all->ray_cast
				.delta_y;
	}
}

void	check_hit_wall(t_all_data *all)
{
	all->ray_cast.hit = 0;

	while (all->ray_cast.hit == 0)
	{
		if (all->ray_cast.side_dist_x < all->ray_cast.side_dist_y)
		{
			all->ray_cast.side_dist_x += all->ray_cast.delta_x;
			all->ray_cast.map_x += all->ray_cast.step_x;
			all->ray_cast.side = 0;
		}
		else
		{
			all->ray_cast.side_dist_y += all->ray_cast.delta_y;
			all->ray_cast.map_y += all->ray_cast.step_y;
			all->ray_cast.side = 1;
		}
		if (all->map_data.map[all->ray_cast.map_x][all->ray_cast.map_y] == '1')
			all->ray_cast.hit = 1;
	}
}

/*void	ray_hit(t_head *h)
{
	while (h->map[h->ray.map_y][h->ray.map_x] != '1')
	{
		if (h->ray.first_side_x < h->ray.first_side_y)
		{
			h->ray.first_side_x += h->ray.delta_x;
			h->ray.map_x += h->ray.step_x;
			h->ray.side = 0;
		}
		else
		{
			h->ray.first_side_y += h->ray.delta_y;
			h->ray.map_y += h->ray.step_y;
			h->ray.side = 1;
		}
	}
}
*/

void calc_dist(t_all_data *all)
{
	if (all->ray_cast.side == 0)
		all->ray_cast.perp_dist = (all->ray_cast.map_x - all->map_data.x + (1 -
				all->ray_cast.step_x) / 2) / all->ray_cast.ray_dir_x;
	else
		all->ray_cast.perp_dist = (all->ray_cast.map_y - all->map_data.y
				+ (1 - all->ray_cast.step_y) / 2) / all->ray_cast.ray_dir_y;
}

void	wall_cast(t_all_data *all)
{
	all->wall.line_height = (int)(all->world.y_res / all->ray_cast.perp_dist);
	all->wall.draw_start = -all->wall.line_height / 2 + all->world.y_res / 2;
	if (all->wall.draw_start < 0)
		all->wall.draw_start = 0;
	all->wall.draw_end = all->wall.line_height / 2 + all->world.y_res / 2;
	if (all->wall.draw_end >= all->world.y_res)
		all->wall.draw_end = all->world.y_res - 1;
}

/*int move_pl(int keycode, t_all_data *all)
{
	if (keycode == 13)
	{
		if (all->map_data.map[all->map_data.y - all->ray_cast.pl_dir_y * MOVE_SPEED][all->map_data.x] == '0')
			all->map_data.y -= all->ray_cast.pl_dir_y * MOVE_SPEED;
		if (all->map_data.map[all->map_data.y][all->map_data.x - all->ray_cast.pl_dir_x * MOVE_SPEED] == '0')
			all->map_data.x -= all->ray_cast.pl_dir_x * MOVE_SPEED;
	}
	if (keycode == 1)
	{
		if (all->map_data.map[all->map_data.y - all->ray_cast.pl_dir_y * MOVE_SPEED][all->map_data.x] == '0')
			all->map_data.y += all->ray_cast.pl_dir_y * MOVE_SPEED;
		if (all->map_data.map[all->map_data.y][all->map_data.x + all->ray_cast.pl_dir_x * MOVE_SPEED] == '0')
			all->map_data.x += all->ray_cast.pl_dir_x * MOVE_SPEED;
	}
	if (keycode == 2)
	{
		if (all->map_data.map[all->map_data.y + all->ray_cast.pl_dir_x *
												MOVE_SPEED][all->map_data.x] == '0')
			all->map_data.y += all->ray_cast.pl_dir_x * MOVE_SPEED;
		if (all->map_data.map[all->map_data.y][all->map_data.x +
											   all->ray_cast.pl_dir_y * MOVE_SPEED] == '0')
			all->map_data.x += all->ray_cast.pl_dir_y * MOVE_SPEED;
	}
	if (keycode == 0)
	{
		if (all->map_data.map[all->map_data.y - all->ray_cast.pl_dir_x *
		MOVE_SPEED][all->map_data.x] == '0')
			all->map_data.y -= all->ray_cast.pl_dir_x * MOVE_SPEED;
		if (all->map_data.map[all->map_data.y][all->map_data.x -
		all->ray_cast.pl_dir_y * MOVE_SPEED] == '0')
			all->map_data.x -= all->ray_cast.pl_dir_y * MOVE_SPEED;
	}
	if (keycode == 53)
	{
		mlx_destroy_window(all->vars.mlx, all->vars.win);
		exit(0);
	}
	return (0);
}*/

void	wall_line_draw(t_all_data *all, int x)
{
	while (all->wall.roof <= all->wall.draw_start)
	{
		my_mlx_pixel_put(&all->img, x, all->wall.roof, 0xFFFFFFFF);
		all->wall.roof++;
	}
	while (all->wall.draw_start <= all->wall.draw_end)
	{
		my_mlx_pixel_put(&all->img, x, all->wall.draw_start, 0x000000FF);
		all->wall.draw_start++;
	}
	while (all->wall.draw_end < all->world.y_res)
	{
		my_mlx_pixel_put(&all->img, x, all->wall.draw_end, 0xFFFFFFFF);
		all->wall.draw_end++;
	}
}

void	draw_walls(t_all_data *all)
{
	int	x;

	x = 0;
	while (x < /*all->world.x_res*/2)
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
	all.world = world;
	player_init(&all);
	ft_mlx_init(&all);
	draw_walls(&all);
	//draw_map(&all);
	mlx_put_image_to_window(all.vars.mlx, all.vars.win, all.img.img, 0, 0);
	//mlx_hook(all.vars.win, 2, 1L<<0, &move_player, &all.vars);
	//mlx_loop_hook(all.vars.mlx, move_pl, all);
	mlx_loop(all.vars.mlx);
}