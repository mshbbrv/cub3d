/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:30:02 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/12 13:40:18 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	file_header(t_all_data *all, int fd)
{
	unsigned int	size;
	unsigned char	file_header[14];

	ft_bzero(file_header, 14);
	size = 54 + (8 * all->parse_data.y_res * all->parse_data.x_res);
	file_header[0] = 'B';
	file_header[1] = 'M';
	file_header[2] = size;
	file_header[3] = size >> 8;
	file_header[4] = size >> 16;
	file_header[5] = size >> 24;
	file_header[10] = 54;
	write(fd, file_header, 14);
}

void	info_header(t_all_data *all, int fd)
{
	unsigned char	info_header[40];

	ft_bzero(info_header, 40);
	info_header[0] = 40;
	info_header[4] = (unsigned int)(all->parse_data.x_res);
	info_header[5] = (unsigned int)(all->parse_data.x_res >> 8);
	info_header[6] = (unsigned int)(all->parse_data.x_res >> 16);
	info_header[7] = (unsigned int)(all->parse_data.x_res >> 24);
	info_header[8] = (unsigned int)(all->parse_data.y_res);
	info_header[9] = (unsigned int)(all->parse_data.y_res >> 8);
	info_header[10] = (unsigned int)(all->parse_data.y_res >> 16);
	info_header[11] = (unsigned int)(all->parse_data.y_res >> 24);
	info_header[12] = 1;
	info_header[14] = 32;
	write(fd, info_header, 40);
}

void	screenshot(t_all_data *all)
{
	int	fd;
	int	height;
	int length;

	if ((fd = open("screenshot.bmp", O_CREAT | O_WRONLY |
	O_TRUNC, S_IRWXU)) == -1)
		error_handler("Screenshot error");
	file_header(all, fd);
	info_header(all, fd);
	height = all->parse_data.y_res;
	length = all->parse_data.x_res * all->img_data.bits_per_pixel / 8;
	while (height >= 0)
	{
		write(fd, (unsigned char *)(all->img_data.addr + height *
		all->img_data.line_length), length);
		height--;
	}
	close(fd);
	free_mem(all);
	exit(0);
}

void	start_render(t_all_data *all)
{
	all->keys_data.w = 0;
	all->keys_data.s = 0;
	all->keys_data.a = 0;
	all->keys_data.d = 0;
	all->keys_data.esc = 0;
	all->keys_data.left = 0;
	all->keys_data.right = 0;
	sprite_player_init(all);
	my_mlx_init(all);
	texture_init(all);
	render_walls(all);
	render_sprite(all);
	mlx_put_image_to_window(all->vars.mlx, all->vars.win, all->img_data.img,
							0, 0);
	if (all->screenshot == 1)
		screenshot(all);
	mlx_hook(all->vars.win, 2, 1L << 0, key_on, all);
	mlx_hook(all->vars.win, 3, 1L << 1, key_off, all);
	mlx_hook(all->vars.win, 17, 0L, close_window, all);
	mlx_loop_hook(all->vars.mlx, movement, all);
	mlx_loop(all->vars.mlx);
}
