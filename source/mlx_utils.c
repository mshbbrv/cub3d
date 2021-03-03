/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:38:51 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/03 14:38:56 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_clear_window(t_all_data *all)
{
	int	x;
	int	y;

	y = 0;
	while (y < all->parse_data.y_res)
	{
		x = 0;
		while (x < all->parse_data.x_res)
		{
			my_mlx_pixel_put(&all->img_data, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

int		close_window(t_all_data *all)
{
	mlx_destroy_window(all->vars.mlx, all->vars.win);
	exit (0);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	my_mlx_init(t_all_data *all)
{
	all->vars.mlx = mlx_init();
	all->vars.win = mlx_new_window(all->vars.mlx, all->parse_data.x_res,
								   all->parse_data.y_res, "cub3d");
	all->img_data.img = mlx_new_image(all->vars.mlx, all->parse_data.x_res,
									  all->parse_data.y_res);
	all->img_data.addr = mlx_get_data_addr(all->img_data.img, &all->img_data
			.bits_per_pixel, &all->img_data.line_length, &all->img_data.endian);
}
