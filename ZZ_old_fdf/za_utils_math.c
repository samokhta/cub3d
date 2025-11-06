/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   za_utils_math.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:49:54 by sravizza          #+#    #+#             */
/*   Updated: 2025/10/30 11:31:16 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	isox(int x, int y)
{
	return ((x - y) * cos(0.523599));
}

int	isoy(int x, int y, int z)
{
	return ((x + y) * sin(0.523599) - z);
}

//sqrt(2)/2 ~= 0.707
int	cavx(int x, int z)
{
	return (x + (int)(z * 0.707));
}

int	cavy(int y, int z)
{
	return (y + (int)(z * 0.707));
}

float	get_fract(int x, int y, t_line line)
{
	int		dx;
	int		dy;

	dx = line.x1 - line.x0;
	dy = line.y1 - line.y0;
	if (abs(dx) > abs(dy) && dx != 0)
		return ((float)(x - line.x0) / (float)abs(dx));
	else if (abs(dx) < abs(dy) && dy != 0)
		return ((float)(y - line.y0) / (float)abs(dy));
	else if (abs(dx) == abs(dy) && dx != 0)
		return ((float)(x - line.x0) / (float)abs(dx + dy));
	return (0.5);
}
