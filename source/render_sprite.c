
#include "cub3d.h"

void	sprites_dist_calc(t_all_data *all)
{
	int i;

	i = 0;
	while (i < all->sprite_data.num_sprites)
	{
		all->sprite_data.order[i] = i;
		all->sprite_data.dist[i] = ((all->map_data.pl_x - all->sprite_data
				.sprite[i].x) * (all->map_data.pl_x - all->sprite_data.sprite[i]
						.x) + (all->map_data.pl_y - all->sprite_data.sprite
								[i].y) * (all->map_data.pl_y - all->sprite_data
										.sprite[i].y));
		i++;
	}
}

void	sort_sprites(t_all_data *all)
{
	int		i;
	int 	j;
	double	tmp_dist;
	int 	tmp_order;

	i = 0;
	while (i < all->sprite_data.num_sprites)
	{
		j = all->sprite_data.num_sprites;
		while (j > i)
		{
			if (all->sprite_data.dist[j - 1] < all->sprite_data.dist[j])
			{
				tmp_dist = all->sprite_data.dist[j - 1];
				tmp_order = all->sprite_data.order[j - 1];
				all->sprite_data.dist[j - 1] = all->sprite_data.dist[j];
				all->sprite_data.order[j - 1] = all->sprite_data.order[j];
				all->sprite_data.dist[j] = tmp_dist;
				all->sprite_data.order[j] = tmp_order;
			}
			j--;
		}
		i++;
	}
}

void 	trans_screen_calc(t_all_data *all)
{
	all->sprite_data.inv_det = 1.0 / (all->rc.cam_plane_x * all->rc
			.pl_dir_y - all->rc.pl_dir_x * all->rc.cam_plane_y);
	all->sprite_data.trans_x = all->sprite_data.inv_det * (all->rc
			.pl_dir_y * all->sprite_data.x - all->rc.pl_dir_x *
			all->sprite_data.y);
	all->sprite_data.trans_y = all->sprite_data.inv_det * (-all->rc
			.cam_plane_y * all->sprite_data.x + all->rc.cam_plane_x *
												all->sprite_data.y);
	all->sprite_data.screen_x = (int)((all->parse_data.x_res / 2.0) * (1 +
			all->sprite_data.trans_x / all->sprite_data.trans_y));
}

void	render_sprite(t_all_data *all)
{
	int	i;

	i = 0;
	sprites_dist_calc(all);
	sort_sprites(all);
	while (i < all->sprite_data.num_sprites)
	{
		all->sprite_data.x = all->sprite_data.sprite[all->sprite_data
				.order[i]].x - all->map_data.pl_x;
		all->sprite_data.y = all->sprite_data.sprite[all->sprite_data
				.order[i]].y - all->map_data.pl_y;
		trans_screen_calc(all);
		sprite_height_calc(all);
		sprite_width_calc(all);
		draw_sprite(all);
		i++;
	}
}