/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <samokhta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:20:09 by samokhta          #+#    #+#             */
/*   Updated: 2025/03/07 15:40:25 by samokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_bresenham	x_set_params(int x, int y, t_point **map)
{
	t_bresenham	res;

	res.x = x;
	res.y = y;
	res.x1 = x + 1;
	res.y1 = y;
	res.z = map[y][x].z;
	res.z1 = map[y][x + 1].z;
	res.color = map[y][x].color;
	return (res);
}

t_bresenham	y_set_params(int x, int y, t_point **map)
{
	t_bresenham	res;

	res.x = x;
	res.y = y;
	res.x1 = x;
	res.y1 = y + 1;
	res.z = map[y][x].z;
	res.z1 = map[y + 1][x].z;
	res.color = map[y][x].color;
	return (res);
}

void	x_draw(t_size increment, t_bresenham *x_bres,
			t_mlx_data data, int grid_size)
{
	*x_bres = x_set_params(increment.x, increment.y, data.map);
	bresenham(*x_bres, data, grid_size);
}

void	y_draw(t_size increment, t_bresenham*y_bres,
			t_mlx_data data, int grid_size)
{
	*y_bres = y_set_params(increment.x, increment.y, data.map);
	bresenham(*y_bres, data, grid_size);
}
