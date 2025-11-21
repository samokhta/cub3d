/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <samokhta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-20 14:19:08 by samokhta          #+#    #+#             */
/*   Updated: 2025-11-20 14:19:08 by samokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_collsion(t_data *data, double new_x, double new_y)
{
	int	map_x;
	int	map_y;

	map_x = (int)(new_x);
	map_y = (int)(new_y);
	if (data->map.coor[map_y][map_x] == '1')
		return (false);
	return (true);
}

void	movement(t_data *data, t_player *p, double move_speed)
{
	if (data->key.w && check_collsion(data,
			p->x + p->dir_x * move_speed, p->y + p->dir_y * move_speed))
	{
		p->x += p->dir_x * move_speed;
		p->y += p->dir_y * move_speed;
	}
	if (data->key.s && check_collsion(data,
			p->x - p->dir_x * move_speed, p->y - p->dir_y * move_speed))
	{
		p->x -= p->dir_x * move_speed;
		p->y -= p->dir_y * move_speed;
	}
	if (data->key.a && check_collsion(data,
			p->x - p->plane_x * move_speed, p->y - p->plane_y * move_speed))
	{
		p->x -= p->plane_x * move_speed;
		p->y -= p->plane_y * move_speed;
	}
	if (data->key.d && check_collsion(data,
			p->x + p->plane_x * move_speed, p->y + p->plane_y * move_speed))
	{
		p->x += p->plane_x * move_speed;
		p->y += p->plane_y * move_speed;
	}
}

void	rotate_player(t_player *p, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir_x;
	old_plane_x = p->plane_x;
	p->dir_x = p->dir_x * cos(rot_speed) - p->dir_y * sin(rot_speed);
	p->dir_y = old_dir_x * sin(rot_speed) + p->dir_y * cos(rot_speed);
	p->plane_x = p->plane_x * cos(rot_speed) - p->plane_y * sin(rot_speed);
	p->plane_y = old_plane_x * sin(rot_speed) + p->plane_y * cos(rot_speed);
}

void	input_check(t_data *data)
{
	movement(data, &data->player, MOVEMENT_SPEED);
	if (data->key.left_arr)
		rotate_player(&data->player, -ROTATION_SPEED);
	if (data->key.right_arr)
		rotate_player(&data->player, ROTATION_SPEED);
	if (data->key.esc == true)
		close_window(data);
}

//TODO: update la position wasd de sorte a ce que ca depende de la camera
//TODO: fix leaks/invalid reads
//TODO: norminette