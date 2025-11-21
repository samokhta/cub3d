/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <samokhta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-20 14:14:58 by samokhta          #+#    #+#             */
/*   Updated: 2025-11-20 14:14:58 by samokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	int		offset;
	char	*dst;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	offset = (y * img->line_length + x * (img->bits_per_pixel / 8));
	dst = img->addr + offset;
	*(unsigned int *)dst = color;
}

void	ft_img_init(void *mlx, t_img *new_img, int width, int height)
{
	new_img->img = mlx_new_image(mlx, width, height);
	new_img->height = height;
	new_img->width = width;
	new_img->addr = mlx_get_data_addr(new_img->img,
			&new_img->bits_per_pixel, &new_img->line_length, &new_img->endian);
}
