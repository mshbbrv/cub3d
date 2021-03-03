/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:24:39 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/03 16:12:46 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	tex_color(t_data *texture, int x, int y)
{
	char			*dst;
	unsigned int	color;

	dst = texture->addr + (y * texture->line_length + (texture->width - x - 1) *
											  (texture->bits_per_pixel / 8));
	color = *(unsigned int*)dst;
	return (color);
}

void	render_walls(t_all_data *all)
{
	int		x;

	x = 0;
	while (x < all->parse_data.x_res)
	{
		ray_calc(all, x);
		step_calc(all);
		hit_calc(all);
		wall_calc(all);
		wall_hit_calc(all);
		current_tex_calc(all);
		draw_walls(all, x);
		x++;
	}
}
