/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:42:40 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/19 13:38:19 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	get_texture_pixel(void *texture, int x, int y)
{
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	unsigned int	color;

	addr = mlx_get_data_addr(texture, &bpp, &line_len, &endian);
	color = *(unsigned int *)(addr + (y * line_len + x * (bpp / 8)));
	return (color);
}

void	draw_line(t_data *data, t_ray *ray, int x)
{
	int		y;
	int		tex_y;
	double	step;
	double	tex_pos;
	int		color;

	step = (double)data->map.tex_size / ray->line_height;
	tex_pos = (ray->draw_start - WINDOW_HEIGHT
			/ 2 + ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_y = (int)tex_pos & (data->map.tex_size - 1);
		tex_pos += step;
		color = get_texture_pixel(ray->texture, ray->tex_x, tex_y);
		ft_pixel_put(&data->screen_img, x, y, color);
		y++;
	}
}
