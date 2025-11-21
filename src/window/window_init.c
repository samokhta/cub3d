/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael <sael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:15:08 by samokhta          #+#    #+#             */
/*   Updated: 2025/11/21 21:31:13 by sael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    safe_destroy_image(void *mlx, t_img *img)
{
    if (img && img->img)
    {
        mlx_destroy_image(mlx, img->img);
        img->img = NULL;
    }
}


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

int	key_press(int key, t_data *data)
{
	if (key == KEY_ESC)
		data->key.esc = true;
	if (key == KEY_W)
		data->key.w = true;
	if (key == KEY_S)
		data->key.s = true;
	if (key == KEY_A)
		data->key.a = true;
	if (key == KEY_D)
		data->key.d = true;
	if (key == KEY_LEFT)
		data->key.left_arr = true;
	if (key == KEY_RIGHT)
		data->key.right_arr = true;
	return (0);
}

int	key_unpress(int key, t_data *data)
{
	if (key == KEY_ESC)
		data->key.esc = false;
	if (key == KEY_W)
		data->key.w = false;
	if (key == KEY_S)
		data->key.s = false;
	if (key == KEY_A)
		data->key.a = false;
	if (key == KEY_D)
		data->key.d = false;
	if (key == KEY_LEFT)
		data->key.left_arr = false;
	if (key == KEY_RIGHT)
		data->key.right_arr = false;
	return (0);
}

void	init_keys(t_data *data)
{
	data->key.w = false;
	data->key.a = false;
	data->key.s = false;
	data->key.d = false;
	data->key.left_arr = false;
	data->key.right_arr = false;
	data->key.esc = false;
}

void	ft_window_init(t_data *data)
{
	data->mlx = mlx_init(); //leak
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	init_keys(data);
	mlx_key_hook(data->win, key_press, data);
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 3, 1L << 1, key_unpress, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	return ;
}
