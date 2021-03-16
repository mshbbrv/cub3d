/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:11:38 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/13 19:13:42 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_handler(char *error_str)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(error_str, 1);
	exit(EXIT_FAILURE);
}

void	free_map(t_all_data *all)
{
	int	i;

	i = 0;
	while (all->map_data.map[i])
		free(all->map_data.map[i++]);
	free(all->map_data.map);
}

void	free_mem(t_all_data *all)
{
	system("killall afplay");
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
		free_map(all);
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
