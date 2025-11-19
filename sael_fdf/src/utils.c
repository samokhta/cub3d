/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samokhta <samokhta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:05:17 by samokhta          #+#    #+#             */
/*   Updated: 2025/02/28 15:03:22 by samokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_error(char *string)
{
	ft_putstr_fd(string, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split == NULL)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	hex_to_decimal(char *hex)
{
	int	length;
	int	base;
	int	decimal;
	int	i;

	length = ft_strlen(hex);
	base = 1;
	decimal = 0;
	i = length - 1;
	while (i >= 0)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			decimal += (hex[i] - '0') * base;
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			decimal += (hex[i] - 'A' + 10) * base;
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			decimal += (hex[i] - 'a' + 10) * base;
		base *= 16;
		i--;
	}
	return (decimal);
}

void	free_map(t_point **map, t_size map_size)
{
	int	y;

	y = 0;
	if (map == NULL)
		return ;
	while (y < map_size.y)
	{
		free(map[y]);
		y++;
	}
	free(map);
}

void	print_map(t_point **map, t_size size)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			printf("%d  ", map[y][x].z);
			x++;
		}
		printf("\n");
		y++;
	}
}
