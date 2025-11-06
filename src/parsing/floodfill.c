/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:16:57 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/06 16:16:19 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//start at player position
// move in all directions
// if 0 ok keep on moving, change to V
// if 1 stop
// if out fo bounds or SPACE, map is incomplete

int	validate_map(t_map *map)
{
	char **flood;

	flood = copy(map->coor); //create function
	if (!flood)
		return (format_error("malloc fail"), 0);
	if (!flood_fill(map, flood, map->player[0], map->player[1]))
		return (0);
	return (1);
}

int flood_fill(t_map *map, char **flood, int row, int col)
{
	if (row < 0 || row >= map->length || col < 0 || col >= map->width || flood[row][col] == ' ')
		return (0);
	if (row == 1)
		return (1);
	flood[row][col] = 'V';
	if (!flood_fill(map, flood, row + 1, col)
	|| !flood_fill(map, flood, row - 1, col)
	|| !flood_fill(map, flood, row, col + 1)
	|| !flood_fill(map, flood, row, col - 1))
		return (0);
	return (1);
}
