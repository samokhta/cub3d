/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_get_coor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:28:03 by sravizza          #+#    #+#             */
/*   Updated: 2025/10/30 11:30:52 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_x(t_data *data, int x, int y)
{
	int	z;

	z = data->map.location[y * data->map.width + x]
		* data->img.mod.zoom / data->img.mod.altcoef;
	x *= data->img.mod.zoom;
	y *= data->img.mod.zoom;
	rotate(data, &x, &y, &z);
	if (data->keys.cav_view == 1)
		return (cavx(-x, y) + data->img.mod.x_offset
			- (data->map.width * data->img.mod.zoom) / 2);
	return (isox(x, y)
		+ data->img.mod.x_offset - (data->map.width * data->img.mod.zoom) / 2);
}

int	get_y(t_data *data, int x, int y)
{
	int	z;

	z = data->map.location[y * data->map.width + x]
		* data->img.mod.zoom / data->img.mod.altcoef;
	x *= data->img.mod.zoom;
	y *= data->img.mod.zoom;
	rotate(data, &x, &y, &z);
	if (data->keys.cav_view == 1)
		return (cavy(-z, y) + data->img.mod.x_offset
			- (data->map.width * data->img.mod.zoom) / 2);
	return (isoy(x, y, z)
		+ data->img.mod.y_offset - (data->map.height * data->img.mod.zoom) / 2);
}
