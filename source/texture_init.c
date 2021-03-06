/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:05:11 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/06 16:05:15 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_tex_init(t_all_data *all)
{
	all->n_texture.img = mlx_xpm_file_to_image(all->vars.mlx, all->parse_data
			.no, &all->n_texture.width, &all->n_texture.height);
	all->n_texture.addr = mlx_get_data_addr(all->n_texture.img,
											&all->n_texture.bits_per_pixel,
											&all->n_texture.line_length,
											&all->n_texture.endian);

	all->s_texture.img = mlx_xpm_file_to_image(all->vars.mlx, all->parse_data
			.so, &all->s_texture.width, &all->s_texture.height);
	all->s_texture.addr = mlx_get_data_addr(all->s_texture.img,
											&all->s_texture.bits_per_pixel,
											&all->s_texture.line_length,
											&all->s_texture.endian);

	all->w_texture.img = mlx_xpm_file_to_image(all->vars.mlx, all->parse_data
			.we, &all->w_texture.width, &all->w_texture.height);
	all->w_texture.addr = mlx_get_data_addr(all->w_texture.img,
											&all->w_texture.bits_per_pixel,
											&all->w_texture.line_length,
											&all->w_texture.endian);

	all->e_texture.img = mlx_xpm_file_to_image(all->vars.mlx, all->parse_data
			.ea, &all->e_texture.width, &all->e_texture.height);
	all->e_texture.addr = mlx_get_data_addr(all->e_texture.img,
											&all->e_texture.bits_per_pixel,
											&all->e_texture.line_length,
											&all->e_texture.endian);
}

void 	sprite_tex_init(t_all_data *all)
{

	all->sprite_texture.img = mlx_xpm_file_to_image(all->vars.mlx,
													all->parse_data
															.s,
															&all->sprite_texture.width, &all->sprite_texture.height);
	all->sprite_texture.addr = mlx_get_data_addr(all->sprite_texture.img,
												 &all->sprite_texture.bits_per_pixel,
												 &all->sprite_texture.line_length,
												 &all->sprite_texture.endian);
}

void	texture_init(t_all_data *all)
{
	wall_tex_init(all);
	sprite_tex_init(all);
}
