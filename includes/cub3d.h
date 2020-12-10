/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:48:32 by thjonell          #+#    #+#             */
/*   Updated: 2020/12/10 20:52:32 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include <fcntl.h>
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# define not_validate(x) ((x) != '0' && (x) != '1' && (x) != '2' && (x) != 'N' \
&& (x) != 'S' && (x) != 'E' && (x) != 'W' && (x) != ' ')
# define not_validate_edge(x) ((x) != '1' && (x) != ' ')
# define pl_validate(x) ((x) == 'N' || (x) == 'S' || (x) == 'E' || (x) == 'W')
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

int		world_parse(char *argv);
int		r_parse(char ***line, t_world ***world);
int		texture_parse(char ***line, char **str, int i);
int		color_parse(char ***line, int *color);
int		map_validate(char **map, int size);
#endif
