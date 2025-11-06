/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_events_basic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:00:57 by sravizza          #+#    #+#             */
/*   Updated: 2025/10/30 11:30:58 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		handle_closing(data);
	handle_offset(keysym, data);
	handle_zoom(keysym, data);
	handle_rotation(keysym, data);
	handle_reset(keysym, data);
	return (0);
}

void	update_hooks(t_data *data)
{
	if (data->keys.x_off_p)
		data->img.mod.x_offset -= data->img.mod.movecoef;
	if (data->keys.x_off_m)
		data->img.mod.x_offset += data->img.mod.movecoef;
	if (data->keys.y_off_p)
		data->img.mod.y_offset -= data->img.mod.movecoef;
	if (data->keys.y_off_m)
		data->img.mod.y_offset += data->img.mod.movecoef;
	if (data->keys.zoom_m)
		data->img.mod.zoom--;
	if (data->keys.zoom_p)
		data->img.mod.zoom++;
	if (data->keys.alt_p)
		data->img.mod.altcoef++;
	if (data->keys.alt_m)
		data->img.mod.altcoef--;
	if (data->img.mod.zoom < 1)
		data->img.mod.zoom = 1;
	data->img.mod.movecoef = data->map.height * data->map.width
		/ (data->img.mod.zoom * 1000);
	if (data->img.mod.movecoef < 1)
		data->img.mod.movecoef = 1;
	update_hooks2(data);
	return ;
}

void	update_hooks2(t_data *data)
{
	if (data->keys.x_rot_p)
		data->img.mod.x_rot += 0.01;
	if (data->keys.x_rot_m)
		data->img.mod.x_rot -= 0.01;
	if (data->keys.y_rot_p)
		data->img.mod.y_rot += 0.01;
	if (data->keys.y_rot_m)
		data->img.mod.y_rot -= 0.01;
	if (data->keys.z_rot_p)
		data->img.mod.z_rot += 0.01;
	if (data->keys.z_rot_m)
		data->img.mod.z_rot -= 0.01;
	return ;
}

int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == XK_w)
		data->keys.y_off_m = 0;
	if (keysym == XK_s)
		data->keys.y_off_p = 0;
	if (keysym == XK_a)
		data->keys.x_off_m = 0;
	if (keysym == XK_d)
		data->keys.x_off_p = 0;
	if (keysym == XK_q)
		data->keys.zoom_m = 0;
	if (keysym == XK_e)
		data->keys.zoom_p = 0;
	if (keysym == XK_c)
		data->keys.alt_p = 0;
	if (keysym == XK_v)
		data->keys.alt_m = 0;
	handle_keyrelease2(keysym, data);
	return (0);
}

int	handle_keyrelease2(int keysym, t_data *data)
{
	if (keysym == XK_Left)
		data->keys.z_rot_m = 0;
	if (keysym == XK_Right)
		data->keys.z_rot_p = 0;
	if (keysym == XK_Down)
		data->keys.x_rot_m = 0;
	if (keysym == XK_Up)
		data->keys.x_rot_p = 0;
	if (keysym == XK_f)
		data->keys.y_rot_m = 0;
	if (keysym == XK_g)
		data->keys.y_rot_p = 0;
	return (0);
}
