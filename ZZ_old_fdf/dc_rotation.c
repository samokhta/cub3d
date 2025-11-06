/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dc_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:22:44 by sravizza          #+#    #+#             */
/*   Updated: 2025/10/30 11:30:54 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_data *data, int *x, int *y, int *z)
{
	*x -= data->map.width / 2;
	*y -= data->map.height / 2;
	rotate_x(data, y, z);
	rotate_y(data, x, z);
	rotate_z(data, x, y);
	*x += data->map.width / 2;
	*y += data->map.height / 2;
}

void	rotate_x(t_data *data, int *y, int *z)
{
	int	tmp;

	tmp = *y;
	*y = tmp * cos(data->img.mod.x_rot) - *z * sin(data->img.mod.x_rot);
	*z = tmp * sin(data->img.mod.x_rot) + *z * cos(data->img.mod.x_rot);
}

void	rotate_y(t_data *data, int *x, int *z)
{
	int	tmp;

	tmp = *x;
	*x = tmp * cos(data->img.mod.y_rot) + *z * sin(data->img.mod.y_rot);
	*z = *z * cos(data->img.mod.y_rot) - tmp * sin(data->img.mod.y_rot);
}

void	rotate_z(t_data *data, int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = tmp * cos(data->img.mod.z_rot) - *y * sin(data->img.mod.z_rot);
	*y = tmp * sin(data->img.mod.z_rot) + *y * cos(data->img.mod.z_rot);
}
