/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 21:47:36 by thjonell          #+#    #+#             */
/*   Updated: 2021/03/02 22:11:35 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	left_rotation(t_all_data *all)
{
	double	last_dir_x;
	double	last_cam_plane_x;

	last_dir_x = all->rc.pl_dir_x;
	all->rc.pl_dir_x = all->rc.pl_dir_x * cos(-ROT) - all->rc.pl_dir_y * sin
			(-ROT);
	all->rc.pl_dir_y = last_dir_x * sin(-ROT) + all->rc.pl_dir_y *
			cos(-ROT);
	last_cam_plane_x = all->rc.cam_plane_x;
	all->rc.cam_plane_x = all->rc.cam_plane_x * cos(-ROT) - all->rc
			.cam_plane_y * sin(-ROT);
	all->rc.cam_plane_y = last_cam_plane_x * sin(-ROT) + all->rc.cam_plane_y
			* cos(-ROT);
}

void	right_rotation(t_all_data *all)
{
	double	last_dir_x;
	double	last_cam_plane_x;

	last_dir_x = all->rc.pl_dir_x;
	all->rc.pl_dir_x = all->rc.pl_dir_x * cos(ROT) - all->rc.pl_dir_y * sin
			(ROT);
	all->rc.pl_dir_y = last_dir_x * sin(ROT) + all->rc.pl_dir_y * cos(ROT);
	last_cam_plane_x = all->rc.cam_plane_x;
	all->rc.cam_plane_x = all->rc.cam_plane_x * cos(ROT) - all->rc
			.cam_plane_y * sin(ROT);
	all->rc.cam_plane_y = last_cam_plane_x * sin(ROT) + all->rc.cam_plane_y *
			cos(ROT);
}