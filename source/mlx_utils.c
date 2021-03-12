/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:38:51 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/12 13:51:51 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				close_window(t_all_data *all)
{
	mlx_destroy_window(all->vars.mlx, all->vars.win);
	exit(0);
}

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void			my_mlx_init(t_all_data *all)
{
	all->vars.mlx = mlx_init();
	all->vars.win = mlx_new_window(all->vars.mlx, all->parse_data.x_res,
	all->parse_data.y_res, "cub3d");
	all->img_data.img = mlx_new_image(all->vars.mlx, all->parse_data.x_res,
	all->parse_data.y_res);
	all->img_data.addr = mlx_get_data_addr(all->img_data.img,
	&all->img_data.bits_per_pixel, &all->img_data.line_length,
	&all->img_data.endian);
}

unsigned int	tex_color(t_data *texture, int x, int y)
{
	char			*dst;
	unsigned int	color;

	dst = texture->addr + (y * texture->line_length + (texture->width - x - 1) *
	(texture->bits_per_pixel / 8));
	color = *(unsigned int*)dst;
	return (color);
}
