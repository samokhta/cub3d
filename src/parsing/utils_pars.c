/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:09:17 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/06 13:43:13 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int params_complete(t_map *map)
{
	if (map->no && map->so && map->ea && map->we && map->c[0] != -1 && map->f[0] != -1)
		return (1);
	return (0);
}

int	empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] && str[i] == '\n')
		return (1);
	return (0);
}


char *clean_line(char *src)
{
	int		start;
	int		end;
	char	*dest;

	if (!src)
		return (NULL);
	start = 0;
	while (src[start] == ' ' || src[start] == '\t')
		start++;
	end = ft_strlen(src) - 1;
	if (end >= 0 && src[end] == '\n')
		end--;
	while (end >= start && (src[end] == ' ' || src[end] == '\t'))
		end--;
	dest = ft_substr(src, start, end - start + 1);
	if (!dest)
		return (NULL);
	return (dest);
}

int	get_player_coor(t_map *map)
{
	int	x;
	int	y;	

	x = 0;
	while (map->coor && map->coor[x])
	{
		y = 0;
		while (map->coor[x][y])
		{
			if (map->coor[x][y] == 'N' || map->coor[x][y] == 'S'
				|| map->coor[x][y] == 'E' || map->coor[x][y] == 'W')
			{
				if (map->player[0] != -1)
					return (0);
				map->player[0] = x;
				map->player[1] = y;
				map->player[2] = map->coor[x][y];
				// map->coor[x][y] = '0';
			}
			y++;
		}
		x++;
	}
	// ft_printf("HERE");
	return (map->player[0] != -1);
}

char	*skip_empty_lines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && (empty_line(line)))
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}
