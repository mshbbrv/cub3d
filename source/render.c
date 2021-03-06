/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:30:02 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/06 20:05:19 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

	sprite_player_init(&all);
	my_mlx_init(&all);
	texture_init(&all);
	render_walls(&all);
	render_sprite(&all);
	mlx_put_image_to_window(all.vars.mlx, all.vars.win, all.img_data.img,
							0, 0);
	mlx_hook(all.vars.win, 2, 1L<<0, key_on, &all);
	mlx_hook(all.vars.win, 3, 1L<<1, key_off, &all);
	mlx_hook(all.vars.win, 17, 0L, close_window, &all);
	mlx_loop_hook(all.vars.mlx, movement, &all);
	mlx_loop(all.vars.mlx);
}