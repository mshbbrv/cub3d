/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 21:35:02 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/03 14:33:45 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int 	movement(t_all_data *all)
{
	mlx_clear_window(all->vars.mlx, all->vars.win);
	//my_clear_window(all);
	if (all->keys_data.w)
		w_move(all);
	if (all->keys_data.s)
		s_move(all);
	if (all->keys_data.a)
		a_move(all);
	if (all->keys_data.d)
		d_move(all);
	if (all->keys_data.left)
		left_rotation(all);
	if (all->keys_data.right)
		right_rotation(all);
	if (all->keys_data.esc)
	{
		mlx_destroy_window(all->vars.mlx, all->vars.win);
		exit (0);
		//free mem
	}
	render_walls(all);
	mlx_put_image_to_window(all->vars.mlx, all->vars.win, all->img_data.img,
							0, 0);
	return (0);
}

void	w_move(t_all_data *all)
{
	if (all->map_data.map[(int)(all->map_data.pl_y + all->rc.ray_dir_y *
	MOVE_SPEED)][(int) all->map_data.pl_x] != '1')
		all->map_data.pl_y += all->rc.ray_dir_y * MOVE_SPEED;
	if (all->map_data.map[(int)all->map_data.pl_y][(int)(all->map_data.pl_x +
	all->rc.ray_dir_x * MOVE_SPEED)] != '1')
		all->map_data.pl_x += all->rc.ray_dir_x * MOVE_SPEED;
}

void	s_move(t_all_data *all)
{
	if (all->map_data.map[(int)(all->map_data.pl_y - all->rc.ray_dir_y *
	MOVE_SPEED)][(int) all->map_data.pl_x] != '1')
		all->map_data.pl_y -= all->rc.ray_dir_y * MOVE_SPEED;
	if (all->map_data.map[(int)all->map_data.pl_y][(int)(all->map_data.pl_x -
	all->rc.ray_dir_x * MOVE_SPEED)] != '1')
		all->map_data.pl_x -= all->rc.ray_dir_x * MOVE_SPEED;
}

void	a_move(t_all_data *all)
{
	if (all->map_data.map[(int)(all->map_data.pl_y - all->rc.ray_dir_x *
	MOVE_SPEED)][(int) all->map_data.pl_x] != '1')
		all->map_data.pl_y -= all->rc.ray_dir_x * MOVE_SPEED;
	if (all->map_data.map[(int)all->map_data.pl_y][(int)(all->map_data.pl_x +
	all->rc.ray_dir_y * MOVE_SPEED)] != '1')
		all->map_data.pl_x += all->rc.ray_dir_y * MOVE_SPEED;
}

void	d_move(t_all_data *all)
{
	if (all->map_data.map[(int)(all->map_data.pl_y + all->rc.ray_dir_x *
	MOVE_SPEED)][(int) all->map_data.pl_x] != '1')
		all->map_data.pl_y += all->rc.ray_dir_x * MOVE_SPEED;
	if (all->map_data.map[(int)all->map_data.pl_y][(int)(all->map_data.pl_x -
	all->rc.ray_dir_y * MOVE_SPEED)] != '1')
		all->map_data.pl_x -= all->rc.ray_dir_y * MOVE_SPEED;
}