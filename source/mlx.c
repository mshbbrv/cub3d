/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:30:02 by thjonell          #+#    #+#             */
/*   Updated: 2020/12/21 21:21:34 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct  s_data {
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
}               t_data;

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
			my_mlx_pixel_put(&img, i * size + y, j * size + x,
							 color);
	}
}

void	draw_map(t_data img, char **map)
{
	int	i;
	int j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == '1')
				draw_big_pixel(i, j, img, 0x00FFFFFF);
			if (pl_validate(map[j][i]))
				draw_big_pixel(i, j, img, 0x00FF0000);
			if (map[j][i] == '2')
				draw_big_pixel(i, j, img, 0x000000FF);
			i++;
		}
		j++;
	}
}

void	put_map(char **map)
{
	void	*mlx;
	void	*mlx_win;
	t_data  img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 640, 480, "Hello, World!");
	img.img = mlx_new_image(mlx, 1920, 1080);

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	draw_map(img, map);
	my_mlx_pixel_put(&img, 0, 0, 0xFFFFFFF);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}