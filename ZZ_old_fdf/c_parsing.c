/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:59:10 by sravizza          #+#    #+#             */
/*   Updated: 2025/10/30 11:30:43 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	parsing(char **argv, t_map map, t_data *data)
{
	map = get_width_and_height(argv, map, data);
	map.location = malloc(sizeof(int) * map.height * map.width);
	if (!map.location)
		(ft_mlx_destroy(data, 0), error("map.location malloc fail"));
	map.color = malloc(sizeof(int) * map.height * map.width);
	if (!map.color)
		(free(map.location), ft_mlx_destroy(data, 0),
			error("map.color malloc fail"));
	map = get_location_and_color(argv, map, data);
	return (map);
}

t_map	get_width_and_height(char **argv, t_map map, t_data *data)
{
	int		fd;
	char	*line;

	fd = open((const char *) argv[1], O_RDONLY);
	if (fd < 0)
		(ft_mlx_destroy(data, 0), handle_closing(data),
			error("cannot open file (1)"));
	line = get_next_line(fd);
	if (line)
	{
		map.width = width_count(line, ' ');
		map.height++;
		free(line);
	}
	line = get_next_line(fd);
	while (line)
	{
		map.height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}

t_map	get_location_and_color(char **argv, t_map map, t_data *data)
{
	int		m;
	int		fd;
	char	**temp1;
	char	*line;

	fd = open((const char *) argv[1], O_RDONLY);
	if (fd < 0)
		(ft_mlx_destroy(data, 1), handle_closing(data),
			error("cannot open file (2)"));
	m = 0;
	line = get_next_line(fd);
	while (line)
	{
		temp1 = ft_split(line, ' ');
		m = get_location_and_color2(&map, m, temp1);
		free_all(temp1);
		free(line);
		line = get_next_line(fd);
	}
	return (map);
}

int	get_location_and_color2(t_map *map, int m, char **temp1)
{
	int		t;
	char	**temp2;

	t = 0;
	while (temp1[t])
	{
		temp2 = ft_split(temp1[t], ',');
		map->location[m] = ft_atoi(temp2[0]);
		if (temp2[1] != NULL)
			map->color[m] = ft_atoi_base16(temp2[1]);
		else if (temp2[1] == NULL && map->location[m] != 0)
			map->color[m] = GREEN;
		else
			map->color[m] = BLUE;
		free_all(temp2);
		t++;
		m++;
	}
	return (m);
}

int	width_count(char const *str, char c)
{
	int			i;
	static int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == 0))
			count++;
		i++;
	}
	return (count);
}
