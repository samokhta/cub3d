/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <samokhta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-20 14:15:01 by samokhta          #+#    #+#             */
/*   Updated: 2025-11-20 14:15:01 by samokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(t_data *data, int x, int y, int size)
{
	int	i;
	int	j;

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
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_pixel_put(&data->minimap_img,
				x + j, y + i, rgb_to_int(data->map.f));
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
