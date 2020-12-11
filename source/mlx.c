/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:30:02 by thjonell          #+#    #+#             */
/*   Updated: 2020/12/11 14:15:51 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		x;
	int 	y;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 640, 480, "Hello, World!");
	x = 100;
	y = 100;
	while (y++ < 200)
	{
		x = 100;
		while (x++ < 200)
			mlx_pixel_put(mlx, mlx_win, x ,y, 0xFFFFFF);
	}
	mlx_loop(mlx);
}