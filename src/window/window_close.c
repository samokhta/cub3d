/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_lose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:44:22 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/27 12:56:55 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_data *data)
{
	free_all(data);
	safe_destroy_image(data->mlx, &data->screen_img);
	safe_destroy_image(data->mlx, &data->minimap_img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

void	cleanup_window(t_data *data)
{
	free_all(data);
	safe_destroy_image(data->mlx, &data->screen_img);
	safe_destroy_image(data->mlx, &data->minimap_img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}
