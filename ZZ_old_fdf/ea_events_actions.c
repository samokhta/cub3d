/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ea_events_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:11:14 by sravizza          #+#    #+#             */
/*   Updated: 2025/10/30 11:31:04 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_closing(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	return (0);
}

int	handle_reset(int keysym, t_data *data)
{
	if (keysym == XK_r)
	{
		data->img.mod.zoom = min(WINDOW_WIDTH / data->map.width,
				WINDOW_HEIGHT / data->map.height) * 0.5;
		data->img.mod.x_offset = (WINDOW_WIDTH
				- (data->map.width * data->img.mod.zoom));
		data->img.mod.y_offset = (WINDOW_HEIGHT
				- (data->map.height * data->img.mod.zoom));
		data->img.mod.altcoef = 5;
		data->img.mod.x_rot = 0;
		data->img.mod.y_rot = 0;
		data->img.mod.z_rot = 0;
		data->keys.cav_view = 0;
		data->keys.neg_view = 0;
	}
	if (keysym == XK_l)
		data->keys.cav_view = 1;
	if (keysym == XK_n && data->keys.neg_view == 0)
		data->keys.neg_view = 1;
	else if (keysym == XK_n && data->keys.neg_view == 1)
		data->keys.neg_view = 0;
	return (0);
}

int	handle_offset(int keysym, t_data *data)
{
	if (keysym == XK_w)
		data->keys.y_off_m = 1;
	if (keysym == XK_s)
		data->keys.y_off_p = 1;
	if (keysym == XK_a)
		data->keys.x_off_m = 1;
	if (keysym == XK_d)
		data->keys.x_off_p = 1;
	return (0);
}

int	handle_zoom(int keysym, t_data *data)
{
	if (keysym == XK_q && data->img.mod.zoom > 2)
		data->keys.zoom_m = 1;
	if (keysym == XK_e)
		data->keys.zoom_p = 1;
	if (keysym == XK_c)
		data->img.mod.altcoef++;
	if (keysym == XK_v && data->img.mod.altcoef > 2)
		data->img.mod.altcoef--;
	return (0);
}

int	handle_rotation(int keysym, t_data *data)
{
	if (keysym == XK_Left)
		data->keys.z_rot_m = 1;
	if (keysym == XK_Right)
		data->keys.z_rot_p = 1;
	if (keysym == XK_Down)
		data->keys.x_rot_m = 1;
	if (keysym == XK_Up)
		data->keys.x_rot_p = 1;
	if (keysym == XK_f)
		data->keys.y_rot_m = 1;
	if (keysym == XK_g)
		data->keys.y_rot_p = 1;
	return (0);
}
