/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:44:22 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/19 15:38:48 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_data *data)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		init_ray(data, &ray, x);
		init_step_and_side_dist(data, &ray);
		dda(data, &ray);
		get_wall_dist(data, &ray);
		get_wall_height(&ray);
		get_texture(data, &ray);
		draw_line(data, &ray, x);
		x++;
	}
}
