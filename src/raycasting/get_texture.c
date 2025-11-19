/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:32:29 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/19 15:39:09 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pick_texture(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			ray->texture = data->map.tex_ea;
		else
			ray->texture = data->map.tex_we;
	}
	else
	{
		if (ray->ray_dir_y > 0)
			ray->texture = data->map.tex_so;
		else
			ray->texture = data->map.tex_no;
	}
}

void	get_texture_coor(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_x = data->player.y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = data->player.x + ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * data->map.tex_size);
	if ((ray->side == 0 && ray->ray_dir_x > 0)
		|| (ray->side == 1 && ray->ray_dir_y < 0))
		ray->tex_x = data->map.tex_size - ray->tex_x - 1;
}

void	get_texture(t_data *data, t_ray *ray)
{
	pick_texture(data, ray);
	get_texture_coor(data, ray);
}
