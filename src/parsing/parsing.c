/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael <sael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:58:24 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/21 21:17:26 by sael             ###   ########.fr       */
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
		return (get_next_line(-1), close(fd), free_params(map), 0);
	if (!read_map(fd, map, 0))
		return (get_next_line(-1), close(fd), free_params(map), 0);
	if (!get_player_coor(map))
		return (get_next_line(-1), close(fd), free_params(map), 0);
	close(fd);
	get_next_line(-1);
	if (!validate_map(map))
		return (free_params(map), 0);
	return (1);
}
