/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:11:38 by thjonell          #+#    #+#             */
/*   Updated: 2020/12/21 17:44:40 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_handler(char *error_str)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(error_str, 1);
	exit(EXIT_FAILURE);
}

void	file_validate(char *file)
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

int		main(int argc, char **argv)
{
	if (argc != 2)
		error_handler("Invalid number of arguments");
	file_validate(argv[1]);
	world_parse(argv[1]);
	return (0);
}
