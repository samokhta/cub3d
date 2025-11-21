/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael <sael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:59:36 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/21 21:31:38 by sael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_double(char **str)
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
	free_lst(&map->lst);
	free_double(map->coor);
}

void	free_all(t_data *data)
{
	free_params(&data->map);
	free_textures(data);
}

int	ft_isfilename(int c)
{
	if (ft_isalnum(c) || c == '-' || c == '_' || c == '/' || c == '.')
		return (1);
	return (0);
}
