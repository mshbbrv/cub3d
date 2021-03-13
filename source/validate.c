/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 19:12:37 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/13 20:23:30 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		not_validate(char s)
{
	if (s != '0' && s != '1' && s != '2' && s != 'N' && s != 'S' && s !=
	'E' && s != 'W' && s != ' ')
		return (1);
	return (0);
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
	if (ft_strncmp("--save", str, ft_strlen("--save")) == 0 && ft_strlen(str)
	== ft_strlen("--save"))
		all->screenshot = 1;
	else
		error_handler("Invalid argument");
}
