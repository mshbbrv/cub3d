/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 19:13:39 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/12 18:12:30 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_walls(t_all_data *all)
{
	int		x;

	x = 0;
	while (x < all->parse_data.x_res)
	{
		ray_calc(all, x);
		step_calc(all);
		hit_calc(all);
		perp_dis_calc(all);
		wall_calc(all);
		current_tex_calc(all);
		wall_hit_calc(all);
		draw_walls(all, x);
		all->sprite_data.z_buffer[x] = all->rc.perp_dist;
		x++;
	}
}
