/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:11:38 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/12 13:02:05 by thjonell         ###   ########.fr       */
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
	return (0);
}
