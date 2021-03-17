/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:45:13 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/17 21:45:14 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_middle_lines(char **map, t_map_stuff *ms)
{
	if (ms->j > 0 && ms->j < ms->map_size && map[ms->j][ms->i] != '\0')
	{
		ms->nbs = ft_strlen(map[ms->j - 1]) < ft_strlen(map[ms->j + 1])
		? ft_strlen(map[ms->j - 1]) : ft_strlen(map[ms->j + 1]);
		if (middle_lines_validate(map, &ms) == -1)
			return (-1);
	}
	return (0);
}
