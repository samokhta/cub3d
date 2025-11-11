/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <samokhta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:28:13 by samokhta          #+#    #+#             */
/*   Updated: 2025/03/07 15:16:04 by samokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	close_free(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data->map, data->map_size);
	exit (0);
}

int	esc_hook(int keycode, t_mlx_data *data)
{
	if (keycode == 65307)
		close_free(data);
	return (0);
}

void	set_hooks(t_mlx_data *data)
{
	mlx_key_hook(data->win, esc_hook, data);
	mlx_hook(data->win, 17, 0, close_free, data);
}
