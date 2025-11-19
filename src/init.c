/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:46:36 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/19 15:37:42 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_filename(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	if (len < 5)
		return (0);
	i = 0;
	while (str[i] && i < len - 4)
	{
		if (!ft_isfilename(str[i]))
			return (0);
		i++;
	}
	if (ft_strncmp(str + len - 4, ".cub", 4))
		return (0);
	return (1);
}

void	initialise_param(t_map *map)
{
	map->f[0] = -1;
	map->f[1] = -1;
	map->f[2] = -1;
	map->c[0] = -1;
	map->c[1] = -1;
	map->c[2] = -1;
	map->no = NULL;
	map->so = NULL;
	map->ea = NULL;
	map->we = NULL;
	map->p_row = -1;
	map->p_col = -1;
	map->p_dir = 'F';
	map->lst = NULL;
	map->coor = NULL;
	map->tex_size = 0;
	map->tex_size = 0;
}

void	assign_dir(t_player *player, double dir_x, double dir_y)
{
	player->dir_x = dir_x;
	player->dir_y = dir_y;
}

void	assign_plane(t_player *player, double plane_x, double plane_y)
{
	player->plane_x = plane_x;
	player->plane_y = plane_y;
}

void	initialise_player(t_player *player, t_map *map)
{
	player->x = (double)map->p_col + 0.5;
	player->y = (double)map->p_row + 0.5;
	if (map->p_dir == 'N')
	{
		assign_dir(player, 0.0, -1.0);
		assign_plane(player, 0.66, 0.0);
	}
	if (map->p_dir == 'S')
	{
		assign_dir(player, 0.0, 1.0);
		assign_plane(player, -0.66, 0.0);
	}
	if (map->p_dir == 'E')
	{
		assign_dir(player, 1.0, 0.0);
		assign_plane(player, 0.0, 0.66);
	}
	if (map->p_dir == 'W')
	{
		assign_dir(player, -1.0, 0.0);
		assign_plane(player, 0.0, -0.66);
	}
}
