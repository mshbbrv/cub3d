/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:52:31 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/13 20:01:45 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		elem_parse(char *line, t_all_data *all)
{
	while (*line == ' ')
		line++;
	if (*line == 'R')
		return (r_parse(line, all, 1));
	else if (*line == 'N' && *(line + 1) == 'O')
		return (texture_parse(line, &all->parse_data.no, 2));
	else if (*line == 'S' && *(line + 1) == 'O')
		return (texture_parse(line, &all->parse_data.so, 2));
	else if (*line == 'W' && *(line + 1) == 'E')
		return (texture_parse(line, &all->parse_data.we, 2));
	else if (*line == 'E' && *(line + 1) == 'A')
		return (texture_parse(line, &all->parse_data.ea, 2));
	else if (*line == 'S')
		return (texture_parse(line, &all->parse_data.s, 1));
	else if (*line == 'F')
		return (color_parse(line, &all->parse_data.floor_color, 1));
	else if (*line == 'C')
		return (color_parse(line, &all->parse_data.ceil_color, 1));
	else if (*line == '\0')
		return (PARSE_SUCCESS);
	return (END_PARSE_ELEM);
}

void	file_reader(char *argv, t_all_data *all, t_list **map_list)
{
	int		fd;
	char	*line;

	if ((fd = open(argv, O_RDONLY)) < 0)
		error_handler("Сan not open .cub file");
	while (get_next_line(fd, &line))
	{
		if (elem_parse(line, all) == END_PARSE_ELEM)
			break ;
		free(line);
	}
	ft_lstadd_back(&*map_list, ft_lstnew(line));
	while (get_next_line(fd, &line))
		ft_lstadd_back(&*map_list, ft_lstnew(line));
	ft_lstadd_back(&*map_list, ft_lstnew(line));
	close(fd);
}

void	map_parse(t_list **map_list, int size, t_all_data *all)
{
	int			i;
	t_list		*tmp;

	if (!(all->map_data.map = (char **)ft_calloc(size + 1, sizeof(char *))))
		error_handler("Can not allocate memory");
	i = 0;
	while (*map_list)
	{
		*(all->map_data.map + i++) = ft_strdup((*map_list)->content);
		tmp = (*map_list)->next;
		free((*map_list)->content);
		free(*map_list);
		*map_list = tmp;
	}
	*(all->map_data.map + i) = NULL;
	if (map_validate(all->map_data.map, size) == -1)
		error_handler("Invalid map");
}

void	data_parsing(char *argv, t_all_data *all)
{
	t_list		*map_list;

	map_list = NULL;
	all->parse_data.x_res = 0;
	all->parse_data.y_res = 0;
	file_reader(argv, all, &map_list);
	map_parse(&map_list, ft_lstsize(map_list), all);
}
