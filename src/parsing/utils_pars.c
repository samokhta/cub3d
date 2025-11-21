/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:09:17 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/06 17:49:08 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	params_complete(t_map *map)
{
	if (map->no && map->so && map->ea && map->we
		&& map->c[0] != -1 && map->f[0] != -1)
		return (1);
	return (0);
}

int	empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if ((str[i] && str[i] == '\n') || str[i] == '\0')
		return (1);
	return (0);
}

char	*clean_line(char *src)
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
	int	col;
	int	row;	

	row = -1;
	while (map->coor && map->coor[++row])
	{
		col = -1;
		while (map->coor[row][++col])
		{
			if (map->coor[row][col] == 'N' || map->coor[row][col] == 'S'
				|| map->coor[row][col] == 'E' || map->coor[row][col] == 'W')
			{
				if (map->p_row != -1)
					return (format_error("too many players"), 0);
				map->p_row = row;
				map->p_col = col;
				map->p_dir = map->coor[row][col];
				map->coor[row][col] = '0';
			}
		}
	}
	if (map->p_row == -1)
		return (format_error("no player"), 0);
	return (1);
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
