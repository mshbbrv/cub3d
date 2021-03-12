/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:11:38 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/12 17:47:18 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_handler(char *error_str)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(error_str, 1);
	exit(EXIT_FAILURE);
}

void	file_ext_validate(const char *file)
{
	int	i;

	i = 0;
	while (*(file + i) != '.')
		i++;
	if (*(file + (i + 1)) != 'c'
		&& *(file + (i + 2)) != 'u'
		&& *(file + (i + 3)) != 'b')
		error_handler("Invalid file extension");
}

void	screenshot_validate(char *str, t_all_data *all)
{
	if (ft_strncmp("--save", str, ft_strlen("--save")) == 0)
		all->screenshot = 1;
	else
		error_handler("Invalid argument");
}

void	free_mem(t_all_data *all)
{
	int	i;

	if (all->sprite_data.sprite)
		free(all->sprite_data.sprite);
	if (all->sprite_data.z_buffer)
		free(all->sprite_data.z_buffer);
	if (all->sprite_data.dist)
		free(all->sprite_data.dist);
	if (all->sprite_data.order)
		free(all->sprite_data.order);
	if (all->parse_data.ea)
		free(all->parse_data.ea);
	if (all->parse_data.no)
		free(all->parse_data.no);
	if (all->parse_data.so)
		free(all->parse_data.so);
	if (all->parse_data.we)
		free(all->parse_data.we);
	if (all->parse_data.s)
		free(all->parse_data.s);
	if (all->map_data.map)
	{
		i = 0;
		while (all->map_data.map[i])
			free(all->map_data.map[i++]);
		free(all->map_data.map);
	}
}

int		main(int argc, char **argv)
{
	t_all_data all;

	all.screenshot = 0;
	if (argc < 2 || argc > 3)
		error_handler("Invalid number of arguments");
	file_ext_validate(argv[1]);
	if (argc == 3)
		screenshot_validate(argv[2], &all);
	data_parsing(argv[1], &all);
	start_render(&all);
	free_mem(&all);
	return (0);
}
