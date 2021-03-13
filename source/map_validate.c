/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 20:36:48 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/13 20:23:53 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	edge_lines_validate(char *line, int *i)
{
	while (line[*i])
	{
		if (NOT_VALIDATE_EDGE(line[*i]))
			return (-1);
		(*i)++;
	}
	return (0);
}

int	symbol_validate(char ***map, t_map_stuff ***ms)
{
	if ((*map)[(**ms)->j][(**ms)->i - 1] == ' '
		|| (*map)[(**ms)->j][(**ms)->i + 1] == ' '
		|| (*map)[(**ms)->j - 1][(**ms)->i] == ' '
		|| (*map)[(**ms)->j - 1][(**ms)->i - 1] == ' '
		|| (*map)[(**ms)->j - 1][(**ms)->i + 1] == ' '
		|| (*map)[(**ms)->j + 1][(**ms)->i] == ' '
		|| (*map)[(**ms)->j + 1][(**ms)->i - 1] == ' '
		|| (*map)[(**ms)->j + 1][(**ms)->i + 1] == ' '
		|| (**ms)->i + 1 >= (**ms)->nbs)
		return (-1);
	return (0);
}

int	middle_lines_validate(char **map, t_map_stuff **ms)
{
	while (map[(*ms)->j][(*ms)->i])
	{
		if ((*ms)->i > 0 && (*ms)->i < (int)ft_strlen(map[(*ms)->j]) - 1
			&& map[(*ms)->j][(*ms)->i] == '0')
			if (symbol_validate(&map, &ms))
				return (-1);
		if ((*ms)->i > 0 && (*ms)->i < (int)ft_strlen(map[(*ms)->j]) - 1
			&& PL_VALIDATE(map[(*ms)->j][(*ms)->i]))
		{
			if (symbol_validate(&map, &ms) || (*ms)->player)
				return (-1);
			(*ms)->player = 1;
		}
		if ((*ms)->i > 0 && (*ms)->i < (int)ft_strlen(map[(*ms)->j]) - 1
			&& map[(*ms)->j][(*ms)->i] == '2')
			if (symbol_validate(&map, &ms))
				return (-1);
		if (not_validate(map[(*ms)->j][(*ms)->i]))
			return (-1);
		((*ms)->i)++;
	}
	return (0);
}

int	lines_validate(char **map, t_map_stuff *ms)
{
	while (map[ms->j])
	{
		ms->i = 0;
		while (map[ms->j][ms->i] == ' ')
			ms->i++;
		if (NOT_VALIDATE_EDGE(map[ms->j][ms->i]))
			return (-1);
		ms->i++;
		if ((ms->j == 0 || ms->j == ms->map_size)
			&& edge_lines_validate(map[ms->j], &ms->i) == -1)
			return (-1);
		if (ms->j > 0 && ms->j < ms->map_size)
		{
			ms->nbs = ft_strlen(map[ms->j - 1]) < ft_strlen(map[ms->j + 1])
			? ft_strlen(map[ms->j - 1]) : ft_strlen(map[ms->j + 1]);
			if (middle_lines_validate(map, &ms) == -1)
				return (-1);
		}
		if (NOT_VALIDATE_EDGE(map[ms->j][ms->i - 1]))
			return (-1);
		ms->j++;
	}
	if (!ms->player)
		return (-1);
	return (0);
}

int	map_validate(char **map, int map_size)
{
	t_map_stuff ms;

	ms.i = 0;
	ms.j = 0;
	ms.player = 0;
	ms.map_size = --map_size;
	return (lines_validate(map, &ms));
}
