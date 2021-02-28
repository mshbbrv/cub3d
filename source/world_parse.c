/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:52:31 by thjonell          #+#    #+#             */
/*   Updated: 2021/02/27 15:47:35 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	elem_parse(char **line, t_world **world)
{
	if (*(*line) == 'R')
		return (r_parse(&line, &world, 1));
	else if (*(*line) == 'N' && *(*line + 1) == 'O')
		return (texture_parse(&line, &(*world)->no, 2));
	else if (*(*line) == 'S' && *(*line + 1) == 'O')
		return (texture_parse(&line, &(*world)->so, 2));
	else if (*(*line) == 'W' && *(*line + 1) == 'E')
		return (texture_parse(&line, &(*world)->we, 2));
	else if (*(*line) == 'E' && *(*line + 1) == 'A')
		return (texture_parse(&line, &(*world)->ea, 2));
	else if (*(*line) == 'S')
		return (texture_parse(&line, &(*world)->s, 1));
	else if (*(*line) == 'F')
		return (color_parse(&line, (*world)->f, 1));
	else if (*(*line) == 'C')
		return (color_parse(&line, (*world)->c, 1));
	else if (*(*line) == '\0')
		return (PARSE_SUCCESS);
	return (END_PARSE_ELEM);
}

void	file_reader(char *argv, t_world *world, t_list **map_list)
{
	int		fd;
	char	*line;

	if ((fd = open(argv, O_RDONLY)) < 0)
		error_handler("Сan not open .cub file");
	while (get_next_line(fd, &line))
	{
		if (elem_parse(&line, &world) == END_PARSE_ELEM)
			break ;
	}
	ft_lstadd_back(&*map_list, ft_lstnew(line));
	while (get_next_line(fd, &line))
		ft_lstadd_back(&*map_list, ft_lstnew(line));
	ft_lstadd_back(&*map_list, ft_lstnew(line));
	close(fd);
}

void	map_parse(t_list **map_list, int size, t_map_data *map_data)
{
	//char		**map;
	int			i;

	if (!(map_data->map = (char **)ft_calloc(size + 1, sizeof(char *))))
		error_handler("Can not allocate memory");
	i = 0;
	while (*map_list)
	{
		*(map_data->map + i++) = (*map_list)->content;
		*map_list = (*map_list)->next;
	}
	*(map_data->map + ++i) = NULL;
	if (map_validate(map_data->map, size) == -1)
		error_handler("Invalid map");
	//start_mlx(map_data);
}

void	world_parse(char *argv)
{
	t_world		world;
	t_list		*map_list;
	t_map_data	map_data;

	map_list = NULL;
	world.x_res = 0;
	world.y_res = 0;
	file_reader(argv, &world, &map_list);
	/*ft_putnbr_fd(world.x_res, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(world.y_res, 1);
	ft_putchar_fd('\n', 1);
	ft_putendl_fd(world.no, 1);
	ft_putendl_fd(world.so, 1);
	ft_putendl_fd(world.we, 1);
	ft_putendl_fd(world.ea, 1);
	ft_putendl_fd(world.s, 1);
	ft_putnbr_fd(world.f[0], 1);
	ft_putchar_fd(',', 1);
	ft_putnbr_fd(world.f[1], 1);
	ft_putchar_fd(',', 1);
	ft_putnbr_fd(world.f[2], 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(world.c[0], 1);
	ft_putchar_fd(',', 1);
	ft_putnbr_fd(world.c[1], 1);
	ft_putchar_fd(',', 1);
	ft_putnbr_fd(world.c[2], 1);
	ft_putchar_fd('\n', 1);*/
	map_parse(&map_list, ft_lstsize(map_list), &map_data);
	start_mlx(map_data, world);
}