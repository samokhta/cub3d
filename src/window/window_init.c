/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <samokhta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:16:26 by samokhta          #+#    #+#             */
/*   Updated: 2025/11/11 16:03:22 by samokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	int		offset;
	char	*dst;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
	{
		printf("pixel out of bounds\n");
		return;
	}
	offset = (y * img->line_length + x * (img->bits_per_pixel / 8));
	dst = img->addr + offset;
	*(unsigned int *)dst = color;
}

int    key_hook(int keycode, t_data *data)
{
	if (keycode == 65307) // Escape key
	{
		mlx_destroy_image(data->mlx, data->img.img);
		mlx_destroy_display(data->mlx);
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

int close_hook(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_display(data->mlx);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

void    ft_window_init(t_data *data)
{
	data->mlx = mlx_init();
    data->img.img = mlx_new_image(data->mlx, 1000, 1000);
	data->img.height = 1000;
	data->img.width = 1000;
    data->img.addr = mlx_get_data_addr(data->img.img,
            &data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	data->win = mlx_new_window(data->mlx, 1000, 1000, "cub3d");

    mlx_key_hook(data->win, key_hook, data);
    mlx_hook(data->win, 17, 0, close_hook, data);
    return ;
}

//void    ft_window_init(t_data *data)
//{
//	data->mlx = mlx_init();
//    data->img.img = mlx_new_image(data->mlx, 1920, 1080);
//    data->img.addr = mlx_get_data_addr(data->img.img,
//            &data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
//	data->win = mlx_new_window(data->mlx, 1920, 1080, "cub3d");
//    mlx_key_hook(data->win, key_hook, &data);
//    mlx_hook(data->win, 17, 0, close_hook, &data);
//	mlx_loop(data->mlx);
//    return ;
//}
