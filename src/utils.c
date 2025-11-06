/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:59:36 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/06 16:32:13 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all(char **str)
{
	int	i;

	if (!str || !(*str))
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
	return ;
}

void	format_error(char *msg)
{
	ft_printf("Error\n%s\n", msg);
	return ;
}

void	free_params(t_map *map)
{
	free(map->no);
	free(map->so);
	free(map->ea);
	free(map->we);
	free_lst(&(map->lst));
	free_all(map->coor);
}
