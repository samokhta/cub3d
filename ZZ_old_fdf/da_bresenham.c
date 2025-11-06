/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   da_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:05:00 by sravizza          #+#    #+#             */
/*   Updated: 2025/10/30 11:30:49 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_line(t_data *data, t_line line)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	d;

	dx = abs(line.x1 - line.x0);
	dy = abs(line.y1 - line.y0);
	sx = 1;
	sy = 1;
	if (line.x1 < line.x0)
		sx = -1;
	if (line.y1 < line.y0)
		sy = -1;
	d = dx - dy;
	bresenham(data, line, (t_line_bres){dx, dy, sx, sy, d});
	return (0);
}

int	bresenham(t_data *data, t_line line, t_line_bres bres)
{
	int	color;
	int	ppx;
	int	ppy;

	ppx = line.x0;
	ppy = line.y0;
	while (ppx != line.x1 || ppy != line.y1)
	{
		color = get_color(ppx, ppy, line);
		if (data->keys.neg_view == 1)
			color = 0xFFFFFF - color;
		img_pixel_put(&data->img, ppx, ppy, color);
		if ((2 * bres.d) > (-bres.dy))
		{
			bres.d -= bres.dy;
			ppx += bres.sx;
		}
		else if ((2 * bres.d) < bres.dx)
		{
			bres.d += bres.dx;
			ppy += bres.sy;
		}
	}
	return (0);
}

void	render_right_line(t_data *data, int x, int y)
{
	int		x0;
	int		x1;
	int		y0;
	int		y1;

	x0 = get_x(data, x, y);
	y0 = get_y(data, x, y);
	x1 = get_x(data, x + 1, y);
	y1 = get_y(data, x + 1, y);
	render_line(data, (t_line){x0, y0, x1, y1,
		data->map.color[y * data->map.width + x],
		data->map.color[y * data->map.width + x + 1]});
	return ;
}

void	render_down_line(t_data *data, int x, int y)
{
	int		x0;
	int		x1;
	int		y0;
	int		y1;

	x0 = get_x(data, x, y);
	y0 = get_y(data, x, y);
	x1 = get_x(data, x, y + 1);
	y1 = get_y(data, x, y + 1);
	render_line(data, (t_line){x0, y0, x1, y1,
		data->map.color[y * data->map.width + x],
		data->map.color[(y + 1) * data->map.width + x]});
	return ;
}
