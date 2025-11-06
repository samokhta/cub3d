/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_rendering.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:00:23 by sravizza          #+#    #+#             */
/*   Updated: 2025/10/30 11:30:47 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render(t_data *data)
{
	if (data->win_ptr == NULL || data->img.img == NULL)
		return (1);
	update_hooks(data);
	render_background(data);
	render_fdf(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	return (0);
}

void	render_fdf(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width - 1)
			render_right_line(data, x++, y);
		y++;
	}
	y = 0;
	while (y < data->map.height - 1)
	{
		x = 0;
		while (x < data->map.width)
			render_down_line(data, x++, y);
		y++;
	}
	return ;
}

void	render_background(t_data *data)
{
	int	x;
	int	y;
	int	color;

	color = BLACK;
	if (data->keys.neg_view == 1)
		color = GRAY;
	y = 0;
	while (y <= WINDOW_HEIGHT)
	{
		x = 0;
		while (x <= WINDOW_WIDTH)
			img_pixel_put(&data->img, x++, y, color);
		y++;
	}
	return ;
}

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}
