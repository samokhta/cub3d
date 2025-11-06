/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <samokhta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:16:26 by samokhta          #+#    #+#             */
/*   Updated: 2025/11/06 15:24:45 by samokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	int		offset;
	char	*dst;

	offset = (y * img->line_length + x * (img->bits_per_pixel / 8));
	dst = img->addr + offset;
	*(unsigned int *)dst = color;
}

int    key_hook(int keycode, t_data *data)
{
    (void)data;
    if (keycode == 65307) // Escape key
    {
        // Add any necessary cleanup code here
        exit(0);
    }
    return (0);
}

int close_hook(t_data *data)
{
    (void)data;
    // Add any necessary cleanup code here
    exit(0);
    return (0);
}

void    ft_window_init(t_data *dataptr)
{
    t_data   data;

    data = *dataptr;
	data.mlx = mlx_init();
    data.img.img = mlx_new_image(data.mlx, 1920, 1080);
    data.img.addr = mlx_get_data_addr(data.img.img,
            &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	data.win = mlx_new_window(data.mlx, 1920, 1080, "cub3d");
    mlx_key_hook(data.win, key_hook, &data);
    mlx_hook(data.win, 17, 0, close_hook, &data);
	mlx_loop(data.mlx);
    return ;
}
