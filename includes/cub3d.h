/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:48:32 by thjonell          #+#    #+#             */
/*   Updated: 2021/02/28 18:37:59 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
//# include "mlx_int.h"
//# include "mlx_new_window.h"
//# include "mlx_opengl.h"
//# include "mlx_png.h"
# define not_validate(x) ((x) != '0' && (x) != '1' && (x) != '2' && (x) != 'N' \
&& (x) != 'S' && (x) != 'E' && (x) != 'W' && (x) != ' ')
# define not_validate_edge(x) ((x) != '1' && (x) != ' ')
# define pl_validate(x) ((x) == 'N' || (x) == 'S' || (x) == 'E' || (x) == 'W')
# define END_PARSE_ELEM 1
# define PARSE_SUCCESS 0
# define MOVE_SPEED 0.5

typedef struct	s_map_data
{
	int		x;
	int 	y;
	char	player;
	char	**map;
}				t_map_data;

typedef struct  s_vars {
	void		*mlx;
	void		*win;
}               t_vars;

typedef struct  s_data {
	void        *img;
	char        *addr;
	int 		bits_per_pixel;
	int			line_length;
	int 		endian;
}               t_data;

typedef struct s_world
{
	int			x_res;
	int			y_res;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	int 		f[3];
	int 		c[3];
}				t_world;

typedef struct	s_map_stuff
{
	int 		i;
	int			j;
	int			player;
	int 		map_size;
	int			nbs;
}				t_map_stuff;

typedef struct	s_ray_cast
{
	double 		camera_y;
	double		pl_dir_x;
	double		pl_dir_y;
	double 		ray_dir_x;
	double		ray_dir_y;
	double		plane_x;
	double		plane_y;
	double 		delta_x;
	double		delta_y;
	int			step_x;
	int 		step_y;
	double		side_dist_x;
	double 		side_dist_y;
	int			map_x;
	int 		map_y;
	int			hit;
	int 		side;
	double		perp_dist;
}				t_ray_cast;


typedef struct	s_wall
{
	double		perp_dist;
	int			line_height;
	int 		draw_start;
	int 		draw_end;
	int			roof;
}				t_wall;

typedef struct	s_all_data
{
	t_vars		vars;
	t_map_data	map_data;
	t_data		img;
	t_world		world;
	t_ray_cast	ray_cast;
	t_wall		wall;
}				t_all_data;

void	world_parse(char *argv);
int		r_parse(char ***line, t_world ***world, int i);
int		texture_parse(char ***line, char **str, int i);
int		color_parse(char ***line, int *color, int i);
int		map_validate(char **map, int size);
void	start_mlx(t_map_data map_data, t_world world);
void	error_handler(char *error_str);
#endif
