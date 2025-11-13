/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael <sael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:16:26 by samokhta          #+#    #+#             */
/*   Updated: 2025/11/13 18:09:49 by sael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    key_hook(int keycode, t_data *data)
{
	(void)data;
	if (keycode == 65307) // Escape key
	{
		//mlx_destroy_image(data->mlx, data->wall_img.img);
		//mlx_destroy_window(data->mlx, data->win);
		//mlx_destroy_display(data->mlx);
		exit(0);
	}
	return (0);
}

int close_hook(t_data *data)
{
	(void)data;
	//mlx_destroy_image(data->mlx, data->wall_img.img);
	//mlx_destroy_window(data->mlx, data->win);
	//mlx_destroy_display(data->mlx);
	exit(0);
	return (0);
}

void    ft_window_init(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");

	ft_background_init(data);
	ft_minimap(data);

	mlx_put_image_to_window(data->mlx, data->win, data->background_img.img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->minimap_img.img, 0, 0);
    mlx_key_hook(data->win, key_hook, data);
    mlx_hook(data->win, 17, 0, close_hook, data);
    return ;
}

/*
image pour le fond
image pr le render 3d
image pour la minimap
image pour le joueur sur la minimap
*/
