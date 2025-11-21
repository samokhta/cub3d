/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <samokhta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:59:36 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/19 15:57:40 by samokhta         ###   ########.fr       */
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
	free_lst(&(map->lst));
	free_double(map->coor);
}

void	free_all(t_data *data)
{
	free_params(&data->map);
	printf("freeing all allocated memory\n");
	free_textures(data);
	printf("all memory freed\n");
}

int	ft_isfilename(int c)
{
	if (ft_isalnum(c) || c == '-' || c == '_' || c == '/' || c == '.')
		return (1);
	return (0);
}
