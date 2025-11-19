/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <samokhta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:28:04 by samokhta          #+#    #+#             */
/*   Updated: 2025/03/07 16:06:50 by samokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	my_mlx_pixel_put(t_mlx_img *img, int x, int y, unsigned int color)
{
	int		offset;
	char	*dst;

	offset = (y * img->line_length + x * (img->bits_per_pixel / 8));
	dst = img->addr + offset;
	*(unsigned int *)dst = color;
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	center(t_bresenham *params, t_mlx_data data, int grid_size)
{
	params->x += (grid_size * data.map_size.x / 2) + 150;
	params->y += (grid_size * data.map_size.y / 2) + 150;
	params->x1 += (grid_size * data.map_size.x / 2) + 150;
	params->y1 += (grid_size * data.map_size.y / 2) + 150;
}

void	grid(t_bresenham *params, int grid_size)
{
	params->x *= grid_size;
	params->y *= grid_size;
	params->x1 *= grid_size;
	params->y1 *= grid_size;
	params->z *= grid_size / 4;
	params->z1 *= grid_size / 4;
}

void	bresenham(t_bresenham src, t_mlx_data data, int grid_size)
{
	t_bresenham		params;
	float			x_step;
	float			y_step;
	float			max;

	params = src;
	grid(&params, grid_size);
	isometric(&params.x, &params.y, params.z);
	isometric(&params.x1, &params.y1, params.z1);
	center(&params, data, grid_size);
	x_step = params.x1 - params.x;
	y_step = params.y1 - params.y;
	max = max1(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(params.x - params.x1) || (int)(params.y - params.y1))
	{
		if (!(params.x >= 0 && params.x < 1000
				&& params.y >= 0 && params.y < 1000))
			my_mlx_pixel_put(&data.img, 0, 0, 0x000000);
		else
			my_mlx_pixel_put(&data.img, params.x, params.y, params.color);
		params.x += x_step;
		params.y += y_step;
	}
}
