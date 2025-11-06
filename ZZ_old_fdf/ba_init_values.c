/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ba_init_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:45:47 by sravizza          #+#    #+#             */
/*   Updated: 2025/10/30 11:30:41 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_initial_values(t_data *data)
{
	data->img.mod.zoom = min(WINDOW_WIDTH / data->map.width,
			WINDOW_HEIGHT / data->map.height) * 0.5;
	if (data->img.mod.zoom < 1)
		data->img.mod.zoom = 1;
	data->img.mod.x_offset = (WINDOW_WIDTH
			- (data->map.width * data->img.mod.zoom));
	data->img.mod.y_offset = (WINDOW_HEIGHT
			- (data->map.height * data->img.mod.zoom));
	data->img.mod.altcoef = 5;
	data->img.mod.movecoef = data->map.height
		* data->map.width / (data->img.mod.zoom * 1000);
	if (data->img.mod.movecoef < 1)
		data->img.mod.movecoef = 1;
	data->img.mod.x_rot = 0;
	data->img.mod.y_rot = 0;
	data->img.mod.z_rot = 0;
	ft_initial_keys(data);
	return ;
}

void	ft_initial_keys(t_data *data)
{
	data->keys.x_off_p = 0;
	data->keys.x_off_m = 0;
	data->keys.y_off_p = 0;
	data->keys.y_off_m = 0;
	data->keys.zoom_p = 0;
	data->keys.zoom_m = 0;
	data->keys.alt_p = 0;
	data->keys.alt_m = 0;
	data->keys.reset = 0;
	data->keys.x_rot_p = 0;
	data->keys.x_rot_m = 0;
	data->keys.y_rot_p = 0;
	data->keys.y_rot_m = 0;
	data->keys.z_rot_p = 0;
	data->keys.z_rot_m = 0;
	data->keys.cav_view = 0;
	data->keys.neg_view = 0;
}
