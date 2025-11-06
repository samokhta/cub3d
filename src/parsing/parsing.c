/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:58:24 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/06 13:21:06 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	parsing(char *file, t_map *map)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (format_error("cannot open file"), 0);
	initialise_param(map);
	if (!read_params(fd, map))
		return (close(fd), free_params(map), 0);
	skip_empty_lines(fd);
	if (!read_map(fd, map))
		return (close(fd), free_params(map), 0);
	if (!get_player_coor(map) || map->player[0] == -1)
		return ((close(fd), free_params(map), 0));
	// if something left
		// wrong
	close(fd);
	print_params(map);
	print_map(map);
	return (1);
}
