/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael <sael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:33:26 by samokhta          #+#    #+#             */
/*   Updated: 2025/11/18 15:34:21 by sael             ###   ########.fr       */
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
			ft_pixel_put(&data->minimap_img, x + j, y + i, 0xFFFFFF);
			j++;
		}
		i++;
	}
}

void	draw_square_bg(t_data *data, int x, int y, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_pixel_put(&data->minimap_img, x + j, y + i, rgb_to_int(data->map.f));
			j++;
		}
		i++;
	}
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	find_size(int img_size, int map_max)
{
	int	i;
	i = 1;
	while ((i + 1) * map_max <= img_size - 10)
		i++;
	//printf("tile size: %d\n", i);
	return (i);
}

void	display_minimap(t_data *data, int tile_size, int offset_x, int offset_y)
{
	int x;
	int y;
	int map_x;
	int map_y;

	map_y = 0;
	y = offset_y;
	while (data->map.coor[map_y])
	{
		map_x = 0;
		x = offset_x;
		while (data->map.coor[map_y][map_x])
		{
			if (data->map.coor[map_y][map_x] == '1')
				draw_square(data, x, y, tile_size);
			map_x++;
			x += tile_size;
		}
		map_y++;
		y += tile_size;
	}	
}

int	find_offset(int img_length, int map_length, int tile_size)
{
	int	offset;

	offset = img_length - (map_length * tile_size);
	return (offset / 2);
}

void	display_player(t_data *data, int tile_size, int offset_x, int offset_y)
{
	int	player_x;
	int	player_y;
	int	size;
	int	i;
	int	j;

	player_x = (int)(data->player.x * tile_size) + offset_x;
	player_y = (int)(data->player.y * tile_size) + offset_y;
	size = tile_size / 2;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_pixel_put(&data->minimap_img, player_x + j - size / 2, player_y + i - size / 2, 0xFF0000);
			j++;
		}
		i++;
	}
}

void    ft_minimap(t_data *data)
{
	int	map_max;
	int tile_size;
	int	offset_x;
	int	offset_y;

	map_max = max(data->map.width, data->map.height);
	tile_size = find_size(WINDOW_WIDTH / 8, map_max);
	offset_x = find_offset(WINDOW_WIDTH / 8, data->map.width, tile_size);
	offset_y = find_offset(WINDOW_WIDTH / 8, data->map.height, tile_size);
	ft_img_init(data->mlx, &data->minimap_img, WINDOW_WIDTH / 8, WINDOW_WIDTH / 8);
	draw_square_bg(data, 0, 0, WINDOW_WIDTH / 8);
	display_minimap(data, tile_size, offset_x, offset_y);
	display_player(data, tile_size, offset_x, offset_y);
}
