/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:44:22 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/13 12:51:18 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting (t_data *data)
{
	int		x;
	t_ray	ray;

	clear_window(data);
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		init_ray(data, &ray, x);
		init_step_and_side_dist(data, &ray);
		dda(data, &ray);
		// get_wall_dist(data, &ray);
		// get_wall_height(&ray);
		// get_texture(data, &ray);
		// draw_line(data, &ray, x);
		x++;
	}
}

double	ft_fabs(double d)
{
	if (d < 0)
		d = -d;
	return (d);
}

void	init_ray(t_data *data, t_ray *ray, int x)
{
	double	cam_x;

	cam_x = 2 * x /(double)WINDOW_WIDTH -1;
	ray->ray_dir_x = data->player.dir_x + data->player.plane_x * cam_x;
	ray->ray_dir_y = data->player.dir_y + data->player.plane_y * cam_x;
	ray->map_x = (int)data->player.x;
	ray->map_y = (int)data->player.y;
	if (ray->ray_dir_x == 0)
		ray->d_dist_x = 1e30;
	else
		ray->d_dist_x = ft_fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->ray_dir_y == 1e30;
	else
		ray->d_dist_y = ft_fabs(1 / ray->ray_dir_y);
}

void	init_step_and_side_dist(t_data *data, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->player.x - ray->map_x) * ray->d_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->player.x) * ray->d_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->player.y - ray->map_y) * ray->d_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->player.y) * ray->d_dist_y;
	}
}

void	dda(t_data *data, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->d_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->d_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map.coor[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

void	calculate_wall_distance(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - data->player.x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - data->player.y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
}
