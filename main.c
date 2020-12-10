/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:11:38 by thjonell          #+#    #+#             */
/*   Updated: 2020/12/07 16:27:13 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int		file_validate(char *file)
{
	int	i;

	i = 0;
	while (*(file + i) != '.')
		i++;
	if (*(file + (i + 1)) != 'c'
	&& *(file + (i + 2)) != 'u'
	&& *(file + (i + 3)) != 'b')
		return (-1);
	return (0);
}

int		main(int argc, char **argv)
{
	if (file_validate(argv[1]) || world_parse(argv[1]) < 0)
	{
		ft_putendl_fd("Error", 1);
		return (-1);
	}
	return (0);
}
