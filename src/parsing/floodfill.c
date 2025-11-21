/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael <sael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:16:57 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/21 19:29:15 by sael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//start at player position
// move in all directions
// if 0 ok keep on moving, change to V
// if 1 stop
// if out fo bounds or SPACE, map is incomplete

char	**ft_double_strdup(char **src, int len)
{
	int		i;
	char	**dest;

	if (!src)
		return (NULL);
	while (src[len])
		len++;
	dest = malloc(sizeof(char *) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = ft_strdup(src[i]);
		if (!dest[i])
		{
			while (--i >= 0)
				free(dest[i]);
			free(dest);
			return (NULL);
		}
		i++;
	}
	dest[len] = NULL;
	return (dest);
}

int	flood_fill(t_map *map, char **flood, int row, int col)
{
	if (row < 0 || row >= map->height || col < 0
		|| col >= map->width || flood[row][col] == ' ')
		return (0);
	if (flood[row][col] == '1' || flood[row][col] == 'V')
		return (1);
	flood[row][col] = 'V';
	if (!flood_fill(map, flood, row + 1, col)
		|| !flood_fill(map, flood, row - 1, col)
		|| !flood_fill(map, flood, row, col + 1)
		|| !flood_fill(map, flood, row, col - 1)
		|| !flood_fill(map, flood, row + 1, col + 1)
		|| !flood_fill(map, flood, row - 1, col - 1)
		|| !flood_fill(map, flood, row - 1, col + 1)
		|| !flood_fill(map, flood, row + 1, col - 1))
		return (0);
	return (1);
}

int	validate_map(t_map *map)
{
	char	**flood;

	flood = ft_double_strdup(map->coor, 0);
	if (!flood)
		return (format_error("malloc fail"), 0);
	if (!flood_fill(map, flood, map->p_row, map->p_col))
		return (format_error("map is not valid"), free_double(flood), 0);
	return (free_double(flood), 1);
}
