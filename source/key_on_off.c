/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_on_off.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:39:54 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/03 14:39:57 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_on(int keycode, t_all_data *all)
{
	if (keycode == 13)
		all->keys_data.w = 1;
	if (keycode == 1)
		all->keys_data.s = 1;
	if (keycode == 0)
		all->keys_data.a = 1;
	if (keycode == 2)
		all->keys_data.d = 1;
	if (keycode == 53)
		all->keys_data.esc = 1;
	if (keycode == 123)
		all->keys_data.left = 1;
	if (keycode == 124)
		all->keys_data.right = 1;
	return (0);
}

int	key_off(int keycode, t_all_data *all)
{
	if (keycode == 13)
		all->keys_data.w = 0;
	if (keycode == 1)
		all->keys_data.s = 0;
	if (keycode == 0)
		all->keys_data.a = 0;
	if (keycode == 2)
		all->keys_data.d = 0;
	if (keycode == 53)
		all->keys_data.esc = 0;
	if (keycode == 123)
		all->keys_data.left = 0;
	if (keycode == 124)
		all->keys_data.right = 0;
	return (0);
}
