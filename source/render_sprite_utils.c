#include "cub3d.h"

void	sprite_height_calc(t_all_data *all)
{
	all->sprite_data.height = abs((int)(all->parse_data.y_res /
										all->sprite_data.trans_y));
	all->sprite_data.draw_start_y = -all->sprite_data.height / 2 +
									all->parse_data.y_res / 2;
	if (all->sprite_data.draw_start_y < 0)
		all->sprite_data.draw_start_y = 0;
	all->sprite_data.draw_end_y = all->sprite_data.height / 2 +
								  all->parse_data.y_res / 2;
	if (all->sprite_data.draw_end_y >= all->parse_data.y_res)
		all->sprite_data.draw_end_y = all->parse_data.y_res - 1;

}

void	sprite_width_calc(t_all_data *all)
{
	all->sprite_data.width = abs((int)(all->parse_data.y_res /
									   all->sprite_data.trans_y));
	all->sprite_data.draw_start_x = -all->sprite_data.width / 2 +
									all->sprite_data.screen_x;
	if (all->sprite_data.draw_start_x < 0)
		all->sprite_data.draw_start_x = 0;
	all->sprite_data.draw_end_x = all->sprite_data.width / 2 +
								  all->sprite_data.screen_x;
	if (all->sprite_data.draw_end_x >= all->parse_data.x_res)
		all->sprite_data.draw_end_x = all->parse_data.x_res - 1;
}

void 	draw(t_all_data *all)
{
	int	y;
	int	d;

	y = all->sprite_data.draw_start_y;
	while (y < all->sprite_data.draw_end_y)
	{
		d = y * 256 - all->parse_data.y_res * 128 +
			all->sprite_data.height * 128;
		all->sprite_data.tex_y = ((d * all->sprite_texture
				.height) / all->sprite_data.height) / 256;
		all->sprite_data.color = tex_color_spr
				(&all->sprite_texture, all->sprite_texture.width,
				 all->sprite_texture.height);
		if ((all->sprite_data.color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(&all->img_data, all->sprite_data
									 .draw_start_x,
							 all->sprite_data.draw_start_y, all->sprite_data.color);
		y++;
	}
}

void	draw_sprite(t_all_data *all)
{
	int stripe;

	stripe = all->sprite_data.draw_start_x;
	while (stripe < all->sprite_data.draw_end_x)
	{
		all->sprite_data.tex_x = (int)(256 * (stripe - (-all->sprite_data
				.width / 2 + all->sprite_data.screen_x)) *
									   all->sprite_texture.width / all->sprite_data
											   .width) / 256;
		if (all->sprite_data.trans_y > 0 && stripe > 0 && stripe <
														  all->parse_data.x_res && all->sprite_data.trans_y <
																				   all->sprite_data.z_buffer[stripe])
			draw(all);
		stripe++;
	}
}
