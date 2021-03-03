
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
	if (all->rc.side == 0 && all->rc.ray_dir_x > 0)
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
