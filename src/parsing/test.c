/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:01:39 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/06 11:48:13 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void print_params(t_map *map)
{
	ft_printf("NO: %s\n", map->no);
	ft_printf("SO: %s\n", map->so);
	ft_printf("EA: %s\n", map->ea);
	ft_printf("WE: %s\n", map->we);
	ft_printf("F: %d, %d, %d\n", map->f[0], map->f[1], map->f[2]);
	ft_printf("C: %d, %d, %d\n", map->c[0], map->c[1], map->c[2]);
}

void print_map(t_map *map)
{
	int y;

	y = -1;
	while (map->coor[++y])
		ft_printf("%s$\n", map->coor[y]);
}
