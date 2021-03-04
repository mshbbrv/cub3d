/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:30:27 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/04 19:05:19 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_calc(t_all_data *all, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)all->parse_data.x_res - 1;
	all->rc.ray_dir_y = all->rc.pl_dir_y + all->rc.cam_plane_y * camera_x;
	all->rc.ray_dir_x = all->rc.pl_dir_x + all->rc.cam_plane_x * camera_x;
	all->rc.map_y = (int)all->map_data.pl_y;
	all->rc.map_x = (int)all->map_data.pl_x;
	all->rc.delta_y = fabs(1 / all->rc.ray_dir_y);
	all->rc.delta_x = fabs(1 / all->rc.ray_dir_x);

}

void	step_calc(t_all_data *all)
{
	if (all->rc.ray_dir_x < 0)
	{
		all->rc.step_x = -1;
		all->rc.side_dist_x = (all->map_data.pl_x - all->rc.map_x) *
							  all->rc.delta_x;
	}
	else
	{
		all->rc.step_x = 1;
		all->rc.side_dist_x = (all->rc.map_x + 1.0 - all->map_data.pl_x)
							  * all->rc.delta_x;
	}
	if (all->rc.ray_dir_y < 0)
	{
		all->rc.step_y = -1;
		all->rc.side_dist_y = (all->map_data.pl_y - all->rc.map_y) *
							  all->rc.delta_y;
	}
	else
	{
		all->rc.step_y = 1;
		all->rc.side_dist_y = (all->rc.map_y + 1.0 - all->map_data.pl_y)
							  * all->rc.delta_y;
	}
}

void	hit_calc(t_all_data *all)
{
	all->rc.hit = 0;
	while (all->rc.hit == 0)
	{
		if (all->rc.side_dist_x < all->rc.side_dist_y)
		{
			all->rc.side_dist_x += all->rc.delta_x;
			all->rc.map_x += all->rc.step_x;
			all->rc.side = 0;
		}
		else
		{
			all->rc.side_dist_y += all->rc.delta_y;
			all->rc.map_y += all->rc.step_y;
			all->rc.side = 1;
		}
		if (all->map_data.map[all->rc.map_y][all->rc.map_x] == '1')
			all->rc.hit = 1;
	}
}

void 	perp_dis_calc(t_all_data *all)
{
	if (all->rc.side == 0)
		all->rc.perp_dist = (all->rc.map_x - all->map_data.pl_x + (1.0 -
				all->rc.step_x) / 2) / all->rc.ray_dir_x;
	else
		all->rc.perp_dist = (all->rc.map_y - all->map_data.pl_y + (1.0 -
				all->rc.step_y) / 2) / all->rc.ray_dir_y;
}

void	wall_calc(t_all_data *all)
{
	all->wall.line_height = (int)(all->parse_data.y_res / all->rc
			.perp_dist);
	all->wall.draw_start = -all->wall.line_height / 2 + all->parse_data
																.y_res / 2;
	if (all->wall.draw_start < 0)
		all->wall.draw_start = 0;
	all->wall.draw_end = all->wall.line_height / 2 + all->parse_data.y_res / 2;
	if (all->wall.draw_end >= all->parse_data.y_res)
		all->wall.draw_end = all->parse_data.y_res - 1;
}

