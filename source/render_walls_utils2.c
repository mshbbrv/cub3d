
#include "cub3d.h"

void	wall_hit_calc(t_all_data *all)
{
	if (all->rc.side == 0)
		all->wall.wall_x = all->map_data.pl_y + all->rc.perp_dist * all->rc
				.ray_dir_y;
	else
		all->wall.wall_x = all->map_data.pl_x + all->rc.perp_dist * all->rc
				.ray_dir_x;
	all->wall.wall_x -= floor(all->wall.wall_x);

	all->wall.tex_x = (int)(all->wall.wall_x * all->texture.width);
	if (all->rc.side == 0 && all->rc.ray_dir_x > 0)
		all->wall.tex_x = all->texture.width - all->wall.tex_x - 1;
	if (all->rc.side == 1 && all->rc.ray_dir_y < 0)
		all->wall.tex_x = all->texture.width - all->wall.tex_x - 1;
	all->rc.step = 1.0 * all->texture.height / all->wall.line_height;
	all->wall.tex_pos = (all->wall.draw_start - all->parse_data.y_res / 2 +
			all->wall.line_height / 2) * all->rc.step;
}

void 	current_tex_calc(t_all_data *all)
{

	if (all->rc.side == 0 && all->map_data.pl_x > all->rc.ray_dir_x +
	all->map_data.pl_x)
		all->texture = all->w_texture;
	if (all->rc.side == 0 && all->map_data.pl_x < all->rc.ray_dir_x +
												  all->map_data.pl_x)
		all->texture = all->e_texture;
	if (all->rc.side == 1 && all->map_data.pl_y > all->rc.ray_dir_y +
												  all->map_data.pl_y)
		all->texture = all->n_texture;
	if (all->rc.side == 1 && all->map_data.pl_y < all->rc.ray_dir_y +
												  all->map_data.pl_y)
		all->texture = all->s_texture;
}

void	draw_walls(t_all_data *all, int x)
{
	all->wall.ceil = 0;
	while (all->wall.ceil <= all->wall.draw_start)
	{
		my_mlx_pixel_put(&all->img_data, x, all->wall.ceil,
						 all->parse_data.ceil_color);
		all->wall.ceil++;
	}
	while (all->wall.draw_start < all->wall.draw_end)
	{
		all->wall.tex_y = (int)all->wall.tex_pos % (all->texture.width - 1);
		all->wall.tex_pos += all->rc.step;
		all->wall.color = tex_color(&all->texture, all->wall.tex_x, all->wall
				.tex_y);
		my_mlx_pixel_put(&all->img_data, x, all->wall.draw_start,
						 all->wall.color);
		all->wall.draw_start++;
	}
	while (all->wall.draw_end < all->parse_data.y_res)
	{
		my_mlx_pixel_put(&all->img_data, x, all->wall.draw_end,
						 all->parse_data.floor_color);
		all->wall.draw_end++;
	}
}