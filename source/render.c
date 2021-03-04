/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:30:02 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/04 20:38:26 by thjonell         ###   ########.fr       */
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

void	wall_tex_init(t_all_data *all)
{
	all->n_texture.img = mlx_xpm_file_to_image(all->vars.mlx, all->parse_data
	.no, &all->n_texture.width, &all->n_texture.height);
	all->n_texture.addr = mlx_get_data_addr(all->n_texture.img,
										 &all->n_texture.bits_per_pixel,
										 &all->n_texture.line_length,
										 &all->n_texture.endian);

	all->s_texture.img = mlx_xpm_file_to_image(all->vars.mlx, all->parse_data
	.so, &all->s_texture.width, &all->s_texture.height);
	all->s_texture.addr = mlx_get_data_addr(all->s_texture.img,
											&all->s_texture.bits_per_pixel,
											&all->s_texture.line_length,
											&all->s_texture.endian);

	all->w_texture.img = mlx_xpm_file_to_image(all->vars.mlx, all->parse_data
	.we, &all->w_texture.width, &all->w_texture.height);
	all->w_texture.addr = mlx_get_data_addr(all->w_texture.img,
											&all->w_texture.bits_per_pixel,
											&all->w_texture.line_length,
											&all->w_texture.endian);

	all->e_texture.img = mlx_xpm_file_to_image(all->vars.mlx, all->parse_data
	.ea, &all->e_texture.width, &all->e_texture.height);
	all->e_texture.addr = mlx_get_data_addr(all->e_texture.img,
											&all->e_texture.bits_per_pixel,
											&all->e_texture.line_length,
											&all->e_texture.endian);
}

void	start_render(t_map_data map_data, t_world world)
{
	t_all_data all;

	all.keys_data.w = 0;
	all.keys_data.s = 0;
	all.keys_data.a = 0;
	all.keys_data.d = 0;
	all.keys_data.esc = 0;
	all.keys_data.left = 0;
	all.keys_data.right = 0;
	all.map_data = map_data;
	all.parse_data = world;
	player_init(&all);
	my_mlx_init(&all);
	wall_tex_init(&all);
	//render_walls(&all);
	mlx_put_image_to_window(all.vars.mlx, all.vars.win, all.img_data.img,
							0, 0);
	mlx_hook(all.vars.win, 2, 1L<<0, key_on, &all);
	mlx_hook(all.vars.win, 3, 1L<<1, key_off, &all);
	mlx_hook(all.vars.win, 17, 0L, close_window, &all);
	mlx_loop_hook(all.vars.mlx, movement, &all);
	mlx_loop(all.vars.mlx);
}