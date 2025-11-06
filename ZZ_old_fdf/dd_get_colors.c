/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dd_get_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:29:08 by sravizza          #+#    #+#             */
/*   Updated: 2025/10/30 11:30:56 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color(int x, int y, t_line line)
{
	int		red;
	int		green;
	int		blue;
	float	fract;

	if (line.c0 == line.c1)
		return (line.c0);
	fract = get_fract(x, y, line);
	if (fract > 1)
		fract = 1;
	else if (fract < 0)
		fract = 0;
	red = get_red(line.c0)
		+ (int)((get_red(line.c1) - get_red(line.c0)) * fract);
	green = get_green(line.c0)
		+ (int)((get_green(line.c1) - get_green(line.c0)) * fract);
	blue = get_blue(line.c0)
		+ (int)((get_blue(line.c1) - get_blue(line.c0)) * fract);
	return (combine_rgb(red, green, blue));
}

int	get_red(int color)
{
	return ((color >> 16) & 0xFF);
}

int	get_green(int color)
{
	return ((color >> 8) & 0xFF);
}

int	get_blue(int color)
{
	return (color & 0xFF);
}

int	combine_rgb(int r, int g, int b)
{
	return (((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF));
}
