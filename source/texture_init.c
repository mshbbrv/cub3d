/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:05:11 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/14 13:31:10 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_check(t_all_data *all, void *img)
{
	if (img == NULL)
	{
		free(img);
		free_mem(all);
		error_handler("Empty texture file");
	}
}

void	wall_text_init_util(t_all_data *all)
{
	all->w_texture.img = mlx_xpm_file_to_image(all->vars.mlx,
	all->parse_data.we, &all->w_texture.width, &all->w_texture.height);
	texture_check(all, all->w_texture.img);
	all->w_texture.addr = mlx_get_data_addr(all->w_texture.img,
											&all->w_texture.bits_per_pixel,
											&all->w_texture.line_length,
											&all->w_texture.endian);
	all->e_texture.img = mlx_xpm_file_to_image(all->vars.mlx,
	all->parse_data.ea, &all->e_texture.width, &all->e_texture.height);
	texture_check(all, all->e_texture.img);
	all->e_texture.addr = mlx_get_data_addr(all->e_texture.img,
											&all->e_texture.bits_per_pixel,
											&all->e_texture.line_length,
											&all->e_texture.endian);
}

void	wall_tex_init(t_all_data *all)
{
	all->n_texture.img = mlx_xpm_file_to_image(all->vars.mlx,
	all->parse_data.no, &all->n_texture.width, &all->n_texture.height);
	texture_check(all, all->n_texture.img);
	all->n_texture.addr = mlx_get_data_addr(all->n_texture.img,
											&all->n_texture.bits_per_pixel,
											&all->n_texture.line_length,
											&all->n_texture.endian);
	all->s_texture.img = mlx_xpm_file_to_image(all->vars.mlx,
	all->parse_data.so, &all->s_texture.width, &all->s_texture.height);
	texture_check(all, all->s_texture.img);
	all->s_texture.addr = mlx_get_data_addr(all->s_texture.img,
											&all->s_texture.bits_per_pixel,
											&all->s_texture.line_length,
											&all->s_texture.endian);
	wall_text_init_util(all);
}

void	sprite_tex_init(t_all_data *all)
{
	all->sprite_texture.img = mlx_xpm_file_to_image(all->vars.mlx,
	all->parse_data.s, &all->sprite_texture.width, &all->sprite_texture.height);
	texture_check(all, all->sprite_texture.img);
	all->sprite_texture.addr = mlx_get_data_addr(all->sprite_texture.img,
	&all->sprite_texture.bits_per_pixel, &all->sprite_texture.line_length,
	&all->sprite_texture.endian);
}

void	texture_init(t_all_data *all)
{
	wall_tex_init(all);
	sprite_tex_init(all);
}
