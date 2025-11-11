/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:01:39 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/11 14:27:00 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_params(t_map *map)
{
	ft_printf("NO: %s\n", map->no);
	ft_printf("SO: %s\n", map->so);
	ft_printf("EA: %s\n", map->ea);
	ft_printf("WE: %s\n", map->we);
	ft_printf("F: %d, %d, %d\n", map->f[0], map->f[1], map->f[2]);
	ft_printf("C: %d, %d, %d\n", map->c[0], map->c[1], map->c[2]);
}

void	print_map(char **map)
{
	int	y;

	ft_printf("\n");
	y = 0;
	while (map[y])
	{
		ft_printf("%s$\n", map[y]);
		y++;
	}
	ft_printf("\n");
}

void	print_player_stats(t_player *player)
{
	printf("\nPLAYER:\n");
	printf("X: %f\n", player->x);
	printf("Y: %f\n", player->y);
	printf("dir_X: %f\n", player->dir_x);
	printf("dir_Y: %f\n", player->dir_y);
	printf("plane_X: %f\n", player->plane_x);
	printf("plane_Y: %f\n", player->plane_y);
}
