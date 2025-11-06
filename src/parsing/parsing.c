/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:58:24 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/06 18:04:33 by sravizza         ###   ########.fr       */
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
	if (!read_map(fd, map, 0, NULL))
		return (close(fd), free_params(map), 0);
	if (!get_player_coor(map))
		return ((close(fd), free_params(map), 0));
	// if something left
		// wrong
	close(fd);
	print_params(map);
	ft_printf("\nPLAYER:\nrow: %i\ncol: %i\ndir: %c\n", map->p_row, map->p_col, map->p_dir);
	ft_printf("\nMAP:\nheight: %i\nwidth: %i\n", map->height, map->width);
	if (!validate_map(map))
		return (0);
	printf("\nMAP VALIDATED\n");
	// print_map(map->coor);
	return (1);
}
