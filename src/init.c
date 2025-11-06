/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:46:36 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/06 11:21:35 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isfilename(int c)
{
	if (ft_isalnum(c) || c == '-' || c == '_')
		return (1);
	return (0);
}

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

void initialise_param(t_map *map)
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
	map->player[0] = -1;
	map->player[1] = -1;
	map->player[2] = -1;
	map->lst = NULL;
	map->coor = NULL;
}
