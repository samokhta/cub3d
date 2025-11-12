/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <samokhta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:33:26 by samokhta          #+#    #+#             */
/*   Updated: 2025/11/11 15:54:40 by samokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define MINIMAP_SIZE 10

void	draw_square(t_data *data, int x, int y, int size, int color)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_pixel_put(&data->img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void    ft_minimap(t_data *data)
{
	int x;
	int y;
	int map_x;
	int map_y;
	int square_size;

	square_size = MINIMAP_SIZE;
	map_y = 0;
	y = 0;
	while (data->map.coor[map_y])
	{
		map_x = 0;
		x = 0;
		while (data->map.coor[map_y][map_x])
		{
			if (data->map.coor[map_y][map_x] == '1')
				draw_square(data, x, y, square_size, 0xFFFFFF); // Wall - white
			else if (data->map.coor[map_y][map_x] == '0')
				draw_square(data, x, y, square_size, 0x000000); // Floor - black
			map_x++;
			x += square_size;
		}
		map_y++;
		y += square_size;
	}
}