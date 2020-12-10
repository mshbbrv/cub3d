/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:52:31 by thjonell          #+#    #+#             */
/*   Updated: 2020/12/10 20:33:22 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	elem_parse(char **line, t_world **world)
{
	if (*(*line + 0) == 'R')
		return (r_parse(&line, &world));
	else if (*(*line + 0) == 'N' && *(*line + 1) == 'O')
		return (texture_parse(&line, &(*world)->no, 2));
	else if (*(*line + 0) == 'S' && *(*line + 1) == 'O')
		return (texture_parse(&line, &(*world)->so, 2));
	else if (*(*line + 0) == 'W' && *(*line + 1) == 'E')
		return (texture_parse(&line, &(*world)->we, 2));
	else if (*(*line + 0) == 'E' && *(*line + 1) == 'A')
		return (texture_parse(&line, &(*world)->ea, 2));
	else if (*(*line + 0) == 'S')
		return (texture_parse(&line, &(*world)->s, 1));
	else if (*(*line + 0) == 'F')
		return (color_parse(&line, (*world)->f));
	else if (*(*line + 0) == 'C')
		return (color_parse(&line, (*world)->c));
	else if (*(*line + 0) == '\0')
		return (0);
	return (-2);
}

int	file_reader(char *argv, t_world *world, t_list **map_list)
{
	int		fd;
	char	*line;
	int		br;

	if ((fd = open(argv, O_RDONLY)) < 0)
		return (-1);
	while (get_next_line(fd, &line))
	{
		if ((br = elem_parse(&line, &world)) == -2)
			break ;
		//if (br == -1)
		//	return (-1);
	}
	ft_lstadd_back(&*map_list, ft_lstnew(line));
	while (get_next_line(fd, &line))
		ft_lstadd_back(&*map_list, ft_lstnew(line));
	ft_lstadd_back(&*map_list, ft_lstnew(line));
	close(fd);
	return (0);
}

int	map_parse(t_list **map_list, int size)
{
	char	**map;
	int		i;

	if (!(map = (char **)ft_calloc(size + 1, sizeof(char *))))
		return (-1);
	i = 0;
	while (*map_list)
	{
		*(map + i++) = (*map_list)->content;
		*map_list = (*map_list)->next;
	}
	*(map + ++i) = NULL;
	if (map_validate(map, size) == -1)
		return (-1);
	while (*map)
		ft_putendl_fd(*map++, 1);
	return (0);
}

int	world_parse(char *argv)
{
	t_world world;
	t_list	*map_list;
	int 	i;

	map_list = NULL;
	world.x_res = 0;
	world.y_res = 0;
	i = 0;
	if (file_reader(argv, &world, &map_list) == -1)
		return (-1);
	if (map_parse(&map_list, ft_lstsize(map_list)) == -1)
		return (-1);
	ft_putnbr_fd(world.x_res, 1);
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
	ft_putchar_fd('\n', 1);
	return (0);
}
