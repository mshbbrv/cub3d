/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:48:32 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/16 22:57:34 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "get_next_line.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define NOT_VALIDATE_EDGE(x) ((x) != '1' && (x) != ' ')
# define PL_VALIDATE(x) ((x) == 'N' || (x) == 'S' || (x) == 'E' || (x) == 'W')
# define END_PARSE_ELEM 1
# define PARSE_SUCCESS 0
# define MOVE_SPEED 0.2
# define ROT 0.05

typedef struct		s_map_data
{
	double			pl_x;
	double			pl_y;
	char			**map;
}					t_map_data;

typedef struct		s_vars
{
	void			*mlx;
	void			*win;
}					t_vars;

typedef struct		s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_data;

typedef struct		s_parse_data
{
	int				x_res;
	int				y_res;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	unsigned int	floor_color;
	unsigned int	ceil_color;
	int				res_flag;
	int 			f_color_flag;
	int 			c_color_flag;
	int 			no_flag;
	int 			so_flag;
	int 			we_flag;
	int				ea_flag;
	int 			s_flag;
}					t_parse_data;

typedef struct		s_map_stuff
{
	int				i;
	int				j;
	int				player;
	int				map_size;
	int				nbs;
}					t_map_stuff;

typedef struct		s_ray_cast
{
	double			camera_x;
	double			pl_dir_x;
	double			pl_dir_y;
	double			ray_dir_x;
	double			ray_dir_y;
	double			cam_plane_x;
	double			cam_plane_y;
	double			delta_x;
	double			delta_y;
	int				step_x;
	int				step_y;
	double			side_dist_x;
	double			side_dist_y;
	int				map_x;
	int				map_y;
	int				hit;
	int				side;
	double			perp_dist;
	double			step;
}					t_ray_cast;

typedef struct		s_wall
{
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				ceil;
	double			wall_x;
	double			tex_pos;
	int				tex_x;
	int				tex_y;
	unsigned int	color;
}					t_wall;

typedef struct		s_keys_data
{
	int				w;
	int				s;
	int				a;
	int				d;
	int				esc;
	int				left;
	int				right;
}					t_keys_data;

typedef struct		s_sprite
{
	double			x;
	double			y;

}					t_sprite;

typedef struct		s_sprite_data
{
	double			*z_buffer;
	int				num_sprites;
	t_sprite		*sprite;
	double			*dist;
	int				*order;
	double			x;
	double			y;
	double			inv_det;
	double			trans_x;
	double			trans_y;
	int				screen_x;
	int				height;
	int				width;
	int				draw_start_y;
	int				draw_end_y;
	int				draw_start_x;
	int				draw_end_x;
	int				tex_x;
	int				tex_y;
	unsigned int	color;
}					t_sprite_data;

typedef struct		s_all_data
{
	t_vars			vars;
	t_map_data		map_data;
	t_data			img_data;
	t_parse_data	parse_data;
	t_ray_cast		rc;
	t_wall			wall;
	t_keys_data		keys_data;
	t_sprite_data	sprite_data;
	t_data			n_texture;
	t_data			s_texture;
	t_data			e_texture;
	t_data			w_texture;
	t_data			texture;
	t_data			sprite_texture;
	int				screenshot;
}					t_all_data;

void				data_parsing(char *argv, t_all_data *all);
int					r_parse(char *line, t_all_data *all, int i);
int					texture_parse(char *line, char **str, int i, t_all_data *all);
int					color_parse(char *line, unsigned int *color, int i,
					t_all_data *all);
int					map_validate(char **map, int size);
void				error_handler(char *error_str);
void				start_render(t_all_data *all);
void				render_walls(t_all_data *all);
void				w_move(t_all_data *all);
void				s_move(t_all_data *all);
void				a_move(t_all_data *all);
void				d_move(t_all_data *all);
void				left_rotation(t_all_data *all);
void				right_rotation(t_all_data *all);
void				ray_calc(t_all_data *all, int x);
void				step_calc(t_all_data *all);
void				hit_calc(t_all_data *all);
void				wall_calc(t_all_data *all);
void				draw_walls(t_all_data *all, int x);
int					movement(t_all_data *all);
int					key_off(int keycode, t_all_data *all);
int					key_on(int keycode, t_all_data *all);
void				my_mlx_init(t_all_data *all);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
int					close_window(t_all_data *all);
void				wall_hit_calc(t_all_data *all);
void				current_tex_calc(t_all_data *all);
unsigned int		tex_color(t_data *texture, int x, int y);
void				perp_dis_calc(t_all_data *all);
void				player_dir_init(t_all_data *all, char player);
void				player_init(t_all_data *all);
void				wall_tex_init(t_all_data *all);
void				sprite_tex_init(t_all_data *all);
void				sprite_player_init(t_all_data *all);
void				texture_init(t_all_data *all);
void				sprite_width_calc(t_all_data *all);
void				sprite_height_calc(t_all_data *all);
void				draw_sprite(t_all_data *all);
void				render_sprite(t_all_data *all);
void				screen_size_init(t_all_data *all);
void				free_mem(t_all_data *all);
void				render_minimap(t_all_data *all);
void				file_ext_validate(const char *file);
void				screenshot_validate(char *str, t_all_data *all);
int					not_validate(char s);
void				double_res_check(char *line, t_all_data *all);
void				double_tex_check(char *line, t_all_data *all);
void				double_color_check(char *line, t_all_data *all);
void				empty_line_check(char *line);
void				invalid_color_check(int tmp, char *line, int i, int j);
void				digit_check(char *line, int i);
void				elem_check(t_all_data *all);
#endif
