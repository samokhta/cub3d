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

void	draw_square(t_data *data, int x, int y, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_pixel_put(&data->img, x + j, y + i, 0xFFFFFF);
			j++;
		}
		i++;
	}
}

int	find_size(t_data *data)
{
	int	i;
	int	map_max;
	int	img_max;

	i = 0;
	if (data->map.width >= data->map.height)
		map_max = data->map.width;
	else
		map_max = data->map.height;
	if (data->img.width >= data->img.height)
		img_max = data->img.height;
	else
		img_max = data->img.width;
	while ((i + 1) * map_max <= img_max)
		i++;
	
	printf("tile size: %d\n", i);
	return (i);
}

void    ft_minimap(t_data *data)
{
	int x;
	int y;
	int map_x;
	int map_y;
	int square_size;

	square_size = find_size(data);
	map_y = 0;
	y = 0;
	while (data->map.coor[map_y])
	{
		map_x = 0;
		x = 0;
		while (data->map.coor[map_y][map_x])
		{
			if (data->map.coor[map_y][map_x] == '1')
				draw_square(data, x, y, square_size);
			map_x++;
			x += square_size;
		}
		map_y++;
		y += square_size;
	}
}
